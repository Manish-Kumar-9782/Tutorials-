#include<stdio.h>

// no return type --> void
void show_odd_even(int x); 
int isOdd(int x);
int isEven(int x);

//===========================================//
void main() {
	int x = 11;
	show_odd_even(x); // testing that our x number is even.

	int even_result =  isEven(x);
	int odd_result = isOdd(x);
	printf("%d is an even number..! : %d\n", x,even_result);
	printf("%d is an odd number..! : %d\n", x,odd_result);

	int y = 21;
	if (isEven(y)) {
		printf("%d is an even number..!  \n", y);
	}
	else {
		printf("%d is an odd number..! \n", y);
	}
}
//===========================================//
void show_odd_even(int x) {
	if (x % 2 == 0) {
		printf("%d is an even number..!\n", x);
	}
	else{
		printf("%d is an odd number..!\n", x);
	}
}

int isOdd(int x) {
	if (x % 2 != 0) {
		return 1;
	}
	return 0; // 0: false
}

int isEven(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0; // 0: false
}