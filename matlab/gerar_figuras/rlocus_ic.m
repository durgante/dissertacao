%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;

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

%Os laços for separam o vetor de polos em dois vetores, cada um contendo os
%valores dos polos diferentes
R = rlocus(ic, K);
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

[P, Z] = pzmap(ic);


%% Plot

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor=define_cor(colorido, 3);

%Plot básico
close all
figure
hold on
grid

plot(real(R1), imag(R1), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor(1, 1:3));

plot(real(R2), imag(R2), 'LineWidth', 1.5, ...
                         'LineStyle', 'x', ...
                         'MarkerSize', 8, ...
                         'Color', cor(2, 1:3));

plot(real(Z), imag(Z), 'LineWidth', 1.5, ...
                       'LineStyle', 'o', ...
                       'MarkerSize', 8, ...
                       'Color', cor(3, 1:3));
                   
%Escolha dos pontos marcados nos eixos
set(gca, 'XTick', [-8000 -4000 0]);
set(gca, 'YTick', [-5000 -2500 0 2500 5000]);
%set(gca, 'XTickLabel', []);
                     
%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [-10^4 0.2*10^4]);
set(gca, 'YLim', [-5500 5500]);

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
    matlab2tikz('./gerar_figuras/rlocus_ic.tex', 'width', '0.8\textwidth', ...
                'interpretTickLabelAsTex', true, 'encoding', 'UTF-8', 'extraAxisOptions', axoptions);
end