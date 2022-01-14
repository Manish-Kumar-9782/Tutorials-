/*	Program: A survey to known the popularity of four cars (Ambassador, fiat, Dolphin and Maruti)
	was conducted in four cities (Bombay, Calcutta, Delhi and Madras). Each person surveryed was 
	asked to give his city and type of car he was using. The result, in coeded form ar tabulated as 
	follows:
	
	M 1 C 2 B 1 D 3 M 2 B 4
	C 1 D 3 M 4 B 2 D 1 C 3
	D 4 D 4 M 1 M 1 B 3 B 3
	C 1 C 1 C 2 M 4 M 4 C 2
	D 1 C 2 B 3 M 1 B 1 C 2
	D 3 M 4 C 1 D 2 M 3 B 4
	
	M - Madras			1-Ambassdor
	D - Delhi			2-Fiat
	C - Calcutta 		3-Dolphin
	B - Bonbay			4-Maruti
	
	Write a program to produce a table showing popularity of various cars in four cities.

*/

#include<stdio.h>

void main(){
	
	int i, j, car;
	int frequency[5][5] = {{0}, {0}, {0}, {0}, {0}}; // all other elements will be initialized automatically to zeros.
	// frequecny arrays stores the as frequency[Cities][Cars]	
	char city; // to store the city code.
	
	printf("For each person, enter the city code \n");
	printf("Followed by the car code.\n");
	printf("Enter the letter X to indicate end.\n");
	
	/*-----------TABULATION BEGINS------------------*/
	
	for(i=1; i<100; i++){
		
		scanf("%c", &city);
		
		if(city == 'X')
			break;
		scanf("%d", &car);
		
		// Now we will count the total cars in each cities by using the switch statements.
		
		switch(city){
			// in this we are increasing the counting of each car in each city.
			case 'B': frequency[1][car]++;
					break;
					
			case 'C': frequency[2][car]++;
					break;
					
			case 'D': frequency[3][car]++;
					break;
			
			case 'M': frequency[4][car]++;
					break;
		}
	}
	// in this above for loop we have read all the values in which we have counted all the cars in each city.
	
	/*------------------------TABULATION COMPLETD AND PRINTING BEGINS---------------------------------*/
	
	// Now we need to print all the computed information in the form of frequency table.
	
	printf("\n\n Popularity Table\n\n");
	printf("____________________________________________\n");
	
	// Now we will print the Heading of Columns of the table
	printf("City   Ambassdor   Fiat   Dolphin   Maruti\n");
	printf("____________________________________________\n");
	
	// now we need to print the table , since we want to print also the names of cities as index of each columns
	// so for that we need to make another switch statement which will print cities names according to the index number.
	
	for(i=1; i<=4; i++){
		
		switch(i){
			
			case 1: printf("Bombay	");
					break;
						
			case 2: printf("Calcutta");
					break;
				
			case 3: printf("Delhi	");
					break;
				
			case 4: printf("Madras	");
					break;
				
			/*Note: we avoid this switch statement by using another array variable as cities 
					which will hold all the citis name with their respecitve codes and we can 
					print them with thier respecitve code, with this array we dont need this switch statement.
			*/
				}
		// getting out from the switch statements.
		
		// Now we need to print the data by printing the each row.
		for(j=1; j<=4; j++)
			printf("%7d", frequency[i][j]);
		
		// Now we need to make a newline also after finishing each row.
		printf("\n");
		
	}
	printf("____________________________________________\n");
	/*----------------------END OF THE PRINTING OF TABLE--------------------*/
}
