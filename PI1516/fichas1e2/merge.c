#include <stdio.h>

void merge(int r[], int a[], int b[], int na, int nb);
void printv(int v[], int N);

int main(){
	int a[3] = {1,3,5};
	int b[3] = {2,4,6};
	int r[6];

	printv(a,3);
	printv(b,3);

	merge(r,a,b,3,3);
	printv(r,6);

	return 1;
}


void merge(int r[], int a[], int b[], int na, int nb)
{
	int i, ai=0, bi=0;
	for(i=0;i<na+nb;i++){
		if(a[ai] <= b[bi]){
			r[i] = a[ai];
			ai++;
		}
		else{
			r[i] = b[bi]; bi++;
		}
	}

}

void printv(int v[], int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}
