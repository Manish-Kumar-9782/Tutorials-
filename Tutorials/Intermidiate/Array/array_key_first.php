<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_key_first</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
/**
* In this section we will learn about the `array_key_first` function. 
* 
* array_key_first: Gets the first key of an array.
* 
*      Get the first key of the given `array` without affecting the internal 
*      array pointer.
* 
* Syntax:
*      array_key_first(array $array): int|string|null
* 
* Parameters:
* 
*      array:
*          An array with keys to get.
*     
* Return: 
*      Returns the first key of array if the `array` is not empty; `null` otherwise.
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
     * In this section we will learn about the `array_key_first` function. 
     * 
     * array_key_first: Gets the first key of an array.
     * 
     *      Get the first key of the given `array` without affecting the internal 
     *      array pointer.
     * 
     * Syntax:
     *      array_key_first(array $array): int|string|null
     * 
     * Parameters:
     * 
     *      array:
     *          An array with keys to get.
     *     
     * Return: 
     *      Returns the first key of array if the `array` is not empty; `null` otherwise.
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

    $result = array_key_first($array);

    show_array($array);

    echo "<br>First key of the Array: ", $result;
    ?>
</body>

</html>