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

%zero de fase n�o m�nima
alphaj= - theta22/theta21;

%inteiro necess�rio para fazer Pm estritamente pr�prio
N=1;

PA= z^(-N)*((1-(alphaj)^(-1))*(z-alphaj))/((1-alphaj)*(z-(alphaj)^(-1)));
PM= collect(P0/PA, z);

%part � a parte da express�o de Q0 que deve ser separada em fra��es
%parciais para eliminar os termos inst�veis
part= z^(-1)*PA^(-1)*RM;

%fazendo fra��es parciais encontramos um termo cujo denominador cont�m
%(z+theta22/theta21) o que faz dele um termo inst�vel. Este termo � elimi
%nado e ficamos apenas com:
part=theta21/(z-1);
%part=1/(z-1);

Q0= z*((PM*RM)^(-1))*part;

%Q0 tem um polo em z=-theta21/theta22, ou seja, com parte real negativa.
%Por isso � necess�rio calcular Qc de forma a substituir esse polo por um
%polo na origem

Np=1;
polo=-theta21/theta22;
Qc= z^(-Np)*((z-polo)/(1-polo));

%Express�o final de Q

Q= Q0*Qc;


%lembrando que o comando

%pretty(collect(G, z))

%ir� apresentar G na command window do matlab em termos de coeficientes de
%z e de uma forma mais agrad�vel de ler