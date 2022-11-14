<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_filter</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_filter` function. 
* 
* array_filter: Filters elements of an array using a callback function.
* 
*      Iterates over each value in the `array` passing them to the `callback`
*      function. if the `callback` function return 'true', the current value
*      from `array` is returned into the result array.
* 
*      Array keys are preserved, and may result in gaps if the `array` was indexed.
*      The result array can be reindexed using the `array_values()` function.  
* 
* Syntax:
*      array_filter(array $array, ?callable $callback = null, int $mode = 0): array
* 
* Parameters:
* 
*      array:
*          The array to iterate over.
* 
*      callback:
*          The callback function to use.
* 
*          if no callback is supplied, all empty entries of `array` will be removed
* 
*      mode:
*          Flag determining what argument are sent to callback:
*              
*              * ARRAY_FILTER_USE_KEY - pass key as the only argument to `callback` 
*                  instead of the value.
*              
*              * ARRAY_FILTER_USE_BOTH - pass both value and key as argument to `callback`
*                  instead of the value.
*          
*          Default is 0 which will pass value as the only argument to `callback` instead. 
* 
* Return: 
*      Return the filtered array.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_filter` function. 
     * 
     * array_filter: Filters elements of an array using a callback function.
     * 
     *      Iterates over each value in the `array` passing them to the `callback`
     *      function. if the `callback` function return 'true', the current value
     *      from `array` is returned into the result array.
     * 
     *      Array keys are preserved, and may result in gaps if the `array` was indexed.
     *      The result array can be reindexed using the `array_values()` function.  
     * 
     * Syntax:
     *      array_filter(array $array, ?callable $callback = null, int $mode = 0): array
     * 
     * Parameters:
     * 
     *      array:
     *          The array to iterate over.
     * 
     *      callback:
     *          The callback function to use.
     * 
     *          if no callback is supplied, all empty entries of `array` will be removed
     * 
     *      mode:
     *          Flag determining what argument are sent to callback:
     *              
     *              * ARRAY_FILTER_USE_KEY - pass key as the only argument to `callback` 
     *                  instead of the value.
     *              
     *              * ARRAY_FILTER_USE_BOTH - pass both value and key as argument to `callback`
     *                  instead of the value.
     *          
     *          Default is 0 which will pass value as the only argument to `callback` instead. 
     * 
     * Return: 
     *      Return the filtered array.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have an array and we want to filter that array with the help
    // of the specific callback function.

    $array1 = ['a' => 1, 'b' => 2, 'c' => 3, 'd' => 4, 'e' => 5];
    $array2 = [6, 7, 8, 9, 10, 11, 12];
    show_array($array1);
    show_array($array2);

    function odd($var)
    {
        // returns whether the input integer is odd
        return $var & 1;
    }

    function even($var)
    {
        // returns whether the input integer is even
        return !($var & 1);
    }

    // first we will print both the array.
    heading(3, "Filtering Array:");

    heading(4, "Filtering odd values:");
    show_array(array_filter($array1, "odd"));

    heading(4, "Filtering even values:");
    show_array(array_filter($array2, "even"));
    ?>
</body>

</html>