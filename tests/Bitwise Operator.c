#include<stdio.h>

//&&, ||, ! are called logical operators

// In this section we will see bitwise operator &, |, ^, ~, <<,>> 

// & AND operator
// | OR operator
// ^ XOR operator
// ~ complimentry operator
// << left shift
// >> right shift

void main(){
	
	int a,b,c;
	// Here int is a keyword and a,b,c are the identifiers.
	int AND_result, OR_result, COMP_result, XOR_result, LS_result, RS_result;
	
	a=9; // Here 9 is a literal, 
	b=5;
	c=-30;
	
	AND_result = a & b; 
	OR_result = a|b;
	XOR_result = a^b;
//	COMP_result = ~a;
	LS_result = a<<2;
	RS_result = a>>2;
	
	printf("Result of the AND operator: %d \n", AND_result);
	printf("Result of the OR operator: %d \n", OR_result);
	printf("Result of the XOR operator: %d \n", XOR_result);
//	printf("Result of the COMP operator: %d \n", COMP_result);
	printf("Result of the LS operator: %d \n", LS_result);
	printf("Result of the RS operator: %d \n", RS_result);
	
	
}
