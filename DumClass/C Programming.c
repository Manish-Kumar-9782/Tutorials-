#include<stdio.h>
/* multiline comment.
	arithmatic Operator

	1. + : plus Operator.
	2. - : minus Operator.
	3. / : division Operator.
	4. * : multiply Operator.
	5. % : modulus Operator.
*/


// type casting: --> implicit casting, explicit casting.

void main() {

	int a = 17;
	int b = 3;

	int add_result = a + b;
	int minus_result = a - b;
	float division_result = (float)a / b;
	//Note if variable a and b are both int type. then it will only return result as integer.
	// to get result in float we need to convert a into float by using explicit 
	int multiply_result = a * b;
	int modulus_result = a % b;

	printf("add result: %d\n", add_result);
	printf("minus result: %d\n", minus_result);
	printf("division result: %f\n", division_result);
	printf("multiply result: %d\n", multiply_result);
	printf("modulus result: %d\n", modulus_result);

}