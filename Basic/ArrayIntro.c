#include<stdio.h>

void printArray(int[], int);  //declaration of printArray function char[], float[]
void printArray2(int[], int);

int main(){
	
	int num1[5]; // declaration of array num1
	int num2[5] = {1,2,3,4,5};  // initalization of num2 array.
	int num3[5] = {0};  // initialzing each element of array with zero (0)

	int i=0;
	
	printArray(num1, 5);  // without array notation
	printArray(num2, 5);  // without array notation	
	printArray2(num3, 5);  // wi
	
	printArray2(num2, 5);  // with array notation
	// output:  array:[1,2,3,4,5]
	
	printf("\nEnter num1 array elements: ");
	
	for(i=0; i<5; i++){
		scanf("%d", &num1[i]);
	}
	
	printf("num1 input values: ");
	printArray2(num1, 5);
}

void printArray(int arr[], int size){
	
	int i=0;  // counter for for-loop
	
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void printArray2(int arr[], int size){
//	arr = num2;
// size = 5;
// i != size-1  ; 3 != 4 --> True
	
	
	int i=0;
	printf("array:[");
	
	for(i=0; i<size; i++){
		
		if(i!=size-1){  // 4 != 4 --> Flase
			printf("%d,", arr[i]);
		}
		else{
			printf("%d", arr[i]);
		}
		
	}
	printf("]\n");
}

