#include <iostream>
using namespace std;

/*
    Program::String resize: String.resize();

     This function is used to resize the string from length k number to c numbers.

    Syntax:: str.size(k, c) -> integer;

    @param:: k: it is the number of the characters specified in the first parameter.
        it resize the string such that string contains k characters.

        -> if k is shorter than the length of the string, string length shortened to the
            length specified by k, removing all characters beyong k.

        -> if k is large than the length extended to the length specified by k.

    @param:: c: c is a new character to be added in a new space, if k is larger than
        the length of the string.

    Syntax:: str.resize(k,c) -> None;


*/

void example1(); // decreasing the length of string.
void example2(); // increasing the length of string.

int main()
{

    example1();

    cout << "\n\n";

    example2();

    return 0;
}

void example1()
{
    string str1;

    str1 = "hello  Welcome";

    cout << "String before resizing: " << str1 << endl;

    str1.resize(5);

    cout << "String after resizing: " << str1 << endl;
}

void example2()
{
    string str1;
    int new_size;

    str1 = "hello  Welcome";
    new_size = str1.length() + 7;

    cout << "String before resizing: " << str1 << endl;

    str1.resize(new_size, 'a');

    cout << "String after resizing: " << str1 << endl;
}
