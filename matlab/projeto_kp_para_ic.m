%% Definições Básicas
Ts=1/12000;
z=tf('z',Ts);

L1=0.98e-3;
%L1=0.5e-3;
L2=0.54e-3;
C=40e-6;
%C=80e-6;

Lg=0:1e-4:100*5e-3;
w=sqrt((L1+L2+Lg)./(L1.*(L2+Lg).*C));

%kp tem que ser menor que a linha azul e maior que a linha vermelha
f1=((2.*cos(w.*Ts)-1).*w.*L1)./(sin(w.*Ts));
f2=((cos(w.*Ts)-1).*w.*L1)./(sin(w.*Ts));

close all
%Análise do ganho kp máximo que pode ser usado (é o ganho em Lg=0)
plot(Lg,f1,'b', Lg, f2, 'r')
title('Ganho kp em função da indutância variável da rede Lg')
xlabel('Lg')
ylabel('kp')

%% Definição dos parâmetros
Lg=0;
w=sqrt((L1+L2+Lg)/(L1*(L2+Lg)*C));
ki=sin(w*Ts)/(w*L1);
a=2*cos(w*Ts);
%kp=5.23;
kp=3.35;
%kp=1.91;

%% Planta discreta em malha aberta (análise de root locus)
N_z_ma= ki*(z-1);
D_z_ma= z*(z^2-a*z+1);

P_z_ma= N_z_ma/D_z_ma;
figure
rlocus(P_z_ma);


%% Planta discreta em malha fechada
N_z_mf= ki*kp*(z-1);
D_z_mf= z^3-a*z^2+(ki*kp+1)*z-ki*kp;

P_z_mf= N_z_mf/D_z_mf;
figure
pzmap(P_z_mf);

K1= Ts/(L1+L2+Lg);
Gd= K1/(z*(z-1)) - (K1*sin(w*Ts)/(w*Ts))*((z-1)/D_z_ma);

God= Gd/P_z_ma;

G=P_z_mf*God;

figure
bode(G);
%hold on

% 20log(k)= diferença entre os ganhos no diagrama de bode, ou seja k=
% 10^(dif/20)
%k=5.29;
k=3.338;
%k=1.8557;
Go= k*Ts/((L1+L2)*z*(z-1));
figure
pzmap(G);
figure
bode(G);
hold on
bode(Go);
delta=G-Go;
delta=minreal(delta, 0.01);
%figure
%pzmap(delta)

%bode(Go);