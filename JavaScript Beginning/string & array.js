console.log("Hello")

// string
let str = "Hello world;";

let Manish = "hello";
// creating a an array.
let arr = ['H', 'e', 'l', 'l', 'o', ' ', "w", 'o', 'r', 'l', 'd', ';']


// double quotes string
let str1 = "Hello, my name is 'Manish Kumar' and i am a very ver bad boy.";

// single quotes string
let str3 = 'Hello, my name is "Manish Kumar" and i am a very ver bad boy.';

// let str2 = "Hello, my name is "  Manish  Kumar  " and i am a very ver bad boy.";

// template string.
let badBoy = "Manish Kumar"
let tempString = `Hello my name is ${badBoy}  and i am a very ver bad boy!!`
// ${variable}

// Array: 
// first create an array.
let arr2 = [1, 2, 3, 4, 5, 6];
let another_Array = ["Manish", 21, 5, 6, "O-"];

// first operation on the array
// 1. accessing an element form the array
console.log("Accessing Array element  2: ", another_Array[1]);
console.log("Accessing Array element  5: ", another_Array[4]);

console.log("\n-----------------------\n");
console.log(another_Array)


/**
 * Object:
 *      Properties:
 *          it store some data.
 *      Methods:
 *          it is the function to perform some defined operations.
 *          they may return: some output or not.
 */

// Array.push() method: add the new value at the end of the array.
another_Array.push("Kuldeep")

// Array.pop() method: remove the value at the end of the array.
another_Array.pop()

// Array.unshift() method: add the new value at the beginning of the array
another_Array.unshift("Kuldeep")
console.log(another_Array)
another_Array.unshift("Kushal")
console.log(another_Array)
// Array.shift() method: remove the value form the beginning of the array.
another_Array.shift();
console.log("another Array: ", another_Array)

//================================================================//
//================================================================//
// push method.

// first adding values individually.
console.log("Array Push Operation\n-----------------------\n----------------------------\n");
console.log("Array push with individual values")
// -------------------------------------------------------//
another_Array.push("lokesh", 20, 5.6);  // <-----------------------------

console.log("Another Array:", another_Array);

// Now adding values by using arrays.
console.log("\n-----------------------\n");
console.log("Array push with another array.")


another_Array.push([1, 2, 3], [4, 5, 6, 7]); // <-----------------------------

console.log("Another Array:", another_Array);

//================================================================//
//================================================================//
// new array with concate method.
let newArray = ['Kuldeep', 'Manish', 21, 5, 6, 'O-'];
console.log("New Array:", newArray);

// Concatenating values with individually specified.
console.log("\n-----------------------\n----------------------------\n");
let updated = newArray.concat("lokesh", 20, 5.6)
console.log("Original Array:", newArray);
console.log("Updated Array :", updated);

//
console.log("\n-----------------------\n");

updated = newArray.concat(["lokesh", 20, 5.6], [0, 9, 8])
console.log("Original Array:", newArray);
console.log("Updated Array :", updated);
//================================================================//
//================================================================//

// Object Introduction

// Object --> Properties
// Object --> methods/ behavior
let student = {
    Name: "manish",
    Age: 27,
    Height: 5.6,
    BloodGroup: "O-"
}

console.log(student);
