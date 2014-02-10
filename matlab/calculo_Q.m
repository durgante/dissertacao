syms z theta11 theta12 theta21 theta22 lambda1 lambda0 A B

theta1= [theta11 theta12];
theta2= [theta21 theta22];
theta= [theta1 theta2];

Lambda= z^2 + lambda1*z + lambda0;

an_1= [z; 1];
al= [z; 1];

R0= Lambda - theta1*an_1;
Z0= theta2*al;

P0= collect(Z0/R0, z);

RA= 1;
RM= z/(z-1);
R= collect(RA*RM, z);


%% Produto de Blashcke

%zero de fase não mínima
alphaj= - theta22/theta21;

%inteiro necessário para fazer Pm estritamente próprio
N=1;

PA= z^(-N)*((1-(alphaj)^(-1))*(z-alphaj))/((1-alphaj)*(z-(alphaj)^(-1)));
PM= collect(P0/PA, z);

%part é a parte da expressão de Q0 que deve ser separada em frações
%parciais para eliminar os termos instáveis
part= z^(-1)*PA^(-1)*RM;

%fazendo frações parciais encontramos um termo cujo denominador contém
%(z+theta22/theta21) o que faz dele um termo instável. Este termo é elimi
%nado e ficamos apenas com:
part=theta21/(z-1);
%part=1/(z-1);

Q0= z*((PM*RM)^(-1))*part;

%Q0 tem um polo em z=-theta21/theta22, ou seja, com parte real negativa.
%Por isso é necessário calcular Qc de forma a substituir esse polo por um
%polo na origem

Np=1;
polo=-theta21/theta22;
Qc= z^(-Np)*((z-polo)/(1-polo));

%Expressão final de Q

Q= Q0*Qc;


%lembrando que o comando

%pretty(collect(G, z))

%irá apresentar G na command window do matlab em termos de coeficientes de
%z e de uma forma mais agradável de ler