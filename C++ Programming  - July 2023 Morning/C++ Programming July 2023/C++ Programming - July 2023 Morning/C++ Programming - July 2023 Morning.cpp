#include<iostream>

// iostream std namespace.
// using namespace std;

// cin : console input , istream.
// cout: console output, ostream.
// properties, attribute, data members.
// methods, function defined within the objects.

// cin cout  contained inside a name space called std.

// :: scope resolution operator.

int main() {

	int a = 10;
	std::cout << "Hello world.." << std::endl;

	// to get the input from user we use cin object.

	/*
	std::cout << "Enter a number: ";
	std::cin >> a;
	*/

	std::cout << "your input number: " << a;

	return 0;
}