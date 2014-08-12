%% Op��es do Gr�fico

%Plot colorido? 1=sim 0=n�o
colorido=0;

%Exportar para formato .tex? 1=sim 0=n�o
exportar=0;

%Figura tamanho normal ou comprida? 1=normal 0=comprida
figura_normal=1;


%% Dados para plotar

%Chama o script que inicializa os parametros do filtro LCL
parametros_filtro_LCL;

%Carrega vari�veis para serem plotadas
load('resultados_3.mat');
nome=resultados_3;

t=nome.X.Data;
theta1=nome.Y(1,5).Data;
theta2=nome.Y(1,6).Data;
theta3=nome.Y(1,7).Data;
theta4=nome.Y(1,8).Data;

%% Prepara��o do Plot

%Define cores do gr�fico (primeiro argumento=1 -> gr�fico colorido; =0
% gr�fico em tons de cinza; segundo argumento = n�mero de cores necess�rio)
cor=define_cor(colorido, 1);

%Defini��es do gr�fico
%Define a raz�o �urea
phi=0.5*(1+sqrt(5));
%Define uma escala em fun��o da raz�o �urea
scale=20;

%Tamanho dos vetores e que parte plotar
tamanho=size(t);
inicio=123218;
final=123914;
passo=1;
X_ini=10.2681;
X_end=10.3261;

%Determina as propor��es em fun��o do tipo de figura
if figura_normal
    %Dimens�es para figuras normais (fun��o da raz�o �urea):
    height=1/phi;
    width=1;
else
    %Dimens�es para figuras compridas (fun��o da raz�o �urea):
    height=1/phi;
    width=2;
end

%N�mero de colunas para acomodar subplots
subplotsx=1;
%N�mero de linhas para acomodar subplots
subplotsy=4;
%Espa�o sobrando na esquerda da janela de plot
leftedge=2.5;
%Espa�o sobrando na direita da janela de plot
rightedge=0.5;
%Espa�o sobrando na parte de cima da janela de plot
topedge=3;
%Espa�o sobrando na parte de baixo da janela de plot
bottomedge=5;
%Espa�o entre os gr�ficos no eixo X
spacex=0.2;
%Espa�o entre os gr�ficos no eixo Y
spacey=0.2;
%Tamanho da fonte
fontsize=8;
%Altura da janela de plot (para poder acomodar todos os gr�ficos)
plotheight=height*scale*subplotsy+spacey*(subplotsy-1)+topedge+bottomedge;
%Largura da janela de plot
plotwidth=width*scale*subplotsx+spacey*(subplotsx-1)+leftedge+rightedge;

%Fun��o que determina as posi��es dos gr�ficos para montar o subplot
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
        if ii==4
            hold on
            plot(t(inicio:passo:final), theta1(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor(1, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [0.542 0.547 0.552]);
            set(gca, 'XTick', [10.27 10.28 10.29 10.3 10.31 10.32]);
            set(gca, 'XTickLabel', {''});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [0.54 0.555]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('\theta_1');
            %xlabel('tempo (ciclos)');
            title('');
            %legend(...
            %    '{i2_a}^*', ...
            %    'i2_a', 'location', 'NE');
            hold off
        end
        
        if ii==3
            hold on
            plot(t(inicio:passo:final), theta2(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor(1, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [0.172 0.177 0.182]);
            set(gca, 'XTick', [10.27 10.28 10.29 10.3 10.31 10.32]);
            set(gca, 'XTickLabel', {''});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [0.17 0.185]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('\theta_2');
            %xlabel('tempo (ciclos)');
            title('');
            %legend(...
            %    '{i2_a}^*', ...
            %    'i2_a', 'location', 'NE');
            hold off
        end

        if ii==2
            hold on
            plot(t(inicio:passo:final), theta3(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor(1, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [-1.192 -1.188 -1.184]);
            set(gca, 'XTick', [10.27 10.28 10.29 10.3 10.31 10.32]);
            set(gca, 'XTickLabel', {''});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [-1.195 -1.18]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('\theta_3');
            %xlabel('tempo (ciclos)');
            title('');
            %legend(...
            %    '{i2_a}^*', ...
            %    'i2_a', 'location', 'NE');
            hold off
        end

        if ii==1
            hold on
            plot(t(inicio:passo:final), theta4(inicio:passo:final), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor(1, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', [1.728 1.735 1.742]);
            set(gca, 'XTick', [10.27 10.28 10.29 10.3 10.31 10.32]);
            set(gca, 'XTickLabel', 10.27:0.01:10.32);

            %Escolha dos limites dos eixos X e Y
            set(gca, 'XLim', [X_ini X_end]);
            set(gca, 'YLim', [1.725 1.745]);
            
            %Grid
            grid on
            box on

            %Labels
            ylabel('\theta_4');
            xlabel('tempo (ciclos)');
            title('');
            %legend(...
            %    '{i2_a}^*', ...
            %    'i2_a', 'location', 'NE');
            hold off
        end

    end
end

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Op��es extras para os eixos
    axoptions={'scaled x ticks = false', 'scaled y ticks = false', ...
        'y tick label style={/pgf/number format/.cd, fixed, fixed zerofill,precision=3}', ...
        'legend columns=-1', ...
        'legend style={/tikz/every even column/.append style={column sep=0.3cm}}', ...
            'legend style={font=\footnotesize}'};

    %Exporta
    matlab2tikz('./theta_exp_Lg.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8', 'extraAxisOptions', axoptions);
end