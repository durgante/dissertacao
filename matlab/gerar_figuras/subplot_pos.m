function [ positions ] = subplot_pos(plotwidth,plotheight,leftmargin,rightmargin,bottommargin,topmargin,nbx,nby,spacex,spacey)
%subplot_pos Determina a posi��o e o tamanho perfeito para subplots.
%   Esta fun��o recebe como argumento o tamanho da janela de plot, o espa�o
%   que se quer deixar para margens, a separa��o entre os gr�ficos e o
%   n�mero de gr�ficos. A fun��o devolve ent�o a posi��o e o tamanho que o
%   gr�fico deve ser desenhado.
 
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