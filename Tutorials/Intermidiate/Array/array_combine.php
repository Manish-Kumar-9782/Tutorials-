<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_combine</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body>
    <pre>
/**
* In this section we will learn about the array_combine function. 
* 
* array_combine: Creates an array by using the values from the keys array as `keys`
*      and the `values` from the values array as the corresponding values. 
* 
* Syntax:
*      array_combine(array $keys, array $values): array
* 
* Parameters:
* 
*      keys:
*          Array of keys to be used. Illegal values for key will be converted to string.
*      
*      values: 
*          Array of values to be used.
* 
* Return: 
*      Return the combined array.
* 
* Errors/Exception:
*      As of PHP 8.0.0, a ValueError is thrown if the number of elements in keys and values 
*      does not match. Prior to PHP 8.0.0, a E_WARNING was emitted instead.
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the array_combine function. 
     * 
     * array_combine: Creates an array by using the values from the keys array as `keys`
     *      and the `values` from the values array as the corresponding values. 
     * 
     * Syntax:
     *      array_combine(array $keys, array $values): array
     * 
     * Parameters:
     * 
     *      keys:
     *          Array of keys to be used. Illegal values for key will be converted to string.
     *      
     *      values: 
     *          Array of values to be used.
     * 
     * Return: 
     *      Return the combined array.
     * 
     * Errors/Exception:
     *      As of PHP 8.0.0, a ValueError is thrown if the number of elements in keys and values 
     *      does not match. Prior to PHP 8.0.0, a E_WARNING was emitted instead.
     */

    //  suppose that we have

    $colors = array('green', 'red', 'yellow');
    $fruits = array('avocado', 'apple', 'banana');

    // Now we will combine both the array, we will use colors array as the key and 
    // fruits array as the values.

    heading(3, "Colors Array:");
    show_array($colors);

    heading(3, "Fruits Array:");
    show_array($fruits);

    heading(3, "Combined array where keys are colors and values are fruits:");
    $combined_array  = array_combine($colors, $fruits);
    show_array($combined_array);
    ?>
</body>

</html>