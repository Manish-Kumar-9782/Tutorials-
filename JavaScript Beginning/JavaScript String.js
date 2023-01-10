function displaySep() {
    console.log("---------------------------------------\n\n");
}

// # 1. Creating A String.

let Greeting = "Hello, My Name is Bhanu Saini";

// # 2. Accessing character from string.
// We can access character from string by using the [] brackets.
// Accessing 2nd character from Greeting --> Greeting[1];

console.log("2nd character from Greeting: ", Greeting[1]);

// String is also an object:
// Object contains two things
// ---> 1. data
// ---> 2. function/method/behavior
// we can access any method/function by using '.' dot member operator.
// Syntax: String.MethodName(parameters)

// parameters: it is the input given from external environment of 
// the method.

// 1. method takes input
// 2. method perform some action.
// 3. method return something (in nothing then undefined will be found.)
// 
// Finding the index number of Name word inside the Greeting message.
console.log("Name found at: ", Greeting.indexOf('Name'));

// Finding the character using the index number by using the at method.
console.log("Character at index number 18: ", Greeting.at(18))

// Concatenation Operation with + Operator
displaySep();
let firstName = "Bhanu";
let secondName = "Saini";
let fullName = firstName + " " + secondName

// Concatenation operation with concat method.
console.log("FirstName: ", firstName);
console.log("SecondName: ", secondName);
console.log("fullName: ", fullName)
console.log("Concatenation of firstName and secondName: ",
    firstName.concat(secondName));

displaySep();

// String Case Conversion UpperCase or LowerCase.


// 1. Upper case : by using the String.toUpperCase();
// Lower case: by using the String.toLowerCase();
console.log("Original FullName: ", fullName);
console.log("fullName to LowerCase: ", fullName.toLowerCase());
console.log("fullName to UpperCase: ", fullName.toUpperCase());
displaySep();


// 2. startWith and endsWith methods.

// to check that a string starts or ends with a 
// given substring.

// startWith : To check that a string start with a
// given String.

let number = "+91-7894563214";

// Now we want to test that our number is starts from +91.
console.log("Phone Number: ", number);
console.log("is starts with +91: ", number.startsWith("+91"));

// testing that our number ends with "978" number.
console.log("is ends with 978: ", number.endsWith("978"));


