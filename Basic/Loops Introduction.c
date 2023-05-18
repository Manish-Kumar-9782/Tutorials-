#include<stdio.h>

/*
	In this section we will see what are loops, types of loops and when we 
	should use loops.
	
	loop: loop is basically a cyclice execution of statement in a block again 
	and again until we don't tell them to stop. after stoping the loop comes
	out of the loop and exeucte the other statement which are placed out of
	that loop.
	
	Loop: 
		1. while loop
		2. for loop
	
	whlie loop: it is generally used whenever we don't know the termination point
		or in other word that we don't know that how much time loop will run.
	
	cycle => iteration.
	
	basic example: reading a file.
	
	for loop: it is generally used whenever we know that when will our loop 
		end.
		
	basic example : computing sum, counting.
	
	----------------------------------------------------------------------
	syntax of for loop: 
		for(initialization; condition; step/increment/decrment){
			// statements with counter variable
			// initialized in for loop.
		}
		
	sudocode:
		1. use `for` keyword.
		2. after `for` we use () parantesis;
		3. in () we define three things
			a. initializing a counter varaible which will be used to 
				termiate our for loop or used in other computation
				inside the code block.
			2. condition: it will decide that when will our loop end.
			3. step/increment/decrement: it will increase or decrease the 
				counter variable value.
				
				
	----------------------------------------------------------------------
	
	syntax of while loop:
		while(condition){
			// statments.
		}
		
	sudocode:
		1. first we write `while` keyword.
		2. after this we put `()` paranthesis.
		3. inside () we put the termination condition.
		4. after that make a block {} and put some statement
		5. make a loop terminating point inside the loop.
		
	we have do_while() loop also.
*/

void main(){
	
	// first of all make variable as conter variable for `for-loop`.
	// int i = 0;
	
	int i =0;
	
	for(i=0; i<=10; i += 3){
		printf("i: %d\n", i);
	}
	
}
