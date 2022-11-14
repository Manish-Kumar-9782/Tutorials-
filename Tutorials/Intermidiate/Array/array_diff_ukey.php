<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_diff_ukey</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre>
/**
* In this section we will learn about the `array_diff_ukey` function. 
* 
* array_diff_ukey: Compute the difference of arrays using a callback function
*      on the keys for comparison.
* 
*      Compares the keys from array against the keys from arrays and return the 
*      difference. This function is like `array_diff()` except the comparison is 
*      done on the keys instead of the values.
* 
*      Unlike `array_diff_key()` a user supplied callback function is used for the 
*      indices comparison, not internal function.
* 
* Syntax:
*      array_diff_ukey(array $array, array ...$arrays, callable $key_compare_func): array
* 
* Parameters:
* 
*      array:
*          The array to compare from.
* 
*      arrays:
*          Arrays to compare against.
* 
*      key_compare_func:
*          The comparison function must return an integer less than, equal to, or 
*          greater than zero if the first argument is considered to be respectively 
*          less than, equal to, or greater than the second.
* 
*          callback(mixed $a, mixed $b): int
*      
* Return: 
*      Returns an array containing all the entries from array that are not present 
*      in any of the other arrays.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_diff_ukey` function. 
     * 
     * array_diff_ukey: Compute the difference of arrays using a callback function
     *      on the keys for comparison.
     * 
     *      Compares the keys from array against the keys from arrays and return the 
     *      difference. This function is like `array_diff()` except the comparison is 
     *      done on the keys instead of the values.
     * 
     *      Unlike `array_diff_key()` a user supplied callback function is used for the 
     *      indices comparison, not internal function.
     * 
     * Syntax:
     *      array_diff_ukey(array $array, array ...$arrays, callable $key_compare_func): array
     * 
     * Parameters:
     * 
     *      array:
     *          The array to compare from.
     * 
     *      arrays:
     *          Arrays to compare against.
     * 
     *      key_compare_func:
     *          The comparison function must return an integer less than, equal to, or 
     *          greater than zero if the first argument is considered to be respectively 
     *          less than, equal to, or greater than the second.
     * 
     *          callback(mixed $a, mixed $b): int
     *      
     * Return: 
     *      Returns an array containing all the entries from array that are not present 
     *      in any of the other arrays.
     * 
     * Errors/Exception:
     *      ...
     */

    //  suppose that we have multiple arrays.

    function key_compare_func($key1, $key2)
    {
        if ($key1 == $key2)
            return 0; // match found
        else if ($key1 > $key2)
            return 1; // match not found
        else
            return -1; // match not found
    }

    $array1 = array('blue'  => 1, 'red'  => 2, 'green'  => 3, 'purple' => 4);
    $array2 = array('green' => 5, 'blue' => 6, 'yellow' => 7, 'cyan'   => 8);

    // Now if we compare array1 with array2 then it will returns all the entries
    // that are not present in the second array.

    // first we will print both the array.
    heading(3, "Arrays to be compared: ");
    show_array($array1);
    show_array($array2);

    $diff = array_diff_ukey($array1, $array2, "key_compare_func");

    heading(3, "compared array: ");
    display("p", "This array contains the missing values in other array.");
    show_array($diff);

    ?>
</body>

</html>