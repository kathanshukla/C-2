#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	int meatBalls[5] = {2, 5, 3, 12, 3};
	printf("Element \t Address \t Value \n");

	for(i=0;i<5;i++){
		printf("meatBalls[%d] \t %p \t %d \n", i, &meatBalls[i], meatBalls[i]);
	}

	printf("\n*meatBalls \t\t %d \n", *meatBalls);
	printf("\n* [meatBalls+2] \t\t %d \n", *(meatBalls+2));

	return 0;
}	
