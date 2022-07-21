/*----------------------------DOCUMENTATION SECTION-----------------------------*/

	/*
	
		In this section we will discuss about the basic things of the c program.
		
function: function is a set of instruction in which mutiple line of statement(instruction) are defined.
				these instruction can be executed by calling the function by it's name.
		
global declaration area: it is the area (memory area) outside the every function including main funtion
			in which we declare those variable or function, that can be accessed by any function.
		
int: it is a keyword used to store the integer type values (whole numbers).
		
		float: it is a keyword used to store the decimal type values (deciaml values like 1.24, 3.14).
		
		char: it is keyword used to store the character value in a variable.
		
		const: it is a keyword used to define a variable as constant variable, that can be initialized only once.
				const variable value cannot be changed.
		
		void: void is used to define the return type of the function.
		
		return type: if a function return a something to the caller function then the value must be return in 
					specified data type, that type is called return type.
					
		
		printf: this function is only used to print/display a message or data to console screen.
				To display/print the particular kind of data it need a format specifier for that kind of data type.
		
		scanf: this function is only used to read input data from the user.
				To read a particular kind of data it need a format specifier for that kind of data type.
		
		Format Specifier:
			format specifier is used to define that what kind of data will be printed on the consol and scanned
			from the user.
			
			used specifier:-
				
				%c -- to print or scan character type value.
				%d -- to print or scan integer type value.
	
*/


/*Program: In this section we will use the modulus operator to find out the PrimeNumber.*/

/*
	Prime Number: A prime number is a natural number greaater than 1 that is 
	is not a product of two samller natural number. it cannot be completly divided
	from any number execept 1 or itself. for example 2, 3, 5, 7, 9.. etc.
*/

#include<stdio.h>

int main(){
	
/*	Modulus Operator: this operator gives the remainder of a/b if a>b, where a and are the natural number (whole number)*/
	
	int number = 0;  // int type varaible to hold a number to check that, it is a prime number or not.
	// this number will updated by using the scanf function.
	
	printf("Enter a number: ");
	scanf("%d", &number);  
	/* read a value from the user and put that value into a varaible memory address 
		which is named as number.
	*/
	
	int flag = 1; // initiallly we consider our number is prime.
	/*
		A variable to hold true and false value (1 for true, 0 for false.)
		if flag is set as 1, it means number is prime.
		if flag is set as 0, it means number is not prime.
	*/
	
	int i; // counter variable for the for-loop define below.
	for(i=2; i<number; i++){ // start of for-loop
		/*
			counter variable i;
			initialized as 2.
			condition: for loop will run until i is less than number. (Note: number is given by the user.)
		*/
		
		printf("%d %% %d = %d\n\n", number, i, number%i); // explanation is below.
		
		if (number % i == 0){
			// if any i-number in any iteration given the remainder as 0 than the number is not prime number.
			flag = 0; // to set the flag as 0
		}
		
		if (flag == 0){
			// if any i-number gives the remainder as 0, then stop the loop by using break statement.
			break;
		}
		
	}// end of for-loop
	
	printf("%d -- is prime number: %d", number, flag); 
	/*this printf statement will show the result that, given number is prime or not.
		1st %d -----> number
		2nd %d -----> flag
	*/
}

/*
	line at 84: printf("%d %% %d = %d\n\n", number, i, number%i);
	
	* This statement is used to show the result of the remainder in each iteration.
	* 1st %d ----> for number 
	* 2nd %d ----> for i
	* 3rd %d ----> for number%i  result which is remainder 
	* ... %% ----> to print the '%' in the message
*/


/*
	Code Explanation:
	
	inside main funciton:
		1. int number = 0: this statement will declare an integer type variable and initialized it as 0;
		
		2. printf("Enter a number: "): This statement will print the message on the screen.
		
		3. scanf("%d", &number): this statement will read the value from the user and put that value into number variable.
		
		4. int flag = 1: This statement will declare an integer type variable and initialized it as 1;
		
		5. int i: this statement will declare a integer type variable named as i;
		
		6. for(i=2; i<number; i++): this will start a for-loop. 
		
			inside for-loop:
			* 	printf("%d %% %d = %d\n\n", number, i, number%i):
				This statement will show the  three values in some format. (number , i , and result of number%i)
			
			* if (number % i == 0): this will check that number%i gives 0 or not: if 0 then set flag as 0;
			
			* if (flag == 0): it check that flag value is o or not: if flag value is 0 than stop the loop.
		
		7. printf("%d -- is prime number: %d", number, flag):
			this statement will show the resutl with some message.
	
	 
*/
