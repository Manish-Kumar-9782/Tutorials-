#include <iostream>
using namespace std;

/*
    Program::String length: String.length()

    In this section we will see that how to use the String length function to calculate
        the string length.

    Note: This is the actual number of bytes that conform the contents of the string, which
        is not necessarily equal to the storage capacity.

    Syntax: str.length() -> interger;
*/

int main()
{

    string str1;

    str1 = "hello this is string test";

    // Now we will use the length function and will store the returned value

    int len = str1.length();

    cout << "Str length: " << len << endl;

    return 0;
}
