#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//	to use malloc without warning.

int something(int a)
{
	//	this method should return square and cube.
	int square = a * a;
	int cube = square * a;

	return cube, square;
}
//	1. method 1 to return mutliple values by using structure.

typedef struct two
{
	int x;
	int y;
} two;

two return_two_values(int a)
{

	two values;

	values.x = a * a;
	values.y = a * a * a;

	return values;
	//	returning a copy of the values data.
}

//	2. method 2 two return multiple values from a function.

int *return_mutliple_values(int a)
{
	/*
		This mehtod can return multiple values but the disadvatage it that it can only
		return single data type values.
	*/
	int *arr = (int *)malloc(sizeof(int) * 2);
	//	 memory of heap area.
	arr[0] = a * a;
	arr[1] = a * a * a;
	// returning the base address of the array.
	return arr;
}

// 3. Method 3 to return multiple values and multiple data type values.

/*
	Condition:
		1. We must have Union prdefined for returning data types.
		2. Make an pointer with the defined space.
*/

typedef union data_types
{
	//	Note: union can take only single value at a time
	//	it does not work as structure.
	int Integer;
	char String[30];
	float Float;
	double Double;
} datatypes;

datatypes *return_n_values()
{

	datatypes *rvalue = (datatypes *)malloc(sizeof(datatypes) * 4);

	rvalue[0].Integer = 123456;
	strcpy(rvalue[1].String, "Komal Saloni Abhishek");
	rvalue[2].Float = 234.56;
	rvalue[3].Double = 324235435.345345;

	return rvalue;
}

void main()
{
	//	int value = something(10);
	//	printf("values: %d", value);

	// two get_values = return_two_values(3);

	// printf("square of a: %d\n", get_values.x);
	// printf("square of a: %d\n", get_values.y);

	// int *get = return_mutliple_values(4);
	// printf("square of a: %d\n", get[0]);
	// printf("square of a: %d\n", get[1]);

	datatypes *data = return_n_values();

	printf("Integer valuea: %d\n", data[0].Integer);
	printf("String valuea: %s\n", data[1].String);
	printf("Float valuea: %f\n", data[2].Float);
	printf("Double valuea: %lf\n", data[3].Double);
}
