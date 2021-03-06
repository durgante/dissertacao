%% Op��es do Gr�fico

%Plot colorido? 1=sim 0=n�o
colorido=0;

%Exportar para formato .tex? 1=sim 0=n�o
exportar=0;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;

alfa= L1/L;

Gvi_i1= ((1-alfa)*L*C*s^2 + Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

Gvi_i2= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);

C=0;
Gvi_i2_C0= (Rd*C*s + 1) ...
    /(alfa*(1-alfa)*L^2*C*s^3 + Rd*L*C*s^2 + L*s);


%Prepara dados para plotar

%Gera frequ�ncias espa�adas logaritmicamente
t=logspace(3, 5, 2000);

%Pega magnitudes das duas fun��es
[MAG_1, PHASE_1] = bode(Gvi_i2, t);
[MAG_2, PHASE_2] = bode(Gvi_i2_C0, t);

%Prepara magnitudes para o plot
MAG_1 = 20*log10(MAG_1);
MAG_2 = 20*log10(MAG_2);
MAG_1 = squeeze(MAG_1);
MAG_2 = squeeze(MAG_2);

%% Plot

%Define cores do gr�fico (primeiro argumento=1 -> gr�fico colorido; =0
% gr�fico em tons de cinza; segundo argumento = n�mero de cores necess�rio)
cor=define_cor(colorido, 3);

%Plot b�sico
close all
figure
hold on

plot(t, MAG_2, 'LineWidth', 1.5, ...
               'LineStyle', '--', ...
               'Color', cor(2, 1:3));

plot(t, MAG_1, 'LineWidth', 1.5, ...
               'LineStyle', '-', ...
               'Color', cor(3, 1:3));

%Mudan�a de escala do eixo X para logaritmica
set(gca, 'XScale', 'log');

%Escolha dos pontos marcados do eixo Y
set(gca, 'YTick', [-60 -40 -20 0 20]);
%set(gca, 'XTick', [10^3 10^3.5 10^4]);
%set(gca, 'XTickLabel', {'10^{3}', '10^{3.5}', '10^{4}'});

%Escolha dos limites dos eixos X e Y
set(gca, 'XLim', [10^3 10^(4.35)]);
set(gca, 'YLim', [-70 35]);

%Grid
grid on
box on

%Labels
ylabel('Magnitude (dB)');
xlabel('Frequ�ncia (rad/s)');
title('');
legend(...
    'Filtro L', ...
    'Filtro LCL', 'location', 'NE');

%% Define dimens�es do gr�fico
% (argumento=1 -> figuras normais; argumento=0 -> figuras compridas)
ajuste_fino(1);

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Exporta
    matlab2tikz('./L_vs_LCL.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8');
end