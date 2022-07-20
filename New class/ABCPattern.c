#include<stdio.h>

int main(){
	
	// counter i, j
	int i;
	int j;
	for(i=1; i<=26; i++){
		
		for(j=1; j<=i; j++){
			printf("*");
		}
		
		printf("\n");
	}
}
