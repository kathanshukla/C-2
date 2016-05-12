#include <stdio.h>

int main(){
	int soma = 0, numero = 0, maior = 0, maior2=0, nums=0;
	int media = 0;

	printf("Insira um numero para calcular soma, media, o maior, o segundo maior e numero total de numeros lidos: \n");
	printf("Para terminar, insira o numero 0. \n");

	scanf("%d", &numero);

	
	while(numero != 0){
		soma+= numero;
		if(numero > maior){
			maior2 = maior;
			maior = numero;
		} 
		if(numero > maior2 && numero < maior){
			maior2 = numero;
		}

		nums++;
		scanf("%d", &numero);
	}

	if(nums != 0) media = soma / nums;
	printf("Soma = %d \n Média = %d \n Maior = %d\n Segundo Maior = %d\n Total numeros: %d\n\n", soma, media, maior, maior2, nums);

	return 0;
}