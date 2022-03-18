
// Class template with multiple parameters

/*  
    * We can use more than one generic data type in a class template, and each generic data type is separated by the comma.

    Syntax: 
        template<class type1, class type2....>
        class class_name{
            // body of the class.
        };

    * here we can use multiple parameters in the tamplate, this is similar to the fucntion arguments.

*/

// Now we will make the template class by using the mulitple parameters.

#include<iostream>
using namespace std;

template<class Type1, class Type2>
class student{
    // This student class will hold the name, age class, blood group etc information.
    // this information can be stored by using the int and string data type.
    private:
        Type2  Name;
        Type1 Age;
        Type1 Class;
        Type2 Bgroup;

    // Now we will make a construstor to assign some values to the student memebers variable.
    public:
        student(Type2 name, Type1 age, Type1 std, Type2 bgroup){

            Name = name;
            Age = age;
            Class = std;
            Bgroup = bgroup;
        } 

    // Now we will make a display the student information.
        void display(){

            cout<<"Name:        "<<Name<<endl;
            cout<<"Age:         "<<Age<<endl;
            cout<<"Class:       "<<Class<<endl;
            cout<<"Blood Group: "<<Bgroup<<endl;
        }
};
// Now we will make main function in which we will make our student instance.

int main(){

    student<int, string> st("Manish", 26, 16,"O-");

    st.display();

    return 0;
}

/*
    Conclusion: In this section we dissuced about the template class with the multiple paramters.
    this type of class can be very usefull when we want to perform the same logic on the  multiple type of the data
    and the order of the data doesn't matters but in this section we are not considering the order of data type.
*/