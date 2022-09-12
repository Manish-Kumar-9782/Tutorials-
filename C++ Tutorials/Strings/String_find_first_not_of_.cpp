#include <iostream>
using namespace std;

/*
    Program::String find_first_not_of(): str.find_first_not_of();

    This function is used to search the string for the first character that does not match any
    of the characters specified in the string.

    Syntax::str.find_first_not_of(str, pos); --> (1)
    Syntax::str.find_first_not_of(str,pos, n); --> (2)
    Syntax::str.find_first_not_of(ch, pos); --> (3)

    1) Finds the first character equal to none of characters in str.
    2) Finds the first character equal to none of characters in range [s, s+n). This range can include null characters.
    3) Finds the first character not equal to ch.

    @param:: str: string to be searched in our string.
    @param:: pos: it is the position from which we want to begin our search.
    @param:: n: Number of characters identifying characters to be searched for.
    @param:: ch: it defines the character which is to be searched.

    return Value: it return the position of the first character that does not match.
*/

void find_first_not_of1(); // params: str, pos
void find_first_not_of2(); // params: str, pos , n
void find_first_not_of3(); // params: ch, pos

int main()
{

    // 1. find1
    find_first_not_of1();
    printf("\n\n");
    find_first_not_of2();
    printf("\n\n");
    find_first_not_of3();

    return 0;
}

void find_first_not_of1()
{

    // in this we will use the  below function syntax, which will take a string to be searched
    // Syntax::str.find_first_not_of(str);

    string str = "Country";

    //  Now we have a string in which we need to find the the given character, it will return the
    // index number of the character (the character whichever will be found first.)
    int n = str.find_first_not_of("Counry");

    if (n == string::npos)
    {
        cout << "No character is missing..!";
    }
    else
    {
        cout << "Missing character found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_first_not_of2()
{
    // in this section we will use the below sytax funciton, which will take a str and pos
    // from where we need to search the string.

    int not_found_value = string::npos;

    // string::npos  is used to give the number which will be returned when there is no match found
    // in the given string.
    string str = "you are always welcome";

    // matching any character from "iae" to the str.
    int n = str.find_first_not_of("always wlcome", 7);

    if (n == not_found_value)
    {
        cout << "No character is missing..!";
    }
    else
    {
        cout << "Missing character found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_first_not_of3()
{
    // in this section we will the function, whose syntax is defined at below.

    string str = "Rajasthan";

    // finding the first character which is not equal to R
    int n = str.find_first_not_of("R");

    if (n == string::npos)
    {
        cout << "No character is missing..!";
    }
    else
    {
        cout << "Missing character found '" << str.at(n) << "' at position " << n << endl;
    }
}
