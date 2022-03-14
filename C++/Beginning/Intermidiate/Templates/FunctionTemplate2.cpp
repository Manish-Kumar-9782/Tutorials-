// Function template with multiple Parameters

/* 
Now This is the second section of the function template, in first section we have seen that how can we 
    create  a function template and this function template can perfrom addition of the multiple data type.

*/

/*
    Now we will make a template function with multiple data type, this is same as the a function with multiple arguments.
*/

#include<iostream>
using namespace std;

template<class type1, class type2> void func(type1 a, type2 b){

     // Now we will only print the passsed values inside the arguments.

     cout<<"Value of a: "<<a<<endl;
     cout<<"Value of b: "<<b<<endl;
}

// Note: we could have make a complex function to show that how can we use the tmeplate function with multiple parameters,
// but we will use this in c++ STL section.

int main(){

    int a = 100;
    string name = "Manish";

    // Now we will pass this two value inside the template function.

    func(a, name); // this will show the values.

    return 0;
}