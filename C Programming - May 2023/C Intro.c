#include<stdio.h>
// preprocessors, #include means --> we are including the header file
// named as stdio.h  used for standard input output operations.

// Now we make a main function
// main function is our entry point in our program.
void main(){
	printf("Hello World! \n");  /// output operation
	// ; --> end of statement
	// int, float, double, char
	int a;  
	float b;
	double c;
	char d;
	// declaration.
	// Note: we didn't define or assigned any value to those above variables.
	
	// now we will assign some copatible values to variables.
	a = 10; // int: only integer value, %d
	b = 4.5; // float: only point number value. %f
	c = 4.3; // double: only point number value. %l
	d = 'c'; /// char: only character, can be any character in '' single quote. %c
	// to print these values by using the printf function
	// we need to use compatible format specifier type.
	
	// string: sequence of charcters.
	// newlice character: \n  ---> escape sequence characters
	printf("a is : %d (int)\n", a);
	printf("b is : %f (float)\n", b);
	printf("c is : %lf (double)\n", c);
	printf("d is : %c (char)\n", d);
}
