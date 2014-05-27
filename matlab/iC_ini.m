%% Declarações Iniciais
clear all

Ts=1/12000;
Ts1=Ts/10;
VCC=1700;
Vg=311;
z=tf('z', Ts);
s=tf('s');

%Referência
excitacao_persistente=0;
ref_phaseInv_time=60/60;
ref_step_time=60/60;

%Chaveamentos na potência
param_change_time=60/60;
init_time=60/60;

%Outros
flag_time=60/60;
R_init=10;

%Definição dos valores projetados dos elementos do filtro
L1ideal=2e-3;
L2ideal=2e-3;
Lgideal=0;
Cideal=40e-6;
R1ideal=0;
R2ideal=0;
Rgideal=0;

%Definição de erros percentuais para simular variação paramétrica
errL1=0;
errL2=0;
errLg=0;
errC=0;
errR1=0;
errR2=0;
errRg=0;
deltaL1=errL1*L1ideal;
deltaL2=errL2*L2ideal;
deltaLg=errLg*Lgideal;
deltaC=errC*Cideal;
deltaR1=errR1*R1ideal;
deltaR2=errR2*R2ideal;
deltaRg=errRg*Rgideal;

%Definição do valor real medido, incluindo a variação paramétrica
%percentual
L1=L1ideal+deltaL1;
L2=L2ideal+deltaL2+Lgideal+deltaLg;
C=Cideal+deltaC;
R1=R1ideal+deltaR1;
R2=R2ideal+deltaR2+Rgideal+deltaRg;

%Demais elementos
%w=sqrt((L1+L2)/(L1*L2*C));

%% Malha Interna

%Planta
%ki=sin(w*Ts)/(w*L1);
%N_P2_z=ki*(z-1);
%D_P2_z=(z^2-2*cos(w*Ts)*z+1)*z;
%P2_z=N_P2_z/D_P2_z;
%[P2N,P2D]=tfdata(P2_z,'v');

%Controlador
%kp=8; %ganho projetado
%N_C2_z=kp*z^0;
%D_C2_z=1*z^0;
%C2_z=N_C2_z/D_C2_z;
%[C2N,C2D]=tfdata(C2_z,'v');

%Malha fechada (apenas para fins de teste)
%G2_mf_z=(C2_z*(1/z)*P2_z)/(1+C2_z*(1/z)*P2_z);

%% Malha Externa

%Planta
%ko=Ts^2/(C*L2);
%N_P1_z=ko*z;
%D_P1_z=(z-1)^2;
%P1_z=N_P1_z/D_P1_z;
%[P1N,P1D]=tfdata(P1_z,'v');

%Modelo de Referência
p1=0.2;
p2=0.2;
p3=0.2;
km=(1-p1)*(1-p2);%*(1-p3);
N_MR_z=km;
D_MR_z=(z-p1)*(z-p2);%*(z-p3);
MR_z=N_MR_z/D_MR_z;
[MRN,MRD]=tfdata(MR_z,'v');

%Controlador Ressonante
%kp_res=0.1;
%ki_res=5;
%N_CR_s=ki_res*s;
%D_CR_s=s^2 + (2*pi*60)^2;
%CR_s=kp_res + N_CR_s/D_CR_s;
%[CRN,CRD]=tfdata(CR_s,'v');

Kp=0.004780841242217;

