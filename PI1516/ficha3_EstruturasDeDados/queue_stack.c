#include <stdio.h>
#include <stdlib.h>

//Ficha 3 - stdlib para o malloc e free

//Exo1
#define MAX 100
typedef struct stack
{
	int sp;
	int valores[MAX];
}STACK;

void initStack(STACK *s);
int isEmptyS(STACK *s);
int push(STACK *s, int x);
int pop(STACK *s, int* x);
int top(STACK *s, int* x);

void initStack(STACK *s){
	s = (struct stack) malloc(sizeof(STACK));
	s->sp=0;
}

int isEmptyS(STACK *s){
	return s->sp;
}

int push(STACK *s, int x){
	if(s->sp < MAX){
		s->valores[s->sp++] = x;
		return 0;
	}
	else return 1;
}

int pop(STACK *s, int * x){
	if(s->sp>0){
		*x=s->valores[s->(sp-1)];
		s->sp--;
		return 0;
	}
	else return 1;
}

int top(STACK *s, int* x){
	if(s->sp>0){
		*x=s->valores[s->(sp-1)];
	}
}


//Exo2

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



void initQueue(QUEUE *q){
	q = (QUEUE)malloc(sizeof(QUEUE));
	q->inicio=0;
	q->tamanho=0;
}


int isEmptyQ(QUEUE *q){
	return q->tamanho;
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

int main(){

	return 1;
}