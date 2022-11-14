<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_fill_keys</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_fill_keys` function. 
* 
* array_fill_keys: Fill an array with values, specifying keys.
* 
*      Fills an array with the values of the `value` parameter, using the values
*      of the keys array as keys.
* 
* Syntax:
*      array_fill_keys(array $keys, mixed $value): array
* 
* Parameters:
* 
*      keys:
*          Array of values that will be used as keys. Illegal values for keys will
*          be converted to string.
* 
*      value:
*          Value to use for filling.
* 
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
     * In this section we will learn about the `array_fill_keys` function. 
     * 
     * array_fill_keys: Fill an array with values, specifying keys.
     * 
     *      Fills an array with the values of the `value` parameter, using the values
     *      of the keys array as keys.
     * 
     * Syntax:
     *      array_fill_keys(array $keys, mixed $value): array
     * 
     * Parameters:
     * 
     *      keys:
     *          Array of values that will be used as keys. Illegal values for keys will
     *          be converted to string.
     * 
     *      value:
     *          Value to use for filling.
     * 
     *      
     * Return: 
     *      Return the filled array.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we want make an array by filling a value with `count` number of 
    // times.

    $array1 = array('one', 2, 4, "four");
    // array1 filling with 6 "true" values whose index will start from 5.
    $array2 = array_fill_keys($array1, "true");
    // array 2 filling with 4 "false" values whose first index will be -2. 

    // first we will print both the array.
    heading(3, "Filling Array By using keys");

    display("p", "The array which contain the keys for filling the array.");
    show_array($array1);

    display("p", "The array which is filled by using the keys array.");
    show_array($array2);
    ?>
</body>

</html>