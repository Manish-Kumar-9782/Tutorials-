#include<stdio.h>

//	In this section we will make a function which will return  multiple values by using the 
// structures.

// Now we will make two structure which will be used to hold the valued to be returned.


typedef struct two{
	int x;
	int y;
	// Note in this section we are taking same data type value we can use any kind of values.
}two;

typedef struct three{
	int x;
	int y;
	int z;
}three;

void swap(int *a, int *b){
	int x;
	
	x = *a;
	*a = *b;
	*b = x;
}

// Now we will make a function to return some values.

/*
	These function will take an array of integer and they will return the two 
	and three largest values.
	
	These values will be stored in the structure two or three type variable.

	Note: the return type should be same as the structure will be returned.
*/

two return_two_largest_values(int arr[], int size){
//	This function will take an array of integer an will return the two largest values.
//  This function will consider that at least we have two element in our array.

//	Now first of all we will make an struct two vairable to hold the two values.
	two rvalue = {-1,-1};
	int large1, large2;
	
	if(size < 2){
		printf("size should be greater then or equal to 2.");
		return rvalue;
	}
		
	
	if(size == 2){
		large1 =  arr[0];
		large2 =  arr[1];
		
		if(large1 > large2){
			rvalue.x = large1;
			rvalue.y = large2;
			return rvalue;
		}
		else{
			rvalue.x = large2;
			rvalue.y = large1;
			return rvalue;
		}
	}
	else{
		//	Now we need to make the logic to find the two largest nubmber.
		int i=0;
		large1 =  arr[0];
		large2 =  arr[1];
		for(i=2; i<size; i++){
			
			if (arr[i] > large1){
					large2 = large1;
					large1 = arr[i];
				}	
			}	
	}
	
	if(large2 > large1){
		swap(&large2, &large1);
	}
		
	
	rvalue.x = large1;
	rvalue.y = large2;
	return	rvalue;
}

three return_three_largest_values(int arr[], int size){
//	This function will take an array of integer an will return the three largest values.
//  This function will consider that at least we have three element in our array.

//	Now first of all we will make an struct three vairable to hold the two values.
	three rvalue = {-1,-1,-1};
	int large1, large2, large3;
	two two_value= {0,0};
	
	if(size < 3){
		printf("size should be greater then or equal to 3.");
		return rvalue;
	}
		
	
	if(size == 3){
		large1 =  arr[0];
		large2 =  arr[1];
		large3 = arr[2];
		int i =0;
		two_value = return_two_largest_values(arr, 3);
		
		for(i=0; i<3;i++){
			if(arr[i] < two_value.y)
				rvalue.x = two_value.x; rvalue.y = two_value.y; rvalue.z = arr[i];

		}
		return rvalue;
	}
	else{
		//	Now we need to make the logic to find the two largest nubmber.
		int i=0;
		large1 =  arr[0];
		large2 =  arr[1];
		large3 = arr[2];
		for(i=2; i<size; i++){
			
			if (arr[i] > large1){
					large3 = large2;
					large2 = large1;
					large1 = arr[i];
				}	
			}	
	}
	
	if(large2 > large1)
		swap(&large2, &large1);
	
	rvalue.x = large1; rvalue.y = large2; rvalue.z = large3;
	return	rvalue;
//	returning three values.
}


void main(){
	int numbers[11] = {12,34,54,69,320,503,439,232,534,283,682};
	int threes[3] = {4,9,6};
	
	two largest;
	three large_three;
	
	largest = return_two_largest_values(numbers, 11);
	printf("largest 1:  %d\n", largest.x);
	printf("largest 2:  %d", largest.y);
	
	
	large_three = return_three_largest_values(numbers, 11);
	printf("\n\nlargest 1:  %d\n", large_three.x);
	printf("largest 2:  %d\n", large_three.y);	
	printf("largest 3:  %d", large_three.z);
	
}





