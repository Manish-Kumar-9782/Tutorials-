#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn how to overload the template fucntion
as we do a simple funciton overloading.

if multiple template function has the same name but with a different number of
parameters then it is called an overloaded function.
---------------------------------------------------------*/

template <typename type1>
void fun(type1 t1)
{
    cout << "firs parameter: " << t1 << endl;
}

/*---------------------------------------------------------*/

template <typename type1, typename type2>
void fun(type1 t1, type2 t2)
{
    cout << "firs parameter: " << t1 << endl;
    cout << "second parameter: " << t2 << endl;
}

/*---------------------------------------------------------
we have a `fun()` with two differnt function template with differnt
number of parameters. in this case our function template `fun()` has
been overloaded.
---------------------------------------------------------*/

int main()
{
    system("cls");

    // single parameter fun function.
    fun("hello");

    // two parameter fun function.
    fun(13, 3.14);

    return 0;
}
