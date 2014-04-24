function [ ] = ajuste_fino( figura_normal )
%ajuste_fino Seta dimens�es da figura para impress�o.
%   Fun��o que ajusta a posi��o da figura na tela e suas dimens�es
% para exporta��o. A fun��o usa a raz�o �urea para aplicar dimens�es
% esteticamente agrad�veis � figura e garante que todas as figuras
% ter�o as mesmas propor��es. H� um argumento que permite escolher
% se a figura � "normal" ou "comprida", no entanto essas s�o as �nicas
% op��es de dimens�es diferentes dispon�veis.

%Seta as unidades de medida usadas no ajuste das dimens�es
set(gcf, 'Units', 'centimeters');

%Define a raz�o �urea
phi=0.5*(1+sqrt(5));

if figura_normal
    %Dimens�es para figuras normais (fun��o da raz�o �urea):
    height=1/phi;
    width=1;
else
    %Dimens�es para figuras compridas (fun��o da raz�o �urea):
    height=1/phi;
    width=2;
end

%Escala da figura:
scale=20;

%Defini��o da posi��o da figura NA TELA
xpos=2;
ypos=2;
%[pos_x pos_y width_x width_y]
afFigurePosition= [xpos ypos scale*width scale*height];
set(gcf, 'Position', afFigurePosition);

%Garante que as dimens�es da figura exportada sejam as mesmas da figura
%na tela
set(gcf, 'PaperPositionMode', 'auto');

%Garante que os eixos interpretados pelo Latex n�o sejam cortados pelo
%matlab
set(gca, 'Units','normalized',... %
    'Position',[0.15 0.2 0.75 0.7]);

end