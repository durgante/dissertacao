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
load('sim_step.mat');

%% Prepara��o do Plot

%Define cores do gr�fico (primeiro argumento=1 -> gr�fico colorido; =0
% gr�fico em tons de cinza; segundo argumento = n�mero de cores necess�rio)
cor1=define_cor(colorido, 6);
cor2=define_cor(colorido, 6);
cor3=define_cor(colorido, 6);

%Defini��es do gr�fico
%Define a raz�o �urea
phi=0.5*(1+sqrt(5));
%Define uma escala em fun��o da raz�o �urea
scale=20;

%Tamanho dos vetores e que parte plotar
tamanho=size(t);
tempo = [1 4];
ylims = [-0.7 0.4];
yticks = [-0.6 -0.3 0 0.2];

ciclos = tempo(2)-tempo(1)+1;
inicio=tempo(1)*2000+1;
final=tempo(2)*2000+1;
xlims = [tempo(1)/60 tempo(2)/60];
passo=5;

clear xticks;
xticks(ciclos)=0;
for i=1:ciclos
    if i==1
        xticks(i)=xlims(1);
    else
        xticks(i)=xticks(i-1)+1/60;
    end
end
clear i;

%xticks = [xlims(1) 2/60 3/60 4/60 5/60 6/60 7/60 8/60 9/60 xlims(2)];

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
subplotsy=2;
%Espa�o sobrando na esquerda da janela de plot
leftedge=2;
%Espa�o sobrando na direita da janela de plot
rightedge=0.5;
%Espa�o sobrando na parte de cima da janela de plot
topedge=2.5;
%Espa�o sobrando na parte de baixo da janela de plot
bottomedge=4;
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
        if ii==2
            hold on
            plot(t(inicio:passo:final), theta_alpha(inicio:passo:final,1), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor1(1, 1:3));

            plot(t(inicio:passo:final), theta_alpha(inicio:passo:final,2), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor1(2, 1:3));
            
            plot(t(inicio:passo:final), theta_alpha(inicio:passo:final,3), 'LineWidth', 1.5, ...
                           'LineStyle', '-.', ...
                           'Color', cor1(3, 1:3));
                       
            plot(t(inicio:passo:final), theta_alpha(inicio:passo:final,4), 'LineWidth', 1.5, ...
                           'LineStyle', ':', ...
                           'Color', cor1(4, 1:3));
                       
            plot(t(inicio:passo:final), theta_alpha(inicio:passo:final,5), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor1(5, 1:3));
                       
            plot(t(inicio:passo:final), theta_alpha(inicio:passo:final,6), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor1(6, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', yticks);
            set(gca, 'XTick', xticks);
            set(gca, 'XTickLabel', {''});
            set(gca, 'YTickLabel', {'-0,6', '-0,3', '0', '0,2'});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'YLim', ylims);
            set(gca, 'XLim', xlims);
            
            %Grid
            %grid on
            box on

            %Labels
            ylabel('Eixo Alfa');
            %xlabel('tempo (ciclos)');
            title('');
            %legend(...
            %    '{i2_a}^*', ...
            %    'i2_a', 'location', 'NE');
            hold off
        end

        if ii==1
            hold on
            plot(t(inicio:passo:final), theta_Beta(inicio:passo:final,1), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor1(1, 1:3));

            plot(t(inicio:passo:final), theta_Beta(inicio:passo:final,2), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor1(2, 1:3));
            
            plot(t(inicio:passo:final), theta_Beta(inicio:passo:final,3), 'LineWidth', 1.5, ...
                           'LineStyle', '-.', ...
                           'Color', cor1(3, 1:3));
                       
            plot(t(inicio:passo:final), theta_Beta(inicio:passo:final,4), 'LineWidth', 1.5, ...
                           'LineStyle', ':', ...
                           'Color', cor1(4, 1:3));
                       
            plot(t(inicio:passo:final), theta_Beta(inicio:passo:final,5), 'LineWidth', 1.5, ...
                           'LineStyle', '-', ...
                           'Color', cor1(5, 1:3));
                       
            plot(t(inicio:passo:final), theta_Beta(inicio:passo:final,6), 'LineWidth', 1.5, ...
                           'LineStyle', '--', ...
                           'Color', cor1(6, 1:3));

            %Escolha dos pontos marcados do eixo Y
            set(gca, 'YTick', yticks);
            set(gca, 'XTick', xticks);
            set(gca, 'XTickLabel', {''});
            set(gca, 'YTickLabel', {'-0,6', '-0,3', '0', '0,2'});

            %Escolha dos limites dos eixos X e Y
            set(gca, 'YLim', ylims);
            set(gca, 'XLim', xlims);
            
            %Grid
            %grid on
            box on

            %Labels
            ylabel('Eixo Beta');
            %xlabel('tempo (ciclos)');
            title('');
            %legend(...
            %    '{i2_a}^*', ...
            %    'i2_a', 'location', 'NE');
            hold off
        end

%         if ii==1
%             hold on
%             plot(t(inicio:passo:final), theta_O(inicio:passo:final,1), 'LineWidth', 1.5, ...
%                            'LineStyle', '-', ...
%                            'Color', cor1(1, 1:3));
% 
%             plot(t(inicio:passo:final), theta_O(inicio:passo:final,2), 'LineWidth', 1.5, ...
%                            'LineStyle', '--', ...
%                            'Color', cor1(2, 1:3));
%             
%             plot(t(inicio:passo:final), theta_O(inicio:passo:final,3), 'LineWidth', 1.5, ...
%                            'LineStyle', '-.', ...
%                            'Color', cor1(3, 1:3));
%                        
%             plot(t(inicio:passo:final), theta_O(inicio:passo:final,4), 'LineWidth', 1.5, ...
%                            'LineStyle', ':', ...
%                            'Color', cor1(4, 1:3));
%                        
%             plot(t(inicio:passo:final), theta_O(inicio:passo:final,5), 'LineWidth', 1.5, ...
%                            'LineStyle', '-', ...
%                            'Color', cor1(5, 1:3));
%                        
%             plot(t(inicio:passo:final), theta_O(inicio:passo:final,6), 'LineWidth', 1.5, ...
%                            'LineStyle', '--', ...
%                            'Color', cor1(6, 1:3));
% 
%             %Escolha dos pontos marcados do eixo Y
%             set(gca, 'YTick', yticks);
%             set(gca, 'XTick', xticks);
%             %set(gca, 'XTickLabel', {'1', '2', '3', '4'});
%             set(gca, 'XTickLabel', tempo(1):tempo(2));
%             set(gca, 'YTickLabel', {'-0,6', '-0,3', '0', '0,2'});
% 
%             %Escolha dos limites dos eixos X e Y
%             set(gca, 'YLim', ylims);
%             set(gca, 'XLim', xlims);
%             
%             %Grid
%             %grid on
%             box on
% 
%             %Labels
%             ylabel('Eixo O');
%             xlabel('tempo (ciclos)');
%             title('');
%             %legend(...
%             %    '{i2_a}^*', ...
%             %    'i2_a', 'location', 'NE');
%             hold off
%         end

    end
end

%% Imprime figura

if exportar==1
    %Limpa a figura para exportar
    cleanfigure
    
    %Op��es extras para os eixos
    axoptions={'scaled x ticks = false', 'legend columns=-1', ...
        'legend style={/tikz/every even column/.append style={column sep=0.3cm}}', ...
            'legend style={font=\footnotesize}'};

    %Exporta
    matlab2tikz('./theta_sim_step.tex', 'width', '0.8\textwidth', ...
        'encoding', 'UTF-8', 'extraAxisOptions', axoptions);
end