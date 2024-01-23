
// a constant variable
const USER_POINTS = []

// a function to generate a random number
// this function does not takes any input arguments.
function generate_random_number() {
    let random_number = Math.round(Math.random() * 10)
    return random_number
}

// a function to get user input
function user_input() {
    let input_number = prompt("Enter a number: ");
    input_number = parseInt(input_number)
    return input_number
}

// a function to compare the random numbers against the input number
// increases and decreases the user points
function test_turn(random_number, input_number, user_points) {
    let threshold = 5;
    if (input_number == random_number) {
        console.log(`computer:  ${random_number} | person : ${input_number} :: super winner`)
        user_points.push(2)
        // user gained 2 points.
    }

    else if (input_number > threshold && random_number > threshold) {
        console.log(`computer:  ${random_number} | person : ${input_number} :: winner`)
        user_points.push(1)
    }

    else if (input_number < threshold && random_number < threshold) {
        console.log(`computer:  ${random_number} | person : ${input_number} :: winner`)
        user_points.push(1)
    }
    else {
        console.log(`computer:  ${random_number} | person : ${input_number} :: looser`)
        user_points.push(-1)
    }
}


// a function to run a single turn.
function run_turn() {
    let random_number = generate_random_number();
    let user_value = user_input()
    test_turn(random_number, user_value, USER_POINTS)
}