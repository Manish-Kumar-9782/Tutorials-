#include<stdio.h>


/*In this section we will learn about the 2d array of character sequence and we will see 
how to read and write the 2d array of string.

Here are some rule while woriking on the array of character sequence.

1. an array of character must be ended with a null-character.
2. an charcter array can not be assigned with a string after being initialized.
3. array do not 

*/

void CreateArray();  // Creating an array.
void Assign2DArrayValue();  // a fuction assign some value in a 2d character array.
void Assign2DArrayValue_restricted(); // A function to assign some value in a 2d array by following some restricted rules.

void main(){

//	1. Creating array by using the CreateArray.
//	CreateArray();
	
//	2. Creating a 2d array and assigning some value in the sub array.
//	Assign2DArrayValue();

//	3. Creating a 2d array and assigning some value with some restriction.
	Assign2DArrayValue_restricted();
}

// Creating and reading the array.
void CreateArray(){
	
	char Name2[] = {'K','o','m','a','l','\0'}; // if we initialize the array of character by using the initializer
	// list then we must mention the null-character at the end of the array. 
	// null-character defines the compiler that where 
	
	char Name[] = "Komal"; 
	/* if we initialize the character array by using the duble qoute string, for e.g. "hello" then
	the null-character will be auto added */
	printf("Name: %s", Name);
	printf("\nName2: %s", Name2);
}

/* Assigning some values in an array.
   In this function we will make a 2d array and we will try to assign some values in
   a sub array.
*/
void Assign2DArrayValue(){
	
	// [[6], [6], [6], [6], [6]]
	// "one   two   three four  five  "
	
	
	int i=0;
	char Names[][7] = {"one", "two", "1234567", "four", "five"};
	
	/* Internally the above array is stored in the given format.
	
		Names: [["one"], ["two"], ["1234567"], ["four"], ["five"]]
		
		Names array contain 5 sub array and each array has a length of 7 elements.
		
	*/
	
	/* here first we have initialized the 2d array where each sub array contain the 7 elemnt.
	Note: Here last position in each array should be reserved for null-character.
	
	Here Since we have used the double-qouted string to initilize the array value hence null-character
	is added by default at the last postion of the string.
	*/	
	
//	Now we will assign some character at the position of the 0th element 
//  Since 0th element is also a chracter of array hence we need to use the loop to
//  access each element of sub array so we can assign the values in that sub array.
	for(i=0; i<7; i++){
		scanf("%c", &Names[0][i]);
	}
//	printf("position of i:%d ", i);
//	Names[0][i] ='\0';

	// problems with this approach
	/*
		1. it does not add the null-character at the end of the string.
		
		2. if the input string length is equal to size-1 and input is submitted by using the 
			carrige return or enter key then  ther will be newline charcter present in the string.
			
		3. if the input string is greater than the size of the array then it will merge with the second 
			subarray of the Names array. Because there is no null-character to tell the compiler that 
			where to stop the reading for string.
	*/
	
//	Note: we can make a more restricted function to read and write the string.
	
//	Printing the elements.
	for(i=0; i<5; i++){
	
		printf("\nNames[%d] : %s", i, Names[i]);
	}
	
}


/*
Now we will Make a more restricted function to assign some values into a sub array of an array.
*/
void Assign2DArrayValue_restricted(){
	
	// first we will create an array with some initialized value.
	
	char Names[][7] = {"one", "two", "1234567", "four", "five"};
	
	// Now our task to modify or assign the values into the sub string.
	
	/*
		Note: we can not perfom the direct assignment on the sub-array like this:
		Names[0] = "MyName" // this will give an array.
		
		Problem: Names[0] it gives an adrress of the array/pointer and we are changing the value
			of the address not the value of the Names[0].
			
		Solution: To perform the assignment operation we need to access the each element of the
			selected sub array.
			
		Our plan: In this we will use the do-while loop to perfrom our task with some conditional statement.
		so we can avoid the overflow.
	*/
	
	// since size of the each sub array is 7 so we will use that size.
	
	int i=0;
	char ch; // to read the every character from the input stream/ console.
	int count = 0; // a counter which will count the length of reading string.
	
	// if number of character read by ch is greater then the given array size it will terminate the loop 
	do{
		
		scanf("%c", &ch); // reading each character and storing it in a ch variable.
		
		if(ch != '\n'){
			Names[0][count] = ch;  // if the character is not the '\n' (newline character then assign the value.)
		}
//		printf("character counted: %d\n", count);
		
		if(count>=7-2){   
		// if count count position is reached at the size-2  then assign the null-chracter at the last position
		// and break the loop after assigning the value.
//			printf("count reached its limit.");
			Names[0][count+1] = '\0';  // last position is resereved for the null-character.
			break;
		}
		count++;
	}while( !(ch == '\n' || ch == '\r' ));
	
	
	// Printing the each sub-array values.
	for(i=0; i<5; i++){
	
		printf("\nNames[%d] : %s", i, Names[i]);
	}
	
}
	
// Note: we can use the gets() function or %s format specifier to read the string 
// and assign it to the sub sub array.

