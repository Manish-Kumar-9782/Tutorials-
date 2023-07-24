#include<iostream>
#include<string>

// <return-type> function_name(parameter_list){}
// default parameter;

// int func(int , double=10);

void greeting(std::string msg, std::string to="User");

int add(int, int);
float add(float, float);
double add(double, double);

int main() {

	greeting("you are going to visit principle."); // giving message to default 

	std::cout << std::endl;

	greeting("Hello how are you, i hope your day will be fun.. take care..", "Karan");

	std::cout << "===============================================" << std::endl;

	std::cout << "int add: " << add(23, 45) << std::endl;
	std::cout << "float add: " << add((float)23.45, (float)45.546)<<std::endl;
	std::cout << "double add: " << add(73.45, 65.546)<<std::endl;
	return 0;
}

void greeting(std::string msg, std::string to) {
	std::cout << "Hello " << to << ", " << "You have a message..!" << std::endl;
	std::cout << "Message::=> "<<msg << std::endl;
}


// function overloading.
/*
	1. number of parameter should not match if the are same type.
	2. if number of parameters are same then they must be different type.
	3. if above both condition fails then their return type must be different.
*/

int add(int a, int b) {
	std::cout << "adding integers: " << std::endl;
	return a + b;
}


float add(float a, float b) {
	std::cout << "adding float: " << std::endl;
	return a + b;
}

double add(double a, double b) {
	std::cout << "adding doubles: " << std::endl;
	return a + b;
}