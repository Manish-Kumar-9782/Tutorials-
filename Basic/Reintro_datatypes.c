#include<stdio.h>
//#include<conio.h>

void main(){
	
	char ch; // character type single contain.
	int i; // integer data type.
	float f; // float 
	
	double lf; 
//	bool bl = false;
	
	sizeof(ch);  // operator.
	
	printf("char memory in bytes: %d\n", sizeof(char));
	printf("int memory in bytes: %d\n", sizeof(int));
	printf("float memory in bytes: %d\n", sizeof(float));
	printf("double memory in bytes: %d\n", sizeof(double));
//	printf("bool memory in bytes: %d\n", sizeof(bool));


	printf("\n---------------------------------------------------------------\n");
	
//	printf("short char memory in bytes: %d\n", sizeof(short char));
	printf("short int memory in bytes: %d\n", sizeof(short int));
	printf("long int memory in bytes: %d\n", sizeof(long int));
	printf("long long int memory in bytes: %d\n", sizeof(long long int));
	
	printf("\n---------------------------------------------------------------\n");
	
	int a = -12;  // signed int // long signed int
	
	printf("integer value a: %d\n", a);
	
	unsigned int b = -1116546515;
	
	printf("integer value b: %d\n", b);
	
}
