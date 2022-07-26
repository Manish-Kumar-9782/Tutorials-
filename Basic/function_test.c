#include<stdio.h>

int add(){
	
	int a = 10;
	int b = 20;
	int c = a+b;
	
	return c;
}
 
int a;
void main(){
	
	int x = add();
	printf("result of add : %d", x);
	
}

