
console.log("Hello this is from function.js file...!")

/**
 * 
 * Functions 
 * 
 * syntax:
 * 
 * function function_name(parameter1, parameter2,..., parameterN){
 *      // body block
 *      // statement 1
 *      // statement 2
 *      // statement 3
 *  return value; (optional)
 * }
 * 
 */

// greeting function definition
function greeting(name) {
    console.log("Hello, " + name + " my name is devid.");
    console.log("i am glad to inform you that you have won some prize.")
}


function greeting2(name, sender) {
    console.log(`Hello, ${name} my name is ${sender}`)
    console.log("i am glad to inform you that you have won some prize.")
}

// greeting("Aasish");
// greeting("Payal");
// greeting("Kuldeep")

console.log("\n\n");

const names = ["Aasish", "Payal", "Kuldeep", "Kursheed", "Karan", "Pooja", "Mahesh", "Bhanu", "Lokendra", "Abhishek"]

for (let i = 0; i < names.length; i++) {
    greeting(names[i])
    console.log("\n");
}


console.log("================================================");
for (let i = 0; i < names.length; i++) {
    greeting2(names[i], names[names.length - 1 - i])
    console.log("\n");
}


// =================================================================

// function parameters and positional arguments.

function add(a, b) {
    return a + b;
    // function with return value.
}


function add_show(a, b) {
    console.log("result a+b: ", a + b);
    // function with no return value. (only logging.)
}

// function to test that a number is prime or not.

function isPrime(number) {

    // if given number is 0 or 1 then return false. 
    if (number == 0 || number == 1) {
        return false;
    }

    // now test number by dividing and testing the remainder.

    // number%n where 
    // n is positive number n<number and n > 1
    // 7  > n< 7, n > 1

    for (let n = 2; n < number; n++) {
        if (number % n == 0) {
            return false;
        }
    }

    return true;
}


console.log("================================")
console.log("Prime Numbers in b/w 1, 100");


const PrimeNumbers = []

for (let i = 0; i <= 100; i++) {

    if (isPrime(i)) {
        PrimeNumbers.push(i)
    }
}

console.log(PrimeNumbers)