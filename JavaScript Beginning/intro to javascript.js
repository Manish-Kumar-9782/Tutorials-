/**
 * Multi comment section
 * 
 * Keywords: Keywords are the predefined word in javaScript, which are reserved for special purpose
 *      in our javaScript programming, and these words are known as keywords.
 *      e.g: let, const, var, 
 * 
 * Identifier: Identifiers are user-defined names of variables, function, class, object,..., etc. 
 * 
 * Variables: Variables are container for values or other kind of object. if our variable is defined with
 *  var and let keyword then we can changer our variable value.
 * 
 *  if variable is defined with const keyword then we can't change variable value.
 * 
 * Since 'var' is ES5 (EcmaScript version 5) part and 'let' comes with ES6, 'let' is more secure than 'var'
 * hence we will use only let keyword for declaring variables.
 */

//  Now make a variable with let 

// a = 10;

let letx = 10;

/**
 * Rule to naming variable:
 * 
 *      1. Variable name should not start form numbers/digits
 *      2. Does not support special character in a variable.
 *      3. A Variable Name should not have white-space in b/w two words.
 *          eg. let my name : not allowed
 *      4. A Variable Name can have underscore  "_" in b/w two or multiple words words.
 *          eg. let my_name : allowed
 *      5. A variable Name cannot be wrapped inside the double or single quotes.
 *          eg. let "my_name" or 'my_name' : not allowed
 */


// We have three keyword to make variables -> var, let, const

let my_name; // declaration of variable 

// = : assignment operator
// it has to part left and right
// left part -> lvalue, loperand.
// right part -. rvalue, roperand.

// To show some message on console screen we can use console interface.

console.log("Hello world..!");

/**
 * Note: here console.log() is a function to show message on the browser console screen.
 * 
 * "Hello World..!" is a string which is wrapped inside the "" double quotes.
 */

let a = 10;
let b = 20;

console.log("value of a + b: ", a + b);
console.log("value of a + b: ", b);
console.log("value of a + b: ", a);
