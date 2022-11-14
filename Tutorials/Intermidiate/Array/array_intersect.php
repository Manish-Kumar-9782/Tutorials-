<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_intersect</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_intersect` function. 
* 
* array_intersect: Computes the intersection of arrays.
* 
*      it returns an array containing all the values of array that are present
*      in all the arguments. Note that keys are preserved.
* 
* Syntax:
*      array_intersect(array $array, array ...$arrays): array
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
*      Returns an array containing all of the values in array whose values exist 
*      in all of the parameters.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_intersect` function. 
     * 
     * array_intersect: Computes the intersection of arrays.
     * 
     *      it returns an array containing all the values of array that are present
     *      in all the arguments. Note that keys are preserved.
     * 
     * Syntax:
     *      array_intersect(array $array, array ...$arrays): array
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
     *      Returns an array containing all of the values in array whose values exist 
     *      in all of the parameters.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have an array and we want to filter that array with the help
    // of the specific callback function.

    $array1 = array("a" => "green", "red", "blue");
    $array2 = array("b" => "green", "yellow", "red");

    // intersecting both array
    $result = array_intersect($array1, $array2);

    heading(2, "Intersection Of Arrays:");

    show_array($array1);
    show_array($array2);

    heading(3, "Result:");
    show_array($result);
    ?>
</body>

</html>