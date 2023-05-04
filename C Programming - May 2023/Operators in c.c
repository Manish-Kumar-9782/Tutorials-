#include<stdio.h>

/*
	operators:
		1. artihmatic Operators
		2. assignment Operators
		3. comparison Operators
		4. logical Operators
		5. bitwise Operators
		6. Increment and Decrement Operator
		7. Ternary Operator
		8. sizeOf operator
*/

/*
	Arithmatic Operators:
		1. + : plus Operator
		2. - : minus Operator
		3. / : divsion Operator
		4. * : multiply Operator
		5. % : modulus Operator
*/

void main(){
	
	// = assignment Operator
	// left variable = right value
	// right values goes to left variable.
	
	int a = 10; // declaration and intialization
	
//	a = 20; // assignment operation
	int b = 20;
	
	// result of a + b 
	int c = a+b; // first adding a+b  and assigning the value to c
	// means initalizing c with result of a+b;
	printf("add of %d + %d = %d\n",a,b,c);
	
	printf("%d - %d = %d\n", b,a,b-a);
	printf("%d / %d = %d\n", b,a,b/a);
	printf("%d * %d = %d\n", b,a,b*a);
	printf("%d %% %d = %d\n", 7,3,7%3);
	
	
	/*
		Assignment Operator:
			1. += : add and assign
			2. -= : minus and assign
			3. /= : divide and asign
			4. *= : multiply and assign
			5. %= : modulus and assign
	*/
	
	
	// performing a+b
	printf("=============================\n");
	printf("a is : %d\n", a);
	printf("b is: %d\n",b);
	printf("add of %d + %d = %d\n",a,b,a+b);
	printf("a is : %d\n", a);
	printf("b is: %d\n",b);
	
	printf("------------------\n");
	printf("a is : %d\n", a);
	printf("b is: %d\n",b);

	a = a+b; // updating a
	// a is 30
	printf("after performing: a = a+b;\n");
	printf("a is : %d\n", a);
	printf("b is: %d\n",b);
	// a = a+ 20;  ---> a += 20;
	printf("after performing: b += 20;\n");
	b += 20;
	printf("b is: %d\n",b);
}
