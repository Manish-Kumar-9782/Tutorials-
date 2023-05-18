#include<stdio.h>

/*
	Logical Opearators:
	
	1. &&: AND Operator
	2. ||: OR Operator.
	3. ! : NOT Operator.
	
	
	Logic Output AND Operator. (Binary Operator)
	
	true && false --> false;
	falase && false --> false;
	false && true --> false;
	true && true --> true;
	
	Logic Output OR Operator. (Binary Operator)
	
	true || false --> true;
	falase || false --> false;
	false || true --> true;
	true || true --> true;
	
	Logic Output NOT Operator. (Unary Operator)
	
	!true ---> false;
	!false ---> true;
	
*/

void main(){
	
	int a = 10, b = 45, c = 58; 
	// declaration and initialization of multiple values, 
	// inline declaration and initialization.
	
	// Now we will make some expression to perform the Logical operator.
	printf("a = %d, b = %d, c = %d\n", a,b,c);
	
	printf("\n\nLogical Operator of AND Operator\n");
	printf("------------------------------------------\n");
	printf("is a less than b -> %d -- and b is greater than c. -> %d\n", a<b, b>c);
	printf("is a less than b and b is greater than c. %d\n", a<b && b>c);
	printf("is a less than b and c is greater than b. %d\n", a<b && c>b);
	
	printf("\n\nLogical Operator of OR Operator\n");
	printf("------------------------------------------\n");
	printf("is a less than b -> %d -- or b is greater than c. -> %d\n", a<b, b>c);
	printf("is a less than b or b is greater than c. %d\n", a<b || b>c);
	printf("is a less than b or c is greater than b. %d\n", a<b || c>b);
	printf("is b less than a or a is greater than c. %d\n", a>b || c<a);
	
	
	printf("\n\nLogical Operator of OR Operator\n");
	printf("------------------------------------------\n");
	printf("is a not less than b: %d", !(a<b));
	
}
