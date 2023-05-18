#include<stdio.h>

int main(){
	
	// counter i, j
	int i;
	int j;
	for(i=1; i<=10; i++){
		
		for(j=1; j<=i; j++){
			printf("*");
		}
		
		printf("\n");
	}
}
