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


Zi= L1*s + R1;

Zg= (L2 + Lg)*s + R2 + Rg;

Z0= 1/(C*s) + Rd;

L= L1+L2+Lg;

alfa= L1/L;

Gvi_i1= ((1-alfa)*L*C*s^2 + Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

Gvi_i2= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);


bodemag(Gvi_i2);