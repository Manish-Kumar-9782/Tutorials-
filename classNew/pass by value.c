#include<stdio.h>

void change(int *a, int *b){
	*a =  *a+ 10;
	*b =  *b+ 10;
}


void main(){
	int a=100, b=200;
	
//	change(a, b);
//	printf("a: %d ", a);
//	printf("b\: %d ", b);
//	
	printf("\n=====================\n");
	change(&a, &b);
	printf("a: %d ", a);
	printf("b\: %d ", b);
}


