<?php

echo "Hello world";

echo "<h1> Hello world </h1>";

echo "<h1 style='color:red;'> Hello world </h1>";

// echo "<script> alert('hello this is alert') </script>";

echo htmlspecialchars("<script> alert('hello this is alert') </script>");

// Operators:
/**
 * 
 * arithmetic operators:
 * +, -, /, *, %
 * 
 * assignment operator:
 * =, +=, -=, /=, *=, %=,
 * 
 * increment operator
 * ++, -- 
 * ++i, --i, i++, i--;
 * 
 * 
 * Relational Operator:
 * 
 * less than- <; greater than- >, less than equal- <=; greater than equal- >=, equality ==, not equal- !=;
 * 
 * logical operator:
 * 
 * !(NOT), &&(AND), ||(OR)
 * 
 *
 * Data type
 * 
 * integer, float -- Number;
 * String -- char sequence;
 * boolean -- true, false;
 * null;
 * array;
 * associative array -- replacement of js object; (key:value pairs.)
 * Resource.
 *  
 */

//

//  if-else statement

// variable : variable name with prefix dollar sign $<name of the variable>

$value = 10;

if ($value < 10) {
    echo "<br>value is less than 10<br>";
} else {
    echo "<br>value is greater than 10<br>";
}



$value = 12;

if ($value < 10) {
    echo "<br>value is less than 10<br>";
} elseif ($value > 10) {
    echo "<br>value is greater than 10<br>";
} else {
    echo "<br>value is equal to 10";
}


function display($string)
{
    echo "<br>" . $string . "<br>";
}


// Other conditional statement: switch statement

$color = 'jgkadjgklajsdlk';

switch ($color) {
    case 'red':
        # code...
        display("Signal is red! Please stop..");
        break;

    case 'green':
        # code...
        display("single is green! you can go");
        break;

    case 'orange':
        # code...
        display("Be careFull signal is going to red");
        break;

    default:
        # code...
        display("system has been crashed");
        break;
}




// loop: for-loop, while-loop, do-while loop;

// initialization, termination condition, increment
for ($i = 0; $i < 10; $i++) {
    display("<div style='background-color: red; display:flex; justify-content:center; align-item:center; width:100px; height:100px'><h1>$i</h1></div>");
}


// while loop

// when to used while loop: whenever we don't know the number of iteration of loop.
$i = 0; // counter initialization.
display("<h1>While loop output:</h1>");
while ($i < 5) {

    display("<div style='background-color: blue; display:flex; justify-content:center; align-item:center; width:100px; height:100px'><h1>$i</h1></div>");
    $i++; // counter increment
}


display("<h1>do-While loop output:</h1>");

$i = 5;
do {
    display("first time runs do while loop");
    $i++;
} while ($i < 10);

// =====================================================================//


// functions: first we use 'function' keyword with postfix function name
// we have parameter list following by function name, in this we can pass n number of arguments.
function myfunc($x, $y)
{
    // it is a non return function.
    $result = $x + $y; // performing mathematical operation.
    display("Result: $x + $y = $result");
}

myfunc(15460, 200);


// function with type restriction
function myfunc2(int $x, int $y)
{
    // it is a non return function.
    $result = $x + $y;
    display("Result: $x + $y = $result");
}


// myfunc("hello", "jello");
// myfunc2(123, "jello");
myfunc2(152, 235);


// function with returning a value.
function func_return(int $x, float $y)
{
    // it is a non return function.
    $result = $x + $y;
    // display("Result: $x + $y = $result");
    return $result;
}


function func_return_int(int $x, float $y): int
{
    // it is a non return function.
    $result = $x + $y;
    // display("Result: $x + $y = $result");
    return $result;
}

function func_pre_defined($x = 100, $y = 10.20)
{
    return $x * $y * $y;
}


$output = func_return(10, 34.9);
$output2 = func_return_int(10, 34.9);
$preoutput = func_pre_defined();
$preoutputx = func_pre_defined(10, 20);

display("output: $output");
display("output2: $output2");
display("Output pre defined values: $preoutput");
display("Output pre defined values: $preoutputx");


// Array 

$array = [3, 4, 5, 5, 6, 8];

// another way to  make array by using the Array() class constructor.
$arr = array(1, 2, 3, 4, 5);

// To print/show the array we need to use print_r() function.

echo "Array 2: ", print_r($arr);

foreach ($array as $value) {
    $value *= $value; // computing square
    display("<div style='background-color: blue; display:flex; justify-content:center; align-item:center; width:100px; height:100px'><h1>$value</h1></div>");
};


// Associative Array: like js object.

$pairs = [
    "name" => "Gotam",
    "age" => 21,
    "height" => 5.6
];

// echo $pairs;
// print_r($pairs);
// echo "<br>";
// print_r(array_keys($pairs));

echo "Name: " . $pairs["name"];

// $_POST // $_GET ->> global variable.


$data = [
    [
        "name" => "Gotam",
        "age" => 21,
        "height" => 5.6
    ],
    [
        "name" => "Suraj",
        "age" => 22,
        "height" => 5.7
    ],
    [
        "name" => "Narendra",
        "age" => 22,
        "height" => 5.5
    ]
];

echo "<br>Column Names: ", print_r(array_keys($data[0]));
