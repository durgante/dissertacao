%% Declarações Iniciais
clear all

Ts=1/12000;
Ts1=Ts/10;
%VCC=1200;
VCC=1200;
Vg=311;
z=tf('z', Ts);
s=tf('s');

Vg_teste=0;

%Referência
excitacao_persistente=1;
ref_phaseInv_time=600000/60;
ref_step_time=600000/60;

%Chaveamentos na potência
param_change_time=600000/60;
init_time=600000/60;

%Outros
flag_time=0/60;
short_ON_time=600000/60;
short_OFF_time=600001/60;
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
%ki=L2/(L1+L2);
%Kid=2*ki*sin(w*Ts/2)^2;
%N_P2_z=Kid*(z+1);
%D_P2_z=z*(z^2-2*z*cos(w*Ts)+1);
%P2_z=N_P2_z/D_P2_z;
%[P2N,P2D]=tfdata(P2_z,'v');

%Controlador
%kp_kd=3; %ganho projetado
%N_C2_z=kp_kd*(z-1);
%D_C2_z=z;
%C2_z=N_C2_z/D_C2_z;
%[C2N,C2D]=tfdata(C2_z,'v');

%Malha fechada (apenas para fins de teste)
%G2_mf_z=(C2_z*(1/z)*P2_z)/(1+C2_z*(1/z)*P2_z);

%% Malha Externa

%Planta
%ko=1/L2;
%Kod=Ts*ko;
%N_P1_z=Kod*z;
%D_P1_z=(z-1);
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

%Controlador Repetitivo
%kr_rp=0.01;
%N_rp=200;
%d_rp=3;
%Q_rp=0.99;
%alpha_rp=0.1;
%beta_rp=0.8;

Kp=0.001792815465831;

