#include <stdio.h>
#include <stdlib.h>

int main(){
	// type casting expression
	// (type_name) expression
	
	int sum =17, count=5, total;
	double mean;
	
	mean = (double) sum/count;
	// to convert the double
	total = (int) sum/ count;
	printf("%f\n",mean);
	printf("%d\n",total);
	
	
}
