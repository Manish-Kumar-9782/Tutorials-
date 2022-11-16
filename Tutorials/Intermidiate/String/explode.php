<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>explode</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `explode` function. 
     * 
     * explode: Split a string by a string.
     * 
     *      Returns an array of strings, each of which is a substrings of `string` formed by
     *      splitting it on boundaries formed by the string `separator`.
     * 
     * Syntax:
     *      explode(string $separator, string $string, int $limit = PHP_INT_MAX): array
     * 
     * Parameters:
     * 
     *      separator:
     *          The boundary string.
     * 
     *      string:
     *          The input string.
     * 
     *      limit:
     *          if limit is set and positive, the returned array will contain a maximum of 
     *          `limit` elements with the last element containing the rest of `string`.
     *          
     *          if the limit parameter is negative, all components except the last-limit are 
     *          returned.
     * 
     *          if the `limit` parameter is zero, then this is treated as 1. 
     *     
     * Return: 
     *      Returns an array of strings create by splitting the `string` parameter on boundaries 
     *      formed by the separator.
     * 
     *      if `separator` is an empty string(""), explode throws an ValueError. if separator 
     *      contains a value that is not contained in `string` a negative `limit` is used, then
     *      an empty array will be returned, otherwise an array containing `string` will be 
     *      returned.  
     * 
     *      if `separator` values appear at the start or end of string said values will be 
     *      added as an empty array values either in the first or last position of the returned array 
     *      respectively.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      ...
     */
</pre>

    <?php
    include "../Utility.php";
    /**
     * In this section we will learn about the `explode` function. 
     * 
     * explode: Split a string by a string.
     * 
     *      Returns an array of strings, each of which is a substrings of `string` formed by
     *      splitting it on boundaries formed by the string `separator`.
     * 
     * Syntax:
     *      explode(string $separator, string $string, int $limit = PHP_INT_MAX): array
     * 
     * Parameters:
     * 
     *      separator:
     *          The boundary string.
     * 
     *      string:
     *          The input string.
     * 
     *      limit:
     *          if limit is set and positive, the returned array will contain a maximum of 
     *          `limit` elements with the last element containing the rest of `string`.
     *          
     *          if the limit parameter is negative, all components except the last-limit are 
     *          returned.
     * 
     *          if the `limit` parameter is zero, then this is treated as 1. 
     *     
     * Return: 
     *      Returns an array of strings create by splitting the `string` parameter on boundaries 
     *      formed by the separator.
     * 
     *      if `separator` is an empty string(""), explode throws an ValueError. if separator 
     *      contains a value that is not contained in `string` a negative `limit` is used, then
     *      an empty array will be returned, otherwise an array containing `string` will be 
     *      returned.  
     * 
     *      if `separator` values appear at the start or end of string said values will be 
     *      added as an empty array values either in the first or last position of the returned array 
     *      respectively.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      ...
     */

    // 
    // suppose that we have an associative array with key and value pair.
    ?>

    <!-- explode Example 1 -->
    <?php

    $pizza  = "piece1 piece2 piece3 piece4 piece5 piece6";

    heading(1, "Example: 1");
    heading(3, "Our String: ");
    display("p", $pizza, "data");

    // Now we will use the explode to split the string by using the separator.
    heading(4, "Splitting/Exploding the string by using the explode() function");
    $result = explode(" ", $pizza);
    show_array_values($result);
    put_sep();
    ?>

    <!-- explode Example 2 -->

    <?php
    heading(1, "Example: 2");
    heading(3, "Our String: ");
    $data = "foo:*:1023:1000::/home/foo:/bin/sh";
    display('p', $data, "data");

    // Now we will explode the string by using the delimiter/separator ':'
    $result = explode(':', $data,);
    show_array_values($result);
    ?>
</body>

</html>