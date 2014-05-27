function [ ] = ajuste_fino( figura_normal )
%ajuste_fino Seta dimensões da figura para impressão.
%   Função que ajusta a posição da figura na tela e suas dimensões
% para exportação. A função usa a razão áurea para aplicar dimensões
% esteticamente agradáveis à figura e garante que todas as figuras
% terão as mesmas proporções. Há um argumento que permite escolher
% se a figura é "normal" ou "comprida", no entanto essas são as únicas
% opções de dimensões diferentes disponíveis.

%Seta as unidades de medida usadas no ajuste das dimensões
set(gcf, 'Units', 'centimeters');

%Define a razão áurea
phi=0.5*(1+sqrt(5));

if figura_normal
    %Dimensões para figuras normais (função da razão áurea):
    height=1/phi;
    width=1;
else
    %Dimensões para figuras compridas (função da razão áurea):
    height=1/phi;
    width=2;
end

%Escala da figura:
scale=20;

%Definição da posição da figura NA TELA
xpos=2;
ypos=2;
%[pos_x pos_y width_x width_y]
afFigurePosition= [xpos ypos scale*width scale*height];
set(gcf, 'Position', afFigurePosition);

%Garante que as dimensões da figura exportada sejam as mesmas da figura
%na tela
set(gcf, 'PaperPositionMode', 'auto');

%Garante que os eixos interpretados pelo Latex não sejam cortados pelo
%matlab
set(gca, 'Units','normalized',... %
    'Position',[0.15 0.2 0.75 0.7]);

end