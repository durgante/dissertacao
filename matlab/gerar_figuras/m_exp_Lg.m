%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

load('resultados_3.mat');
nome=resultados_3;

t=nome.X.Data;
i2ref=nome.Y(1,2).Data;
i2=nome.Y(1,1).Data;
up=nome.Y(1,9).Data;
m=nome.Y(1,4).Data;

%% Plot

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor=define_cor(colorido, 1);

%Plot básico
close all
figure
hold on

inicio = 123218;
final = 123914;

plot(t(inicio:final), m(inicio:final), 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor(1, 1:3));

% plot(t(inicio:final), i2(inicio:final), 'LineWidth', 1.5, ...
%                'LineStyle', '-', ...
%                'Color', cor(2, 1:3));

%Mudança de escala do eixo X para logaritmica
%set(gca, 'XScale', 'log');

%Escolha dos pontos marcados do eixo Y
set(gca, 'YTick', [1500 2000 2500 3000 3500]);
set(gca, 'XTick', [10.27 10.28 10.29 10.3 10.31 10.32]);
set(gca, 'XTickLabel', {'10,27', '10,28', '10,29', '10,3', '10,31', '10,32'});
set(gca, 'YTickLabel', {'1.500', '2.000', '2.500', '3.000', '3.500'});

%Escolha dos limites dos eixos X e Y
set(gca, 'YLim', [1150 3800]);
set(gca, 'XLim', [10.2681 10.3261]);

%Grid
grid on
box on

%Labels
ylabel('m');
xlabel('Tempo (s)');
title('');
%legend(...
%    'i2^*', ...
%    'i2', 'location', 'NW');

%% Define dimensões do gráfico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Opções extras para os eixos
    axoptions={'scaled x ticks = false', 'legend columns=-1', ...
        'legend style={/tikz/every even column/.append style={column sep=0.3cm}}', ...
            'legend style={font=\footnotesize}'};
    
    %Exporta
    matlab2tikz('./m_exp_Lg.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8', 'extraAxisOptions', axoptions);
end