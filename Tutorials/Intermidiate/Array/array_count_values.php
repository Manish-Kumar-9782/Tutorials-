<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_count_values</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body>
    <pre>
/**
* In this section we will learn about the `array_count_values` function. 
* 
* array_count_values: returns an array using the values of array as keys and their
*      frequency in array as values.
* 
* Syntax:
*      array_count_values(array $array): array
* 
* Parameters:
* 
*      array:
*          The array of value to count.
*      
* Return: 
*      Returns an associative array of values from array as keys and their count as value.
* 
* Errors/Exception:
*      Throws E_WARNING for every element which is not string or int.
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_count_values` function. 
     * 
     * array_count_values: returns an array using the values of array as keys and their
     *      frequency in array as values.
     * 
     * Syntax:
     *      array_count_values(array $array): array
     * 
     * Parameters:
     * 
     *      array:
     *          The array of value to count.
     *      
     * Return: 
     *      Returns an associative array of values from array as keys and their count as value.
     * 
     * Errors/Exception:
     *      Throws E_WARNING for every element which is not string or int.
     */

    //  suppose that we have an array with duplicate values.

    $array = array(1, "hello", 1, "world", "hello", "world", 2, 3, 4, 2, 5, 6, 3, 2, 5, 6, 3);

    // Now we will compute the frequency of each values.
    heading(3, "Original Array: ");
    show_array($array);

    $frequency = array_count_values($array);
    heading(3, "Frequency array returned by array_count_values function: ");
    show_array($frequency);
    ?>
</body>

</html>