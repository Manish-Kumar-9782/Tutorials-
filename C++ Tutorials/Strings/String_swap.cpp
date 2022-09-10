#include <iostream>
using namespace std;

/*
    Program::String swap: String.swap();

    In this section we will see that how to exchange the values or swap the string values.
        by using the swap method of string object.

    Syntax: str.swap(string& str) -> None;

    @param:: str: string which need to be swap with the another string.
*/

int main()
{

    string str1, substr;

    str1 = "hello is a string test to get the substrig";

    substr = str1.substr(11, 11);

    cout << "sub-string in b/w 11-22:\t" << substr << endl;

    return 0;
}
