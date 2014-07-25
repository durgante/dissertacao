%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;

Rd=0;
Z0= 1/(C*s) + Rd;
Gi1_i2_Rd0=Z0/(Zg+Z0);
Rd=2;
Z0= 1/(C*s) + Rd;
Gi1_i2_Rd2=Z0/(Zg+Z0);
Rd=10;
Z0= 1/(C*s) + Rd;
Gi1_i2_Rd10=Z0/(Zg+Z0);


%Prepara dados para plotar

%Gera frequências espaçadas logaritmicamente
t=logspace(3, 5, 2000);

%Pega magnitudes das duas funções
[MAG_1, PHASE_1] = bode(Gi1_i2_Rd0, t);
[MAG_2, PHASE_2] = bode(Gi1_i2_Rd2, t);
[MAG_3, PHASE_3] = bode(Gi1_i2_Rd10, t);

%Prepara magnitudes para o plot
MAG_1 = 20*log10(MAG_1);
MAG_2 = 20*log10(MAG_2);
MAG_3 = 20*log10(MAG_3);
MAG_1 = squeeze(MAG_1);
MAG_2 = squeeze(MAG_2);
MAG_3 = squeeze(MAG_3);

%% Plot

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor=define_cor(colorido, 3);

%Plot básico
close all
figure
hold on

plot(t, MAG_3, 'LineWidth', 1.5, ...
               'LineStyle', '-.', ...
               'Color', cor(1, 1:3));

plot(t, MAG_2, 'LineWidth', 1.5, ...
               'LineStyle', '--', ...
               'Color', cor(2, 1:3));

plot(t, MAG_1, 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor(3, 1:3));

%Mudança de escala do eixo X para logaritmica
set(gca, 'XScale', 'log');

%Escolha dos pontos marcados nos eixos
set(gca, 'YTick', [-20 0 20 40 60]);
set(gca, 'XTick', [10^3 10^3.5 10^4]);
set(gca, 'XTickLabel', {'$10^{3}$', '$10^{3.5}$', '$10^{4}$'});

%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [10^3 10^(4.1)]);
set(gca, 'YLim', [-30 70]);

%Labels
ylabel('Magnitude (dB)');
xlabel('Frequência (rad/s)');
title('');
legend(...
    'R_d = 10\Omega', ...
    'R_d = 2\Omega', ...
    'R_d = 0\Omega', 'location', 'NE');
    

%% Define dimensões do gráfico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa figura para exportar
    cleanfigure
    
    %Exporta
    matlab2tikz('./R_in_LCL.tex', 'width', '0.8\textwidth', ...
        'interpretTickLabelAsTex', true, 'encoding', 'UTF-8');
end