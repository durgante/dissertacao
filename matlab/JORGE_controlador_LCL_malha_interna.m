 %% Controlador robusto - figuas boas - Modelagem do conversor
clear all, close all, clc, format long

% Dados de potência do conversor usado na bancada
P     = 5e5;
Vfase = 220;
Inom  = P/Vfase;
w     = 2*pi*60;           
Zbase = Vfase/Inom;
Lbase = Zbase/w;
Cbase = 1/(w*Zbase);
vcc   = 400; % pelo menos...
icc   = vcc/P;

% Discretização
fs    = 12000;
Ts    = 1/fs;
s     = tf('s'); 
z     = tf('z',Ts);
f_sw  = 12000;          % Freqüência de comutação
Tsw   = 1/f_sw;        % Período de comutação
w_sw  = 2*pi*f_sw;     %

format long e
cos_w_Ts = cos(w*Ts);                   %
sin_w_Ts = sin(w*Ts);                   %
Ts;                                     %
dois_pi_f = w/fs;                       % 2*pi/334
cos_w_Ts2 = cos_w_Ts^2;                 %
sin_w_Ts2 = sin_w_Ts^2;                 %
cos_sin_w_Ts = cos_w_Ts*sin_w_Ts;       %
cos_2_sin_w_Ts = 2*cos_w_Ts*sin_w_Ts;   %

format long

% Parâmetros do filtro
Lc   = 1e-3;         % Indutância do lado do conversor
rc   = 0.01;          % Resistência série do indutor do conversor
C    = 40e-6;        % Capacitor do filtro LCL
Lg_1 = 0.5e-3;       % Indutância mínima da rede
rg_1 = 0.01;          % Resistência série do indutor do lado da rede

% Será considerada uma indutância mínima da rede de 0 e máxima de 1mH.
Lg_2_min = 0.e-3;   % Indutância mínima da rede
Lg_2_max = 25e-3;   % Indutância máxima da rede
rg_2 = 0.;          % Resistência equivalente série da rede

Lg_min = Lg_1+Lg_2_min;       % Indutância TOTAL da rede
Lg_max = Lg_1+Lg_2_max;       % Indutância TOTAL da rede
rg = rg_1+rg_2;

Lc_pu  = Lc/Lbase;      
C_pu   = C/Cbase;       
Lg1_pu = Lg_1/Lbase;
Lg2_min_pu = Lg_2_min/Lbase;
Lg2_max_pu = Lg_2_max/Lbase;
Lg_min_pu  = Lg_min/Lbase;
Lg_max_pu  = Lg_max/Lbase;

% Valores intermediários
Lt_min    = Lc+Lg_min;          % Soma das indutâncias do conversor e da rede
Lt_max    = Lc+Lg_max;          % Soma das indutâncias do conversor e da rede
z_LC_max  = sqrt(1/(Lg_min*C)); % Impedância infinita para a corrente no conversr
z_LC_min  = sqrt(1/(Lg_max*C)); % Impedância infinita para a corrente no conversr
w_res_max = sqrt(Lt_min*z_LC_max^2/Lc);     % Frequencia de ressonância
w_res_min = sqrt(Lt_max*z_LC_min^2/Lc);     % Frequencia de ressonância

com_01 = char(sprintf('Potência nominal                   = %10.3d VA',P));
com_02 = char(sprintf('Tensão nominal de fase (rms)       = %10.3g V',Vfase));
com_03 = char(sprintf('Corrente nominal (rms)             = %10.3g A',Inom));
com_04 = char(sprintf('Indutor do lado do conversor       = %10.3g %%',Lc_pu*100));
com_05 = char(sprintf('Capacitor de filtro                = %10.3g %%',C_pu*100));
com_06 = char(sprintf('Indutor do lado da rede            = %10.3g %%',Lg1_pu*100));
com_07 = char(sprintf('Indutância da rede  min.           = %10.3g %%',Lg2_min_pu*100));
com_08 = char(sprintf('Indutância da rede  min.           = %10.3g %%',Lg2_max_pu*100));
com_09 = char(sprintf('Indutor min. TOTAL do lado da rede = %10.3g %%',Lg_min_pu*100));
com_10 = char(sprintf('Indutor max. TOTAL do lado da rede = %10.3g %%',Lg_max_pu*100));
com_11 = char(sprintf('Freqüência de corte do filto max.  = %10.3g Hz',w_res_max/(2*pi)));
com_12 = char(sprintf('Freqüência de corte do filto min.  = %10.3g Hz',w_res_min/(2*pi)));
p1 = char(sprintf('Especificação = \n \n %s \n %s \n %s \n\n %s \n %s \n %s \n\n %s \n %s \n %s \n %s \n\n %s \n %s',com_01,com_02,com_03,com_04,com_05,com_06,com_07,com_08,com_09,com_10,com_11,com_12));
sprintf(' %s \n %s',p1)

