#include <stdio.h>
#include <stdlib.h>

typedef struct slist * LInt;
typedef struct slist{
	int valor;
	LInt prox;
}Nodo;

typedef struct{
	LInt inicio, fim;
}DifList;

void p(LInt l){
	printf("Lista : \n");
	while(l){
		printf("%d\n", l->valor);
		l=l->prox;
	}
	printf("Fim da Lista.\n");

}

void pp(DifList l){
	printf("Lista : \n");
	while(l.inicio){
		printf("%d\n", l.inicio->valor);
		l.inicio=l.inicio->prox;
	}
	printf("Fim da Lista.\n");
}


LInt snoc(LInt l, int x){
	LInt new, aux=l;
	new = (LInt) malloc(sizeof(Nodo));
	new->valor = x;
	new->prox = NULL;

	if(l==NULL)return new;
	while(aux->prox)aux=aux->prox;
	aux->prox = new;
	return l;
}

DifList snoc2(DifList l, int x){
	LInt new; 
	new = (LInt) malloc(sizeof(Nodo));
	new->valor = x;
	new->prox = NULL;

	if(l.inicio==NULL){
		l.inicio = l.fim = new;
		return l;
	}
	l.fim->prox=new;
	l.fim=new;
	return l;
}

DifList concat(DifList a, DifList b){
	if(a.inicio == NULL) return b;
	a.fim->prox = b.inicio;
	if(b.fim!=NULL) a.fim = b.fim;
	return a;
}

int main(){

	LInt lista1 = NULL; 
	DifList l; l.inicio=NULL; l.fim=NULL;
    DifList lu; lu.inicio=NULL; lu.fim=NULL;
    

	lista1 = snoc(lista1, 1);
	p(lista1);
	lista1 = snoc(lista1, 2);
	lista1 = snoc(lista1, 3);
	lista1 = snoc(lista1, 4);
	lista1 = snoc(lista1, 5);
	lista1 = snoc(lista1, 6);
	p(lista1);

	
	l = snoc2(l, 1);
	l = snoc2(l, 2);
	l = snoc2(l, 3);
	pp(l);


	lu = snoc2(lu, 4);
	lu = snoc2(lu, 5);
	lu = snoc2(lu, 6);
	pp(lu);

	l = concat(l, lu);
	pp(l);
	return 0;
}