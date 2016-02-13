#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){

	char password[8];
	int dollar = 0;
	int up,number=0;
	int i;
	int goodpw = 0;

	
	while(!goodpw){
		printf("Insert a password:\n");
		scanf("%s",password);
		for(i=0;password[i]!=0;i++){
			if(password[i] == '$' ) dollar = 1;
			if(isupper(password[i])){
				//printf("Upper found.");
				up = 1;
			} 
			if(isdigit(password[i])){
				number = 1;
				//printf("Number found!");
			} 
		}
	
		if(number && up && dollar){
			goodpw = 1; printf("Done.");
			break;
		} 
		printf("Not a good password. Be sure you have a number, an uppercase letter and a dollar sign.\n");

	}
}