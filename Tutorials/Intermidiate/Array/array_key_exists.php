<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_key_exists</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_key_exists` function. 
* 
* array_key_exists: Checks if the given key or index exists in the array.
* 
*      It returns `true` if the given key is set in the array. `key` can
*      be any value possible for an array index.
* 
* Syntax:
*      array_key_exists(string|int $key, array $array): bool
* 
* Parameters:
* 
*      key:
*          Value to check.
* 
*      array:
*          An array with keys to check.
*     
* Return: 
*      Returns `true` if array is a list, `false` otherwise.
* 
* Errors/Exception:
*      ...
* 
* Note: 
*      it will search for the keys in the first dimension only. Nested 
*      keys in multidimensional arrays will not be found.
*/

</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the `array_key_exists` function. 
     * 
     * array_key_exists: Checks if the given key or index exists in the array.
     * 
     *      It returns `true` if the given key is set in the array. `key` can
     *      be any value possible for an array index.
     * 
     * Syntax:
     *      array_key_exists(string|int $key, array $array): bool
     * 
     * Parameters:
     * 
     *      key:
     *          Value to check.
     * 
     *      array:
     *          An array with keys to check.
     *     
     * Return: 
     *      Returns `true` if array is a list, `false` otherwise.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      it will search for the keys in the first dimension only. Nested 
     *      keys in multidimensional arrays will not be found.
     */

    // 
    // suppose that we have an associative array with key and value pair.
    $array = ["name" => "myName", "age" => 26, "height" => 5.6, "bloodGroup" => "O-"];

    $result = array_key_exists("name", $array);

    show_array($array);

    echo "<br>is name present in the array: ", var_dump($result);
    ?>
</body>

</html>