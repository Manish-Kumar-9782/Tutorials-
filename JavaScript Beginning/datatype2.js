console.log("Hello world!");

console.log("Jo project nhi karta wo bewkuf hain", 3, "Manish Kumar");

let Name = "lokesh"; // string data type
let age = 21; // integer (number)
let height = 6.0; // float (number)

console.log("Name: ", Name);
console.log("Age: ", age);
console.log("Height: ", height);


// To perform some basic operations on the values we have operators.

/**
 *  1. Arithmetic Operators
 *          -> + : plus operator.
 *          -> - : minus operator.
 *          -> * : multiply operator.
 *          -> / : divide operator.
 *          -> % : modulus operator.
 * 
 *  2. Assignment Operators
 *      -> += : add and assignment operator.
 *      -> -= : subtract and assignment operator.
 *      -> *= : multiply and assignment operator.
 *      -> /= : divide and assignment operator.
 *      -> %= : modulus and assignment operator.
 * 
 *       x = x + 10;  ---> x += 10; 
 * // we have x (integer or float) and we want update our x values by adding 10 itself.
 * 
 *  3. Comparison/Relational Operators
 * 
*       == Comparison Operator (equal equal Operator)
        != Not equal operator
        === Identical Operators
        !== Not Identical Operators
        <= less than equal operator
        >= greater than equal operator
        < less than operator
        > greater than operator

        
 *  4. Logical Operators


    5. Increment and Decrement Operators.

        ++ : increment Operators
        -- : decrement Operators
 */

// making new variables to store some numbers.

let x = 10;
let y = 20;
let z = 30;

console.log("x: ", + x, "\ty: ", y, "\tz: ", z);

console.log("x + y :", x + y);
// int this above statement

/**
 *  "x + y :" -> it is a simple message to show on the console, it will not
 *  perform any kind of operation.
 * 
 *  x + y :" -> it is a arithmetic operation b/w x and y variable which will add them
 * and given the result value.
 */
console.log("------------------------------------")
console.log("x: " + x)  // this statement will perform concatenation operation.
console.log("x: " * x)
console.log("x: " / x)
console.log("x: " - x)
console.log("x: " % x)


// Assignment Operator


// we have x , if we want to add some values to x as expression x + 10;
// this will not update the value of x, it will just give us the result value.
// if we want to update the value of x then we need to assign the result value to x
// by using the assignment operator =, like this: x = x + 10;

// to short this operator we have add and assignment operators, x += 10; 

console.log("before add and assignment operators x is: ", x);
console.log("adding some value with x + 10: ", x + 10);
console.log("after adding value 10 with x is: ", x, "\t x is not updated.");
// to update the value of x we can use += add and assignment operators.
console.log("updating value of x with 10: ", x += 10);
console.log("After updating value of x with 10: ", x, "\t x is updated");


// ======================================= //
// Relational Operators