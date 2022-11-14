<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_diff</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre>
/**
* In this section we will learn about the `array_diff` function. 
* 
* array_diff: Compares array against one or more other arrays and returns the values in 
*      array that are not present in any of the other arrays.
* 
* Syntax:
*      array_diff(array $array, array ...$arrays): array
* 
* Parameters:
* 
*      array:
*          The array to compare from.
* 
*      arrays:
*          Arrays to compare against.
*      
* Return: 
*      Returns an array containing all the entries from array that are not present in 
*      any of the other arrays. Keys in the array array are preserved.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_diff` function. 
     * 
     * array_diff: Compares array against one or more other arrays and returns the values in 
     *      array that are not present in any of the other arrays.
     * 
     * Syntax:
     *      array_diff(array $array, array ...$arrays): array
     * 
     * Parameters:
     * 
     *      array:
     *          The array to compare from.
     * 
     *      arrays:
     *          Arrays to compare against.
     *      
     * Return: 
     *      Returns an array containing all the entries from array that are not present in 
     *      any of the other arrays. Keys in the array array are preserved.
     * 
     * Errors/Exception:
     *      ...
     */

    //  suppose that we have multiple arrays.

    $array1 = array("a" => "green", "red", "blue", "red");
    $array2 = array("b" => "green", "yellow", "red");

    // Now if we compare array1 with array2 then it will returns all the entries
    // that are not present in the second array.

    // first we will print both the array.
    heading(3, "Arrays to be compared: ");
    show_array($array1);
    show_array($array2);

    $diff = array_diff($array1, $array2);

    heading(3, "compared array: ");
    display("p", "This array contains the missing values in other array.");
    show_array($diff);

    ?>
</body>

</html>