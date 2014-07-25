%Printar Resultados

%Na estrutura exportada do controldesk, as variaveis sao:
%resultados.X.Data - t -> é o tempo da simulação
%resultados.Y(1,1).Data - i2_real
%resultados.Y(1,2).Data - i2m_k
%resultados.Y(1,3).Data - iC_real
%resultados.Y(1,4).Data - m
%resultados.Y(1,5).Data - theta1
%resultados.Y(1,6).Data - theta2
%resultados.Y(1,7).Data - theta3
%resultados.Y(1,8).Data - theta4
%resultados.Y(1,9).Data - up_alpha -> é a ação de controle que sai do bloco
%do adaptativo

%resultados_3
%Neste arquivo, inicialmente se tem L2 = 0.54mH + 2.14mH
%No instante t=10.298s L2 passa a ser L2 = 0.54mH
%No instante t=8.593s ocorre uma inversão de fase na referência

%% Plot

%Nome do arquivo exportado do controldesk com os pontos para plotar
load('resultados_3.mat');
nome=resultados_3;

close all;

%o que printar?
acaodecontrole=1;
i2vsi2m=1;
thetas=1;
correntecapacitor=1;
normalizador=1;

if acaodecontrole>0
%Ação de Controle
figure
plot(nome.X.Data,nome.Y(1,9).Data)
grid on
title('Ação de Controle');
xlabel('t');
ylabel('up');
end

if i2vsi2m>0
%i2 medido vs saída do modelo de referência
figure
plot(nome.X.Data,nome.Y(1,1).Data,'b',nome.X.Data,nome.Y(1,2).Data,'r')
grid on
title('i2 medido x i2m(k)');
xlabel('t');
ylabel('i2(b) e i2m(r)');
end

if thetas>0
%thetas
figure
plot(nome.X.Data,nome.Y(1,5).Data,'b',nome.X.Data,nome.Y(1,6).Data,'g',nome.X.Data,nome.Y(1,7).Data,'r',nome.X.Data,nome.Y(1,8).Data,'c')
grid on
title('thetas');
xlabel('t');
ylabel('theta1(b), theta2(g), theta3(r), theta4(c)');
end

if correntecapacitor>0
%Corrente do Capacitor
figure
plot(nome.X.Data,nome.Y(1,3).Data)
grid on
title('Corrente Medida no Capacitor');
xlabel('t');
ylabel('iC');
end

if normalizador>0
%Normalizador
figure
plot(nome.X.Data,nome.Y(1,4).Data)
grid on
title('Normalizador');
xlabel('t');
ylabel('m');
end