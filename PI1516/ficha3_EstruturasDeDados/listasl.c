#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist *LInt;
typedef struct difl *DInt;

typedef struct slist{
    int valor;
	LInt prox;
} Nodo;

typedef struct difl{
	LInt inicio, fim;
}DifList;

void p(LInt l){
	Nodo * aux = l;
	while(aux){
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
}


void print(DInt l){
	if(l->inicio != NULL){
		Nodo* aux = l->inicio;
		while(aux){
			printf("%d\n", aux->valor);
			aux = aux->prox;
		}
	}
}

/* b) */
LInt cons(LInt l, int x){
	LInt aux = (LInt)malloc(sizeof(Nodo));
	aux->valor=x;
	aux->prox= l;
	return aux;
}

LInt tail(LInt l){
	LInt aux = l; LInt e = l;
	if(l==NULL){
		free(l);
		return NULL;
	}
	else{
		aux = aux->prox;
		e->prox = NULL;
		free(e);
		return aux;
	}
}


LInt init(LInt l){
	LInt aux = l; LInt ant = NULL;
	if(l==NULL){
		free(l);
		return NULL;
	}
	else{
		while(aux->prox){
			ant = aux;
			aux=aux->prox;
		}
		ant->prox = NULL;
		free(aux);
		return l;
	}
}

LInt snoc(LInt l, int x){
	LInt aux=l; LInt ant = NULL;
	if(l==NULL){
		l = (Nodo*)malloc(sizeof(Nodo));
		l->valor = x;
		return l;
	}
	else{
		while(aux){
			ant = aux;
			aux = aux->prox;

		}
		aux = (Nodo*)malloc(sizeof(Nodo));
		ant->prox = aux;
		aux->valor=x;
		aux->prox = NULL;
		return l;

	}
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

DInt concat2(DInt a, DInt b) {
	if(a->inicio == NULL) return b;

	a->fim->prox = b->inicio;
	return a;
}

DInt snoc2(DInt l, int x){
	if(l == NULL){
		l = (DifList*) malloc(sizeof(DifList));
		l->inicio = l->fim = NULL;
	}
	
	if(l->inicio==NULL){
		l->fim = (LInt)malloc(sizeof(Nodo));
		l->fim->valor = x;
		l->fim->prox = NULL;
		l->inicio = l->fim;
		return l;
	}

	DInt auxL = (DifList*) malloc(sizeof(DifList));
	auxL->inicio = auxL->fim = NULL;
	Nodo* iter = l->inicio;
	Nodo* temp = (LInt)malloc(sizeof(Nodo));
	Nodo* aux = temp;
	auxL->inicio = temp;

	while(iter){
		temp->valor = iter->valor;
		temp->prox = NULL;

		temp = (LInt)malloc(sizeof(Nodo));
		aux->prox = temp;
		aux = aux->prox;
		iter = iter->prox;
	}

	temp->valor = x;
	temp->prox = NULL;

	auxL->fim = temp;

	return auxL;
}

int main(){

	/* a) */
	
	LInt l = (Nodo*) malloc(sizeof(Nodo));
	l->valor=10;
	l->prox = (Nodo*) malloc(sizeof(Nodo));
	l->prox->valor = 5;
	l->prox->prox = (Nodo*) malloc(sizeof(Nodo));
	l->prox->prox->valor= 15;
	l->prox->prox->prox=NULL;
	p(l);
	printf("\n");
	
	//10, 5 15
	
	LInt lista = (Nodo*) malloc(sizeof(Nodo));
	lista->valor = 10;
	lista->prox = NULL;
	
	
	lista = snoc(lista, 15);
	lista = snoc(lista, 16);
	lista = snoc(lista, 20);
	
	
	lista = init(lista);
	lista = cons(lista, 1);
	

	lista = concat(lista, l);
	p(lista);
	printf("\n");
	
	

	/*
	DInt lista = (DifList*) malloc(sizeof(DifList));
	lista->inicio = lista->fim = NULL;
	lista = snoc2(lista, 3);
	print(lista);
	printf("\n");

	DInt lista2 = (DifList*) malloc(sizeof(DifList));
	lista2->inicio = lista2->fim = NULL;
	lista2 = snoc2(lista, 4);

	lista = concat2(lista, lista2);
	print(lista);
	printf("\n");
	
	lista = snoc2(lista, 4);
	print(lista);
	printf("\n");
	*/
	return 1;
}