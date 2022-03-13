// In this section we will see how can we use the enum classes to define a set of value inside a scope.

#include<iostream>

using namespace std;

enum class Color {red, blue, green};
enum class TrafficLight {yellow, green, red};

// We have defined two different set of color.
// One set is only used to define the color,
// and another set is only used to define the traffic light color.
// we can't use the Color's color to define the Traffic Light color.

// enumerators are  ( in this case colors ) in the scope of their enum class, so that they can be used repeatedly 
// in diffenent enum class without confusion.
// for example Color::red is color's red which is different form the TrafficLight::red color.

int main(){

    // Now if we a variale of Color then we can see that, what happens when we pass a value which is out of scope.

    // Color x = red; // in this we will get error; since this red does not belongs to any scope we will get error.
    // Color y = TrafficLight::red; // error: this red color does not belogs to the Color's scope;
    Color z = Color::red; // OK: this color belongs to the Color scope.

    // Note: we cant assign any integer value to the Color's variable.
    // To do that we need to remove 'class' from 'enum class' 


   /*
   Note: by default enum class has only assignment, initialization, and compairsons only we need to define manuallu other
        Operators like operatr<<, operator++, operator--, operator[] and others operators as well. 
   */
}