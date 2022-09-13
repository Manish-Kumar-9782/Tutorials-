#include <iostream>
#include <string>
using namespace std;

/*
    Program::String pop_back: String.pop_back();

    Removes the last character from the string.

    Syntax::str.pop_back();
*/

int main()
{
    // suppose that we have string.
    system("cls");
    string str = "Hello welcome";

    // in this section we want to remove 'e' from the stirng. so we can use the pop_back()
    // method of string object.

    cout << "string before the push_back: " << str << endl;
    str.pop_back();
    cout << "string after the pop_back: " << str << endl;
    return 0;
}
