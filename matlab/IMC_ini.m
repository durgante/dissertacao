%% Definições Iniciais

Ts=1/12000;
s=tf('s');
z=tf('z', Ts);

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
[PN,PD]=tfdata(P_s,'v');

K1=Ts/(L1+L2);
wn= sqrt((L1+L2)/(L1*C*L2));
P_z = (K1/(z*(z-1)))-((K1*sin(wn*Ts))/(wn*Ts))*((z-1)/(z*(z^2-2*cos(wn*Ts)*z+1)));
%P_z = c2d(P_s, Ts);
%[PN,PD]=tfdata(P_z,'v');

% Referência
%R_s=1/s;

%% Discretização

% Planta
%P_z = c2d(P_s, Ts);
%uDeltaA_z = c2d(uDeltaA_s, Ts);
%[PNz,PDz]=tfdata(P_z,'v');

% Referência
%R_z= c2d(R_s, Ts);
%R_z=z/(z-1);