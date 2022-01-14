#include<stdio.h>

// In this section we will work on the arithmetic operators
void main(){
	
	int a, b;
	
	// Now we need to define or assign some values into a and b.
	a = 11;
	b = 3;
	
	float x,y;
	x=11;
	y=3;
	
	char ch;
	ch = 'c';
	
	printf("Addtion operator: a + b = %d \n", a+b);
	
	printf("Subtraction operator: a - b = %d \n", a-b);
	
	printf("Multiply operator: a * b = %d \n", a*b);
	
	printf("Division operator: a / b = %d \n", a/b);
	
	printf("Division operator on float values: x / y = %f \n", x/y);
	
	printf("Modulus operator: a %% b = %d \n", a%b);
	
	
	printf("\nSize of the integer and float values  (all values are defined in byte unit).\n");
	printf("\nSize of integer a and b  : %d %d  ", sizeof(a), sizeof(b));
	printf("\nSize of float x and y : %d %d ", sizeof(x), sizeof(y));
	printf("\nSize of char c: %d", sizeof(ch));
	
}
