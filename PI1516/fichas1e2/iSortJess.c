#include <stdio.h>


void iSort(int v[], int N){
	int valor; int i, j; int doagain=0;

	for(i=0;i<N;i++){
	if(doagain){
	i--; doagain=0;
	} 
	for(j=0;j<N-1;j++){

		if(v[j]>v[j+1]){

			valor = v[j];
			v[j] = v[j+1];
			v[j+1]=valor;
			doagain=1;
		}
	}
	}


}

int main(){
	int i;
	int vetor[4]={8,5,4,9};

	int N=4;
	for(i=0;i<N;i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");

	iSort(vetor, N);
	for(i=0;i<N;i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");

}