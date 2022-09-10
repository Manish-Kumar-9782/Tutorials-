#include <iostream>
using namespace std;

/*
    Program::String substr: String.substr();

    Now in this section we will see that how to get the substring from an existing string
        by using the substr method.

    Syntax:: str.substr(int pos, int n) -> string;

    @param:: pos: position from which we need to get the substring.
    @param:: n  : number of character to get after the specified position.
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
