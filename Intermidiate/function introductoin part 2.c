#include<stdio.h>

/*
	function  is a like of buliding block in which we define some statements to do 
	some work. these statements are defined once and used again and again.
	
	syntax:
	
	// header part of function
	<retur_data_type> <function_name>(<parameter_list>){
		
		// code block (body part of the function.)
		// ... there can be multiple statements.
		
		// finally we may return somthing.
		// Note: if <return_data_type> is not void, then we must need to return
		// something with that associated data type value.
		
		return <return_data_type_value> //if not void.
	}
	
	
	// IN C/C++ we can define a function into four parts.
	
	1. function with no argument and no return value.
	2. function with argument and no return value.
	3. funciton with no argument but return vlaue.
	4. funciton with argument and return value.
	
	prameter list: (int a, int b)
	
	parameter list are used to store the information coming as argument during calling 
	the function. these parameter are used intenally by function to perform the some
	kind operation with  that incomming data.
	
	and after processing all the data result will be passed through the return keyword.

	// note: functions are usuallly defined outside the main function, on global scope.
	
	//  first we need to declare the fuction,  before the main function, if we are going
	to define that function after the main function.
	// 

*/

// declaring add function 
void add(int, int);

void main(){
	
	// now calling the function
	

	while(1){
		// now we will take input from the user. for that we need two variable to
		// store the data given by user.
		printf("\n-------------------------\n");
		int a, b;
		printf("Enter value a: \n");
		scanf("%d",&a);
		
		printf("Enter value b: \n");
		scanf("%d",&b);
		
		// Note: & is an address operator, which gives the reference of the variable
		// at which our value going to be stored.
		
		// now we will call the add function
		add(a,b);
		printf("\n-------------------------\n");
	}
}

void add(int a, int b){
	
	int c = a + b;
	printf("adding %d + %d = %d \n", a, b,c);
}

