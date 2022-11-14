<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_diff_assoc</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre>
/**
* In this section we will learn about the `array_diff_assoc` function. 
* 
* array_diff_assoc: Compares array against arrays and returns that difference. Unlike 
*      array_diff() the array keys are also used in the comparison.
* 
* Syntax:
*      array_diff_assoc(array $array, array ...$arrays): array
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
*      Returns an array containing all the values from array that are not present
*      in any of the other arrays.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_diff_assoc` function. 
     * 
     * array_diff_assoc: Compares array against arrays and returns that difference. Unlike 
     *      array_diff() the array keys are also used in the comparison.
     * 
     * Syntax:
     *      array_diff_assoc(array $array, array ...$arrays): array
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
     *      Returns an array containing all the values from array that are not present
     *      in any of the other arrays.
     * 
     * Errors/Exception:
     *      ...
     */

    //  suppose that we have multiple arrays.

    $array1 = array("a" => "green", "b" => "brown", "c" => "blue", "red");
    $array2 = array("a" => "green", "yellow", "red");

    // Now if we compare array1 with array2 then it will returns all the entries
    // that are not present in the second array.

    // first we will print both the array.
    heading(3, "Arrays to be compared: ");
    show_array($array1);
    show_array($array2);

    $diff = array_diff_assoc($array1, $array2);

    heading(3, "compared array: ");
    display("p", "This array contains the missing values in other array. Note that 
    we are comparing array with considering the keys also.");
    show_array($diff);

    ?>
</body>

</html>