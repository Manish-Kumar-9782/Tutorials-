#include <iostream>
using namespace std;

/*
Enum in C/C++ is a data type that contains fixed set of constants.

if we want to put a number of values in terms of constant in a set then
we can use the Enumeration data type.

like if we want to put the days of week:
    enum week{sunday, monday, tuesday, wednesday, thursday, firday, saturday}

or we can make the yes or no/ true or false.

    enum choice{yse, no}
    enum bool{true, false}

// in this we can put some constant based values in a set.
// Note: The C++ enum constants are static and final implicitly.
*/

/*
    Points on Enum data types.

        -> enum imporves type safety
        -> enum can be easily used in switch
        -> enum can be traversed
        -> enum can have field, constructors and methods.
        -> enum may implement many interfaces but cannot extend
            any class because it internally extends Enum class.
*/

void Enum();       // 1. simple enum data type.
void class_Enum(); // 2. class enum data type.
// void printEnum();  // to show the enum data.

int main()
{
    system("cls");
    Enum();

    printf("\n\n");
    class_Enum();
    return 0;
}

void Enum()
{

    // In this section we will make a simple Enumeration in which
    // we can make a set of constant which will be serialize in an order.

    enum week
    {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday
    };

    enum choice
    {
        no,
        yes
    };

    enum Bool
    {
        False,
        True
    };

    // Now first of all we need to make a vairable for enum data type.
    week day;
    Bool value;
    value = False;
    // day = 10;
    // Now we can assign any value in the wk form the week.

    day = monday;

    // Now we can access all the constant values.
    cout << "Monday :"
         << " " << day << endl;

    day = thursday;

    cout << "thursday :"
         << " " << day << endl;

    cout << "False :"
         << " " << value << endl;
}

void class_Enum()
{
    // Now in this case we will make a enum class
    // enum class values can not be used directly for that
    // we need to use the scope resolution (::) operator.

    enum class week
    {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday
    };

    // Now if we make a variable of week type then we need to
    // use the scope resolution operator to access the its value.

    // if we don't use the scope resolution it will raise an error.

    // week day = moday; // will raise an error.
    // error: 'moday' was not declared in this scope

    // In this case we need to use scope resolution on the week class.
    week day = week::monday;

    // cout << "week::monday " << day << endl;
    // No << operator for enum class defined.

    // Note: enum classes are type-safe
}