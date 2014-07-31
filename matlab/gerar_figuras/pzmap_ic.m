%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;

ZC_L2=Z0*Zg/(Z0+Zg);

% Vc/U
G1=minreal(ZC_L2/(Zi+ZC_L2));
% Ic/U
G2=minreal(G1/Z0);
% I2/U
G=minreal(G1/Zg);

% Discretizando usando ZOH pois são relacionadas a entrada U
% (fazendo R1=R2=Rg = 0ohms)
Delay=1/z;
Ki1=(L2+Lg)/(L1+L2+Lg);
wn=sqrt( (L1+L2+Lg)/L1/C/(L2+Lg) );
Ki1d=2*Ki1*sin(wn*Ts/2)^2;
Ki2=1/L1;
Ki2d=sin(wn*Ts)/wn/L1;

G1d=Ki1d*(z+1)/(z^2-2*z*cos(wn*Ts)+1)*Delay; % igual a "G1d=c2d(G1,Ts)/z"
G2d=Ki2d*(z-1)/(z^2-2*z*cos(wn*Ts)+1)*Delay; % igual a "G2d=c2d(G2,Ts)/z"
Gd=( Ts/(L1+L2+Lg)/(z-1) - ...
    sin(wn*Ts)/wn/(L1+L2+Lg)*(z-1)/(z^2-2*z*cos(wn*Ts)+1) )*Delay; % que é igual a "Gd=c2d(G,Ts)/z"

% Ginner_iC_i2
G_iC_i2 = minreal(Gd/G2d);
% Ginner_vC_i2
G_vC_i2 = minreal(Gd/G1d);

% MALHA FECHADA COM CONTROLADOR "P" (controle de iC)
KP=8;
G_u_iC=minreal(KP*G2d/(1+KP*G2d));
G_u_iC_i2=minreal(G_u_iC*G_iC_i2);

% MALHA FECHADA COM CONTROLADOR "PD" (controle de vC)
CPD=3*(z-0.9)/z;
G_u_vC=minreal(CPD*G1d/(1+CPD*G1d));
G_u_vC_i2=minreal(G_u_vC*G_vC_i2,0.01);

[P, Z] = pzmap(G_u_iC_i2);


%% Desenha o grid

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor=define_cor(colorido, 3);

close all
figure
hold on

zeta = 0:.1:.9;
wn = 0:pi/10:pi;

%Desenha o círculo de raio unitário (removi porque está sobrepondo outro
% círculo desenhado pelos outros comandos do grid
%t = 0:.1:6.3;
%plot(sin(t), cos(t), 'LineWidth', 1, ...
%                     'LineStyle', ':', ...
%                     'Color', cor(1, 1:3));

m = tan(asin(zeta));
zz = exp((0:pi/20:pi)'*(-m + sqrt(-1)*ones(1,length(m))));
plot(real(zz), imag(zz), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor(1, 1:3));
plot(real(zz),-imag(zz), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor(1, 1:3));
                     
e_itheta = exp(sqrt(-1)*(pi/2:pi/20:pi)');
e_r = exp(wn);
zw = (ones(length(e_itheta), 1)*e_r).^(e_itheta*ones(1,length(e_r)));

plot(real(zw), imag(zw), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor(1, 1:3));
plot(real(zw),-imag(zw), 'LineWidth', 1, ...
                         'LineStyle', ':', ...
                         'Color', cor(1, 1:3));

%% Plot

%Desenha os pólos
plot(real(P), imag(P), 'LineWidth', 1.5, ...
                       'LineStyle', 'x', ...
                       'MarkerSize', 10, ...
                       'Color', cor(2, 1:3));
                     
%Desenha os zeros
plot(real(Z), imag(Z), 'LineWidth', 1.5, ...
                       'LineStyle', 'o', ...
                       'MarkerSize', 8, ...
                       'Color', cor(3, 1:3));

%Escolha dos pontos marcados nos eixos
set(gca, 'XTick', [-4 -3 -2 -1 0 1]);
set(gca, 'YTick', [-1 0 1]);
%set(gca, 'XTickLabel', []);
                     
%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [-4 1.2]);
set(gca, 'YLim', [-1.4 1.4]);

%Box
box on

%Labels
ylabel('Eixo Imaginário');
xlabel('Eixo Real');
title('');

%% Define dimensões do gráfico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure

    %Exporta
    matlab2tikz('./pzmap_ic.tex', 'width', '0.8\textwidth', ...
            'interpretTickLabelAsTex', true, 'encoding', 'UTF-8');
end