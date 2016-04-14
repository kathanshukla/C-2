#include <stdio.h>
//This version is only for 2x2 matrices.

void mult(int N, int M, int K, int r[N][M], int a[N][K], int b[K][M]){
	
	int i , j;
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){

		r[i][j] = a[i][0] * b[0][j] + a[i][1]*b[1][j];
		}
	}
}


int main(){

	/*int a[2][2] ={  {1,1},  {2,1}};
	int b[2][2] = { {1,2}, {1,1}};
	*/
	int a[2][2], b[2][2]; int N,M; N=2,M=2;
	a[0][0]=1; a[0][1] = 1; a[1][0] = 2; a[1][1] = 1;
	b[0][0]=1; b[0][1] = 2; b[1][0] = 1; b[1][1] = 1;
	
	int r[2][2];

	int i,j;
	//printing
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("  x  \n");
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("=\n");


	
	/* Calling the function above */
	mult(2,2,2,r,a,b);
	
	//Problem solved, passed as parameters and working! TODO: more dimensions.
	

	//printing
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			printf("%d\t",r[i][j]);
		}
		printf("\n");
	}

	return 1;
}

//thank you http://stackoverflow.com/questions/18661702/passing-matrix-as-a-parameter-in-function