<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_keys</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `array_keys` function. 
     * 
     * array_keys: Return all the keys or a subset of the keys of an array.
     * 
     *      It return the keys, numeric and string, from the array.
     * 
     *      If a `search_value` is specified, then only the keys for that value are 
     *      returned. Otherwise all the keys from the array are returned.
     * 
     * Syntax:
     *      array_keys(array $array): array
     *      array_keys(array $array, mixed $search_value, bool $strict = false): array
     * 
     * Parameters:
     * 
     *      array:
     *          An array containing keys to return.
     * 
     *      search_value:
     *          if specified, then only keys containing this value are returned.
     * 
     *      strict:
     *          Determine if strict comparison (===) should be used during the search.
     *     
     * Return: 
     *      Returns an array of all the keys in array.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *    
     */
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_keys` function. 
     * 
     * array_keys: Return all the keys or a subset of the keys of an array.
     * 
     *      It return the keys, numeric and string, from the array.
     * 
     *      If a `search_value` is specified, then only the keys for that value are 
     *      returned. Otherwise all the keys from the array are returned.
     * 
     * Syntax:
     *      array_keys(array $array): array
     *      array_keys(array $array, mixed $search_value, bool $strict = false): array
     * 
     * Parameters:
     * 
     *      array:
     *          An array containing keys to return.
     * 
     *      search_value:
     *          if specified, then only keys containing this value are returned.
     * 
     *      strict:
     *          Determine if strict comparison (===) should be used during the search.
     *     
     * Return: 
     *      Returns an array of all the keys in array.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *    
     */

    // 
    // suppose that we have an associative array with key and value pair.
    $array = [
        "name" => "myName", "age" => 26, "height" => 5.6,
        "bloodGroup" => "O-"
    ];

    $result = array_keys($array);

    show_array($array);

    echo "<br>keys of the Array: ";
    show_array($result);
    ?>
</body>

</html>