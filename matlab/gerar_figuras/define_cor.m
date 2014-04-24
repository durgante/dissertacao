function [ cor ] = define_cor( colorido, num_cores )
%define_cor Define as cores da figura.
%   A fun��o recebe um argumento, que define se a figura ser� colorida ou
% n�o. Se for colorida, ser�o definidas cores aleat�rias. Se n�o for
% colorida, ser�o definidos tons de cinza.

%Pr�-aloca��o de mem�ria para a vari�vel
cor=zeros(num_cores, 3);

%Defini��o de cores
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

