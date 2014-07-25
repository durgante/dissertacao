function [ positions ] = subplot_pos(plotwidth,plotheight,leftmargin,rightmargin,bottommargin,topmargin,nbx,nby,spacex,spacey)
%subplot_pos Determina a posição e o tamanho perfeito para subplots.
%   Esta função recebe como argumento o tamanho da janela de plot, o espaço
%   que se quer deixar para margens, a separação entre os gráficos e o
%   número de gráficos. A função devolve então a posição e o tamanho que o
%   gráfico deve ser desenhado.
 
    subxsize=(plotwidth-leftmargin-rightmargin-spacex*(nbx-1.0))/nbx;
    subysize=(plotheight-topmargin-bottommargin-spacey*(nby-1.0))/nby;
 
    for i=1:nbx
       for j=1:nby
 
           xfirst=leftmargin+(i-1.0)*(subxsize+spacex);
           yfirst=bottommargin+(j-1.0)*(subysize+spacey);
 
           positions{i,j}=[xfirst/plotwidth yfirst/plotheight subxsize/plotwidth subysize/plotheight];
 
       end
    end
end