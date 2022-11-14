<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_flip</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_flip` function. 
* 
* array_flip: Filters elements of an array using a callback function.
* 
*      Iterates over each value in the `array` passing them to the `callback`
*      function. if the `callback` function return 'true', the current value
*      from `array` is returned into the result array.
* 
*      Array keys are preserved, and may result in gaps if the `array` was indexed.
*      The result array can be reindexed using the `array_values()` function.  
* 
* Syntax:
*      array_flip(array $array, ?callable $callback = null, int $mode = 0): array
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
*              * array_flip_USE_KEY - pass key as the only argument to `callback` 
*                  instead of the value.
*              
*              * array_flip_USE_BOTH - pass both value and key as argument to `callback`
*                  instead of the value.
*          
*          Default is 0 which will pass value as the only argument to `callback` instead. 
* 
* <b style="color:orange;">Return</b>: 
*      Return the filtered array.
* 
* Errors/Exception:
*      ...
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_flip` function. 
     * 
     * array_flip: Exchanges all keys with their associated values in an array.
     * 
     *      it returns an array in flip order, e.g keys from `array` becomes values 
     *      and values from `array` becomes keys. 
     * 
     *      Note that values of `array` need to be valid keys. i.e. they need to be 
     *      either int or string. A warning will be emitted if a value has the wrong
     *      type, and the key/value pair in question will not be included in the result.
     * 
     *      if a value has several occurrences, the latest key will be used as its value
     *      , and all other will be lost.
     * 
     * Syntax:
     *      array_flip(array $array): array
     * 
     * Parameters:
     * 
     *      array:
     *          An array of key/value pairs to be flipped.
     *     
     * Return: 
     *      Return the flipped array.
     * 
     * Errors/Exception:
     *      ...
     */

    // Suppose that we have an array and we want to filter that array with the help
    // of the specific callback function.

    $input = array("oranges", "apples", "pears");
    $flipped = array_flip($input);

    heading(2, "Flipping Array:");

    heading(3, "Flipping Indexed array.");
    show_array($input);
    heading(4, "Flipped Array:");
    show_array($flipped);

    put_sep(); // add a new line and a separator.

    $input = array("a" => 1, "b" => 1, "c" => 2);
    $flipped = array_flip($input); // flipping associative array.
    heading(3, "Flipping Associative Array.");
    show_array($input);
    heading(4, "Flipped Array:");
    show_array($flipped);
    ?>
</body>

</html>