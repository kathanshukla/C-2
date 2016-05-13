#include <stdio.h>
#include <stdlib.h>

//Tratar o numero binário como se fosse um numero decimal.
int bitsAUm(unsigned int n){
	  int x = 0;
  	while (n){
		    if(n%10 == 1)
		  	    x++;
		    n /= 10;
	  }
  	return x;
}

//Main incluida
int bitsAUm2(){
	int i; int o; int nums;
    char buffer [33];

    printf ("Enter a number: ");
    scanf ("%d",&i);
    nums = 0;
    itoa (i,buffer,10);
    printf ("decimal: %s\n",buffer);

    /*
    itoa (i,buffer,16);
    printf ("hexadecimal: %s\n",buffer);
    itoa (i,buffer,2);
    printf ("binary: %s\n",buffer);
	*/
    for(i = 0; buffer[i]; i++){
    	if(o = (buffer[i] ==  '1'))
    	nums++;
    	//printf("%d\n", o);
    }
	
	printf("Numero de '1''s no numero binário são: %d\n", nums);
	return 0;
}

int main(){
	
	unsigned int n = 1;
	int numero = 0;
	printf("Insira numero binário: \n");
	scanf("%d", &n);
	numero = bitsAUm(n);
	printf("Nº de bits a 1: %d\n", numero);
	

	//bitsAUm2();


	return 0;
}