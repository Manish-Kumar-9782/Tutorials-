#include<stdio.h>


/* 2d array

	<data-type> <array-name> [2][3]
*/
void main() {

	// simple integer c array
	// i for row --> i=2
	// j for column --> j=3
	int matrix[2][3] = { {10,20,30}, 
						 {90,80,70}};

	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 3; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n=================================\n");

	// character 2d array to store multiple string
	char name[3][10] = { "Bhavya", "Kusha", {'k','u','l','d','e','e','p'}};

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 10; j++) {
			printf("%c", name[i][j]);
		}
		printf("\n");
	}
}