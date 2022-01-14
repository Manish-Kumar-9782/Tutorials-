#include<stdio.h>

// in this section we will increment and decrement operator
// ++ and -- (increment and decrement operator ) are used to increase and decrease values by one and more steps.

void main(){
	
	int a , b, n;
	n=5;  // n will be used as the step number in the increment or decrement operation.
	a =10;
	b=20;
	
	// Now we will check post increment (post increment is denoted or written by var++)
	printf("Post Increment Var++\n");
	printf("--------------------------------------------------\n");
	printf("increasing the value of a by one step: %d, \n\n", a++);
	// In this statement a++ will increase the value of a after excution of this line
	printf("checking the value a after increment operator: %d\n", a);
	// in this statement we will check the increased value of a.


	// Now we will check pre increment (pre increment is denoted or written by ++var)
	printf("\n\nPre Increment ++Var\n");
	printf("--------------------------------------------------\n");
	printf("increasing the value of a by one step: %d, \n\n", ++b);
	// In this statement a++ will increase the value of a after excution of this line
	printf("checking the value a after increment operator: %d\n", b);
	// in this statement we will check the increased value of a.
	
	
	// Now we will increse the value of a by n steps.
	printf("\n\nPost Increment Var+n\n");
	printf("--------------------------------------------------\n");
	printf("\nIncresing the value of a by n steps %d :", a+=n);
	
	
	
	// Working on the decrement operator
	
		// Now we will check post increment (post increment is denoted or written by var++)
	printf("\n\nPost Decrement Var--\n");
	printf("--------------------------------------------------\n");
	printf("Decrising the value of a by one step: %d, \n\n", a--);
	// In this statement a++ will increase the value of a after excution of this line
	printf("checking the value a after increment operator: %d\n", a);
	// in this statement we will check the increased value of a.


	// Now we will check pre increment (pre increment is denoted or written by ++var)
	printf("\n\nPre Decrement --Var\n");
	printf("--------------------------------------------------\n");
	printf("Decrising the value of a by one step: %d, \n\n", --b);
	// In this statement a++ will increase the value of a after excution of this line
	printf("checking the value a after increment operator: %d\n", b);
	// in this statement we will check the increased value of a.
	
	
	// Now we will increse the value of a by n steps.
	printf("\n\nPost Decrement Var-n\n");
	printf("--------------------------------------------------\n");
	printf("\n Decrising the value of a by n steps %d :", a-n);

}
