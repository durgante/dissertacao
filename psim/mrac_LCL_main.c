#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mrac_LCL.h"

//*************************************************************************
//Declaração dos protótipos das funções
void calculo_acao_controle(filtro *p);

double vcc, vag, vbg, dTa, dTb;

filtro fLCL = {
  {theta1,theta2,theta3,theta4,theta5,theta6},  //theta_k
  {0,0,0,0,0,0},                                //omega_k
  {0,0,0,0,0,0},                                //omega_k_1
  {0,0,0,0,0,0},                                //omega_k_2
  {0,0,0,0,0,0},                                //eta_k_1
  {0,0,0,0,0,0},                                //eta_k_2
  0,                                            //i2m_k
  0,                                            //i2m_k_1
  0,                                            //i2m_k_2
  0,                                            //i2ref_k
  0,                                            //i2ref_k_1
  0,                                            //i2ref_k_2
  0,                                            //iC_k
  0,                                            //v_k_1
  0,                                            //v_k_2
  Kp/km,                                        //rho_k
  1,                                            //m2
  0,                                            //up
  0,                                            //u_k_1
  0                                             //u_k_2
};

//*************************************************************************
//Função principal chamada pelo PSIM
DLLIMPORT void simuser (t, delt, in, out)

double t, delt;
double *in, *out;
{

//-------------------------------------------------------------------------
//Entradas
  fLCL.omega_k[2] = in[0]; //i2_k
  fLCL.omega_k[3] = in[1]; //i2ref_k
  fLCL.i2ref_k    = in[1];
  fLCL.omega_k[4] = 311*sin(f_rad*t); //compensar distúrbio de tensão
  fLCL.omega_k[5] = 311*cos(f_rad*t); //da rede
  fLCL.iC_k       = in[2]; //iC_k
  vcc             = in[3];

//-------------------------------------------------------------------------
//Cálculo da ação de controle e atualização
  calculo_acao_controle(&fLCL);

//-------------------------------------------------------------------------
//Modulação
  if(fLCL.up>=0)
  {
    vag = fLCL.up;
    vbg = 0;
  }
  else
  {
    vag = 0;
    vbg = -fLCL.up;
  }
  dTa = (vag/(vcc+0.0001))*TxPR;
  dTb = (vbg/(vcc+0.0001))*TxPR;

//-------------------------------------------------------------------------
//Setar saída
  out[0] = dTa; //ação de controle
  out[1] = dTb;
  out[2] = fLCL.i2m_k; //saída do modelo de referência
  out[3] = fLCL.theta_k[0];
  out[4] = fLCL.theta_k[1];
  out[5] = fLCL.theta_k[2];
  out[6] = fLCL.theta_k[3];
  out[7] = fLCL.theta_k[4];
  out[8] = fLCL.theta_k[5];
  out[9] = fLCL.eta_k_1[0];
  out[10]= fLCL.m2;
  out[11]= fLCL.rho_k;
  out[12]= fLCL.up;
}

