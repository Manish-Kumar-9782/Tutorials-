#include<stdio.h>
/*
*			*
*		  * *
*		* * *
*	  * * * *
*	* * * * *
* 
* // number is spaces per line (space)
* // number of starts per line (stars)
* // total lines (lines)
*/
void main() {

	int lines, spaces, stars;
	int i, j;
	lines = 5;
	spaces = 5;
	stars = 0;
	// outer-loop
	for (i = 0; i < lines; i++) {

		// inner loop
		spaces--;  // in each line one space will be removed.
		stars++; // in each line one star will be added.
		for (j = 0; j < spaces+stars; j++) {
		
			if (j < spaces) {
				printf("  ");
			}
			else {
				printf("* ");
			}
		}
		
		printf("\n");
	}

}