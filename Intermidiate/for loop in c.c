#include<stdio.h>

/*
	In this section we will work on th for loop.
	Program: print counting form 1 to 10.
*/

void main(){
	
	// first of all make counter varaible.
	int i =0; // declaraing and initializing the counter varaible.
	
	// now we make for loop
	for(i=1; i<=10; i++){
		printf("%d\n", i);
	}
	
	// i++: increasing the i by one in each iteration.
	
	/*
		Explanation:
		
		1. at initialization: i will be registered as the counter 
		variable and initalized with 1;
			Note: we will not initialize our counter varaible `i` form 0
			because we want to print counting from 1 to 10. 
			
			so for that we need to initialize the i with 1 and increase i with 
			step 1, terminate the for loop when i becomes equal > 10.
			
			termination condition: i <= 10
			
		2. we are printing the  i value in each iteration, and i is changing
			increasing in each iteration by 1.
	*/
	
}
