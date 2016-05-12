#include <stdio.h>
#include <stdlib.h>

typedef struct node *DList;

typedef struct node{
    int value;
	DList prev, next;
} Node;

DList addInt(DList l, int x){
	DList aux = l;

	DList temp = NULL;
	DList temp2 = NULL;
	int i = 0;

	//O i indica a direçao, -1 esquerda, 1 direita.
	// nao permite andar nas duas direçoes, ou esquerda ou direita.

	/*
	Se pretendo inserir o valor 2 na lista  1 3 5 , só vou para a esquerda.
	o 3 é maior que o 2, logo esquerda. o 2 é menor que o 1 , logo iria para a esquerda mas no mas
	porque ele faz break. comecei a andar para a direita, e é isso que tenho de continuar, se precisar
	ou entao parar.
	*/
	while(aux){
		if(aux->value < x){
			if(i == -1) break;
			temp = aux;
			aux = aux->next;
			i = 1;
		}else{
			if(i == 1) break;
			temp = aux;
			aux = aux->prev;
			i = -1;
		}
	}

	temp2 = (DList)malloc(sizeof(Node));
	temp2->value = x;
	switch(i){
		case 0:
			l = temp2;
			temp2->next = NULL;
			temp2->prev = NULL;
			break;
		case 1:
			temp2->prev = temp;
			temp2->next = aux;
			temp->next = temp2;
			if(aux)
				aux->prev = temp2;
			break;
		case -1:
			temp2->prev = aux;
			temp2->next = temp;
			temp->prev = temp2;
			if(aux)
				aux->next = temp2;
			break;
	}

	return l;
}

DList lookLeft(DList l, int x){
	DList aux = l;
	while(aux){
		if(aux->value == x)
			break;
		aux = aux->prev;
	}
	return aux;
}
DList lookRight(DList l, int x){
	DList aux = l;
	while(aux){
		if(aux->value == x)
			break;
		aux = aux->next;
	}
	return aux;
}
DList exists(DList l, int x){
	DList ret = NULL;
	if(!(ret = lookLeft(l,x)))
		ret = lookRight(l,x);
	return ret;
}

DList remove1(DList l){
	DList aux;
	if(l->prev){
		aux = l->prev;
		aux->next = l->next;
	}else{
		aux = l->next;
		aux->prev = l->prev;
	}
	free(l);
	return aux;
}

DList rewind1(DList l){
	DList aux = l, temp;
	while(aux){
		temp = aux;
		aux = aux->prev;
	}
	return temp;
}

DList forward1(DList l){
	DList aux = l, temp;
	while(aux){
		temp = aux;
		aux = aux->next;
	}
	return temp;
}

void printList(DList l){
	printf("Lista:\n");
	DList aux = rewind1(l);
	while(aux){
		printf("%d\n", aux->value);
		aux = aux->next;
	}
	printf("\n");
}

int main(){

	DList a = NULL, b = NULL;
	a = addInt(a, 2);
	a = addInt(a, 4);
	a = addInt(a, 1);
	a = addInt(a, 3);
	printList(a);
	
	b = exists(a, 4);
	printf("Existe: %d\n\n", b->value);

	a = remove1(a);
	printList(a);
	
	a = a->next;
	printf("Actual: %d\n", a->value);
	a = rewind1(a);
	printf("Inicio: %d\n\n", a->value);

	printf("Actual: %d\n", a->value);
	a = forward1(a);
	printf("Fim: %d\n", a->value);

	return 1;
}