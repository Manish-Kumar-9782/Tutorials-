#include<stdio.h>

/*
	switch(variable){

		case constant_value-1:
			 // statement one
			 break;

		case constant_value-2:
			// statement two
			break;

		default:
			// default case statement
	}
*/

void main() {

	int value = 2;
	switch (value) {

	case 1:
		printf("this is case 1.");
		break;
	case 2:
		printf("this is case 2.");
		break;
	case 3:
		printf("this is case 3. ");
		break;

	default:
		printf("This is default case...!");
	}

	printf("\n\n========================================");

	char traffic_light = 'x'; // \0 null character
	switch (traffic_light) {

	case 'g':
		printf("Signal is green you can go..");
		break;
	case 'r':
		printf("Signal is red you please stop...");
		break;
	case 'o':
		printf("Signal is orange please be careful...");
		break;

	default:
		printf("Traffic light system has been failed, Please call traffic police...");
	}


	printf("========================================\n\n");
}