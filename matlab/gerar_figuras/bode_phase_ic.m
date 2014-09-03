%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;
calculo_FTs;

alfa= L1/L;

Gvi_i1= ((1-alfa)*L*C*s^2 + Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

Gvi_i2= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

C=0;
Gvi_i2_C0= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);


%Prepara dados para plotar

%Gera frequências espaçadas logaritmicamente
t=logspace(1, 5, 2000);

%Pega magnitudes das duas funções
[MAG_1, PHASE_1] = bode(G_u_iC_i2, t);
[MAG_2, PHASE_2] = bode(Go_iC, t);
[MAG_3, PHASE_3] = bode(dnm_iC, t);

%Prepara magnitudes para o plot
PHASE_1 = squeeze(PHASE_1);
PHASE_2 = squeeze(PHASE_2);
PHASE_3 = squeeze(PHASE_3);
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

plot(t, PHASE_3, 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor(1, 1:3));

plot(t, PHASE_2, 'LineWidth', 1.5, ...
               'LineStyle', '--', ...
               'Color', cor(2, 1:3));

plot(t, PHASE_1, 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor(3, 1:3));

%Mudança de escala do eixo X para logaritmica
set(gca, 'XScale', 'log');

%Escolha dos pontos marcados do eixo Y
set(gca, 'YTick', [-450 -360 -270 -180 -90 0 90 180 270 360]);
%set(gca, 'XTick', [10^1 10^3.5 10^4]);
%set(gca, 'XTickLabel', {'10^{3}', '10^{3.5}', '10^{4}'});

%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [10^1 10^(4.5)]);
set(gca, 'YLim', [-450 360]);

%Grid
grid on
box on

%Labels
ylabel('Magnitude (dB)');
xlabel('Frequência (rad/s)');
title('');
legend(...
    '\Delta(z)', ...
    'G_o(z)', ...
    'G(z)', ...
    'location', 'NE');

%% Define dimensões do gráfico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Exporta
    matlab2tikz('./bode_phase_ic.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8');
end