#include <iostream>
using namespace std;

/*
    Program::String append: String.append();

    This function is used to extend the string by appending at the end of the current value.

    Syntax::str.append();

    @param:: str: String object which is to be appended in another string object.
    @param:: pos: It determine the position of the first character that is to be
                appended to another object.
    @param:: len: Number of character to be copied in another string object as substring.
    @param:: n: Number of character to copy.
*/

void append1(); // params: str
void append2(); // params: str, pos, len

int main()
{

    string str1;
    string str{"hello"}; // c++11 compiler need to use.

    // using append1 function.
    append1();
    cout << "\n\n"
         << endl;

    // using append2 funciton.
    append2();

    return 0;
}

void append1()
{
    // basic_string& append(const basic_string& str);
    system("cls");
    // suppose that we have two strings
    string str1 = "hello";
    string str2 = "welcome";

    // now if we want to append  str2 at the end of the str1

    cout << "String before append: " << str1 << endl;
    str1.append(str2);
    cout << "String after append: " << str1 << endl;
}

void append2()
{

    string str1 = "hello";
    string str2 = "welcome";

    // now if we want to append  str2 at the end of the str1

    cout << "String before append: " << str1 << endl;
    str1.append(10, '-');
    cout << "String after append: " << str1 << endl;

    //
}
