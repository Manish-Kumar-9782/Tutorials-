#include<stdio.h>
#include<math.h>
// Program: In this seciton we will see a reliablility graph of an electronic component is given by f(r) = exp(-LAMBD*r)

# define LAMBDA 0.001

void main(){
	
	double t;
	int i, R;
	float r;
	
	printf("Reliablility Graph of an Electronic Component\n");
	
	// printing a border line of the for the graph
	for (i=0; i<= 27; i++){
		printf("__");
	}
	// after making the border line we need to print  the points for the grph.
	// making a newline for starting the points for graph
	printf("\n");
	
	// printing points according to the equations.
	for (t=0; t<=3000; t+=150){
		r = exp(-LAMBDA*t);
		R = (int)(50*r+0.5);
		
		printf(" |");
		
		for (i=1; i<=R; ++i){
			printf("*");
		}
		
		printf("#\n"); // printing the last point as # 
		
		/*for(i = 1; i<3; ++i){
			
			printf(" |\n");
		}*/ // this code is optional to put two newline b/w each ** line	
	
	}
	
}
