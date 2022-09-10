#include <iostream>
using namespace std;

/*
    Program::String substr: String.replace();

    This function replaces the portion of the string that begins at character position
        pos and spans the len characters.

    Syntax::str.replace(pos,count,str)

    @param:: pos: start of the substring that is going to be replaced.
    @param:: count: length of the substring that is going to be replaced.
    @param:: len: range of the characters that is going to be replaced.
    @param:: first,last: range of characters that is going to be replaced.
    @param:: str: string to use for replacement.
    @param:: pos2: start of the substring to replace with.
    @param:: count2: number of character to replace with.
    @param:: cstr: pointer to the character to replace with.
    @param:: ch: character value to use for replacement.
    @param:: first2, last2: range of characters to use for replacement.
    @param:: ilist: initializer list with the characters to use for replacement.


    Note: all these paramters are taken from the different-different overloaded replace method.
*/

void replace1(); // params: pos, count, str
void replace2(); // params: first, last, str

int main()
{

    string str1;

    str1 = "hello this is string test";

    // Now we will use the length function and will store the returned value

    int len = str1.length();

    cout << "Str length: " << len << endl;

    return 0;
}

void replace1()
{
    // this will use the function
    /*
        basic_string& replace( size_type pos, size_type count, const basic_string& str );


    */
}