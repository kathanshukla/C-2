#include <stdio.h>
#include <string.h>

//Strings Q 9 

int strlens(char str[]){
	int i;
	for(i=0;str[i];i++);
	return i;
}

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

int main(){

	char je[8] ="jessica";
	char me[6] = "maria";
	printf("Nomes: %s   %s   \n", je, me);
	printf("Tamanho de je = %d \n", strlens(je));

	
	printf("Concatenando... %s \n", strcats(je, me));

	return 0;
}
