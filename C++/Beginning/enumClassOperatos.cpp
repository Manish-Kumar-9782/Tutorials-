// In this section we will see enum class with some operator funcitonlality
// such as operator<<, operator++ etc.

#include<iostream>

using namespace std;

// Now we we will make a  color enum class.

enum class Traffic_Light{red, green, yellow}; //RGB color;

// Now we will Make a function by using the reference of the class.
Traffic_Light& operator++(Traffic_Light& t){
    // prefix increment: ++

    switch (t)
    {
    case Traffic_Light::green: return t = Traffic_Light::yellow;

    case Traffic_Light::yellow: return t = Traffic_Light::red;

    case Traffic_Light::red: return t = Traffic_Light::green; 
    
    default: cout<<"Unknown value"<<endl;
        
    }
}

// Now we will make another operator functionallity for the Traffic Light enum class to display the current variable value.


// Now we will create a variable of Traffic_Light enum class and we will perform the increment on it.

int main(){

    Traffic_Light light = Traffic_Light::red;

    Traffic_Light nextLight = ++light;

    

    return 0;
}