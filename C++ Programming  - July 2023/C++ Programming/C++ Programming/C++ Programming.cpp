#include<iostream>
#include<string>
// :: scope resolution operator

// std::cout --> output object
// std::cin --> input object

int main() {
	int a = 10;
	float f = 3.15;
	std::string str;

	
	std::cout << "Hello World..!" << std::endl;

	std::cout << "my number is: " << f << std::endl;

	std::cout << "Enter any number: ";
	std::cin >> a;

	std::cout << "You have Enter Number: " << a << std::endl;

	std::cout << "Enter you name: ";
	
	std::cin.ignore();
	std::getline(std::cin, str);

	std::cout << "Your Name: " << str << std::endl;

	return 0;
}