#include <stdio.h>
#include <stdlib.h> // to use the malloc without warning.

//	In this section we will make a function which will return  multiple values by using the
// array which will be created dynmically.

// In this section we don't have make the structure since we will use the array reference.

void swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

// Now we will make a function to return some values.
/*
	These function will take an array of integer and they will return the two
	and three largest values.

	These values will be stored in the dynamically created array.

	Note: return type should be a int* for integer values which will be returned.
*/

int *return_two_largest_values(int arr[], int size)
{
	//	This function will take an array of integer an will return the two largest values.
	//  This function will consider that at least we have two element in our array.

	//	Now first of all we will make an struct two vairable to hold the two values.

	//	int large1, large2;
	int *values = (int *)malloc(sizeof(int) * 2);
	;
	// Her we need to make a pointer

	if (size < 2)
	{
		printf("size should be greater then or equal to 2.");
		return values;
	}

	if (size == 2)
	{
		values[0] = arr[0];
		values[1] = arr[1];

		if (values[0] > values[1])
		{
			return values;
		}
		else
		{
			swap(&values[0], &values[1]);
			return values;
		}
	}
	else
	{
		//	Now we need to make the logic to find the two largest nubmber.
		int i = 0;
		values[0] = arr[0];
		values[1] = arr[1];
		for (i = 2; i < size; i++)
		{

			if (arr[i] > values[0])
			{
				values[1] = values[0];
				values[0] = arr[i];
			}
		}
	}

	if (values[1] > values[0])
	{
		swap(&values[1], &values[0]);
	}

	return values;
}

int *return_three_largest_values(int arr[], int size)
{
	//	This function will take an array of integer an will return the three largest values.
	//  This function will consider that at least we have three element in our array.

	//	Now first of all we will make an struct three vairable to hold the two values.

	int *values = (int *)malloc(sizeof(int) * 3);
	//	creating a dynamic memory for three values.

	if (size < 3)
	{
		printf("size should be greater then or equal to 3.");
		return values;
	}

	if (size == 3)
	{
		values[0] = arr[0];
		values[1] = arr[1];
		values[2] = arr[2];
		int i = 0;
		int *two_largest = return_two_largest_values(arr, 3);

		for (i = 0; i < 3; i++)
		{
			if (arr[i] < two_largest[1])
			{

				values[0] = two_largest[0];
				values[1] = two_largest[1];
				values[2] = arr[i];
			}
		}
		return values;
	}
	else
	{
		//	Now we need to make the logic to find the two largest nubmber.
		int i = 0;
		values[0] = arr[0];
		values[1] = arr[1];
		values[2] = arr[2];
		for (i = 3; i < size; i++)
		{
			if (arr[i] > values[0])
			{
				values[2] = values[1];
				values[1] = values[0];
				values[0] = arr[i];
			}
		}
		return values;
		//	returning three values.
	}
}

void main()
{
	int numbers[11] = {12, 34, 54, 69, 320, 503, 439, 232, 534, 283, 682};
	int threes[3] = {4, 9, 6};

	int *two_values;
	int *three_values;

	two_values = return_two_largest_values(numbers, 11);
	printf("largest 1:  %d\n", two_values[0]);
	printf("largest 2:  %d", two_values[1]);

	three_values = return_three_largest_values(numbers, 11);
	printf("\n\nlargest 1:  %d\n", three_values[0]);
	printf("largest 2:  %d\n", three_values[1]);
	printf("largest 3:  %d", three_values[2]);
}