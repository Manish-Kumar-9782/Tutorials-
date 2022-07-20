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
 *****************
  ***************
   *************
    ***********
     *********
      *******
       *****
        ***
         *

*/

int main(){
	
	int i; // index number of row, how many star will print in a single row.
	int j;
	int size = 10;
	int spaces = size-1;
	/*-----------------------------Upper part of pattern--------------------------*/
	for(i=1; i<=size; i++, spaces--){
		
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
	
	spaces = 1; // reseting the spaces.
	/*-----------------------------Down part of pattern--------------------------*/
	for(i=1; i<=size; i++, spaces++){
		
		for(j=1; j<=spaces+2*(size-i)-1; j++){
			
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
