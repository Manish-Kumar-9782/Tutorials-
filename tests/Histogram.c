// Program :Make a hitogram by given data input

#include<stdio.h>

#define N 5

void main(){
	
	int value[N];  // initializing an array with max items 5.
	int i, j, n, x;
	
	// Now we need to input the value of each histogram.
	
	for(i=0; i<=N; i++){
		
		// Now here we will iterate the loop upto Maximum N value
		// and we will store all the values into the value array.
		printf("Enter the group-%d:  ", i);
		scanf("%d", &x); // first we will store the value of group into x
		value[i] = x; // then this value will pass to the value[i] positon in the value array.
		
		// Note: value array contains all the values which is inputted by the user.
	}
	
	// making a new line in the output terminal
	printf("\n");
	printf("|\n");
	
	for(n=0; n < N; ++n){
		
		for (i=1; i<=3; i++){  // this loop will help us to draw three lines.
			
			if (i==2)
				printf("Group-%1d |", n+1);  // placing the Group lable text at the mid of the bar.
			else
				printf("        |");  // aligning the axis lines
			
			for(j=1; j<=value[n]; ++j)
				printf("*"); // making points of the historgram.
				
			if(i==2)
				printf("(%d)\n", value[n]); // Putting the value at the mid line to show that how much value that group have.
			else
				printf("\n"); //  after end of the each draw of line of a bar we will draw next line.
		}
		printf("\n");
	}
}
