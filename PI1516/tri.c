#include <stdio.h>

void trih(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<i+1;j++){
			putchar('#');
		}
		putchar('\n');
	}
	j=n-1;

	for(i=n-1;i>=0;i--){
		for(j=0; j<i; j++){
			putchar('#');
		}
		putchar('\n');
	}
}


void triv(int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < 2*n-1; j++){
			if(j >= n-1-i && j <= n-1+i)
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int main(){
	triv(5);
	return 0;
}
/*



j <= i && j>0


i 1
j 1

# # # # 
# # #
# # 
#

0 1 2 3 4 5
1 x
2 x x
3 x x x
4 x x x
5 x x 

*/