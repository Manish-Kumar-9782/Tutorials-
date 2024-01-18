
let a = 10
let b = 10

if (a > b) {
    console.log("a is greater than b")
}
else if (a < b) {
    console.log("a is less than b")
}
else if (a == b) {
    console.log("a is equal to b")
}
else {
    console.log("a and b are not comparable")
}


// guessing the number

let random_number = Math.round(Math.random() * 10);
let threshold = 5;
let input_number = prompt("Enter a number: ");
input_number = parseInt(input_number)

if (input_number == random_number) {
    console.log(`computer:  ${random_number} | person : ${input_number} :: super winner`)
}

else if (input_number > threshold && random_number > threshold) {
    console.log(`computer:  ${random_number} | person : ${input_number} :: winner`)
}

else if (input_number < threshold && random_number < threshold) {
    console.log(`computer:  ${random_number} | person : ${input_number} :: winner`)
}
else {
    console.log(`computer:  ${random_number} | person : ${input_number} :: looser`)
}
