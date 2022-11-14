<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_fill</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre>
/**
* In this section we will learn about the `array_fill` function. 
* 
* array_fill: Fill an array with values.
* 
*      Fills an array with count entries of the values of the `value` parameter, keys
*      starting at the `start_index` parameter.
* 
* Syntax:
*      array_fill(int $start_index, int $count, mixed $value): array
* 
* Parameters:
* 
*      start_index:
*          The first index of the returned array.
* 
*          If `start_index` is negative, the first index of the returned array 
*          will be `start_index` and the following indices will start from zero.
* 
*      count:
*          Number of element ot insert. Must be greater than or equal to zero.
* 
*      value:
*          Value to use for filling.
*      
* Return: 
*      Return the filled array.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_fill` function. 
     * 
     * array_fill: Fill an array with values.
     * 
     *      Fills an array with count entries of the values of the `value` parameter, keys
     *      starting at the `start_index` parameter.
     * 
     * Syntax:
     *      array_fill(int $start_index, int $count, mixed $value): array
     * 
     * Parameters:
     * 
     *      start_index:
     *          The first index of the returned array.
     * 
     *          If `start_index` is negative, the first index of the returned array 
     *          will be `start_index` and the following indices will start from zero.
     * 
     *      count:
     *          Number of element ot insert. Must be greater than or equal to zero.
     * 
     *      value:
     *          Value to use for filling.
     *      
     * Return: 
     *      Return the filled array.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we want make an array by filling a value with `count` number of 
    // times.

    $array1 = array_fill(5, 6, "true");
    // array1 filling with 6 "true" values whose index will start from 5.
    $array2 = array_fill(-2, 4, "false");
    // array 2 filling with 4 "false" values whose first index will be -2. 

    // first we will print both the array.
    heading(3, "Filling Array ");

    display("p", "array1 filling with 6 'true' values whose index will start from 5.");
    show_array($array1);

    display("p", "array2 filling with 4 'false' values whose first index will be -2. ");
    show_array($array2);
    ?>
</body>

</html>