#include "Turma1.h"

int insere(Turma *t, Aluno a){
	while(*t){
		if( (*t)->aluno.numero == a.numero )return 1;
		if(  (*t)->aluno.numero > a.numero ) t = &((*t)->esq);
		else t = &((*t)->dir);
	}

	//*t agora é NULL pois saiu do ciclo while
	(*t) = (Turma) malloc (sizeof(struct nodo));
	if((*t)==NULL) return 2; //Código de erro espaço insuficiente
	(*t)->aluno=a;
	(*t)->esq = NULL; (*t)->dir = NULL; 
	return 0;

}

/* 
* Imprime por número, ordem inorder.
* */
void imprime(Turma t){
	if(t == NULL) return;
	imprime(t->esq);
	printf("%d,%s,%f\n", t->aluno.numero, t->aluno.nome, t->aluno.nota);
	imprime(t->dir);
	
}

Aluno* procura(Turma t, int n){
	//Se encontrar devolve o endereço do Aluno
	while(t){
		if(t->aluno.numero == n) return &( t->aluno );
		else if(t->aluno.numero > n) t = t->esq;
		else t= t->dir;
	}

	return NULL;
	//Retorna NULL caso número nao exista ou caso a árvore inicial seja vazia.
}

int update(Turma t, Aluno a){
	//Atualiza o Aluno colocando o novo aluno recebido como parametro.
	Aluno * aux;
	aux = procura(t, a.numero);
	if(aux){
		*aux = a;
		return 0;
	}
	else return 1;
}

/**
* Função recursiva sem utilização de variáveis.
*/
int aprovados(Turma t){
	if(t==NULL)return 0;
	if(t->aluno.nota >= 9.5) return (1 + aprovados(t->esq) + aprovados(t->dir));
	else return ( aprovados(t->esq) + aprovados(t->dir));
}

/**
* Função que liberta a memória, de baixo para cima.
*/
void freet(Turma t){
	if(t==NULL) return;
	freet(t->esq);
	freet(t->dir);
	free(t);
}


int main(){
	Aluno a1 = {10885 , "Alcino", 18.5};
	Aluno a2 = {77782, "Mariana", 9.5};
	Aluno a3 = {79175, "Vitor", 6.5};

	Turma t = NULL;

	insere(&t, a2);
	insere(&t, a1);
	insere(&t, a3);

	imprime(t);

	/*
	Teste das novas funções
	*/
	Aluno * aux;
	aux = procura(t, 77782);
	printf("%s\n", aux->nome);
	//Procura a Mariana e imprime o seu nome

	a2.nota = 10.5;

	printf("Nota da mariana antes do update: %f\n", aux->nota);
	update(t, a2);
	printf("Nota da mariana depois do update: %f\n", aux->nota);

	printf("Nº de aprovados: %d\n", aprovados(t));
	freet(t);


	return 0;
}

