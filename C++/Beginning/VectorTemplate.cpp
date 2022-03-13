// In this section we will make a program in which we will see that how to create a template and impliment it.

#include<iostream>
using namespace std;
// Now to make a template we just need to define the template<typename VarName>; 
// this is the simplest type of the template
// The main use of the template is to reduce the re-writing the same logic code for different type of the data type

/*
    To understand the requirment of the template first of all we will make a template class with a simple addition function.
    this function will give us the sumation of the vector elements.

    NOte: if the elements are integers then result should be in integer or if the elements are flaots/double then result should
            be in float/double

        The above case applies with all kind of numeric data types.
*/

// Now first of all we will make a vectorX class with out implementing the templates and persforming the sum.

class VectorInt{

public:
    int *arr;
    int size;

    // Note: above variable are private by default. Now we need to make a constructor 

    VectorInt(int m){
        // Now in this we will allocate the memory to the vector;
        size = m;
        arr = new int[size]; // allocate the memory to store the int type variables.
    } 

    // now we will make a function to display the vector elements.

    void display(){

        cout<<"Int Vector: ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // Now we will make a function to add all the elements.

    int sum(){
        // a sum function to add the only int type values.
        int result = 0;

        for(int i=0; i<size; i++){
            result += arr[i];
        }

        return result;
    }

};


// Now here To calculate the the float data type value we neeed to define a different class using float value.
// This have to be done for all type of data 
class VectorFloat{

public:
    float *arr;
    int size;

    // Note: above variable are private by default. Now we need to make a constructor 

    VectorFloat(int m){
        // Now in this we will allocate the memory to the vector;
        size = m;
        arr = new float[size]; // allocate the memory to store the int type variables.
    } 

    // now we will make a function to display the vector elements.

    void display(){

        cout<<"Float Vector: ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // Now we will make a function to add all the elements.

    float sum(){
        // a sum function to add the only int type values.
        float result = 0;

        for(int i=0; i<size; i++){
            result += arr[i];
        }

        return result;
    }

};


// Now to overcome this multiple data type problem we will use the template 
// which will eliminate the rewritting problem for the same logic.

// Making a template

template<class Type> // this is the declaration of the template.

// Now we will make onlye single vector class for all kind of data types
class Vector{

public:

    // Note: In this vector class we have to use Type data type instead of int or float on the arr data.
    Type *arr;  // here Type is the Type which is defined in the template
    int size;

    // Note: above variable are private by default. Now we need to make a constructor 

    Vector(int m){
        // Now in this we will allocate the memory to the vector;
        size = m;
        arr = new Type[size]; // allocate the memory to store the int type variables.
    } 

    // now we will make a function to display the vector elements.

    void display(){

        cout<<"Vector: ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // Now we will make a function to add all the elements.

    Type sum(){
        // a sum function to add the Type data (user defined data).
        // this function will add any kind of numeric data.
        Type result = 0;

        for(int i=0; i<size; i++){
            result += arr[i];
        }

        return result;
    }

};

// Now we we will make the main function.

int main(){

    VectorInt vecXi(3);  // a vector of int type
    VectorFloat vecXf(3); // a vector of float type

    vecXi.arr[0] = 10;
    vecXi.arr[1] = 20;
    vecXi.arr[2] = 30;


    vecXf.arr[0] = 10.12;
    vecXf.arr[1] = 12.65;
    vecXf.arr[2] = 56.85;
    // Now we will display the 

    vecXi.display();
    vecXf.display();

    // Now we will compute the sum and diplay the sum;

    cout<<"Sum of Int vec: "<<vecXi.sum()<<endl;
    cout<<"Sum of Float vec: "<<vecXf.sum()<<endl;


    // Now we will make another vector which have the ability to compute the anykind of numeric data 
    // Now we will make to object of Vector class one for int and another for float.

    Vector <int>vecInt(3);  // Initiating a int type vector 
    Vector <float>vecFloat(3); // Initiating a float type vector by using the same Vector class.
    // here a class which follow the template structure need to be specified about that which kind of data it is going to use.

    // Now we need to assign the values into the vectorsl
    vecInt.arr[0] = 80;
    vecInt.arr[1] = 90;
    vecInt.arr[2] = 100;

    vecFloat.arr[0] = 80.80;
    vecFloat.arr[1] = 90.90;
    vecFloat.arr[2] = 100.10;


    // Now we will display the vectors:
    vecInt.display();
    vecFloat.display();


    // Now we can compute the sum;
    
    cout<<"Sum of Int vec: "<<vecInt.sum()<<endl;
    cout<<"Sum of Float vec: "<<vecFloat.sum()<<endl;

    return 0;
}


// Note: template is the most advance thing in the c++, it provides the edge  flexibility to the C++.
// Here we have seen the sigle use of the template which clearly gives us the reason why to use the template.
// There are huge advantage of using the template in C++.