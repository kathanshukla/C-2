#include <stdio.h>
#include <string.h>

//Strings Q 9 

int strlens(char str[]){
	int i;
	for(i=0;str[i];i++);
	return i;
}

//Q10
//Concatena s2 a s1
char* strcats(char s1[], char s2[]){
	int i, j;

	for(i=0;s1[i];i++);

	for(j=0;s2[j];j++){
		s1[i] = s2[j];
		i++;
	}
	s1[i] = '\0';
	return s1;
}

/**
*	copia a string source para dest retornando o valor desta ultima
*/
char* strcpyt(char *dest, char source[]){
	int i, j=0;
	for(i=0;source[i];i++){
		dest[j]=source[i];
		j++;
	}
	dest[j]='\0';
	return dest;
}

//Q 12
int strcmps(char s1[], char s2[]){

	int i, j=0; int yes=0;

	//Testa comprimentos das palavras primeiro.
	if(strlen(s1)>strlen(s2)) return 1;
	if(strlen(s1)<strlen(s2)) return -1;

	for(i=0;s1[i];i++){
		if(s1[i] > s2[j]){
			return 1;
		}
		else if(s1[i] < s2[j]){
			return -1;
		}
		else{
			j++;
			continue;
		}
		
	}
	return yes;
}

int main(){

	char je[8] ="jessica";
	char me[6] = "maria";
	
	/*
	printf("Nomes: %s   %s   \n", je, me);
	printf("Tamanho de je = %d \n", strlens(je));

	
	printf("Concatenando... %s \n", strcats(je, me));
	*/
	
	//StrCpyt Teste Questao 11
	
	/*
	printf("String me antes de copiar: %s\n", me);
	strcpyt(me, je);
	printf("String me depois de copiar: %s\n", me);
	*/

	/*

	if('a' < 'b') printf("YES");
	if('b' > 'a') printf("YES");
	if('a' == 'a') printf("YES");
	*/

	printf("%d\n", strcmps("ana", "ano"));
	return 0;
}
