#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Hello Alert!\a\n");

	//Scanf
	char username[10];
	char countryname[10];
	int age;

	printf("What is your name?\n");
	scanf("%s", username);
	printf("Where are you from?\n");
	scanf("%s", countryname);
	printf("How old are you?\n");
	scanf("%d", &age);

	printf("\nWelcome %s ! We love %s. We also know you were born in %d\n", username, countryname, 2016-age);
	return 0;
}
