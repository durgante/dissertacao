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

[P, Z] = pzmap(G_u_vC_i2);

%% Impressão

%Plot colorido? 1=sim 0=não
cor=0;

%Exportar? 1=sim 0=não
exportar=1;

if cor==0
    cor1=[1/3, 1/3, 1/3];
    cor2=[2/3, 2/3, 2/3];
    cor3=[0, 0, 0];
else
  cor1=rand(1, 3);
  cor2=rand(1, 3);
  cor3=rand(1, 3);
end

close all
figure
hold on

%Desenha o grid
zeta = 0:.1:.9;
wn = 0:pi/10:pi;
t = 0:.1:6.3;
plot(sin(t), cos(t), 'LineWidth', 1, ...
                     'LineStyle', ':', ...
                     'Color', cor2);

m = tan(asin(zeta));
zz = exp((0:pi/20:pi)'*(-m + sqrt(-1)*ones(1,length(m))));
plot(real(zz), imag(zz), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor2);
plot(real(zz),-imag(zz), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor2);
                     
e_itheta = exp(sqrt(-1)*(pi/2:pi/20:pi)');
e_r = exp(wn);
zw = (ones(length(e_itheta), 1)*e_r).^(e_itheta*ones(1,length(e_r)));

plot(real(zw), imag(zw), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor2);
plot(real(zw),-imag(zw), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor2);

%Desenha os pólos
plot(real(P), imag(P), 'LineWidth', 1.5, ...
                       'LineStyle', 'x', ...
                       'MarkerSize', 10, ...
                       'Color', cor1);
                     
%Desenha os zeros
plot(real(Z), imag(Z), 'LineWidth', 1.5, ...
                       'LineStyle', 'o', ...
                       'MarkerSize', 8, ...
                       'Color', cor3);

%Escolha dos pontos marcados nos eixos
set(gca, 'XTick', [-4 -3 -2 -1 0 1]);
set(gca, 'YTick', [-1 0 1]);
%set(gca, 'XTickLabel', []);
                     
%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [-4 1.2]);
set(gca, 'YLim', [-1.4 1.4]);

%Labels
ylabel('Eixo Imaginário');
xlabel('Eixo Real');
title('');

%% Ajuste fino do gráfico

%Seta unidades do gráfico para centímetros
set(gcf, 'Units', 'centimeters');

%seta a posição e as dimensões da figura NA TELA
phi=0.5*(1+sqrt(5));

%figuras normais
height=1/phi;
width=1;

%figuras compridas
%height=1/phi;
%width=2;
scale=20;
xpos=2;
ypos=2;
afFigurePosition= [xpos ypos scale*width scale*height]; %[pos_x pos_y width_x width_y]
set(gcf, 'Position', afFigurePosition); % [left bottom width height]

%Vincula a posição na tela com a posição no papel
set(gcf, 'PaperPositionMode', 'auto');

%Impede que os eixos escritos pelo Latex sejam cortados
set(gca, 'Units','normalized',... %
    'Position',[0.15 0.2 0.75 0.7]);


%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure

    %Exporta
    matlab2tikz('./gerar_figuras/pzmap_vc.tex', 'width', '0.8\textwidth', ...
            'interpretTickLabelAsTex', true, 'encoding', 'UTF-8');
end