// assignment operators
/*
	= --> assign               
	+= --> add and assign
	-= --> subtract and assign
	*= --> multiply and assign
	/= --> divide and assign
*/

#include <stdio.h>


int main(){
	
	int a = 0;   // using assignment operator to assign a value in a variable.
	int b = 0;
	
	
	a = 10;
	
	printf("result : %d\n", a+30);
	printf("a is : %d\n", a);
	
//	a = a+30;  // a += 30;

	a += 30;  // adding and assigning the value to a
	printf("Now a is %d: \n", a);
//	
	a -= 10;  // subtrating and assigning the value
	printf("subtract: updated a value: %d \n", a);
//	
	a *= 3;
	printf("muliply: updated a value: %d\n", a);
	
	a /= 2;
	printf("Divide: updated a value: %d\n", a);
	
}
