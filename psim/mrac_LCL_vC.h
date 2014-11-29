//Definição das constantes
#define	f_hz       60
#define f_rad      376.99111843     // 2*pi*60
#define Ts         0.00008333       // 12kHz
#define gama       0.99
#define gamaD      0.0098
#define delta0     0.99
#define kp_kd      3                // ganho do controlador da malha int.
#define Kp         0.0017928154     // multiplicação dos ganhos int. e ext.
#define p1         0.2              // polos do modelo de referência
#define p2         0.2
#define km         0.64             // ganho do modelo de referência
#define TxPR       128              // amplitude da triangular do PWM

//Definição dos valores iniciais dos thetas
#define theta1     0.3258
#define theta2    -2.9077
#define theta3    -0.2815
#define theta4     13.1402
#define theta5     0
#define theta6     0

//*************************************************************************
//Definição do struct que será o conjunto de variáveis

typedef struct
{
  double theta_k[6];      //var no instante k
  double omega_k[6];
  double omega_k_1[6];    //var no instante k-1
  double omega_k_2[6];    //var no instante k-2
  double eta_k_1[6];
  double eta_k_2[6];
  double i2m_k;
  double i2m_k_1;
  double i2m_k_2;
  double i2ref_k;
  double i2ref_k_1;
  double i2ref_k_2;
  double vC_k;
  double vC_k_1;
  double v_k_1;
  double v_k_2;
  double rho_k;
  double m2;
  double up;
  double u_k_1;
  double u_k_2;
} filtro;

//*************************************************************************
//NÃO REMOVER - necessário para o funcionamento da dll
#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

//DLLIMPORT void simuser (t, delt, in, out);

#endif /* _DLL_H_ */
//NÃO REMOVER - necessário para o funcionamento da dll
//*************************************************************************
