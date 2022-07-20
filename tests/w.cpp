#include<stdio.h> // header files

//#define PI 3.14
const double PI = 3.14;
// PI = 3.14

void Myname();  // declaration of myname function.
void place(); // declaration of myplace function 
double CircleArea(double);

int main(){

	double CArea = 0;
	
	Myname();
	place();
	printf("Hello world \n\n");  //
	
	CArea = CircleArea(2.3);
	printf("Cricle Area : %lf", CArea);
	return 0;
}


void Myname(){
	
	printf("Hello this is Priyanshu");
}

void place(){
	printf(" I am from dause ");
}


double CircleArea(double r){
	
	return PI*r*r;
	
}
