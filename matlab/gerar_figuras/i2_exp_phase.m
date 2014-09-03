%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

load('resultados_4.mat');
nome=resultados_4;

t=nome.X.Data;
i2ref=nome.Y(1,2).Data;
i2=nome.Y(1,1).Data;

%% Plot

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor=define_cor(colorido, 2);

%Plot básico
close all
figure
hold on

inicio = 107485;
final = 108085;

plot(t(inicio:final), i2ref(inicio:final), 'LineWidth', 1.5, ...
               'LineStyle', '--', ...
               'Color', cor(1, 1:3));

plot(t(inicio:final), i2(inicio:final), 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor(2, 1:3));

%Mudança de escala do eixo X para logaritmica
%set(gca, 'XScale', 'log');

%Escolha dos pontos marcados do eixo Y
set(gca, 'YTick', [-4 -2 0 2 4]);
set(gca, 'XTick', [8.96 8.97 8.98 8.99 9]);
set(gca, 'XTickLabel', {'8,96', '8,97', '8,98', '8,99', '9'});

%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [8.957 9.007]);
set(gca, 'YLim', [-5.5 5.5]);

%Grid
grid on
box on

%Labels
ylabel('i2^* \times i2 (A)');
xlabel('Tempo (s)');
title('');
legend(...
    'i2^*', ...
    'i2', 'location', 'NW');

%% Define dimensões do gráfico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Exporta
    matlab2tikz('./i2_exp_phase.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8');
end