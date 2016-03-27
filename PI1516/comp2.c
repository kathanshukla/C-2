#include <stdio.h>
#define MAXBITS 32

//assume-me input em binário
int main(int argc, char* argv[]){
    char bin1[MAXBITS], bin2[MAXBITS];
	int i;
	for(i = 0; argv[1][i] != '\0'; i++){
		bin1[i] = argv[1][i];
		bin2[i] = argv[1][i];
	}

	compP2_1(bin1);
	compP2_2(bin2);
	return 0;
}

int compP2_1(char* bin){
	int i, x, y = 0, ex = 1;

	for(i = 0; i < MAXBITS; i++){
		if(bin[i] == '\0')
			break;
	}

	for(x = 0; x < i; x++){
		if(bin[x] == '1')
			bin[x] = '0';
		else
			bin[x] = '1';
	}

	for(x = i-1; x >= 0; x--){
		if(ex == 1)
			if(bin[x] == '1')
				bin[x] = '0';
			else{
				bin[x] = '1';
				ex = 0;
			}
	}

	printf("1. %s\n", bin);
	return 0;
}

int compP2_2(char* bin){
	int i, x, y, ex = 0;

	for(i = 0; i < MAXBITS; i++){
		if(bin[i] == '\0')
			break;
	}

	for(x = i-1; x >= 0; x--){
		if(ex == 0){
			if(bin[x] == '1')
				ex = 1;
		}
		else{
			if(bin[x] == '0')
				bin[x] = '1';
			else
				bin[x] = '0';
		}
	}

	printf("2. %s\n", bin);
	return 0;
}