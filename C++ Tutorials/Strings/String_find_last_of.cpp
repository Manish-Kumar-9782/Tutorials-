#include <iostream>
using namespace std;

/*
    Program::String find_last_of(): str.find_last_of();

    This function is used for finding the location of first occurance of the specified
    characters.

    Syntax::str.find_last_of(str); --> (1)
    Syntax::str.find_last_of(str,pos); --> (1)
    Syntax::str.find_last_of(ch, pos, n); --> (2)

    1) Finds the last character equal to one of the characters in str.
    2) Finds the last character equal to one of the characters in the range [s, s+n).
        This range can include null characters.

    @param:: str: string to be searched in our string.
    @param:: pos: position at which the search is to finish.
    @param:: n: length of character string identifying characters to search for.
    @param:: ch: Character to be searched in the string.

    return value: it returns the position of the last occurance if found else it
        will return string::npos value.
*/

void find_last_of1(); // params: str
void find_last_of2(); // params: str, pos
void find_last_of3(); // params: ch, pos

int main()
{

    // 1. find1
    find_last_of1();
    printf("\n\n");
    find_last_of2();
    printf("\n\n");
    find_last_of3();

    return 0;
}

void find_last_of1()
{

    // in this we will use the  below function syntax, which will take a string to be searched
    // Syntax::str.find_last_of(str);

    string str = "fhon yes well is good";

    //  Now we have a string in which we need to find the the given character, it will return the
    // index number of the character (the character whichever will be found first.)
    int n = str.find_last_of("jailg");

    if (n == string::npos)
    {
        cout << "No match found.";
    }
    else
    {
        cout << "found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_last_of2()
{
    // in this section we will use the below sytax funciton, which will take a str and pos
    // from where we need to search the string.

    // string::npos  is used to give the number which will be returned when there is no match found
    // in the given string.
    string str = "jhon, all is well is good";

    // matching any character from "iae" to the str.
    int n = str.find_last_of("ei", 15);

    if (n == string::npos)
    {
        cout << "No match found.";
    }
    else
    {
        cout << "found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_last_of3()
{
    // in this section we will the function, whose syntax is defined at below.

    string str = "jhon, all is well is good";

    // matching only one character.
    int n = str.find_last_of("a");

    if (n == string::npos)
    {
        cout << "string is not found.";
    }
    else
    {
        cout << "found '" << str.at(n) << "' at position " << n << endl;
    }
}
