%% Definições Iniciais

Ts=0.5;
s=tf('s');
z=tf('z', Ts);

% Planta Contínua
P_s = (-s+1)/(s^2+3*s+2) + 0.01/(s+3);
[PN,PD]=tfdata(P_s,'v');

% Planta Discreta
P_z = c2d(P_s, Ts);
%[PN,PD] = tfdata(P_z,'v');