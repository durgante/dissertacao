%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;
%calculo_FTs;

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

%[P, Z] = pzmap(G_u_iC_i2);
Go=(Ts/(L1+L2))/(z*(z-1));
Go_iC=8.007556285067009*Go;
dnm_iC=minreal(G_u_iC_i2 - Go_iC,0.01);

%% Plot
cor=define_cor(colorido, 3);
opt= bodeoptions;
opt.MagVisible = 'off';
opt.FreqUnits = 'Hz';
%opt.Title = '';
%opt.XLabel = 'Fase (Hz)';
%opt.YLabel = 'Magnitude (dB)';
%Desenha os pólos
fig = figure;
hold on
bodeplot(G_u_iC_i2, opt);

%Escolha dos pontos marcados nos eixos
h= findobj(gcf, 'type', 'line');
set(h, 'LineWidth', 1.5, 'Color', cor(3 ,1:3), 'LineStyle', '-');
bodeplot(Go_iC, opt);
j= findobj(gcf, 'type', 'line');
dif = setdiff(j, h);
set(dif, 'LineWidth', 1.5, 'Color', cor(2, 1:3), 'LineStyle', '--');
bodeplot(dnm_iC, opt);
k= findobj(gcf, 'type', 'line');
dif2= setdiff(k, j);
set(dif2, 'LineWidth', 1.5, 'Color', cor(1, 1:3), 'LineStyle', '-.');

%Box
grid on
box on

%Labels
ylabel('Fase');
xlabel('Frequência');
title('');

%Legenda
%[l_h, o_h, p_h, t_s] = legend('G(z)', 'G_o(z)', '\Delta(z)', 'location', 'NE');

%% Define dimensões do gráfico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure

    %Exporta
    matlab2tikz('./gp_bode_phase_ic.tex', 'width', '0.8\textwidth', ...
            'interpretTickLabelAsTex', true, 'encoding', 'UTF-8');
end