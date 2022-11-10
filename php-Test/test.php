<?php

echo "Hello world";

echo "<h1> Hello world </h1>";

echo "<h1 style='color:red;'> Hello world </h1>";

// echo "<script> alert('hello this is alert') </script>";

echo htmlspecialchars("<script> alert('hello this is alert') </script>");

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
 * !, &&, ||
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

for ($i = 0; $i < 10; $i++) {
    display("<div style='background-color: red; display:flex; justify-content:center; align-item:center; width:100px; height:100px'><h1>$i</h1></div>");
}
