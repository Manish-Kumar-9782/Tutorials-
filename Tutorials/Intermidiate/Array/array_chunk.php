<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_chunk function</title>
</head>

<body>
    <pre>
/**
 * In this section we will learn about the array_chunk function.
 * 
 * array_chunk: Chunks an array into arrays with `length` elements. The last chunk may 
 * contain less than length elements.
 * 
 * Syntax:
 *      array_chunk(array $array, int $length, bool $preserve_keys = false): array
 * 
 * Parameters:
 * 
 *      value:
 *          The array to work on
 *      
 *      length: 
 *          The size of each chunk
 * 
 *      preserve_keys:
 *          When set to true keys will be preserved. Default is false which will re-index 
 *          the chunk numerically.
 * 
 * Return: 
 *      Returns a multidimensional numerically index array, starting with zero,with 
 *      each dimension containing length element.
 * 
 * Errors/Exceptions:
 *      if length is less than 1 `E_WARNING` will be thrown and null returned.
 *  
 */
</pre>

    <?php

    /**
     * In this section we will learn about the array_chunk function.
     * 
     * array_chunk: Chunks an array into arrays with `length` elements. The last chunk may 
     * contain less than length elements.
     * 
     * Syntax:
     *      array_chunk(array $array, int $length, bool $preserve_keys = false): array
     * 
     * Parameters:
     * 
     *      value:
     *          The array to work on
     *      
     *      length: 
     *          The size of each chunk
     * 
     *      preserve_keys:
     *          When set to true keys will be preserved. Default is false which will re-index 
     *          the chunk numerically.
     * 
     * Return: 
     *      Returns a multidimensional numerically index array, starting with zero,with 
     *      each dimension containing length element.
     * 
     * Errors/Exceptions:
     *      if length is less than 1 `E_WARNING` will be thrown and null returned.
     *  
     */

    //  suppose that we have
    $fruits = array(
        "apple", "mango", "grapes", "pineapple", "strawberry",
        "banana", "kiwi", "coconuts", "Orange"
    );

    echo "<h1>Example 1: chunks without preserving keys.</h1><br>";
    //  example 1: chunks without preserving keys.

    print_r($fruits);

    echo "<br><br>";

    // Now we will make chunks and print it.
    echo "Array(";
    foreach (array_chunk($fruits, 3) as $chunk) {
        echo "<br>", print_r($chunk);
    }
    echo "<br>)";
    echo "<br><br>";

    // Example 2: with preserving keys.

    echo "<h1>Example 2: chunks with preserving keys.</h1><br>";
    print_r($fruits);

    echo "<br><br>";

    // Now we will make chunks and print it.
    echo "Array(";
    foreach (array_chunk($fruits, 3, true) as $chunk) {
        echo "<br>", print_r($chunk);
    }
    echo "<br>)";
    echo "<br><br>";
    ?>
</body>

</html>