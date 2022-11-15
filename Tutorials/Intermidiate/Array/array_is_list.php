<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_is_list</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_is_list` function. 
* 
* array_is_list: Checks whether a given `array` is a list.
* 
*      Determines if the given `array` is a list. An array is considered a list if its keys consist
*      of consecutive numbers from 0 to count($array) -1. 
* 
* Syntax:
*      array_is_list(array $array): bool
* 
* Parameters:
* 
*      array:
*          The array being evaluated.
*     
* Return: 
*      Returns `true` if array is a list, `false` otherwise.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_is_list` function. 
     * 
     * array_is_list: Checks whether a given `array` is a list.
     * 
     *      Determines if the given `array` is a list. An array is considered a list if its keys consist
     *      of consecutive numbers from 0 to count($array) -1. 
     * 
     * Syntax:
     *      array_is_list(array $array): bool
     * 
     * Parameters:
     * 
     *      array:
     *          The array being evaluated.
     *     
     * Return: 
     *      Returns `true` if array is a list, `false` otherwise.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have some array and we want to check that, the array is a list.

    $array1 = ['apple', 2, 3];
    $array2 = [0 => 'apple', 'orange'];
    $array3 = [1 => 'apple', 'orange'];

    $result1 = array_is_list($array1);
    $result2 = array_is_list($array2);
    $result3 = array_is_list($array3);
    // Now first we will print and test each array.

    heading(3, "array 1 is list: ");
    show_array($array1);
    heading(4, "Result: $result1");

    heading(3, "array 2 is list: ");
    show_array($array2);
    heading(4, "Result: $result2");

    heading(3, "array 3 is list: ");
    show_array($array3);
    heading(4, "Result: $result3");


    ?>
</body>

</html>