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


Vdc = 20;

a0= (R1 + R2)/(C*L1*L2);
a1= 1/(L1*L2)*(R1*R2+(L1+L2)/C);
a2= R1/L1 + R2/L2;

den= (s^3+a2*s^2+a1*s+a0);

vc= ((2*Vdc/(L1*C))*(s+R2/L2))/den;
ic= ((2*Vdc/(L1)*s)*(s+R2/L2))/den;

%Número de pontos para plotar
pontos=2000;
passo=0.01;

K=0:passo:pontos*passo;

close all
% cor1=rand(1, 3);
% cor2=rand(1, 3);
% cor3=rand(1, 3);
cor1=[1/3, 1/3, 1/3];
cor2=[2/3, 2/3, 2/3];
cor3=[0, 0, 0];

R = rlocus(vc, K);

%Os laços for separam o vetor de polos em dois vetores, cada um contendo os
%valores dos polos diferentes
n=1;
for i=1:2:length(K)
    R1(n)=R(i);
    n=n+1;
end
n=1;
for i=2:2:length(K)
    R2(n)=R(i);
    n=n+1;
end

figure;
plot(real(R1), imag(R1), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor1);
hold on
grid on

plot(real(R2), imag(R2), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor2);

[P, Z] = pzmap(vc);
plot(real(Z), imag(Z), 'LineWidth', 1.5, ...
                       'LineStyle', 'o', ...
                       'MarkerSize', 8, ...
                       'Color', cor3);

%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [-1.2 1.2]);
set(gca, 'YLim', [-1.2*10^4 1.2*10^4]);

%Escolha dos pontos marcados nos eixos
set(gca, 'XTick', [-1 -0.5 0 0.5 1]);
set(gca, 'YTick', [-10^4 -0.5*10^4 0 0.5*10^4 10^4]);
set(gca, 'YTickLabel', {'$-1$', '$-0.5$', '$0$', '$0.5$', '$1$'});

%Labels
ylabel('Eixo Imaginário');
xlabel('Eixo Real');
title('');
                     
%Escolha dos pontos marcados nos eixos
%set(gca, 'YTick', []);
%set(gca, 'XTick', []);
%set(gca, 'XTickLabel', []);
                     

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

cleanfigure
matlab2tikz('rlocus_vc.tex', 'width', '0.8\textwidth', 'interpretTickLabelAsTex', true, 'encoding', 'UTF-8');
