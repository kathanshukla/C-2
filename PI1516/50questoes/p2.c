#include <stdio.h>

//Q8
/*
função que calcula os dois ultimos digitos 
do fatorial de n.
nota: para obter os dois ultimos digitos de um
numero basta calcular o resto da divisao
inteira por 100. 
*/

//TODO
unsigned long long fact(int n){
	unsigned long long retorno = 1;
	while(n>1){
		retorno = retorno * n;
		n--;
	}
	return retorno;
}

int fact2(int n){
	int dois=0;
	dois = fact(n);
	dois = dois % 100;
	return dois;
}

int main(){
	int x = 21;
	unsigned long long  factorial = fact(x);
	unsigned long long doisu = factorial % 100;
	printf("Fatorial de %d é %llu \n", x, factorial);

	printf("Os dois ultimos digitos do fatorial são %llu", doisu);

	/*
	Para calcular os dois ultimos digitos de um numero, 
	basta calcular o resto da dividao inteira por 100.
	*/
	

	

}