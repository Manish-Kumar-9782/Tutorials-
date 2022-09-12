#include <iostream>
using namespace std;

/*
    Program::String find_last_not_of(): str.find_last_not_of();

    This function is used to search the string for the last character that does not match
        with any of the character specified in string.

    Finds the last character equal to none of the characters in the given character sequence.
        The search considers only the interval [0, pos]. If the character is not present
        in the interval, npos will be returned.

    Syntax::str.find_last_not_of(str, pos); --> (1)
    Syntax::str.find_last_not_of(ch*,pos, n); --> (2)
    Syntax::str.find_last_not_of(ch, pos); --> (3)

    1) Finds the last character equal to none of characters in str.
    2) Finds the last character equal to none of characters in the range
        [s, s+n). This range can include null characters.
    3) Finds the last character not equal to ch.

    @param:: str: string to be searched in our string.
    @param:: pos: it is the position from which we want to begin our search.
    @param:: n: Number of characters identifying characters to be searched for.
    @param:: ch: it defines the character which is to be searched.

    return Value: It return the missing found character else return string::npos value.
*/

void find_last_not_of1(); // params: str, pos
void find_last_not_of2(); // params: ch*, pos , n
void find_last_not_of3(); // params: ch, pos

int main()
{

    // 1. find1
    find_last_not_of1();
    printf("\n\n");
    find_last_not_of2();
    printf("\n\n");
    find_last_not_of3();

    return 0;
}

void find_last_not_of1()
{

    // in this we will use the  below function syntax, which will take a string to be searched
    // Syntax::str.find_last_not_of(str);

    string str{"hello this is good practice"};
    string skip_set{"good to know"};

    /*
        Now in this section we are finding the last missing value from the skip_set.
        in this section it will search for all the missing values and it will return the
        last missing value from the skip set if found.
    */
    int n = str.find_last_not_of(skip_set);

    if (n == string::npos)
    {
        cout << "No character is missing..!";
    }
    else
    {
        cout << "Missing character found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_last_not_of2()
{
    // in this section we will use the below sytax funciton, which will take a str and pos
    // from where we need to search the string.

    // string::npos  is used to give the number which will be returned when there is no match found
    // in the given string.
    string str{"abc_123"};
    char const *skip_set{"0123456789"};

    /*
       Now in this section we are finding the last missing value from the skip_set.
       in this section it will search for all the missing values and it will return the
       last missing value from the skip set if found.
   */
    int n = str.find_last_not_of(skip_set);

    if (n == string::npos)
    {
        cout << "No character is missing..!";
    }
    else
    {
        cout << "Missing character found '" << str.at(n) << "' at position " << n << endl;
    }
}

void find_last_not_of3()
{
    // in this section we will the function, whose syntax is defined at below.

    string str = "Rajasthan is a very popular state";

    // finding the first character which is not equal to R
    int n = str.find_last_not_of("abdrsafgafskjljhoidsjrew");

    if (n == string::npos)
    {
        cout << "No character is missing..!";
    }
    else
    {
        cout << "Missing character found '" << str.at(n) << "' at position " << n << endl;
    }
}
