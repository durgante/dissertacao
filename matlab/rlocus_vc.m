%% Dados para plotar

Ts=1/12000;
s=tf('s');

%Definição dos valores projetados dos elementos do filtro
L1ideal=2e-3;
L2ideal=2e-3;
Lgideal=0;
Cideal=40e-6;
R1ideal=0;
R2ideal=0;
Rgideal=0;
Rdideal=0;

%Definição de erros percentuais para simular variação paramétrica
errL1=0;
errL2=0;
errLg=0;
errC=0;
errR1=0;
errR2=0;
errRg=0;
errRd=0;
deltaL1=errL1*L1ideal;
deltaL2=errL2*L2ideal;
deltaLg=errLg*Lgideal;
deltaC=errC*Cideal;
deltaR1=errR1*R1ideal;
deltaR2=errR2*R2ideal;
deltaRg=errRg*Rgideal;
deltaRd=errRd*Rdideal;

%Definição do valor real medido, incluindo a variação paramétrica
%percentual
L1=L1ideal+deltaL1;
L2=L2ideal+deltaL2;
Lg=Lgideal+deltaLg;
C=Cideal+deltaC;
R1=R1ideal+deltaR1;
R2=R2ideal+deltaR2;
Rg=Rgideal+deltaRg;
Rd=Rdideal+deltaRd;


Vdc = 20;

a0= (R1 + R2)/(C*L1*L2);
a1= 1/(L1*L2)*(R1*R2+(L1+L2)/C);
a2= R1/L1 + R2/L2;

den= (s^3+a2*s^2+a1*s+a0);

vc= ((2*Vdc/(L1*C))*(s+R2/L2))/den;
ic= ((2*Vdc/(L1)*s)*(s+R2/L2))/den;

rlocus(vc);
