// Program: In this section we will make a half pyramid program of ALPHABETS.
// in which in each row number will starts form 1 and increased by one in each column.

#include<stdio.h>

void main(){
	
	// to make a half pyramid program we need two loop 
	// one loop will track the row and other one will track the columns.
	int i,j;
	for(i=1; i<=10; i++){
		
		for(j=0; j<i; j++){
			
			printf("%c ",'A'+j);			
		}
		printf("\n");
		
	}
}
