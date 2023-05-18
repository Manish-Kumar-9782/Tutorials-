#include<stdio.h>

void pyramid(int n){
	
	int row=0, columns=0, spaces = 0;
	
	// for row.
	for(row=0, spaces=n; row<= n; row++, spaces--){
		
		// for columns
		for(columns=0; columns < spaces+(2*row+1) ; columns++){
			
			if(columns < spaces){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
}


void main(){
	
	pyramid(10);
}