%% Função de transferência
%Gs_conv1       = (s^2*Lg_min*C+s*rg*C+1)/(s^3*Lg_min*Lc*C+s^2*C*(rg*Lc+rc*Lg_min)+s*(Lc+Lg_min+rg*rc*C)+(rg+rc));
Gs_grid1       = 1/(s^3*Lg_min*Lc*C+s^2*C*(rg*Lc+rc*Lg_min)+s*(Lc+Lg_min+rg*rc*C)+(rg+rc));
Gs_grid2       = 1/(s^3*Lg_max*Lc*C+s^2*C*(rg*Lc+rc*Lg_max)+s*(Lc+Lg_max+rg*rc*C)+(rg+rc));
Gz_grid1       = c2d(Gs_grid1,Ts);
Gz_grid2       = c2d(Gs_grid2,Ts);
Gz_grid1_delay = Gz_grid1/z;
Gz_grid2_delay = Gz_grid2/z;

figure,rlocus(Gs_grid1),hold on,rlocus(Gs_grid2),grid,title('Lugar das raízes (corrente da rede) - planta contínua') 
figure,rlocus(Gz_grid1_delay),hold on,rlocus(Gz_grid2_delay), axis([-4.5 1.5 -1.5 1.5]), grid,title('Lugar das raízes (corrente da rede) - planta discreta com delay') 

figure,pzmap(Gz_grid1_delay),xlim([-4 1]),axis equal
figure,pzmap(Gz_grid2_delay),xlim([-4 1]),axis equal

%% Espaço de estados
Ap_1 = [-rc/Lc -1/Lc 0; 1/C 0 -1/C; 0 1/Lg_min -rg/Lg_min];
Ap_2 = [-rc/Lc -1/Lc 0; 1/C 0 -1/C; 0 1/Lg_max -rg/Lg_max];
Bp   = [1/Lc; 0; 0]; 
Fp_1 = [0; 0; -1/Lg_min]; 
Fp_2 = [0; 0; -1/Lg_max]; 
Cp_g = [0 0 1];  
Dp   = 0;

% Discretização (corrente da rede)
[Ad_1,Bd_1,Cd_g,Dd]   = ssdata(c2d(ss(Ap_1,Bp,Cp_g,Dp),Ts));
[Ad_2,Bd_2,Cd_g,Dd]   = ssdata(c2d(ss(Ap_2,Bp,Cp_g,Dp),Ts));
[Ad_1,Fd_1,Cd_g,Dd] = ssdata(c2d(ss(Ap_1,Fp_1,Cp_g,Dp),Ts));
[Ad_2,Fd_2,Cd_g,Dd] = ssdata(c2d(ss(Ap_2,Fp_2,Cp_g,Dp),Ts));

figure, hold on
h = bodeplot(Gs_grid1);
h = bodeplot(ss(Ap_1,Bp,Cp_g,Dp));
%h = bodeplot(Gz_grid1);
h = bodeplot(ss(Ad_1,Bd_1,Cd_g,Dd,Ts));

h = bodeplot(Gs_grid2);
h = bodeplot(ss(Ap_2,Bp,Cp_g,Dp));
%h = bodeplot(Gz_grid2);
h = bodeplot(ss(Ad_2,Bd_2,Cd_g,Dd,Ts));

grid, setoptions(h,'FreqUnits','Hz')

close all

%% CORRENTE DA REDE => Inclusão do atraso de transporte em espaço de estados
Gd_1     = [Ad_1 Bd_1; 0 0 0 0];
Gd_2     = [Ad_2 Bd_2; 0 0 0 0];
Hd       = [0; 0; 0; 1];
Hd_dist1 = [Fd_1; 0];
Hd_dist2 = [Fd_2; 0];
Cd_grid  = [Cd_g 0];
Dd       = 0;

% Grau relativo 2
Gz_grid1 = tf(ss(Gd_1,Hd,Cd_grid,Dd,Ts));   
Gz_grid2 = tf(ss(Gd_2,Hd,Cd_grid,Dd,Ts));  

