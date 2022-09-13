#include <iostream>
using namespace std;
/*
    Program::String max_size: String.max_size();

    This function returns the maximum length the string can reach due to known system.

    Syntax::str.max_size();

    Note: this funciton does not takes any paramter.

*/

int main()
{

    string str = "Hello world";

    cout << "Our string: " << str << endl;

    cout << "Maximum size of string: " << str.max_size();

    return 0;
}