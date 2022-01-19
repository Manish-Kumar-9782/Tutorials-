#include<stdio.h>
void main(){
	
	int subject_number[5]={50,40,35,45,60};
	int i;
	int total_number=0;
	for(i=0;i<5;i++){
		
		total_number= subject_number[i]+total_number;
		printf("%d ",subject_number[i]);
		
		
	}
	printf("total number obtained =%d",total_number);
	
}
