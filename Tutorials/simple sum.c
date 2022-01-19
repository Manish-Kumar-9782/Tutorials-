#include<stdio.h>

void main(){
	int number[5]={2,5,7,4,6};
	int i;
	int j=0;
	
	
	for(i=0;i<5;i++){
		
		j= number[i]+j;
		printf("%d ",number[i]);
	}
	printf("total sum = %d",j);
	printf("\n");
	
}
