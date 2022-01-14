// Program: Produce a table of binomial cofficient.

#include<stdio.h>

#define MAX 10

void main(){
	
	int m, x, binom;
	printf("m x");
	
	for (m=0; m<=10; ++m)
		printf("%4d", m);
	// this loop will create a header for of m choose to x.
		
	printf("\n----------------------------------\n");
	m = 0;
	
	do{
		printf("%2d ", m);  // printing the column of m values, it will print the very first column.
		x=0; binom=1;
		
		// running the loop while x is less or equal to m
		while(x<=m){   // This inner while loop will print the single row of the binomal cofficient terms.
			
			if(m==0 || x==0){
				printf("%4d", binom);
			}
			else{
				binom = binom*(m-x+1)/x;  // if we have m>0 || x>0 then we can have binom cofficient > 1.
				printf("%4d", binom);
			}
			x++;
		}
		printf("\n");
		m++;
	}
	while(m<=MAX);  // this outer while loop will iterate over each m value which will be used to get cofficients.
	printf("\n----------------------------------\n");
	
}

