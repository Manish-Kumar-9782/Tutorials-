#include <iostream>
#include <string>
using namespace std;

/*
    Program::String insert: String.insert();

    This function is used to finding a specified substring from a existing string.

    Syntax::str.insert(index, count, ch); --> (1)
    Syntax::str.insert(index, ch*); --> (2)
    Syntax::str.insert(index, ch*, count); --> (3)
    Syntax::str.insert(index, str); --> (4)
    Syntax::str.insert(index, str, index_str, count); --> (5)

    1) Inserts count copies of character ch at the position index
    2) Inserts null-terminated character string pointed to by s at the position index. The length of the string is determined by the first null character using Traits::length(s).
    3) Inserts the characters in the range [s, s+count) at the position index. The range can contain null characters.
    4) Inserts string str at the position index
    5) Inserts a string, obtained by str.substr(index_str, count) at the position index

    @param:: index: position at which the content will be inserted.
    @param:: ch: character to insert.
    @param:: count: number of character to insert.
    @param:: str: string to insert.
    @param:: index_str: position of the first character in the string str to insert.

    return value: it will return *this (a pointer of the self string object.)
*/

void insert1(); // str.insert(index, count, ch); --> (1)
void insert2(); // str.insert(index, ch*); --> (2)
void insert3(); // str.insert(index, ch*, count); --> (3)
void insert4(); // str.insert(index, str); --> (4)
void insert5(); // str.insert(index, str, index_str, count); --> (5)

int main()
{
    system("cls");
    // str.insert(index, count, ch); --> (1)
    insert1();

    // str.insert(index, ch*); --> (2)
    insert2();

    // str.insert(index, ch*, count); --> (3)
    insert3();

    // str.insert(index, str); --> (4)
    insert4();

    // str.insert(index, str, index_str, count); --> (5)
    insert5();

    return 0;
}

void insert1()
{
    string str = "hello welcom";
    // str.insert(index, count, ch); --> (1)
    str.insert(str.length(), 5, 'e');
    cout << "str.insert(index, count, ch)" << endl;
    cout << "modified string: " << str << endl;
    printf("\n\n");
}

void insert2()
{
    string str = "hello welcome";
    const char *str2 = " to jaipur"; // literal string
    // str.insert(index, ch*); --> (2)
    str.insert(str.length(), str2);
    cout << "str.insert(index, ch*)" << endl;
    cout << "modified string: " << str << endl;
    printf("\n\n");
}

void insert3()
{
    string str = "hello welcome";
    const char *str2 = " to jaipur";
    // str.insert(index, ch*, count); --> (3)
    str.insert(str.length(), str2, 5);

    cout << "str.insert(index, ch*, count)" << endl;
    cout << "modified string: " << str << endl;
    printf("\n\n");
}

void insert4()
{
    string str = "hello welcome";
    string str2 = " to jaipur";
    // str.insert(index, str);
    str.insert(str.length(), str2);

    cout << "str.insert(index, str)" << endl;
    cout << "modified string: " << str << endl;
    printf("\n\n");
}

void insert5()
{
    string str = "hello welcome";
    string str2 = " to jaipur, it is wonderful to have you.";
    // str.insert(index, str, index_str, count); --> (5)
    str.insert(str.length(), str2, 0, 30);

    cout << "str.insert(index, str, index_str, count);" << endl;
    cout << "modified string: " << str << endl;
    printf("\n\n");
}
