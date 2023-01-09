/**
 * Data Types: IN javaScript we have the following Data Types.
 *
 * 1. number
 *      -> integer
 *      -> float
 * 2. String.
 * 3. Boolean
 * 4. undefined
 * 5. null
 * 6. Symbol
 * 7. BigInt
 * 8. Object
 */

// an student information
function displaySep() {
    console.log("---------------------------------------\n\n");
}
//----------------------------------//

displaySep();
let Age = 22; // number --> integer type value
let Name = "Ravi Kumar"; // string type value
let isMale = true; // Boolean --> true or false
let BloodGroup; // undefined
let Height = null; // null
let Weight = 61.5; // in kg,  --> float type value

console.log("Type of Age: ", typeof Age);
console.log("Type of name: ", typeof Name);
console.log("Type of isMale: ", typeof isMale);
console.log("Type of BloodGroup: ", typeof BloodGroup);
console.log("Type of Height: ", typeof Height);
console.log("Type of Weight: ", typeof Weight);
displaySep();

// Note: typeof is another operator to tell the dataType of data contained inside the variable. 

// String:
// String is a sequence of character, sequence indexing always starts from zero.
//

// string with number: concatenation
console.log("name + age: ", Name + Age + BloodGroup);

// Note: there our number data type will be converted implicitly
// into the string format to perform the concatenation operation. 

// unsupported operator: no operation is defined for minus operator.
console.log("name - age: ", Name - Age - BloodGroup);
console.log("name * age: ", Name * Age);
console.log("name / age: ", Name / Age);
displaySep();

// Creating String in Our JavaScript
// WE can make String by four methods.
/**
 * 1. Double quotes : literal string
 * 2. Single quotes : literal string
 * 3. back ticks: template string
 * 4. String Object.
 */
// camelCase
let doubleQuotesString = "this is double quotes string.";
let singleQuotesString = 'this is single quotes string';
let templateString = `my name is ${Name}`;

console.log("Double Quote String: ", doubleQuotesString);
console.log("Single Quote String: ", singleQuotesString);
console.log("Template  String: ", templateString);
displaySep();
Name = "Manish Kumar";
templateString = `my name is ${Name}`;
console.log("Template  String: ", templateString);


