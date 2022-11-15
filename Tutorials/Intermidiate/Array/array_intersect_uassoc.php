<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_intersect_uassoc</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_intersect_uassoc` function. 
* 
* array_intersect_uassoc: Computes the intersection of arrays with additional index check,
*      compares indexes by a callback function.
* 
*      It returns an array containing all the values of array that are present in all 
*      the arguments. Note that the keys are used in the comparison unlike in `array_intersect()`. 
* 
* Syntax:
*      array_intersect_uassoc(array $array, array ...$arrays, callable $key_compare_func): array
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
*      Returns the value of array whose values exist in all the arguments.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_intersect_uassoc` function. 
     * 
     * array_intersect_uassoc: Computes the intersection arrays using a callback function on the 
     *      keys for comparison.
     * 
     *      it returns an array containing all the values of `array` which have matching keys that 
     *      are present in all the arguments. 
     * 
     * Syntax:
     *      array_intersect_uassoc(array $array, array ...$arrays, callable $key_compare_func): array
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
    $array1 = array("a" => "green", "b" => "brown", "c" => "blue", "red");
    $array2 = array("a" => "GREEN", "b" => "brown", "yellow", "red");

    // intersecting both array
    $result = array_intersect_uassoc($array1, $array2, "strcasecmp");
    // Note strcasecmp is the string case comparison function.

    heading(2, "Intersection Of Arrays:");

    show_array($array1);
    show_array($array2);

    heading(3, "Result:");
    show_array($result);
    ?>
</body>

</html>