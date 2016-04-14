//Exo2
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue
{
	int inicio, tamanho;
	int valores[MAX];
}QUEUE;

void initQueue(QUEUE *q);
int isEmptyQ(QUEUE *q);
int enqueue(QUEUE *q, int x);
int dequeue(QUEUE *q, int*x);
int front(QUEUE *q, int*x);
void printQ(QUEUE *q);

int main(){

	QUEUE q;
	initQueue(&q);
	enqueue(&q, 2); enqueue(&q, 2); enqueue(&q, 8); enqueue(&q, 2);enqueue(&q, 4);
	printQ(&q);
	return 1;
}


void printQ(QUEUE *s){
	int i;
	for(i=0;i<s->tamanho;i++){
		printf("Valor: %d \t", s->valores[i]);
	}
	printf("\n");
}

void initQueue(QUEUE *q){
	q->inicio=0;
	q->tamanho=0;
}


int isEmptyQ(QUEUE *q){
	if(q->tamanho == 0) return 1; else return 0;
}

int enqueue(QUEUE *q, int x){
	if(q->tamanho < MAX){
		q->valores[q->tamanho++] = x;
		return 0;
	}
	else return 1;
}
int dequeue(QUEUE *q, int*x){
	if(q->tamanho >0){
		*x = q->valores[q->inicio];
		q->inicio++;
		return 0;
	}
	else return 1;
}
int front(QUEUE *q, int*x){
	if(q->tamanho >0){
		*x = q->valores[q->inicio];
		return 0;
	}
	else return 1;
}