<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_chunk function</title>
</head>

<body>
    <pre>

/**
* In this section we will see the count method.
* 
* count(): Counts all elements in an array when used with an array. When used 
* with an object that implements the Countable interface, it returns the return 
* value of the method. 
* 
* Syntax: count(Countable|array $value, int $mode = COUNT_NORMAL): int
* 
* Parameters: 
* 
* value: An array or Countable Object.
* 
* mode: if the optional mode parameter is set to COUNT_RECURSIVE (or 1), count() 
* will recursively count the array. This is particularly useful for counting all 
* the elements of a multidimensional array.
* 
* Return: number of elements in values.       
*/

//  Suppose that we have an indexed array with some element
</pre>
    <?php

    /**
     * In this section we will see the count method.
     * 
     * count(): Counts all elements in an array when used with an array. When used 
     * with an object that implements the Countable interface, it returns the return 
     * value of the method. 
     * 
     * Syntax: count(Countable|array $value, int $mode = COUNT_NORMAL): int
     * 
     * Parameters: 
     * 
     * value: An array or Countable Object.
     * 
     * mode: if the optional mode parameter is set to COUNT_RECURSIVE (or 1), count() 
     * will recursively count the array. This is particularly useful for counting all 
     * the elements of a multidimensional array.
     * 
     * Return: number of elements in values.       
     */

    //  Suppose that we have an indexed array with some element

    ?>

    <?php
    $fruits = array("apple", "mango", "grapes", "pineapple", "strawberry");

    // first we will display the array:
    print_r($fruits);

    // Now if we want to count the number of element present in the array then we can
    // use count() function.

    echo "<br>Element present in the array: " . count($fruits) . "<br>";

    ?>
</body>

</html>