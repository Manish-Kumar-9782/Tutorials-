
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
