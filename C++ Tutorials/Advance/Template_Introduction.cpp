#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will  learn about the template, whate are the
template and how to use them.

It allows us to define the generic classes and generic functions
hence it provide the support for the generic programming.

Generic Programming: it is a technique where generic types are
used as parameters in algorightms so that they can work for
varity of data types.

Template can be represent in two types:
    1. Function templates.
    2. Class templates.


Function Template: if a template is defined for function then it
is called function template, it allow us to specify the single datatype
for each parameter, we don't need to specify the specific data type in
that function it will take any kind of parameter.

Class Template: if a template is defined for a class then it is
called as a class template, which allow us the different kind
of type in our class without specifing them in our class.
---------------------------------------------------------*/

template <typename Type>
void function_template(Type a)
{
    cout << "You have entered: " << a << endl;
}

// a template function with multiple parameters.
template <typename type1, typename type2>
void function_template_multiple_types(type1 t1, type2 t2)
{
    cout << "this is a mutliple type template fucntions." << endl;
}

/*
    typename: it is a keyword to specify the our word `Type` is
        a type-placeholder not a variable, so compiler will treate it as a generic type.

    Type: it is a placeholder name for a data type used which is used in th
        function parameter list. it is only a placeholder that the compiler will
        automatically replace this placeholder with the actual data type.
*/

/*
Note: we have to define the body of the template function since it will
    be created during the compilation time according to the given type.
*/

int main()
{
    system("cls");
    string str = "hello";
    function_template(str);

    return 0;
}