figure, pzmap(Gz_grid1),axis equal
figure, pzmap(Gz_grid2),axis equal

figure, hold on
h = bodeplot(Gs_grid1); 
h = bodeplot(Gz_grid1); 
h = bodeplot(Gs_grid2); 
h = bodeplot(Gz_grid2); 
grid, setoptions(h,'FreqUnits','Hz')


%% Realimentação da tensão ou corrente do capacitor (escolher um desses dois vetores)
%Ki = [0  1  0  0]; % Tensão do capacitor
Ki = [1  0 -1  0]; % Corrente do capacitor

%% Controlador P
Dc = 6;   % Ganho proporcional KP

A_til_1 = [Gd_1-Hd*Dc*Ki];
A_til_2 = [Gd_2-Hd*Dc*Ki];
B_til = [Hd*Dc];

Bdist1_til = [Hd_dist1];
Bdist2_til = [Hd_dist2];

C_til = [Cd_grid];

MF_1 = ss(A_til_1, B_til, C_til, 0, Ts );
MF_2 = ss(A_til_2, B_til, C_til, 0, Ts );

MFdist_1 = ss(A_til_1, Bdist1_til, C_til, 0, Ts );
MFdist_2 = ss(A_til_2, Bdist2_til, C_til, 0, Ts );

figure, hold on
h = bodeplot(MF_1); 
h = bodeplot(MF_2); 
h = bodeplot(Gz_grid1); 
grid, setoptions(h,'FreqUnits','Hz')

figure,pzmap(minreal(MF_1)),xlim([-1 1]),axis equal
figure,pzmap(minreal(MF_2)),xlim([-1 1]),axis equal

% figure, hold on
% h = bodeplot(MFdist_1); 
% h = bodeplot(MFdist_2); 
% grid, setoptions(h,'FreqUnits','Hz')


%% Controlador PD
KP = 0.1;
KD = 5;

G_PD = (KP+KD)*(z-KD/(KP+KD))/z;
[Ac,Bc,Cc,Dc] = ssdata(G_PD);   %Obtenção das matrizes

A_til_1 = [Gd_1-Hd*Dc*Ki Hd*Cc;
           -Bc*Ki  Ac];
A_til_2 = [Gd_2-Hd*Dc*Ki Hd*Cc;
           -Bc*Ki  Ac];
B_til = [Hd*Dc;Bc];

Bdist1_til = [Hd_dist1; 0];
Bdist2_til = [Hd_dist2; 0];

C_til = [Cd_grid 0];

MF_1 = ss(A_til_1, B_til, C_til, 0, Ts );
MF_2 = ss(A_til_2, B_til, C_til, 0, Ts );

MFdist_1 = ss(A_til_1, Bdist1_til, C_til, 0, Ts );
MFdist_2 = ss(A_til_2, Bdist2_til, C_til, 0, Ts );

figure, hold on
h = bodeplot(MF_1); 
h = bodeplot(MF_2); 
grid, setoptions(h,'FreqUnits','Hz')

figure,pzmap(minreal(MF_1))%,xlim([-1 1]),axis equal
figure,pzmap(minreal(MF_2))%,xlim([-1 1]),axis equal

% figure, hold on
% h = bodeplot(MFdist_1); 
% h = bodeplot(MFdist_2); 
% grid, setoptions(h,'FreqUnits','Hz')

%% LSIM (simulação no tempo, nao garante tracking, apenas damping)
t = 0:Ts:0.417; 
%r(i) = sin(2*pi*60*t(i));
for i=1:length(t)
    if (i<2*80)
        r(i) = 0; 
    end
    if (i>=2*80 && i<4.75*80)
        r(i) = 0.5*sin(2*pi*60*t(i));
    end
    if (i>=4.75*80 && i<9*80)
        r(i) = -0.5*sin(2*pi*60*t(i));
    end
    if (i>=9*80 && i<13*80)
        r(i) = 0.5*cos(2*pi*60*t(i));
    end
    if (i>=13*80)
        r(i) = cos(2*pi*60*t(i));
    end
end

disturbio = sin(2*pi*60*t);   

figure, hold on
lsim(MF_1,r,t)
lsim(MF_2,r,t),grid

figure, hold on
lsim(MFdist_1,disturbio,t)
lsim(MFdist_2,disturbio,t)

% abs(eig(A_til_1 + B_til*K_res))
% abs(eig(A_til_2 + B_til*K_res))

max(abs(eig(A_til_1)))
max(abs(eig(A_til_2)))

