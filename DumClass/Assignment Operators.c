#include<stdio.h>

/*
* Assignment Operator:
*	1. += : add and assign
*	2. -= : minus and assign
*	3. /= : divide and assign
*	4. *= : multiply and assign
	6. %= : modulus ad assign
*/


void main() {
	int a = 17;
	int b = 3;

	printf("add result: %d\n", a += b); // 20
	printf("minus result: %d\n", a -= b); // 17
	printf("multiply result: %d\n", a*=b); // 51
	printf("division result: %d\n", a /= b); // 17
	printf("modulus result: %d\n", a%=b); // 2

}