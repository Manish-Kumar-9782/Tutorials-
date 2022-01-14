// in this section we will see how can we return a string from a function.

// Note: we should note that string is a array of character so we will return a pointer basically which will return a base address of the variable
// after which we will read the hole value.

// since we will return a pointer we need to define the return type also as a pointer of character type.

#include<stdio.h>


	// Note: Here we need to define a static or global variable.
	// because after execution of this fucntion location will wipe out form the stack memory.
	// So for this solution we need to make a static or global varaible so our address memory will not wipr.
	// we can alos declare a pointer to stor the address of created memory.
	// function space is allocated in the stack memory area.
	// while pointer variable is stroed  in the heap area. 
	// in both cases we will have a read only values we can not modify them or we can say that they are immutable.
	// -> if we try to modify them they will not give any compile error.
	
char* SetString1(){
	
	static char String[] = "This string is returned from ";
	return String;
}

char* SetString2(){
	
	char* String = "This string is return from a pointer";
	return String;
}


const char* SetString3(){
	// since we want to return the const char* from this function.
	const char* String = "This is a const string return from a pointer";
	return String;
}


void main(){

	char  *String1;
	char *String2;
	const char *String3;
	String1= SetString1();
	String2 = SetString2();
	String3 = SetString3();
	printf("String1: %s\n", String1);
	
	// try to modifying the string2;
	// this modification will not give us any compile time error but it will not show the result as we desired.
	// to get the comile time error we need to use const variable.
	String2[0] = 's';
	printf("String2: %s\n", String2);
	
	// trying to modifying the const string from SetString3 funciton.
	
	String3[1] = 't';
	printf("String3: %s\n");
	
	
	}



