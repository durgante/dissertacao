%% Definições Iniciais

Ts=1/12000;
s=tf('s');
z=tf('z', Ts);

%Definição dos lambdas (apenas para calculo dos limites dos thetas)
lambda0=-0.001;
lambda1= 0.03;
lambda2=-0.3;
%lambda3=-2;

%Definição dos valores projetados dos elementos do filtro
L1ideal=2e-3;
L2ideal=2e-3;
Lgideal=0;
Cideal=40e-6;
R1ideal=1;
R2ideal=1;
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

%Definição das impedâncias
Zi= R1 + L1*s;
Zc= 1/(s*C);
Zg= R2 + L2*s;

% Planta
P_s = Zc/(Zi*(Zc+Zg)+Zc*Zg);
%[PN,PD]=tfdata(P_s,'v');

K1=Ts/(L1+L2);
wn= sqrt((L1+L2)/(L1*C*L2));
%P_z = (K1/(z*(z-1)))-((K1*sin(wn*Ts))/(wn*Ts))*((z-1)/(z*(z^2-2*cos(wn*Ts)*z+1)));
P_z = c2d(P_s, Ts);
[PN,PD]=tfdata(P_z,'v');

%% Limites

min= 0.85;
max= 1.15;

theta1_estrela = lambda2-PD(2);
theta1_min = theta1_estrela*min;
theta1_max = theta1_estrela*max;

theta2_estrela = lambda1-PD(3);
theta2_min = theta2_estrela*min;
theta2_max = theta2_estrela*max;

theta3_estrela = lambda0-PD(4);
theta3_min = theta3_estrela*min;
theta3_max = theta3_estrela*max;

%theta4_estrela = lambda0-PD(5);
%theta4_min = theta4_estrela*min;
%theta4_max = theta4_estrela*max;

theta4_estrela = PN(2);
theta4_min = theta4_estrela*min;
theta4_max = theta4_estrela*max;

theta5_estrela = PN(3);
theta5_min = theta5_estrela*min;
theta5_max = theta5_estrela*max;

theta6_estrela = PN(4);
theta6_min = theta6_estrela*min;
theta6_max = theta6_estrela*max;

%theta7_estrela = PN(5);
%theta7_min = theta7_estrela*min;
%theta7_max = theta7_estrela*max;

theta_estrela= [theta1_estrela; theta2_estrela; theta3_estrela; theta4_estrela; theta5_estrela; theta6_estrela];


%% Expressão para P estimado - grau relativo 1

P_e_N = theta_estrela(4)*z^2 + theta_estrela(5)*z + theta_estrela(6);
P_e_D = z^3 + (lambda2-theta_estrela(1))*z^2 + (lambda1-theta_estrela(2))*z + (lambda0-theta_estrela(3));
P_e = P_e_N/P_e_D;

%% Expressão para Q - grau relativo 1

delta= sqrt(theta_estrela(5)^2 - 4*theta_estrela(4)*theta_estrela(6));
z_fnm = (-theta_estrela(5) - delta)/(2*theta_estrela(4));
z_fm = (-theta_estrela(5) + delta)/(2*theta_estrela(4));
phi = 1/z_fnm;
G = (1-phi)/(1-(1/phi));
Q_N = z^3 + (lambda2 - theta_estrela(1))*z^2 + (lambda1 - theta_estrela(2))*z + (lambda0 - theta_estrela(3));
Q_D = z*(z-phi)*(z-z_fm);
%Q_D = z^3*(1-phi)*(1-z_fm);
Q_z = G*(Q_N/Q_D);

%% P Datta
%incerteza = (0.01)/(s+3);
incerteza=0;
P_sd = ((-s+1)/(s^2+3*s+2))+incerteza;
P_zd = c2d(P_sd, 0.5);

%% Expressão para P estimado - Datta
theta_datta = [0.8744; -0.2431; -0.1612; 0.2856];
P_ed_N = theta_datta(3)*z + theta_datta(4);
P_ed_D = z^2 -(0.1+theta_datta(1))*z - (0.02+theta_datta(2));
P_ed = P_ed_N/P_ed_D;

%% Expressão Q - Datta
phid = -theta_datta(3)/theta_datta(4);
Gd = (1-phid)/(theta_datta(3)+theta_datta(4));
Qd_N = z^2 - (0.1+theta_datta(1))*z - (0.02+theta_datta(2));
Qd_D = z*(z-phid);
Qd = Qd_N/Qd_D;




