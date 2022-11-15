<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_intersect_ukey</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_intersect_ukey` function. 
* 
* array_intersect_ukey: Computes the intersection arrays using a callback function on the 
*      keys for comparison.
* 
*      it returns an array containing all the values of `array` which have matching keys that 
*      are present in all the arguments. 
* 
* Syntax:
*      array_intersect_ukey(array $array, array ...$arrays, callable $key_compare_func): array
* 
* Parameters:
* 
*      array:
*          Initial array for comparison of the arrays.
* 
*      arrays:
*          Arrays to compare keys against.
* 
*      key_compare_func:
*          The comparison function must return an integer less than, equal to, or greater than
*          zero if the first argument is considered to be respectively less than, equal to, or greater
*          than the second.
* 
*          callback(mixed $a, mixed $b): int
*     
* Return: 
*      Returns the value of `array` whose keys exist in all the arguments.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_intersect_ukey` function. 
     * 
     * array_intersect_ukey: Computes the intersection arrays using a callback function on the 
     *      keys for comparison.
     * 
     *      it returns an array containing all the values of `array` which have matching keys that 
     *      are present in all the arguments. 
     * 
     * Syntax:
     *      array_intersect_ukey(array $array, array ...$arrays, callable $key_compare_func): array
     * 
     * Parameters:
     * 
     *      array:
     *          Initial array for comparison of the arrays.
     * 
     *      arrays:
     *          Arrays to compare keys against.
     * 
     *      key_compare_func:
     *          The comparison function must return an integer less than, equal to, or greater than
     *          zero if the first argument is considered to be respectively less than, equal to, or greater
     *          than the second.
     * 
     *          callback(mixed $a, mixed $b): int
     *     
     * Return: 
     *      Returns the value of `array` whose keys exist in all the arguments.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have an array and we want to intersect those array by considering
    // key_compare_func function.

    function key_compare_func($key1, $key2)
    {
        if ($key1 == $key2)
            return 0;
        else if ($key1 > $key2)
            return 1;
        else
            return -1;
    }

    $array1 = array('blue'  => 1, 'red'  => 2, 'green'  => 3, 'purple' => 4);
    $array2 = array('green' => 5, 'blue' => 6, 'yellow' => 7, 'cyan'   => 8);

    // intersecting both array
    $result = array_intersect_ukey($array1, $array2, "key_compare_func");

    heading(2, "Intersection Of Arrays:");

    show_array($array1);
    show_array($array2);

    heading(3, "Result:");
    show_array($result);
    ?>
</body>

</html>