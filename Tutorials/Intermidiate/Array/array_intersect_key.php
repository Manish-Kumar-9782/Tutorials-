<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_intersect_key</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_intersect_key` function. 
* 
* array_intersect_key: Compute the intersection of arrays using keys for comparison.
* 
*      It returns an array containing all the entries of `array` which have keys that 
*      are present in all the arguments.
* 
* Syntax:
*      array_intersect_key(array $array, array ...$arrays): array
* 
* Parameters:
* 
*      array:
*          The array with master keys to check.
* 
*      arrays:
*          Array to compare keys against.
*     
* Return: 
*      Returns an associative array containing all the entries of array which have keys
*      that are present in all arguments. 
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_intersect_key` function. 
     * 
     * array_intersect_key: Compute the intersection of arrays using keys for comparison.
     * 
     *      It returns an array containing all the entries of `array` which have keys that 
     *      are present in all the arguments.
     * 
     * Syntax:
     *      array_intersect_key(array $array, array ...$arrays): array
     * 
     * Parameters:
     * 
     *      array:
     *          The array with master keys to check.
     * 
     *      arrays:
     *          Array to compare keys against.
     *     
     * Return: 
     *      Returns an associative array containing all the entries of array which have keys
     *      that are present in all arguments. 
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have an array and we want to intersect those array by considering
    // the keys.

    $array1 = array('blue'  => 1, 'red'  => 2, 'green'  => 3, 'purple' => 4);
    $array2 = array('green' => 5, 'blue' => 6, 'yellow' => 7, 'cyan'   => 8);

    // intersecting both array
    $result = array_intersect_key($array1, $array2);

    heading(2, "Intersection Of Arrays:");

    show_array($array1);
    show_array($array2);

    heading(3, "Result:");
    show_array($result);
    ?>
</body>

</html>