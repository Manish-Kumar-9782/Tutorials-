
let myArray = []  // blank array

let myArray2 = [1, 2, 3, 4, 5]  // array with same type values

let mixArray = [4, 5, "hello", "keill", true, false, null, undefined]  // array with mix type values

console.log("myArray: ", myArray)
console.log("myArray2: ", myArray2)
console.log("mixArray: ", mixArray)

console.log("length of mixArray: ", mixArray.length);

// accessing array element
// array[index_number]

console.log("value at index 5: ", mixArray[5]);

// assigning to array element 

// assigning index number 1 value.
mixArray[1] = 1100;

// Iterating over array

let myArray2_squares = [];
for (let i = 0; i < myArray2.length; i++) {
    console.log('squares: ', myArray2_squares);
    console.log(`value at index ${i}: ${myArray2[i]} --> ${myArray2[i] ** 2}`);
    myArray2_squares.push(myArray2[i] ** 2)

}