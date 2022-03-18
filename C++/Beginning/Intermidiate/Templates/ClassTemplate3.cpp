
// Non-type template arguments in template class.

/*
    * The template can contan multiple arguments, and we can alos use the non-type arguments in addition to the type T 
        argument, we can alos use other types of arguments such as string, function name, 
        constant expression and built-in types.
*/

//  1. A template class with type T and integer data type.

#include<iostream>
using namespace std;

template<class T, int size>
class array{
    public:
    T arr[size]; // automatic array initalization with size.

    // Now we will make a function to display the array.

    void display(){
        cout<<"Array: ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


// Now we will make an instance of array in the main function.

int main(){

    array<int, 3> ar;
    //  Here first we parameter define that what kind of array we will use and 2nd parameter defines the size of the array.


    ar.arr[0] = 23;
    ar.arr[1] = 45;
    ar.arr[2] = 52;

    // Now we will dispaly the array.
    ar.display();

    return 0;
}

/*
    Conclusion: In this section, the template class is created which contains the nontype template arguments,
    (size). it is specified when the object of class 'A' is created.
*/
