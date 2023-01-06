
/**
 * Operators in JavaScript
 *
 *      1. Arithmetic Operator
 *      2. Assignment Operator
 *      3. Increment or Decrement Operator
 *      4. Relational Operator
 *      5. Logical Operator
 */

/**
 *  Arithmetic Operators
 *      1. + : plus operator
 *      2. - : minus operator
 *      3. / : division operator
 *      4. * : multiply operator
 *      5. % : modulus operator
 */

// Working with Number , integer (whole number), floating point number (decimal number)

let a = 10;
let b = 20;

// here '=' is called assignment operator
// assignment operator is used to give right value to left variable.

// Now we will perform some operation with console message.


console.log("a :", a);
console.log("b :", b);
console.log("\n");
// -----------------------
console.log("adding a + b:", a + b);
console.log("subtracting a - b:", a - b);
console.log("subtracting a * b:", a * b);
console.log("subtracting a / b:", a / b);
console.log("\n");
// -------------------------

// Now we will see the modulus operator
// % it gives the remainder or numerator/denominator (3/2 --> 1)

console.log("Modulus of  a / b:", a % b);

// in a % b , if a < b then result will be a.
// in a % b , if a > b then we will get the remainder.

console.log("Modulus of  7 % 3:", 7 % 3);
console.log("\n");


// suppose that we have a container of 100px width and we want to put 4 box in each row.
// with equal width & height
let width = 100; // 100px
console.log("Container Width: ", width);
// first we will compute the width of the box
let boxWidth = 100 / 4;
console.log("Each box width in container: ", boxWidth);

// Now suppose that we have 10 box in a row.
// Now we want to put 4 box in each row.

// Now if we take our denominator as 4 and numerator as 10 then we can get the break point 
// and at break point our result will be 0.
let line = '';
for (let i = 1; i <= 10; i++) {
    line += " " + i + " ";

    if (i % 3 == 0) {
        console.log(line);
        line = "";
    }

}
console.log(line);

console.log("\n\n");



// Assignment Operators

/**
 * -> =  : assignment operator
 * -> += : add & assignment operator.
 * -> -= : minus & assignment operator.
 * -> /= : divide & assignment operator.
 * -> *= : multiply & assignment operator.
 * -> %= : modulus & assignment operator.
 */

// suppose that we have a variable a;

a = 20;
console.log("+= add & assignment Operator")
console.log("a is :", a);

// now adding 20 with a
console.log("a + 20 :", a + 20);
console.log("a is :", a);

// now if we want to put result value of a+20 into a variable.
// a = a + 20; // in place adding. --> a += 20 --> a = a+20;
// first compute the a+20, then assign the result to a.
console.log("Adding and Assigning: a = a + 20: ", a = a + 20);
console.log("A is : ", a);

a = 20;
console.log("+= add & assignment Operator: a+=20: ", a += 20);
console.log("a is :", a);


// Increment & Decrement Operator

/**
 * Post increment x++, Pre increment ++x --> add 1 to x
 * 
 * Post Decrement x--, Pre Decrement --x --> subtract 1 from x
 * 
 * Post Increment/Decrement  -> first use old value then increase/Decrease
 * 
 * Pre Increment/Decrement -> first increase/Decrease the old value then use.
 */

// Now creating x

let x = 10;
console.log("\n\n");
console.log("x at beginning: ", x);

// Post Increment: increasing x by one with post increment
console.log("Post Increment of x: ", x++);
console.log("After Post Increment: ", x);

// Post Decrement: Decreasing x by on with post decrement
console.log("Post Decrement of x: ", x--);
console.log("After Post Decrement: ", x);

console.log("\n\n");
// Pre Increment: Increasing x by one with pre increment
console.log("Pre Increment of x: ", ++x);
console.log("After Pre Increment: ", x);

// Post Decrement: Decreasing x by one with pre increment
console.log("Pre Decrement of x: ", --x);
console.log("After Pre Decrement: ", x);
console.log("\n\n");

// ========================================================= //
// Comparison Operator:

/**
 * 1. greater than operator: >
 * 2. less than operator: <
 * 3. less than or equal operator: <=
 * 4. greater than or equal operator: >=
 * 5. equal equal (equality) operator: ==
 * 6. identity operator: ===
 * 7. not equal operator: !=
 * 8. not identical operator: !== 
 * 
 * binary operator: -> they have both left and right values.
 * 
 * return: true or false.
 */


// suppose that we have three variables
let p = 10;
let q = 20;
let r = 10;
let y = '10';

// Now we will test <, >, <=, >= operators.

console.log("p is less than q: ", p < q);
console.log("p is greater than q: ", p > q);
console.log("p is less or equal than q: ", p <= q);
console.log("p is greater or equal  than q: ", p >= q);
console.log("p is greater or equal  than r: ", p >= r);
console.log("p is equal to r: ", p == r);
console.log("p is equal to y: ", p == y);
console.log("p is identical to y: ", p === y);

console.log("p is not equal to y: ", p != y);
console.log("p is not identical to y: ", p !== y);



// Logical Operator: 

/**
 * 1. AND Operator && (binary Operator) 
 * 2. OR Operator  || (binary operator)
 * 3. NOT operator !  (unary operator)
 * 
 * Logical operator are normally  used with conditional statements and used to combine 
 * multiple conditions.
 * 
 * 
 * 
 * 
 */

p = 10;
q = 40;
r = 30;

console.log("q is greater than p and less than r: ", q > p && q < r)


