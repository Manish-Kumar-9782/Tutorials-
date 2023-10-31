#include <iostream>
#include <string>

using namespace std;

/*
    Function Overloading:

    we have multiple functions by same name but with different:

    1. return type.
    2. number of parameters
    3. type of parameter
*/

int add(int a, int b)
{
    cout << "adding integer values: " << endl;
    return a + b;
}

double add(double a, double b)
{
    cout << "adding double values: " << endl;
    return a + b;
}

int main()
{
    cout << "sum of integers: " << add(1, 2);
    cout << "\n\nsum of doubles: " << add(4.3, 4.5);
    return 0;
}