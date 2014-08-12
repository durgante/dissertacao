%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
%run('C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao\matlab\gerar_figuras\parametros_filtro_LCL.m');

Vdc = 20;

a0= (R1 + R2)/(C*L1*L2);
a1= 1/(L1*L2)*(R1*R2+(L1+L2)/C);
a2= R1/L1 + R2/L2;

den= (s^3+a2*s^2+a1*s+a0);

vc= ((2*Vdc/(L1*C))*(s+R2/L2))/den;
ic= ((2*Vdc/(L1)*s)*(s+R2/L2))/den;


%Número de pontos para plotar
pontos=100;
passo=0.1;

K=0:passo:pontos*passo;

%Os laços for separam o vetor de polos em dois vetores, cada um contendo os
%valores dos polos diferentes
R = rlocus(KP*G2d, K);
n=1;
for i=1:3:length(K)
    R1(n)=R(i);
    n=n+1;
end
n=1;
for i=2:3:length(K)
    R2(n)=R(i);
    n=n+1;
end
n=1;
for i=3:3:length(K)
    R3(n)=R(i);
    n=n+1;
end

[P, Z] = pzmap(KP*G2d);

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

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor=define_cor(colorido, 4);

%Plot básico
%close all
%figure
%hold on
%grid

plot(real(R1), imag(R1), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor(1, 1:3));

plot(real(R2), imag(R2), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor(2, 1:3));

plot(real(R3), imag(R3), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor(3, 1:3));

plot(real(Z), imag(Z), 'LineWidth', 1.5, ...
                       'LineStyle', 'o', ...
                       'MarkerSize', 8, ...
                       'Color', cor(4, 1:3));
                   
%Escolha dos pontos marcados nos eixos
set(gca, 'XTick', [-1 0 1]);
set(gca, 'YTick', [-1 0 1]);
%set(gca, 'XTickLabel', []);
                     
%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [-1.9 1.9]);
set(gca, 'YLim', [-1.1 1.1]);

%Grid
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
    %Limpa figura para exportar
    cleanfigure
    
    %Define opções extra para os eixos
    axoptions={'scaled y ticks = false',...
               ...'y tick label style={/pgf/number format/.cd, fixed, fixed zerofill,precision=3}'};
               'y tick label style={/pgf/number format/.cd, fixed, fixed zerofill, precision=0}',...
               'scaled x ticks = false',...
               'x tick label style={/pgf/number format/.cd, fixed, fixed zerofill, precision=0}'};
    
    %Exporta
    matlab2tikz('./rlocus_controlador_p.tex', 'width', '0.8\textwidth', ...
                'interpretTickLabelAsTex', true, 'encoding', 'UTF-8', 'extraAxisOptions', axoptions);
end