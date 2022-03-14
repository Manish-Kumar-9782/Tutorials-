// In this section we will make a vector template based class with some basic functionallity.

// first of all we will include the iostream header file.
#include<iostream>
using namespace std; 

// Now we will make a template 

template<class Type>

// Now we need to make a vector class
class Vector{

    private: // private scope 
        Type *elem;
        int size;

    public: // public member scope

        // first of all we will make a constructure.
        Vector(int n){
            // n: n is the size of the vector;
            size = n;
            elem = new Type[size];

            // Now we will initialize all the elements with -1;
            for(int i=0; i<size; i++){
                elem[i] = -1;
            }
        }

        // another construstor to initializing a vector with the help of the list.
        // Initialzer-list constructor: Initialize with a list of element;
        Vector(initializer_list<Type> lst){

            size = lst.size();
            elem = new Type[size];

            copy(lst.begin(), lst.end(), elem); // copying all the element of the list into the Vectors;

            
        }

        // Making a destructor of for the Vector instace, destructor is make by using the ~ (tilde) key
        ~Vector(){delete[] elem;} // simplest destructor.

        int Size() {return size;}  // a function to return the size of the vector.

        // display function to display all the vector elements;
        void display(){

            cout<<"\nVector: [";
            for(int i=0; i<size; i++){

                if(i<size-1) cout<<elem[i]<<",";
                else cout<<elem[i];
            }
            cout<<"]\n"<<endl;


        }

        Type sum(){
            // a function to sum all the elements of the vector;
            Type result=0;

            for(int i=0; i<size; i++){
                result += elem[i];
            }

            return result;
        }


        /*============================== OPERATOR OVERLOADING========================================   */
        Type& operator[](int i){ 
            // An operator overloading function to access an element by using [] subscripting.
            if(i>=0 || i<size){
                return elem[i];
            }
            else{
                cout<<"Error: out of bound "<<endl;
            }
            
            return elem[0];  // returning the initial value or base address of the vector.
            // we need to return the value by reference.
        }

        Vector operator+(Vector<Type> b){
                // since We want to add two vector so we need another vector as argument.
            Vector <Type>vec(this->Size());
            if(this->Size() == b.Size()){

                for(int i=0; i<this->Size(); i++){
                   vec[i]= this->elem[i] + b.elem[i];
                }
                return  vec;
            }
            else{
                cout<<"Error: Size mismatch"<<endl;
            }
            return -1;
        }
};


// Now we will make a main function in which we will test out vector class
int main(){

    Vector <int>vec(5);

    vec.display();

    // Now we will make another vector by initializing with the list.
    Vector <int>vec1 = {1,2,3,4,5,6};
    vec1.display();

    Vector <int>vec2 = {10,20,30,40,50, 60};
    vec2.display();

    // Now adding to vectors;
    auto vec3 = vec1 + vec2;

    vec3.display();
    return 0;
}