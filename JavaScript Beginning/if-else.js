
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

function trafficLight(light) {

    switch (light) {
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
    }
}


// 
function runLoop() {

    while (true) {

        let light = prompt("Enter traffic signal rgb color:")


        if (light === "green" || light === "orange" || light === "red") {
            trafficLight(light)
        }
        else {
            // this break will close our while loop
            break;
        }
    }
}

function pyramid(rows, p = "*") {

    let row = 0; // to initialize row form 0 at the beginning of our outer loop.
    let lines = rows; // how many number of lines of pattern we need.
    let spaces = lines;
    let pattern = "";  // in this we will store our pattern.

    // initializing while loop and testing the condition.
    while (row < lines) {

        let stars = 2 * row + 1; // for each row we will decide that how many stars we need to print.
        let columns = 0; // now we need to initialize our inner loop counter variable.

        // initializing our inner loop and testing the condition
        while (columns < (spaces + stars)) {

            // if our column number is less than our spaces then we will print a white space. 
            if (columns < spaces) {
                pattern += " ";
            }
            else {
                // if our column number is greater than our spaces then we will print "*".
                pattern += p;
            }
            // increasing the column number after printing each character either " " or "*".
            columns++;
        }


        // after print a line we need to do.
        pattern += "\n"; // need to add a new line character in our pattern.
        row++; // need to increase the row number.
        spaces--; // need to decrease the number of spaces
    }

    console.log(pattern);
}