function [ cor ] = define_cor( colorido, num_cores )
%define_cor Define as cores da figura.
%   A função recebe um argumento, que define se a figura será colorida ou
% não. Se for colorida, serão definidas cores aleatórias. Se não for
% colorida, serão definidos tons de cinza.

%Pré-alocação de memória para a variável
cor=zeros(num_cores, 3);

%Definição de cores
if colorido==0
    for n=1:num_cores-1
        cor(n, 1:3)=[(num_cores-n)/num_cores, ...
            (num_cores-n)/num_cores, (num_cores-n)/num_cores];
    end
    cor(num_cores, 1:3)=[0,0,0];
else
    for n=1:num_cores
        cor(n, 1:3)=rand(1,3);
    end
end

end