void calculo_acao_controle(filtro *p)
{
  double u_k, up, eta_k[6], e1_k, v_k, q_k, e2_k, ea_k, m2_k;

  // ação de controle adaptativa
  u_k = p->theta_k[0]*p->omega_k[0] +
        p->theta_k[1]*p->omega_k[1] +
        p->theta_k[2]*p->omega_k[2] +
        p->theta_k[3]*p->omega_k[3] +
        p->theta_k[4]*p->omega_k[4] +
        p->theta_k[5]*p->omega_k[5];

  // ação de controle incluindo controlador da malha interna
  p->up = kp*(u_k - p->iC_k);

  // elementos intermediários para atualização das variáveis
  eta_k[0] = p1p2*p->eta_k_1[0] -
          p1*p2*p->eta_k_2[0] +
          km*p->omega_k_2[0];

  eta_k[1] = p1p2*p->eta_k_1[1] -
          p1*p2*p->eta_k_2[1] +
          km*p->omega_k_2[1];

  eta_k[2] = p1p2*p->eta_k_1[2] -
          p1*p2*p->eta_k_2[2] +
          km*p->omega_k_2[2];

  eta_k[3] = p1p2*p->eta_k_1[3] -
          p1*p2*p->eta_k_2[3] +
          km*p->omega_k_2[3];

  eta_k[4] = p1p2*p->eta_k_1[4] -
          p1*p2*p->eta_k_2[4] +
          km*p->omega_k_2[4];

  eta_k[5] = p1p2*p->eta_k_1[5] -
          p1*p2*p->eta_k_2[5] +
          km*p->omega_k_2[5];

  p->i2m_k = (p1+p2)*p->i2m_k_1 -
          p1*p2*p->i2m_k_2 +
          (1-p1)*(1-p2)*p->i2ref_k_2;

  e1_k = p->omega_k[2] - p->i2m_k; //i2_k - i2m_k
  v_k = p1p2*p->v_k_1 - p1*p2*p->v_k_2 + km*p->u_k_2;
  q_k = p->theta_k[0]*eta_k[0] +
        p->theta_k[1]*eta_k[1] +
        p->theta_k[2]*eta_k[2] +
        p->theta_k[3]*eta_k[3] +
        p->theta_k[4]*eta_k[4] +
        p->theta_k[5]*eta_k[5];

  e2_k = q_k - v_k;
  ea_k = e1_k + p->rho_k*e2_k;

  m2_k = 0.1*(eta_k[0]*eta_k[0] +
          eta_k[1]*eta_k[1] +
          eta_k[2]*eta_k[2] +
          eta_k[3]*eta_k[3] +
          eta_k[4]*eta_k[4] +
          eta_k[5]*eta_k[5]) + e2_k*e2_k + p->m2;

  //-----------------------------------------------------------------------
  //Atualização

  //calcula theta(k+1)
  p->theta_k[0] = p->theta_k[0] - (gamaD*ea_k/m2_k)*eta_k[0];
  p->theta_k[1] = p->theta_k[1] - (gamaD*ea_k/m2_k)*eta_k[1];
  p->theta_k[2] = p->theta_k[2] - (gamaD*ea_k/m2_k)*eta_k[2];
  p->theta_k[3] = p->theta_k[3] - (gamaD*ea_k/m2_k)*eta_k[3];
  p->theta_k[4] = p->theta_k[4] - (gamaD*ea_k/m2_k)*eta_k[4];
  p->theta_k[5] = p->theta_k[5] - (gamaD*ea_k/m2_k)*eta_k[5];

  //calcula rho(k+1)
  p->rho_k = p->rho_k - (gama*ea_k*e2_k)/m2_k;

  p->m2 = delta0*(p->m2 - 1) + abs(u_k) + abs(p->omega_k[2]) + 1;

  p->omega_k_2[0] = p->omega_k_1[0];
  p->omega_k_2[1] = p->omega_k_1[1];
  p->omega_k_2[2] = p->omega_k_1[2];
  p->omega_k_2[3] = p->omega_k_1[3];
  p->omega_k_2[4] = p->omega_k_1[4];
  p->omega_k_2[5] = p->omega_k_1[5];

  p->omega_k_1[0] = p->omega_k[0];
  p->omega_k_1[1] = p->omega_k[1];
  p->omega_k_1[2] = p->omega_k[2];
  p->omega_k_1[3] = p->omega_k[3];
  p->omega_k_1[4] = p->omega_k[4];
  p->omega_k_1[5] = p->omega_k[5];

  p->omega_k[0] = u_k; //omega_k(1) = 0*omega_k(1) + 1*u_k;
  p->omega_k[1] = p->omega_k[2]; //omega_k(2) = 0*omega_k(2) + 1*i2_k;

  p->eta_k_2[0] = p->eta_k_1[0];
  p->eta_k_2[1] = p->eta_k_1[1];
  p->eta_k_2[2] = p->eta_k_1[2];
  p->eta_k_2[3] = p->eta_k_1[3];
  p->eta_k_2[4] = p->eta_k_1[4];
  p->eta_k_2[5] = p->eta_k_1[5];

  p->eta_k_1[0] = eta_k[0];
  p->eta_k_1[1] = eta_k[1];
  p->eta_k_1[2] = eta_k[2];
  p->eta_k_1[3] = eta_k[3];
  p->eta_k_1[4] = eta_k[4];
  p->eta_k_1[5] = eta_k[5];

  p->i2ref_k_2 = p->i2ref_k_1;
  p->i2ref_k_1 = p->i2ref_k;

  p->i2m_k_2 = p->i2m_k_1;
  p->i2m_k_1 = p->i2m_k;

  p->v_k_2 = p->v_k_1;
  p->v_k_1 = v_k;

  p->u_k_2 = p->u_k_1;
  p->u_k_1 = u_k;

  return;
}

//*************************************************************************
//NÃO REMOVER - necessário para o funcionamento da dll
BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
//NÃO REMOVER - necessário para o funcionamento da dll
//*************************************************************************
