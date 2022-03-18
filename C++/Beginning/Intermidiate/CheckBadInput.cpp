// In this section we will test a bad input 

// Bad Input: it is an input which is given by a user or any other kind of mechanism and we want to check it from input stream.

// first of all include the iostream
#include<iostream>
using namespace std;

inline void error(const string& s)
// s: const string required
{
	throw runtime_error(s);
}

int main(){

    // Now first make  a variable of any type
    int a = 0; // suppose that we want to check that input for a variabe
    cout<<"\n\nEnter an Integer Value Only: ";
    cin>>a;

    // Now we will test the input stream by using the if statement on cin
    if(cin){
        // if our cin get an integer then we we will oK.
        cout<<"Integer Input: "<<a<<endl;
    }
    else{
        cout<<"Bad input"<<endl; // if cin does not pick an integer then it will be considered as the bad input.
        // we can also use the error funciton to throw an error message.
        error("Couldn't read an integer for variable 'a'.");
    } 
}


// Conclusion: In this we have seen that how can we make a simple mechanism to check the cin input stream for bad input.