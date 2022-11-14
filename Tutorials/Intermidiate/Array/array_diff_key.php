<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_diff_key</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre>
/**
* In this section we will learn about the `array_diff_key` function. 
* 
* array_diff_key: Compares the keys from array against the keys from arrays and 
*      returns the difference. This function is like `array_diff()` except the 
*      comparison is done on the keys instead of the values.
* 
* Syntax:
*      array_diff_key(array $array, array ...$arrays): array
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
*      Returns an array containing all the entries from array whose keys are 
*      absent from all of the other arrays.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_diff_key` function. 
     * 
     * array_diff_key: Compares the keys from array against the keys from arrays and 
     *      returns the difference. This function is like `array_diff()` except the 
     *      comparison is done on the keys instead of the values.
     * 
     * Syntax:
     *      array_diff_key(array $array, array ...$arrays): array
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
     *      Returns an array containing all the entries from array whose keys are 
     *      absent from all of the other arrays.
     * 
     * Errors/Exception:
     *      ...
     */

    //  suppose that we have multiple arrays.

    $array1 = array('blue' => 1, 'red' => 2, 'green' => 3, 'purple' => 4);
    $array2 = array('green' => 5, 'yellow' => 7, 'cyan' => 8);

    // Now if we compare array1 with array2 then it will returns all the entries
    // that are not present in the second array.

    // first we will print both the array.
    heading(3, "Arrays to be compared: ");
    show_array($array1);
    show_array($array2);

    $diff = array_diff_key($array1, $array2);

    heading(3, "compared array: ");
    display("p", "This array contains the missing values in other array.");
    show_array($diff);

    ?>
</body>

</html>