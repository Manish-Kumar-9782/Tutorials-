#include<stdio.h>

/*
	if else statement
	
	syntax:
		if(condition){
			// if body block
		}
		 else{
			// else body block
		}

		/ if 'if-statement` is false (condition == false) then else statement definitely will run.
		// 

		number: n1 < n2; -->  {less than, greater than, equal}

		if (a == "b")


		switch(ch){
		
			case 'a': {}
			case 'b': {}
			case 'c': {}
			default:{}

		}

*/

void main() {

	int a = 20, b = 20;

	if (a < b) {
		printf("a is less than b\n");
	}
	else {
		printf("a is greater than or equal to b\n");
	}

	// making three condition foe each case.
	if (a < b) {
		printf("a is less than b \n");
	}
	else if (a > b) {
		printf("a is greater than b \n");
	}
	else {
		printf("a is equal to b \n");
	}
	
	char ch = 'g'; // '\0' null character

	// 'r': red, 'g': green, 'y':yellow, default: failed
	switch (ch) {

	case 'r': {
		printf("Signal is red, Please Stop..");
		break;
		}
	case 'g': {
		printf("Signal is green, you can go..");
		break;
	}
	case 'y': {
		printf("Signal is yellow, Please Be Careful..");
		break;
	}
	default: {
		printf("Signal is broken, call traffic police..");
		break;
	}
	}
	getch();
}
