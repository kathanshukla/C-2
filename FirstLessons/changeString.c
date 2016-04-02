#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
"Manuel Cenas Tretas" 
"M. Cenas Tretas"
*/

int tamanho(char* nome){
	int i=0; int tamanho=0;
	for(i=0;nome[i]!='\0';i++){
		tamanho++;
	}
	return tamanho;
}

void changeString(char* nome, char* nomesegundo){
	int i=0, j;
	nomesegundo[i] = nome[i];
	nomesegundo[i+1] = '.';
	j = i+2;
	for(i=0;nome[i]!=' ';i++){
		
	}


	for(i-1;nome[i]!='\0'; i++){
		nomesegundo[j]=nome[i];
		j++;
		
	}
	nomesegundo[j] = '\0';



}

int main(){
	char eu[40]="Jessica Cenas maradas Pereira";
	char euz[16] = "dsd";
	
	changeString(eu, euz);

	printf("%s\n", euz);

	return 1;	
}