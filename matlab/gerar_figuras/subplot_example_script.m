%parameters for figure and panel size

figura_normal=1;
colorido=0;

parametros_filtro_LCL;
load('sim_ini.mat');
tamanho=size(t);
passo=5;
cor=define_cor(colorido, 2);

phi=0.5*(1+sqrt(5));
scale=20;
if figura_normal
    %Dimensões para figuras normais (função da razão áurea):
    height=1/phi;
    width=1;
else
    %Dimensões para figuras compridas (função da razão áurea):
    height=1/phi;
    width=2;
end

subplotsx=1;
subplotsy=3;   
leftedge=2;
rightedge=0.5;   
topedge=2.5;
bottomedge=4;
spacex=0.2;
spacey=0.2;
fontsize=8;

plotheight=height*scale*subplotsy+spacey*(subplotsy-1)+topedge+bottomedge;
plotwidth=width*scale*subplotsx+spacey*(subplotsx-1)+leftedge+rightedge;


sub_pos=subplot_pos(plotwidth,plotheight,leftedge,rightedge,bottomedge,topedge,subplotsx,subplotsy,spacex,spacey);
 
%setting the Matlab figure
f=figure('visible','on')
clf(f);
set(gcf, 'PaperUnits', 'centimeters');
set(gcf, 'PaperSize', [plotwidth plotheight]);
set(gcf, 'PaperPositionMode', 'manual');
set(gcf, 'PaperPosition', [0 0 plotwidth plotheight]);
 
%loop to create axes
for i=1:subplotsx
for ii=1:subplotsy
 
ax=axes('position',sub_pos{i,ii},'XGrid','off','XMinorGrid','off','FontSize',fontsize,'Box','on','Layer','top');
 
%z=peaks;
%contour(z);
if ii==3
    hold on
    plot(t(1:passo:tamanho), i2ref_a(1:passo:tamanho), 'LineWidth', 1.5, ...
                   'LineStyle', '--', ...
                   'Color', cor(1, 1:3));

    plot(t(1:passo:tamanho), i2_a(1:passo:tamanho), 'LineWidth', 1.5, ...
                   'LineStyle', '-', ...
                   'Color', cor(2, 1:3));

    %Escolha dos pontos marcados do eixo Y
    set(gca, 'YTick', [-10 0 10 20]);
    set(gca, 'XTick', [1/60 2/60]);
    set(gca, 'XTickLabel', {''});

    %Escolha dos limites dos eixos X e Y
    %set(gca, 'XLim', [10^3 10^(4.35)]);
    set(gca, 'YLim', [-15 25]);

    %Labels
    ylabel('i2^*_a vs i2_a (A)');
    %xlabel('tempo (ciclos)');
    title('');
    legend(...
        'i2^*_a', ...
        'i2_a', 'location', 'NE');
    hold off
end

if ii==2
    hold on
    plot(t(1:passo:tamanho), i2ref_b(1:passo:tamanho), 'LineWidth', 1.5, ...
                   'LineStyle', '--', ...
                   'Color', cor(1, 1:3));

    plot(t(1:passo:tamanho), i2_b(1:passo:tamanho), 'LineWidth', 1.5, ...
                   'LineStyle', '-', ...
                   'Color', cor(2, 1:3));

    %Escolha dos pontos marcados do eixo Y
    set(gca, 'YTick', [-10 0 10 20 30 40 50]);
    set(gca, 'XTick', [1/60 2/60]);
    set(gca, 'XTickLabel', {''});

    %Escolha dos limites dos eixos X e Y
    %set(gca, 'XLim', [10^3 10^(4.35)]);
    set(gca, 'YLim', [-15 50]);

    %Labels
    ylabel('i2^*_b vs i2_b (A)');
    %xlabel('tempo (ciclos)');
    title('');
    legend(...
        'i2^*_b', ...
        'i2_b', 'location', 'NE');
    hold off
end

if ii==1
    hold on
    plot(t(1:passo:tamanho), i2ref_c(1:passo:tamanho), 'LineWidth', 1.5, ...
                   'LineStyle', '--', ...
                   'Color', cor(1, 1:3));

    plot(t(1:passo:tamanho), i2_c(1:passo:tamanho), 'LineWidth', 1.5, ...
                   'LineStyle', '-', ...
                   'Color', cor(2, 1:3));

    %Escolha dos pontos marcados do eixo Y
    set(gca, 'YTick', [-40 -30 -20 -10 0 10]);
    set(gca, 'XTick', [1/60 2/60]);
    set(gca, 'XTickLabel', {'1', '2'});

    %Escolha dos limites dos eixos X e Y
    %set(gca, 'XLim', [10^3 10^(4.35)]);
    set(gca, 'YLim', [-45 15]);

    %Labels
    ylabel('i2^*_c vs i2_c (A)');
    xlabel('tempo (ciclos)');
    title('');
    legend(...
        'i2^*_c', ...
        'i2_c', 'location', 'SE');
    hold off
end

if ii==subplotsy
%title(['Title (',num2str(i),')'])
title('');
end
 
if ii>1
%set(ax,'xticklabel',[])
end
 
if i>1
%set(ax,'yticklabel',[])
end
 
if i==1
%ylabel(['Ylabel (',num2str(ii),')'])
end
 
if ii==1
%xlabel(['Ylabel (',num2str(i),')'])
end
 
end
end
 
%Saving eps with matlab and then marking pdf and eps and png with system commands
%filename=['test'];
%print(gcf, '-depsc2','-loose',[filename,'.eps']);
%system(['epstopdf ',filename,'.eps'])
%system(['convert -density 300 ',filename,'.eps ',filename,'.png'])