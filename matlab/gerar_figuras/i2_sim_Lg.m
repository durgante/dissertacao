%% Opções do Gráfico

%Plot colorido? 1=sim 0=não
colorido=0;

%Exportar para formato .tex? 1=sim 0=não
exportar=0;

%Figura tamanho normal ou comprida? 1=normal 0=comprida
figura_normal=1;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;

%Carrega variáveis para serem plotadas
load('sim_Lg.mat');

%% Preparação do Plot

%Define cores do gráfico (primeiro argumento=1 -> gráfico colorido; =0
% gráfico em tons de cinza; segundo argumento = número de cores necessário)
cor1=define_cor(colorido, 2);
cor2=define_cor(colorido, 2);
cor3=define_cor(colorido, 2);

%Definições do gráfico
%Define a razão áurea
phi=0.5*(1+sqrt(5));
%Define uma escala em função da razão áurea
scale=20;

%Tamanho dos vetores e que parte plotar
tamanho=size(t);
inicio=2000;
final=8001;
passo=5;
X_ini=1/60;
X_end=4/60;

%Determina as proporções em função do tipo de figura
if figura_normal
    %Dimensões para figuras normais (função da razão áurea):
    height=1/phi;
    width=1;
else
    %Dimensões para figuras compridas (função da razão áurea):
    height=1/phi;
    width=2;
end

%Número de colunas para acomodar subplots
subplotsx=1;
%Número de linhas para acomodar subplots
subplotsy=3;
%Espaço sobrando na esquerda da janela de plot
leftedge=2;
%Espaço sobrando na direita da janela de plot
rightedge=0.5;
%Espaço sobrando na parte de cima da janela de plot
topedge=2.5;
%Espaço sobrando na parte de baixo da janela de plot
bottomedge=4;
%Espaço entre os gráficos no eixo X
spacex=0.2;
%Espaço entre os gráficos no eixo Y
spacey=0.2;
%Tamanho da fonte
fontsize=8;
%Altura da janela de plot (para poder acomodar todos os gráficos)
plotheight=height*scale*subplotsy+spacey*(subplotsy-1)+topedge+bottomedge;
%Largura da janela de plot
plotwidth=width*scale*subplotsx+spacey*(subplotsx-1)+leftedge+rightedge;

%Função que determina as posições dos gráficos para montar o subplot
sub_pos=subplot_pos(plotwidth,plotheight,leftedge,rightedge,bottomedge,topedge,subplotsx,subplotsy,spacex,spacey);
 
%Configurando o plot para ficar bem na hora de exportar
f=figure('visible','on');
clf(f);
set(gcf, 'PaperUnits', 'centimeters');
set(gcf, 'PaperSize', [plotwidth plotheight]);
set(gcf, 'PaperPositionMode', 'manual');
set(gcf, 'PaperPosition', [0 0 plotwidth plotheight]);

%% Plot

close all

for i=1:subplotsx
    for ii=1:subplotsy
        ax=axes('position',sub_pos{i,ii},'XGrid','off','XMinorGrid','off','FontSize',fontsize,'Box','on','Layer','top');
        if ii==3
            hold on
            plot(t(inicio:passo:final), i2ref_a(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor1(1, 1:3));

            plot(t(inicio:passo:final), i2_a(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor1(2, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [-10 0 10]);
            set(gca, 'XTick', [1/60 2/60 3/60 4/60]);
            set(gca, 'XTickLabel', {''});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [-15 25]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('{i2_a}^* \times i2_a (A)');
            %xlabel('tempo (ciclos)');
            title('');
            legend(...
                '{i2_a}^*', ...
                'i2_a', 'location', 'NE');
            hold off
        end

        if ii==2
            hold on
            plot(t(inicio:passo:final), i2ref_b(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor2(1, 1:3));

            plot(t(inicio:passo:final), i2_b(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor2(2, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [-10 0 10]);
            set(gca, 'XTick', [1/60 2/60 3/60 4/60]);
            set(gca, 'XTickLabel', {''});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [-15 25]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('{i2_b}* \times i2_b (A)');
            %xlabel('tempo (ciclos)');
            title('');
            legend(...
                '{i2_b}^*', ...
                'i2_b', 'location', 'NE');
            hold off
        end

        if ii==1
            hold on
            plot(t(inicio:passo:final), i2ref_c(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor3(1, 1:3));

            plot(t(inicio:passo:final), i2_c(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor3(2, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [-10 0 10]);
            set(gca, 'XTick', [1/60 2/60 3/60 4/60]);
            set(gca, 'XTickLabel', {'1', '2', '3', '4'});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [-15 25]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('{i2_c}^* \times i2_c (A)');
            xlabel('tempo (ciclos)');
            title('');
            legend(...
                '{i2_c}^*', ...
                'i2_c', 'location', 'NE');
            hold off
        end

    end
end

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Opções extras para os eixos
    axoptions={'scaled x ticks = false', 'legend columns=-1', ...
        'legend style={/tikz/every even column/.append style={column sep=0.3cm}}', ...
            'legend style={font=\footnotesize}'};
    %Exporta
    matlab2tikz('./i2_sim_Lg.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8', 'extraAxisOptions', axoptions);
end