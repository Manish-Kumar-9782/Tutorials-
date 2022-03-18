/*
    Function Template: Generic function use the concept of a function template. Generic functions define a set of operations 
        that can be applied to the various types of data.

    * The type of the data that the function will operate depends on the type of the data 
        passed as parameter.

    Syntax:
        template <class Ttype> return_type func_name(parameter list){
            // body of the funciton.
        }


    * Ttype: it is a placeholder name for a data type used by the function. it is used within the function definition.
        it is only a placeholder that the complier will automatically replace this placeholder with the actual data type.

    class: A class keyword is used to specify a generic type in a template declaration.

*/


// An example of the function template.

#include<iostream>
using namespace std;

// Now we will define a template funciton which will add two numbers.

template<class Type> Type add(Type& a, Type& b){

    return a+b;
}


int main(){

    // Now we will test our code by using different type of data.
    int a,b;
    float m,n;

    a = 10; b = 20;
    m=100; n = 200;

    // Now we will test our add funciton.

    cout<<"Addition of a and b: "<<add(a,b)<<endl;
    cout<<"Addition of m and n: "<<add(m,n)<<endl;

    return 0;
}

// Conclusion: Now we have created the template function which can perform the addition operation on any type either
// it can be integer, float or double.