%% Declarações Iniciais
clear all

Ts=1/12000;
Ts1=Ts/10;
VCC=400;
Vg=311;
z=tf('z', Ts);
s=tf('s');

%Preferências de simulação
incerteza_parametrica=1; %inclui erros percentuais nos valores dos elementos do filtro
incerteza_parametrica_max=8; %valor de 1 a 10 representando porcentagens de 10% a 100% para o máximo do erro paramétrico
excitacao_persistente=0; %torna a referência do tipo excitação persistente
excitacao_persistente_rng=1; %torna as amplitudes das harmônicas da excitação persistente aleatórias

%Referência
ref_amp=10; %amplitude da referência
ref_freq=2*pi*60; %frequência da referência
if excitacao_persistente_rng
    amp_rng=randi(5,6,1)/10;
    ref_amp3=amp_rng(1)*ref_amp;
    ref_amp5=amp_rng(2)*ref_amp;
    ref_amp7=amp_rng(3)*ref_amp;
    ref_amp9=amp_rng(4)*ref_amp;
    ref_amp11=amp_rng(5)*ref_amp;
    ref_amp13=amp_rng(6)*ref_amp;
else
    ref_amp3=ref_amp/2;
    ref_amp5=ref_amp/2;
    ref_amp7=ref_amp/2;
    ref_amp9=ref_amp/2;
    ref_amp11=ref_amp/2;
    ref_amp13=ref_amp/2;
end

%Timers
ref_phaseInv_time=20000/60; %inversão de fase da ref.
ref_step_time=20000/60; %degrau na ref.
param_change_time=20000/60; %variação paramétrica
init_time=20000/60; %tempo de saída do resistor de partida

%Outros
rede_amp=311;
short_ON_time=20000/60; %instante de início do curto
short_OFF_time=20001/60; %instante de término do curto
R_init=10; %valor do resistor de partida

%% VALORES DOS ELEMENTOS

%Definição dos valores projetados dos elementos do filtro
L1ideal=2e-3;
L2ideal=2e-3;
Lgideal=0;
Cideal=40e-6;
R1ideal=0;
R2ideal=0;
Rgideal=0;

%Definição de erros percentuais para simular variação paramétrica
if incerteza_parametrica
    err_rng=randi(incerteza_parametrica_max,7,1)/10;
    errL1=err_rng(1);
    errL2=err_rng(2);
    errLg=err_rng(3);
    errC=err_rng(4);
    errR1=err_rng(5);
    errR2=err_rng(6);
    errRg=err_rng(7);
else
    errL1=0;
    errL2=0;
    errLg=0;
    errC=0;
    errR1=0;
    errR2=0;
    errRg=0;
end
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

Kp=0.004780841242217;

