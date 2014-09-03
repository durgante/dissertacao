%clear all
%close all
%clc

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

%% MALHA FECHADA COM CONTROLADOR "PD" (controle de vC)
CPD=3*(z-0.9)/z;
G_u_vC=minreal(CPD*G1d/(1+CPD*G1d));
G_u_vC_i2=minreal(G_u_vC*G_vC_i2,0.01);

%G_u_iC_i2 É A PLANTA FINAL DE UP PARA I2 USANDO IC
%G_u_vC_i2 É A PLANTA FINAL DE UP PARA I2 USANDO VC
%Faça n=4 e m=1 com kp igual ao kp_novo = kp*3.69.

%Go_iC=(z + 0.270665436545005)/(z^4 -2.828886133187644*z^3 +3.152657784036528*z^2 -1.647543301697770*z +0.323771650848891);
Go=(Ts/(L1+L2))/(z*(z-1));

%dnm_iC=minreal(G_u_iC_i2 - Go,0.01);
%dnm_vC=minreal(G_u_vC_i2 - Go,0.01);
% figure
% bode(G_u_iC_i2,'b')
% hold
% bode(Go,'g')
% bode(dnm_iC,'r')
% hold
% figure
% bode(G_u_vC_i2,'b')
% hold
% bode(Go,'g')
% bode(dnm_vC,'r')
% hold
 Go_iC=8.007556285067009*Go;
 %ganho de Go_iC = 0.166824089272229 (para usar no adaptativo)
 Go_vC=0.257632115700258*Go;
% %ganho de Go_vC = 0.005367335743755 (para usar no adaptativo)
 dnm_iC=minreal(G_u_iC_i2 - Go_iC,0.01);
 dnm_vC=minreal(G_u_vC_i2 - Go_vC,0.01);
% figure
% bode(G_u_iC_i2,'b')
% hold
% bode(Go_iC,'g')
% bode(dnm_iC,'r')
% hold
% figure
% bode(G_u_vC_i2,'b')
% hold
% bode(Go_vC,'g')
% bode(dnm_vC,'r')
% hold
% figure
% pzmap(minreal(dnm_iC))
% figure
% pzmap(minreal(dnm_vC))
%[N,D]=tfdata(minreal(G_u_vC_i2,0.01),'v');
%udeltaA=(N(3)*(z-1)^2)/(D(1)*z^4 + D(2)*z^3 + D(3)*z^2 + D(4)*z + D(5));
%Go=minreal(G_u_vC_i2,0.01)-minreal(udeltaA,0.01);
%udeltaM=(minreal(G_u_vC_i2,0.01)-minreal(Go,0.01))/minreal(Go,0.01);

%pzmaps e bodes
%figure
%pzmap(minreal(G_u_vC_i2,0.01))
%title('pzmap de G(z)');
%figure
%pzmap(minreal(Go,0.01))
%title('pzmap de Go(z)');
%figure
%pzmap(minreal(udeltaA,0.01))
%title('pzmap da dinâmica não modelada aditiva');
%figure
%pzmap(minreal(udeltaM,0.01))
%title('pzmap da dinâmica não modelada multiplicativa');

%figure
%bode(minreal(G_u_vC_i2,0.01), 'b');
%hold
%bode(minreal(Go,0.01), 'g');
%bode(minreal(udeltaA,0.01), 'm');
%bode(minreal(udeltaM,0.01), 'r');
%hold