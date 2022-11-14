<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_intersect_assoc</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_intersect_assoc` function. 
* 
* array_intersect_assoc: Computes the intersection of arrays with additional index
*      check.
* 
*      it returns an array containing all the values of `array` that are also in the 
*      comparison unlike in array_intersect();
* 
* Syntax:
*      array_intersect_assoc(array $array, array ...$arrays): array
* 
* Parameters:
* 
*      array:
*          The array with master values to check.
* 
*      arrays:
*          Arrays to compare values against.
*     
* Return: 
*      Returns an associative array containing all the values in array that are present 
*      in all of the arguments.
* 
* Errors/Exception:
*      ...
*/

</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_intersect_assoc` function. 
     * 
     * array_intersect_assoc: Computes the intersection of arrays with additional index
     *      check.
     * 
     *      it returns an array containing all the values of `array` that are also in the 
     *      comparison unlike in array_intersect();
     * 
     * Syntax:
     *      array_intersect_assoc(array $array, array ...$arrays): array
     * 
     * Parameters:
     * 
     *      array:
     *          The array with master values to check.
     * 
     *      arrays:
     *          Arrays to compare values against.
     *     
     * Return: 
     *      Returns an associative array containing all the values in array that are present 
     *      in all of the arguments.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have an array and we want to filter that array with the help
    // of the specific callback function.

    $array1 = array("a" => "green", "b" => "brown", "c" => "blue", "red");
    $array2 = array("a" => "green", "b" => "yellow", "blue", "red");

    // intersecting both array 
    $result_array = array_intersect_assoc($array1, $array2);

    heading(2, "Intersection Of Associative Arrays:");

    show_array($array1);
    show_array($array2);

    heading(3, "Result:");
    show_array($result_array);
    ?>

</body>

</html>