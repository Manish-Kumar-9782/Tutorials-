#include<stdio.h>

/*
Comparison Operator:
	1. == : equality operator
	2. < : less than operator
	3. > : greater than operator
	4. <= : less than or equal to operator
	5. >= : greater than or equal to operator

	bool: true, false,
		true: 1
		false: 0

Logical Operator:
	1. && : AND Operator
		false && true --> false
		true  && false --> false
		true && true --> true
		false && false --> false

	2. || : OR Operator
		false || true --> true
		true  || false --> true
		false || false --> false
		true || true --> true

	3. !  : NOT Operator
		! true ---> false
		! false ---> true
*/

int main() {

	int a = 20;
	int b = 15;
	int c = 10;

	printf("a is equal to b: %d\n", a == b);
	printf("a is equal to c: %d\n", a == c);
	printf("a is less than b: %d\n", a < b);
	printf("a is less than c: %d\n", a < c);
	printf("a is less than or equal c: %d\n", a <= c);
	printf("=============================================\n\n");

	printf("a is greater than c: %d\n", a > c);
	printf("a is less than b: %d\n", a < b);
	printf("a is less than b and greater than c: %d\n", a < b && a > c);  // 0
	printf("a is less than b or greater than c: %d\n", a < b || a > c);  // 1



}