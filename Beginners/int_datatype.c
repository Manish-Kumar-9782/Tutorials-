/*
	In this section we will learn that why we need differnt kind of data and how to use those different kind 
	data to store.
	
	In this section we will see about the different kind of integer data type which is used to hold differnet range
	values.
	we have different kind of integer types to store the data according to range of the data type.
	
		Data Type           Size in bytes           Range
|-------------------------------------------------------------------|
int                      	4                       2147483647
singned int              	4                       2147483647
unsigned int             	4                       4294967295
short signed int         	2                       32767
short unsigned int       	2                       65535
long singed int         	4                       2147483647
long unsigned int        	4                       4294967295
long long signed int     	8                       9223372036854775807
long long unsigned int   	8                       18446744073709551615

*/


#include<stdio.h>
#include<math.h>

int main(){
	
	// Note: datat type size will be according to the n-bit machine.
	// For now we are using a 32-bit machine
	
	int INT_SIZE 	= sizeof(int);
	int SINT_SIZE 	= sizeof(signed int);
	int UINT_SIZE	= sizeof(unsigned int);
	int HSINT_SIZE 	= sizeof(short signed int);
	int HUINT_SIZE 	= sizeof(short unsigned int);
	int LSINT_SIZE	= sizeof(long signed int);
	int LUINT_SIZE	= sizeof(long unsigned int);
	int LLSINT_SIZE = sizeof(long long signed int);
	int LLUINT_SIZE = sizeof(long long unsigned int);
	
	
    
	printf("%-20s \t %-20s \t %-20s\n", "Data Type", "Size in bytes", "Range");
	printf("|-------------------------------------------------------------------|\n");
	//---------------------------------------------------------------------//
	
	printf("%-20s \t %-20d \t %-20d\n", 	"int",						INT_SIZE, 		(int)pow(2, INT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20i\n", 	"singned int", 				SINT_SIZE, 		(signed int)pow(2, SINT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20u\n", 	"unsigned int", 			UINT_SIZE, 		(unsigned int)pow(2, UINT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20hi\n", 	"short signed int",			HSINT_SIZE, 	(short signed int)pow(2, HSINT_SIZE*8-1)-1);
	printf("%-20s \t %-20d \t %-20hu\n", 	"short unsigned int",		HUINT_SIZE, 	(short unsigned int)pow(2, HUINT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20li\n", 	"long singed int",			LSINT_SIZE, 	(long signed int)pow(2, LSINT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20lu\n", 	"long unsigned int",		LUINT_SIZE, 	(long unsigned int)pow(2, LUINT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20lli\n", 	"long long signed int",		LLSINT_SIZE, 	(long long signed int)pow(2, LLSINT_SIZE*8)-1);
	printf("%-20s \t %-20d \t %-20llu\n", 	"long long unsigned int",	LLUINT_SIZE, 	(long long unsigned int)pow(2, LLUINT_SIZE*8)-1);
	
}
