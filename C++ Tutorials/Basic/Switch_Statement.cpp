#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the switch statement.

switch statement are usefull whenever we want to work with the
multiple condition.

Note: switch statement only works with constant value, enum
value or enum class vlaue. it does not work with the expression
like if-else do.

in this section we will learn the switch statement with
1. integer.
2. char.
3. enum
4. enum class

Note: a switch statement does not work with the string, it only support
const char, integer, enum type.
---------------------------------------------------------*/

// Now we will declare function for each type

void switch_integer();
void switch_char();
void switch_enum();
void switch_enum_class(string &);

/*---------------------------------------------------------*/

int main()
{
    system("cls");
    // swtich_integer
    switch_integer();

    // switch_char
    switch_char();

    // switch_enum
    switch_enum();

    // switch_enum_class
    string str = "red";
    switch_enum_class(str);

    return 0;
}

void switch_integer()
{
    /*---------------------------------------------------------
    In this section we will see that how to use the switch control
    statement with integer values.
    ---------------------------------------------------------*/

    int x;
    cout << "Enter the integer value: ";
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "you have selected 1" << endl;
        break; // break statement break to the case switch to
        // termiate the furthur execution.

    case 3:
        cout << "you have selected 3" << endl;
        break;

    case 4:
        cout << "you have selected 4" << endl;
        break;

    case 5:
        cout << "you have selected 5" << endl;
        break;

    default:
        // this is the default statement
        // this statement will run if all the above statement
        // does not run.
        cout << "default statement" << endl;
        break;
    }
}

/*---------------------------------------------------------*/

void switch_char()
{
    /*---------------------------------------------------------
    In this section we wil use the char as the variable to use the
    switch statement.
    ---------------------------------------------------------*/
    char ch;
    cout << "Enter the any char: ";
    cin >> ch;
    switch (ch)
    {
    case 'a':
        cout << "you have selected a" << endl;
        break; // break statement break to the case switch to
        // termiate the furthur execution.

    case 'b':
        cout << "you have selected b" << endl;
        break;

    case 'c':
        cout << "you have selected c" << endl;
        break;

    case 'd':
        cout << "you have selected d" << endl;
        break;

    default:
        // this is the default statement
        // this statement will run if all the above statement
        // does not run.
        cout << "default statement" << endl;
        break;
    }
}
/*---------------------------------------------------------*/

void switch_enum()
{
    /*---------------------------------------------------------
    In this section we will use the enum data type to use switch
    statement. switch statement work with the enum type since they
    are contant final type.
    ---------------------------------------------------------*/
    enum week
    {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        firday,
        satruday
    };

    week day;
    int Day = -1;
    cout << "Enter any day number: ";
    cin >> Day;
    switch (Day)
    {
    case sunday:
        cout << "you have selected sunday" << endl;
        break; // break statement break to the case switch to
        // termiate the furthur execution.

    case tuesday:
        cout << "you have selected tuesday" << endl;
        break;

    case firday:
        cout << "you have selected firday" << endl;
        break;

    case satruday:
        cout << "you have selected satruday" << endl;
        break;

    default:
        // this is the default statement
        // this statement will run if all the above statement
        // does not run.
        cout << "default statement" << endl;
        break;
    }
}
/*---------------------------------------------------------*/

void switch_enum_class(string &str)
{

    enum class color
    {
        red,
        green,
        orange
    };

    color cl;

    if (str == "red")
    {
        cl = color::red;
    }
    else if (str == "green")
    {
        cl = color::green;
    }
    else if (str == "orange")
    {
        cl = color::orange;
    }

    switch (cl)
    {
    case color::red:
        cout << "Please Stop." << endl;
        break; // break statement break to the case switch to
        // termiate the furthur execution.

    case color::green:
        cout << "You can GO!.." << endl;
        break;

    case color::orange:
        cout << "Carefull..." << endl;
        break;

    default:
        // this is the default statement
        // this statement will run if all the above statement
        // does not run.
        cout << "System crashed" << endl;
        break;
    }
}