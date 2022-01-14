#include<stdio.h>

// Program: In this section we will make a program whihc will compute and display the  inventory report
// suppose that in our invertory we ony have 4 items per day we can restricts items by 4 using define


/*  Item 1: F105 275 575.00
	Item 2: H220 107 99.95
	Item 3: I019 321 215.50
	Item 4: M315 89 725.00
*/
#define ITEMS 4	

// BEGIN OF THE  PROGRAM // 
void main(){
	
	int i, quantity[5];  
	float rate[5], value, total_value;
	char code[5][5];
	
	// initiating i with 1
	i = 1;
	
	// reading the itmes data until all items does't received.
	
	while(i <= ITEMS){
		
		/* Now we will prompt a message to enter the data in an order
		   and then we will input the data by using the scanf function in an order.*/
		   
		printf("Enter code, quantity, and rate: ");
		scanf("%s %d %f", code[i], &quantity[i], &rate[i]);
		i++;
		
		/* Now above code will read all items data, if we have 4 items then we will break this while loop 
		
			-> In above code we asked to user to input code, quantity and rate of an item.
			-> Since code is already a pointer thats why we only need to specify the index number at which we want to store the code number
			-> quantity is an array so we will read all 4 value using index number
			-> rate is also an array so here also we will store all rate corresponding to their porduct with the help of the indexkng.*/
	}
	// Now after reading all items data we need to make a formatted output result so we can read this informtion in simple way.
	/* Table is the best way to display this kind of information So we need to represent all the data in format of table
	   by using the mixed format specifier and flags.*/
	   
	
	/*-----------PRINTING THE HEADING OF TABLE AND THEIR COLUMNS------------------------*/
	printf("\n\n");  // first of all we need to make some newline we can differentiate the result.
	printf("---------INVENTORY REPORT--------\n\n");
	printf("Code\t\tQuantity\t\tRate\t\tValue\n");
	// Now after placing the heading and column names we need to place all the data at their position.
	
	/*---------------PREPARING THE DATA TO DISPLAY THEM AT THEIR RESPECTIVE POSITION--------------*/
	
	total_value = 0;
	i = 1;
	
	while(i <= ITEMS){
		
		value = quantity[i] * rate[i]; // getting the value of each item
		// now we will print the data using their respecitve format specifier
		printf("%-5s\t\t%-10d\t\t%-10.2f\t%-e\n", code[i], quantity[i], rate[i], value);
		total_value += value;
		i++; 
	}
	// Now after displaying all the data we need to display total value.
	printf("\n-----------------------------\n");
	printf("total value = %f", total_value);
	printf("\n-----------------------------\n");
		
}

/*-----------END OF THE PROGRAM-----------*/
