#include<stdio.h>

/*
	In this section we will work on unions:
	
	unios are also user-defined data type like structure, but in this we can only store
	single kind of data.
	
	
	st.name = "manish";
	
	union name{
		int integer;
		float floating_value;
		char charcter;
		char[] string;
	}
*/

union var {
	int Int;
	char Ch;
	char String[13];
	float Float;
};

void main(){
	
	union var num;
	
	num.Int = 10;
	num.Ch = 'x';
	
	printf("number : %d\n", num.Int);
	printf("number : %c\n", num.Ch);
	printf("size of num: %d", sizeof(num));
}



