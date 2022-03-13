// In this section we will make a simlest vecter class and we will see that how vector class looks like

// first of all we will include the io stream file
#include<iostream>
using namespace std;
// Now we will make a class of  vector

class Vector{

    public: // Now first of all we need to make a constructor which will allocate some memory block to the vector.
        Vector(int s): 
            elem{new double[s]}, sz{s} {};  // This is a costructor of a vector class
            // In we are initiating the pointing to the element and also we are allocating the size to the vector.

        // Now we will make another member function to access the element with the help of the Opeartor[];
        double& operator[](int i){
            return elem[i]; // This method will use the brackets to access the element.
            // This functinallity is also called element access: subscripting.
        }

        // Now we will make another function to get the size of the vector.
        int size(){
            return sz;
        }

        // Now we will make another funciton to display all the element 
        void display(){
            
            int i;
            for(i=0; i<sz; i++){
                cout<<elem[i]<<" ";
            }
            cout<<endl;
        }


    private:
        double* elem;  // pointer ot the element.
        int sz; // the number of elements
};


// Now we willmake a int main function to make all things happen

int main(){

    Vector v(6);

    // Now we will allocate some number to the Vector;
    v[1] = 10;
    v[2] = 20;
    v[3] = 30;
    v[4] = 40;

    v.display();

    return 0;
}