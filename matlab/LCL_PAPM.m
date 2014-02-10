%% LCL em P=PA*PM

s=tf('s');
L1=2e-3;
L2=L1;
Lg=0e-3;
C=40e-6;
Ts=1/12000;
z=tf('z',Ts);
r1=0;
r2=0;
rg=0;

ZL1=s*L1+r1;
ZL2=s*(L2+Lg)+r2+rg;
ZC=1/s/C;
ZC_L2=ZC*ZL2/(ZC+ZL2);

% Vc/U
G1=minreal(ZC_L2/(ZL1+ZC_L2));
% Ic/U
G2=minreal(G1/ZC);
% I2/U
G=minreal(G1/ZL2);

%% Discretizando usando ZOH pois são relacionadas a entrada U (fazendo r1=r2=rg = 0ohms)
Delay=1/z;
Ki1=(L2+Lg)/(L1+L2+Lg);
wn=sqrt( (L1+L2+Lg)/L1/C/(L2+Lg) );
Ki1d=2*Ki1*sin(wn*Ts/2)^2;
Ki2=1/L1;
Ki2d=sin(wn*Ts)/wn/L1;

G1d=Ki1d*(z+1)/(z^2-2*z*cos(wn*Ts)+1)*Delay; % igual a "G1d=c2d(G1,Ts)/z"
G2d=Ki2d*(z-1)/(z^2-2*z*cos(wn*Ts)+1)*Delay; % igual a "G2d=c2d(G2,Ts)/z"
Gd=( Ts/(L1+L2+Lg)/(z-1) - sin(wn*Ts)/wn/(L1+L2+Lg)*(z-1)/(z^2-2*z*cos(wn*Ts)+1) )*Delay; % que é igual a "Gd=c2d(G,Ts)/z"

% Ginner_iC_i2
G_iC_i2 = minreal(Gd/G2d);
% Ginner_vC_i2
G_vC_i2 = minreal(Gd/G1d);

%% MALHA FECHADA COM CONTROLADOR "P" (controle de iC)
KP=8;
G_u_iC=minreal(KP*G2d/(1+KP*G2d));
G_u_iC_i2=minreal(G_u_iC*G_iC_i2);

%% PA*PM via produto de Blashcke

N=2;
zero=-3.69;
PA= minreal(z^(-N)*((1-(zero^(-1)))*(z-zero))/((1-zero)*(z-(zero^(-1)))),0.01);
PM=minreal(G_u_iC_i2/PA,0.01);

pzmap(PA, 'b');
hold
pzmap(PM, 'm');
