// Get the binomal cofficient of n powered. where n is the maximum  power
// in this program we need to get cofficient of all terms.
/* for example if we have (x + y)^2  equation  the terms x^2 + 2xy + y^2 
	have cofficient like 1 2 1 by respictive terms.*/
	
// Biomal cofficiant can be get by using the formaula m choose to x for each x.
// in this m is the maximum power of x in the equation and x defines the power x in a term.
// suppose that we have m = 10 and x=1, then it means we are getting the cofficient of a terms which have 1 power of x .
// like 2xy in (x + y)^2 equation.

#include<stdio.h>

void main(){
	
	int m, x, binom;
	// m is the maximum number of power in a equation.
	// x is the power of x in a term.
	// binom is the cofficient value 
	
	// Note: first we need to initialize the m x, and binom value otherwise we will get misleading values.
	m=0; x=0; binom=1;
	
	printf("Enter the maximum power of (x + y)^n  n: ");
	scanf("%d", &m);
	
	for(x=0; x<=m; x++){
		
		// Note: here we should also to make condition where m or x is zero. then binom will be 1.
		
		if(m == 0 || x == 0){
			printf("%4d", binom); // if m or x is zero then we will print only 1.
		}
		else{
			// if m or x is not zero then we will compute the binomial cofficient of each term
			// and we will print it.
			binom = binom*(m-x+1)/x;
			printf("%4d", binom);
		}
		

	}
}

