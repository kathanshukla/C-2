#include <stdio.h>

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

int main(){


	char s1[10] ="marianas";
	char s2[4] ="ana";

	char* o = strstr(s1, s2);

	printf("%s  %s  %s\n ", s1, s2, o);

	

	return 0;
}