
// Overloading a function template

/*
    * This is the 3'rd program in the function template section, untill now we have seen that how can we create a function by using template
        which is called the function template.

    * we have also seen that how can we make a funciton template with multiple parameters.

    * Now we will see that How to overload a Function template.

    Function Overloading:  Function overloading is a feature of ovject oriented programming where two or more functions can have the same name
        but different parameters.

        * When a function name is overloaded with different jobs it is called function overloading.
        * In function overloading "Function" name should be the same and the arguments should be different.
        * Funciton overloading can be considered as an example of poly morphism feature in c++.
*/

// Now we will make a program which will show us the feature of overloading of function template.

#include<iostream>
using namespace std;

template<class Type1> void func(Type1 a){

    // this is a template function with single parameter.
    // Now we will only print the input argument.
    // To Show that which function is calling we will print this line.

    cout<<"\n\nSinble parameter func called..."<<endl;
    cout<<"Value of a argument: "<<a<<endl;

}

// Now we will make another template function with two parameters.
template<class Type1, class Type2> void func(Type1 a, Type2 b){

    // Now this is a template funciton with two parameter and this function name is same as the above one.
    // Now we will show a and b values.
    cout<<"\n\nDouble parameter func called..."<<endl;
    cout<<"Value of a argument: "<<a<<endl;
    cout<<"Value of b argument: "<<b<<endl;
}

// Now we can know which function is called by using the same name.

int main(){

    int a = 1000;
    string name = "Manish";

    // Now first we will use only single variable.

    func(a);

    // Now we will use both the variable.
    func(a,name);

    return 0;
}

// Colclusing: Overloading a function template is same as the overloading a simple funciton.