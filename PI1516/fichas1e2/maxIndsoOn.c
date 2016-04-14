#include <stdio.h>
/* Ordena o array encontrando o indice com o elemento maior do array, e colocando-o na última posição do array. */

void swap(int v[], int i1, int i2);
void ordena(int v[], int N);
int maxInd(int v[], int N);
void printVetor(int v[], int N);

int main(){
	int N=7;
	int v[7]={1,9,8,5,4,3,2};
	int i;
	printVetor(v,N);
	ordena(v,N);
	printVetor(v,N);
	return 1;
}

void printVetor(int v[], int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int indiceMax(int v[], int N){
	int i, indr=0, valor=v[indr];
	for(i=1;i<N;i++){
		if(v[i] > valor){
			valor = v[i];
			indr = i;
		}
	}
	return indr;
}

void ordena(int v[], int N){
	int i, ind, ult=N;

	for(i=0;i<N;i++){
		ind = indiceMax(v,ult);
		printf("indice = %d\n", ind);
		swap(v,ind,ult-1);
		ult--;
	}
	
}


void swap(int v[], int i1, int i2){
	int valor = v[i1];
	v[i1] = v[i2];
	v[i2] = valor;
}