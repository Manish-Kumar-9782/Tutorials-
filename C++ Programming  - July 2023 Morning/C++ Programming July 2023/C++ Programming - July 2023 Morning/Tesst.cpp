#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void printArray(vector<int>&);
void change(int x);

int main() {

	int* p = NULL; // contains address

	int value = 10;
	int value2 = 20;

	// it also contains address/ alias name of the variable.
	int& x = value;  // initialized during declaration.


	vector<int> numbers = { 1,2,3 };
	

	// int arr[]


	printArray(numbers);

	// adding a new number to array.
	numbers.push_back(10);
	printArray(numbers);


	
	x = value2; 
	cout << "value: " << value << endl;
	cout << "x: " << x<<endl;

	x = 30;


	cout << "value2: " << value2<<endl;

	cout << "value: " << value<<endl;

	//vector<int> numbers = {1,2,3};

	change(value);

	cout << "square of value: " << value << endl;
	
}


// Range For loop
void printArray(vector<int>& arr) {

	for (int value : arr) {
		cout << value <<" ";
	}
	cout << endl;
}


void change(int x) {
	x = x*x;
}