#include <stdio.h>
#include <stdlib.h>

typedef struct slist{
	int valor;
	struct slist *prox;
}*LInt;

typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;


//Exo1 s2 ocorre em s1 ?
char *strstr(char s1[], char s2[]){
	int i,j=0; int in=0; int ou=0;
	int ia=0, ja=0;
// marianas    ana 
	/*
	
	s1 = marianas\0
	s2 = ana\0
	in = 1 ; 

	in=4; ja=0; ia=4;


	*/
	for(i=0;s1[i]; i++){
		//Encontrar a primeira ocorrencia de s2 em s1.
		if(s2[j] == s1[i]){
			in = i;  ja=j; ia=i;
			j++; i++;
			//Encontrar a última ocorrencia de s2
			while(s2[j] == s1[i] && s2[j]!='\0' && s1[i]!='\0'){
				ou=i;
				j++; i++;
				printf("%d\n", in);

				if(s2[j] == '\0') return &(s1[in]);
			}
			j=ja; i=ia;
			//
		}
	}
	printf("%d\n", in);

	return NULL;

	//No final, s2[j] deve ser null ou /0, deve ter chegado ao fim.

}

//exo2
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

//Exo 3
void concat3(LInt *a, LInt b){
	LInt aux = *a;
	if(a==NULL) a = &b;
	while(aux->prox){
		aux = aux->prox; 
	}
	aux->prox = b;
}

LInt concat(LInt a, LInt b){
	LInt aux = a;
	if(a==NULL) return b;
	else{
		while(aux->prox){
			aux = aux->prox;
		}
		aux->prox=b;
		return a;
	}
	
}

void printL(LInt a){
	LInt aux = a;
	while(aux){
		printf("Valor %d \n", aux->valor);
		aux=aux->prox;
	}
}

int main(){

//Testar exo 1
	char s1[10] ="marianas";
	char s2[4] ="ana";

	char* o = strstr(s1, s2);

	printf("%s  %s  %s\n ", s1, s2, o);

//
	//Testar exo2
	int v[4] ={ 90, 4, 80, 2};
	int in = maxInd(v, 4);
	printf("O indice do maior valor no vetor v é %d cujo elemento é %d\n", in, v[in]);

//Testar exo 3
	printf("Antes do concat\n");
	LInt a = (LInt)malloc(sizeof(struct slist));
	a->valor = 10;
	a->prox = (LInt)malloc(sizeof(struct slist));
	a->prox->valor = 20;
	a->prox->prox = NULL;

	printL(a);

	LInt b = (LInt)malloc(sizeof(struct slist));
	b->valor = 30;
	b->prox = (LInt)malloc(sizeof(struct slist));
	b->prox->valor = 40;
	b->prox->prox= NULL;
	printL(b);
	
	concat3(&a, b);
	
	printf("Depois do concat\n");

	//a = concat(a,b);
	printL(a);

	return 0;
}