#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int numero;
	char nome[60];
	float nota;
}Aluno;

typedef struct nodo{
	Aluno aluno;
	struct nodo *esq, *dir;
}*Turma;

int insere(Turma *t, Aluno a);
void imprime(Turma t);
Aluno* procura(Turma t, int n);
int update(Turma t, Aluno a);
int aprovados(Turma t);
void freet(Turma t);
