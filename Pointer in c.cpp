#include <stdio.h>
#include<stdlib.h>

void add_one(int *x){
	*x +=1;
}

int main(void){
	
	int y =2337;
	printf("y = %d\n",y);
	add_one(&y);
	
	printf("y = %d\n",y);
	return 0;
}
