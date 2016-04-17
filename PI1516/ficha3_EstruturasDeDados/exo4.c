#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist *Aluno;

typedef struct slist{
    int numero;
	int nota;
	char *nome;
	Aluno prox;
}Al;

int main(){
	int n, i, j, x, y;
	char buff[8], string[256];
	char *quack;
	Aluno al = (Aluno)malloc(sizeof(Aluno));
	al->prox = NULL;
	Aluno aux = al, aux2 = al;

	fgets(buff, 8, stdin);
	n = atoi(buff);
	for(i = 0; i < n; i++){

		fgets(string, 256, stdin);
		quack = strtok(string, " ");
		aux->numero = atoi(quack);
		quack = strtok(NULL, "&");
		aux->nome = malloc(strlen(quack)+1);
		strcpy(aux->nome, quack);
		aux->nome[strlen(aux->nome)-1] = '\0';

		if(i != n-1){
			aux->prox = (Aluno)malloc(sizeof(Aluno));
			aux = aux->prox;
			aux->prox = NULL;
			aux->nota = 0;
		}
	}

	aux = al;

	printf("notas\n");
	
	for(i = 0; i < n; i++){
		fgets(string, 256, stdin);
		quack = strtok(string, " ");
		x = atoi(quack);
		quack = strtok(NULL, "&");
		for(aux = al; aux; aux = aux->prox){
			if(aux->numero == x)
				aux->nota = atoi(quack);
		}
	}

	while(al){
		if(al->nota == 0)
			printf("%d %s F\n", al->numero, al->nome);
		else if(al->nota <  10)
			printf("%d %s R\n", al->numero, al->nome);
		else 
			printf("%d %s %d\n", al->numero, al->nome, al->nota);
		al = al->prox;
	}
}