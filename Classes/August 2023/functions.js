
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