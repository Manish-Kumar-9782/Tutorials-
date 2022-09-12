#include <iostream>
using namespace std;

/*
    Program::String find_first_of(): str.find_first_of();

    This function is used for finding the location of first occurance of the specified
    characters.

    Syntax::str.find_first_of(str); --> (1)
    Syntax::str.find_first_of(str,pos); --> (1)
    Syntax::str.find_first_of(ch, pos, n); --> (2)

    1) Finds the first character equal to one of the characters in str.
    2) Finds the first character equal to one of the characters in the range [s, s+count).
        This range can include null characters.

    @param:: str: string to be searched in our string.
    @param:: pos: it is the position from which we want to begin our search.
    @param:: n: length of character string identifying characters to search for.
    @param:: ch: Character to be searched in the string.


*/

void find_first_of1(); // params: str
void find_first_of2(); // params: str, pos
void find_first_of3(); // params: ch, pos

int main()
{

    // 1. find1
    find_first_of1();
    printf("\n\n");
    find_first_of2();
    printf("\n\n");
    find_first_of3();

    return 0;
}

void find_first_of1()
{

    // in this we will use the  below function syntax, which will take a string to be searched
    // Syntax::str.find_first_of(str);

    string str = "fhon yes well is good";

    //  Now we have a string in which we need to find the the given character, it will return the
    // index number of the character (the character whichever will be found first.)
    int n = str.find_first_of("jail");

    if (n == string::npos)
    {
        cout << "No match found.";
    }
    else
    {
        cout << "found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_first_of2()
{
    // in this section we will use the below sytax funciton, which will take a str and pos
    // from where we need to search the string.

    int not_found_value = string::npos;

    // string::npos  is used to give the number which will be returned when there is no match found
    // in the given string.
    string str = "jhon, all is well is good";

    // matching any character from "iae" to the str.
    int n = str.find_first_of("iae", 0, 6);

    if (n == not_found_value)
    {
        cout << "No match found.";
    }
    else
    {
        cout << "found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_first_of3()
{
    // in this section we will the function, whose syntax is defined at below.

    string str = "jhon, all is well is good";

    // matching only one character.
    int n = str.find_first_of("a");

    if (n == string::npos)
    {
        cout << "string is not found.";
    }
    else
    {
        cout << "found '" << str.at(n) << "' at position " << n << endl;
    }
}
