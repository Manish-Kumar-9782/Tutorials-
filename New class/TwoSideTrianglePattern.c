#include<stdio.h>

/*
         *
        ***
       *****
      *******
     *********
    ***********
   *************
  ***************
 *****************
*******************


*/

int main(){
	
	int i; // index number of row, how many star will print in a single row.
	int j;
	int spaces = 9;
	for(i=1; i<=10; i++, spaces--){
		
		for(j=1; j<=spaces+2*i-1; j++){
			
			if(j<=spaces){
				printf(" ");
			}
			else{
				printf("*");
			}		
		}
		
		printf("\n");
	}
}
