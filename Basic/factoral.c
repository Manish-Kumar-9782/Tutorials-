// In this section we will compute the factorial of a given number.
// 4! == 1*2*3*4 == 24
#include <stdio.h>


int main(){  // manishkumar9782@gmail.com
	
	int number = 8;
	int factorial = 1;
	int i;   // counter
	
	for(i=1; i<=number; i++){
		printf("factorial = %d * %d\n\n", factorial, i);
		factorial *= i;  ///
	}
	
	printf("Factorial of %d : %d", number, factorial);
}
