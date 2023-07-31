#include<iostream>
#include<string>

using namespace std;

void square(int& x);
void sqr(int x);
int main() {

	int var1 = 10;
	int var2 = 20;

	int* ptr = NULL; // initalized.

	ptr = &var1;

	int& x1 = var1;

	ptr = &var2;  // pointer refernce can be changed.

	//x1 = var2; // it means value contained by var1 is assigned to x1 variable.

	sqr(var1);

	cout << "square of var1: " << var1 << endl;

}

// this function takes reference of the variable.
void square(int& x) {
	x = x * x;
	cout << "inside square function x is : " << x << endl;
}

// this function takes value of the variable.
void sqr(int x) {
	x = x * x;
	cout << "inside sqr function x is : " << x << endl;
}