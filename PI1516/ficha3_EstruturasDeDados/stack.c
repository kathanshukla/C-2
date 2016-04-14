#include <stdio.h>
#include <stdlib.h>

//Ficha 3 - stdlib para o malloc e free

//Exo1
#define MAX 10
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

	s->sp=0;
}

int isEmptyS(STACK *s){
	if(s->sp == 0) return 1; else return 0;
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
		*x=s->valores[s->sp-1];
		s->sp--;
		return 0;
	}
	else return 1;
}

int top(STACK *s, int* x){
	if(s->sp>0){
		*x=s->valores[s->sp-1];
	}
}

void printS(STACK *s){
	int i;
	for(i=0;i<s->sp;i++){
		printf("Valor: %d \t", s->valores[i]);
	}
	printf("\n");
}



int main(){
	STACK s;
	initStack(&s);
	printS(&s);
	push(&s, 1); push(&s, 2); push(&s, 2); push(&s, 2); push(&s, 2); push(&s, 2); 
	printS(&s);


	return 1;
}