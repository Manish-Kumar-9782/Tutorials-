
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

// removing last element from mixArray using pop method.

mixArray.pop() // it will remove undefined 
console.log("\n\nmixArray: ", mixArray);

mixArray.pop() // it will remove null 
console.log("mixArray: ", mixArray);

// Joining values of array.

console.log("--------------------------------------------------------\n");

let joined_value = myArray2.join("--"); // it takes a string as the separator/joiner, by default it is , (comma).
console.log("Joined value: ", joined_value);


// slice method
// it takes two arguments, start and end.
console.log("--------------------------------------------------------\n");
console.log("sliced array in between 2 to 4:", mixArray.slice(2, 4));

// shift and unshift methods
console.log("--------------------------------------------------------\n");
mixArray.unshift("item 1")
console.log("Adding one item to front of array: ", mixArray);

mixArray.unshift("item 2", 5, 345, "jello")
console.log("Adding multiple items to front of array: ", mixArray);


mixArray.shift()
console.log("Removing first item from array: ", mixArray);



