#include<stdio.h>

// top global scope user-defined declaration are contained here

// Now we will define our main entry point for our program

// 8bits --> 1byte 
// a --> 	01100001

// integer: int
// float: float
// double: double
// character: char
// boolean: true-> 1, false-> 0

// to modify the range for each data type, unsigned, short, long

// syntax: <data-type> <variable>;  declaring our varible.
// syntax: <data-type> <variable> = <value>; // declaration & intialization  

//=============================================//
void main(){
	// printf --> console.log()
	printf("Hello world!\n");
	
	// variables
	
	int number = 4; // 4byte
	// %d --> signed integer, int
	char ch= 'a';
	
	// floating point number with float and double
	float fNumber = 3.14; // pi
	
	// double number
	double dNumber = 3.14; // double pi
	
	printf("Size of our number %d\n", sizeof(number));
	
	printf("Size of our character %d\n", sizeof(ch));
	
	printf("Size of our float number %d \n", sizeof(fNumber));
	
	printf("Size of our double number %d \n", sizeof(dNumber));
		
}

//=============================================//
