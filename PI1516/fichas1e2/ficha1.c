
void tri1(int n){
	int i,j=0;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			putchar('#');
		}
		putchar('\n');
	}

	for(i=n;i>=0;i--){
		for(j=0;j<=i;j++){
			putchar('#');
		}
		putchar('\n');
	}
}


int main(){

	tri1(5);


	return 1;
}