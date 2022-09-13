#include <iostream>
#include <string>
using namespace std;

/*
    Program::String push_back: String.push

    This function is used to appends the given character ch to the end of the string.

    Syntax::str.push_back(ch);

    ch: The character to append.
*/

int main()
{
    system("cls");
    // suppose that we have string.

    string str = "Hello welcom";

    // in the above string 'e' is missing from the 'weclome' word, so we can use the push_back
    // function to append the character in the string.

    cout << "string before the push_back: " << str << endl;
    str.push_back('e');
    cout << "string after the push_back: " << str << endl;
    return 0;
}
