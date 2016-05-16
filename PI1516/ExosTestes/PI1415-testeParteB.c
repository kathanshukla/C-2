#include <stdio.h>
#include <stdlib.h>

typedef struct strlist{
	char *string;
	struct strlist *prox;
}*StrList;

/** 
*  Funções para o primeiro Exo. da Parte 2 do PI1415-teste.pdf
*/
int eRepetido(int v[], int numero, int lidos){
	int i; int n=0; 
	//(Só pode haver 1 igual a numero na lista. se houver dois, há repetidos.)
	for(i=0; i<lidos; i++){
		if(v[i] == numero) n++;
	}
	if(n<=1) return 0;
	else return 1;
}

void le100numeros(int* v){
	int indice=0; int r=0;
	int numeroLido = 0;

	while(indice < 100){
		printf("Insira um numero\n");
		scanf("%d",&numeroLido);
		v[indice++] = numeroLido;
		r = eRepetido(v, numeroLido, indice);
		printf("É repetido? %d\n", r);
		if(r==1) break;
	}
	
	

}


int maxInd(int v[], int n){
	int maior=0, maiorindice=0;
	int i;
	for(i=0; i<n;i++){
		if(v[i] > maior){
			maior = v[i];
			maiorindice = i;
		}
	}
	return maiorindice;
}


//Exo2

void unwords(StrList s, char t[], int N){
	int i=0,totalN=0;
	StrList aux = s;
	//i indice para uma palavra, totalN indice para o vetor char t[].
	while(aux && totalN < N){
		i=0;
		for(totalN; aux->string[i] ;totalN++){
			t[totalN] = aux->string[i];
			i++;
			if(totalN == N)break;
		}
		if(totalN == N)break;
		t[totalN++] = ' ';
		aux = aux->prox;
	}
	t[totalN]='\0';
}

void printStr(StrList a){
	while(a){
		printf("%s\n", a->string);
		a=a->prox;
	}
	printf("Fim da StrList.\n");
}

int main(){
	//Exo 1
	
	/*
	int vetor[100];
	int i;
	for(i=0;i<100;i++){
		vetor[i] = 0;
	}

	le100numeros(vetor);
	i = maxInd(vetor, 100);
	printf("O maior numero é o %d no indice %d \n", vetor[i], i);
	*/

	//Exo2
	//Teste 1
	char t[5];
	/*StrList sl = (StrList)malloc(sizeof(struct strlist));
	sl->string = "Maria";
	sl->prox = NULL;

	printStr(sl);
	unwords(sl, t, 3);
	printf("Vetor char: %s\n", t);
	*/
	//Teste 2
	StrList s = (StrList)malloc(sizeof(struct strlist));
	s->string = "Maria";
	s->prox = (StrList)malloc(sizeof(struct strlist));
	s->prox->string = "Joao";
	s->prox->prox = NULL;
	printStr(s);
	unwords(s, t, 18);
	printf("Vetor char: %s\n", t);

	//TODO investigar. Até 6 unwords(s,t,6) funciona, mas a partir de 7 imprime mal.
	return 0;
}
