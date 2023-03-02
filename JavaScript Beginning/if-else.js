
let a = 10
let b = 20

// if a> b
// console.log("a is greater than b")

// if a < b
// console.log("a is less than b")

// condition section `()`

/**
 * Rule1: condition must valid expression.
 * Rule2: expression must return true or false
 * Rule3: if-code-block will run only on true value.
 * Rule4: else will run only on false value.
 * Rule5: if, if-code block gets true, then it will run and else will be ignored.
 */
// if (a > b) {
//     console.log("a is greater than b")
// }
// else {
//     console.log("a is less than b")
// }

// 1. a > b
// 2. a < b
// 3. a == b
// a = 20

// if (a > b) {
//     console.log("a is greater than b")
// }
// else if (a < b) {
//     console.log("a is less than b")
// }
// else {
//     console.log("a is equal to b")
// }

/* let signal = 'hjkhl';

if (signal == "green") {

    console.log(`Signal is ${signal} you can go...`)
}
else if (signal == "red") {

    console.log(`Signal is ${signal} Please stop...`)
}
else if (signal == "orange") {

    console.log(`Signal is ${signal} be careful...`)
}
else {
    console.log("Traffic System failed please call the traffic police...")
}

let light = "red";

switch(light){
    case "green":
        console.log("The light is green: you can go.");
        break;
    case "orange":
        console.log("The light is orange: Be Careful accident ho jayega.");
        break;
    case "red":
        console.log("The light is red: You can't go.");
        break;
    default:
        console.log("Traffic system has been failed. call the traffic police.");
        break;
} */

function StartPattern1() {

    // first we will make variable to store the string in which we will create the pattern.

    let pattern = "";
    let lines = 5;

    // Now we will outer loop for each row.
    for (let row = 0; row < lines; row++) {

        // Now in each row we will put some starts.
        for (let columns = 0; columns < row; columns++) {
            pattern += "🐹";

        }
        pattern += "\n";
    }

    console.log(pattern);

}

StartPattern1();
