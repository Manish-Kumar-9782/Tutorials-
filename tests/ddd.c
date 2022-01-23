#include<stdio.h>

void main(){
	
	int arr[6] = {15,98,64,4};
	int *p;
	
	p = arr;
	
	
	printf("1st Value: %d\n", *p);
	
	// moving tho next element;
	p++;
	
	printf("2nd Value: %d\n",*p );
	
	
	printf("3rd Value: %d\n", *(arr+2));

	printf("3rd Value 2[arr]: %d\n", 2[arr]);
	
	printf("3rd Value arr[2]: %d\n", arr[2]);
	
	
	printf("Address increment arr+1: %d\n", arr+1);
	printf("Address increment arr+2: %d\n", arr+2);
	printf("Address increment arr+3: %d\n", arr+3);
	printf("Address increment arr+4: %d\n", arr+4);
	printf("Address Increment &arr+1: %d\n", &arr+1);	
	
}
