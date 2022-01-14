#include<stdio.h>

/* in this section we will work on the cylinder area expression (formula) and we will calculate 
 
 cylinder area formula  = PI*r*r +  2*PI*r*h  
 
 Here r refers to the redius and h refers to the height of the cylinder.
 
 This is the expression in c to find out the area of the cylinder surface.*/

#define PI 3.14  // defining a constant PI value using define 

void main(){
	
	float r,h, area;
	
	
	printf("Please Enter the redius of your cylinder (dimension in cm): ");
	scanf("%f", &r);
	printf("Please enter the height of the cylinder (dimension in cm): ");
	scanf("%f", &h);
	
	// Now we need to define the formula of the computing the areo of cylinder.
	area = PI*r*r +  2*PI*r*h; 
	
	printf("\n\nCylinder area: %f cm-square", area);
	
	printf("\n\nCylinder area (in formatted)  %.2f cm-square:", area);
	
}


/*  a: acceleration
	h: hight of the body (object)
	v: velocity of the moving object
	m: mass of the moving object
	*/

