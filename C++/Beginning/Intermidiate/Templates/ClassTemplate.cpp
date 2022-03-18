// Class Template

/*
    This is the 4'th section on the template and their uses.

    * IN this section we will discuss about the class template.
    * Class Template: class template can also be defined similarly to the function template.
    *   When a class uses the concept of template, then the class is known as generic class.
    

    Syntax of the class template:
        template<class Type>
        class class_name{
            // body of the class
        }

    * Type: it is a placeholder name which will be determined when the class is instantiated. We can define
        more than one generic data type using comma-separated list. This can be used inside the class body.
*/


// Now we will make a template class.

#include<iostream>
using namespace std;

template<class Type>
class Numbers{
    // this class will hold numeric values of any data types.

    // Now we will declare two variable.
    public:
        Type var1;
        Type var2;

        // Now we will make a function which will add them
        Type add(){return var1 + var2;}

};

// Now we will make a main fucntion 
int main(){

    // Here we will make an object of Numbers class
    Numbers<int> num;
    // Here we need to specify that which data type will use this num instance.

    // Now we will assign some value in num's members variables.
    num.var1 = 10;
    num.var2 = 20;

    // Now we will check teir sum
    cout<<"Add of var1 and var2: "<<num.add()<<endl;

    return 0;
}

/* Conclusion: In this section we have seen that how can we use the template concept to make template classes
        template classes are very usefull when we want the same logical computation on different type of the data 
        and we want to represent them with a single pakage then this tempalte class is very usefull.
*/