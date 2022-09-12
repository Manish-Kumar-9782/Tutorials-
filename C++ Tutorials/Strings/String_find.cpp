#include <iostream>
using namespace std;

/*
    Program::String find: String.find();

    This function is used to finding a specified substring from a existing string.

    Syntax::str.find(str);
    Syntax::str.find(str,pos);
    Syntax::str.find(ch, pos, n);


    @param:: str: string to be searched in our string.
    @param:: pos: It determine the position of the first character that is to be
                appended to another object.
    @param:: n: Number of character to be copied in another string object as substring.
    @param:: ch: Number of character to copy.
*/

void find1(); // params: str
void find2(); // params: str, pos
void find3(); // params: ch, pos

int main()
{

    // 1. find1
    find1();
    printf("\n\n");
    find2();
    printf("\n\n");
    find3();

    return 0;
}

void find1()
{

    // in this we will use the  below function syntax, which will take a string to be searched
    // Syntax::str.find(str);

    string str = "hello this is CPP_Class and it is very special class.";

    // now we want to find a substring which is CPP_Class, it will return the first
    // character index of CPP_Class, if all the characters are matched with case matching.
    // else it will return -1.

    // find the result with exact match
    cout << "find result: " << str.find("CPP_Class") << endl;

    // find the result when match is not exact.
    cout << "find result: " << str.find("CPP_class") << endl;
}

void find2()
{
    // in this section we will use the below sytax funciton, which will take a str and pos
    // from where we need to search the string.

    int not_found_value = string::npos;

    string str = "hello this is CPP_Class and it is very special class.";

    // find the result with exact match
    int n = str.find("CPP_Class", 10);

    if (n == not_found_value)
    {
        cout << "string is not found.";
    }
    else
    {
        cout << "find result: " << n << endl;
    }

    // find the result when match is not exact.
    cout << "find result: " << str.find("CPP_class", 10) << endl;

    n = str.find("CPP_class", 10);

    if (n == not_found_value)
    {
        cout << "string is not found.";
    }
    else
    {
        cout << "find result: " << n << endl;
    }
}

void find3()
{
    // in this section we will the function, whose syntax is defined at below.
    // Syntax::find(ch,pos,n)

    string str = "hello this is CPP_Class and it is very special class.";

    /*
        ch: we are searching the first appeareance from of the 'ch' character from the
            given pos. by default it is 0.

        pos: to define that from where we need to search the character.
    */

    int n = str.find('C', 15);

    if (n == string::npos)
    {
        cout << "string is not found.";
    }
    else
    {
        cout << "find result: " << n << endl;
    }
}
