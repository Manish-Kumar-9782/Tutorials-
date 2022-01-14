#include<stdio.h>
void main()
{
	int i,b,multi=0;
	
	printf("enter the number");
	scanf("%d",&b);
	
	for(i=0;i<=b;i++)
		multi=multi+i;
	
	printf("total multi %d",multi);
}
