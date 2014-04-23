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


Zi= L1*s + R1;

Zg= (L2 + Lg)*s + R2 + Rg;

Z0= 1/(C*s) + Rd;

L= L1+L2+Lg;

alfa= L1/L;

Gvi_i1= ((1-alfa)*L*C*s^2 + Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

Gvi_i2= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

C=0;
Gvi_i2_C0= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

%% Plot

close all

%Gera frequências espaçadas logaritmicamente
t=logspace(3, 5, 2000);

%Pega magnitudes das duas funções
[MAG_1, PHASE] = bode(Gvi_i2, t);
[MAG_2, PHASE] = bode(Gvi_i2_C0, t);

%Prepara magnitudes para o plot
MAG_1 = 20*log10(MAG_1);
MAG_2 = 20*log10(MAG_2);
MAG_1 = squeeze(MAG_1);
MAG_2 = squeeze(MAG_2);

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

%Plot básico
hold off
plot(t, MAG_1, 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor3);
hold on
plot(t, MAG_2, 'LineWidth', 1.5, ...
               'LineStyle', '--', ...
               'Color', cor1);

%Mudança de escala do eixo X para logaritmica
set(gca, 'XScale', 'log');

%Escolha dos pontos marcados do eixo Y
set(gca, 'YTick', [-60 -40 -20 0 20]);
set(gca, 'XTick', [10^3 10^3.5 10^4]);
set(gca, 'XTickLabel', {'$10^{3}$', '$10^{3.5}$', '$10^{4}$'});

%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [10^3 10^(4.35)]);
set(gca, 'YLim', [-70 35]);

%Labels
ylabel('Magnitude (dB)');
xlabel('Frequência (rad/s)');
title('');
legend(...
    'Filtro LCL', ...
    'Filtro L', 'location', 'NE');
    

%% Ajuste fino do gráfico

% we set the units of the measures used through the file
%
% [ inches | centimeters | normalized | points | {pixels} | characters ]
set(gcf, 'Units', 'centimeters');

% we set the position and dimension of the figure ON THE SCREEN
%
% NOTE: measurement units refer to the previous settings!
%afFigurePosition = [1 1 20 5.5];        % [pos_x pos_y width_x width_y]
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

% we link the dimension of the figure ON THE PAPER in such a way that
% it is equal to the dimension on the screen
%
% ATTENTION: if PaperPositionMode is not 'auto' the saved file
% could have different dimensions from the one shown on the screen!
set(gcf, 'PaperPositionMode', 'auto');

% in order to make matlab to do not "cut" latex-interpreted axes labels
set(gca, 'Units','normalized',... %
    'Position',[0.15 0.2 0.75 0.7]);


%% Imprime figura

if exportar==1
    cleanfigure
    matlab2tikz('L_vs_LCL.tex', 'width', '0.8\textwidth', 'encoding', 'UTF-8');
end