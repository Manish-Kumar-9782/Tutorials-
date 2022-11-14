<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>array_column</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body>
    <pre>
/**
* In this section we will learn about the array_column function. array_column 
*   function takes the multi-dimensional array.
* 
* array_column:returns the values from a single column of the array, identified 
    by the column_key. Optionally, an index_key may be provided to index the values 
    in the returned array by the values from the index_key column of the input array. 
* 
* Syntax:
*      array_column(array $array, int|string|null $column_key, int|string|null $index_key = null): array
* 
* Parameters:
* 
*      array:
*          A multi-dimensional array or an array of objects from which to pull a column of
*          values from. if an array of objects is provided, then public properties cna be 
*          directly pulled. in order for protected or private properties to be pulled, the 
*          class must implement both the __get() and __isset() magic methods.
*      
*      column_key: 
*          The column of values to return. This value may be integer key  or the column
*          we wish to retrieve, or it may be string key name for an associative array or
*          property name. it may also be `null` to return complete array or object (this
*          is useful together with index_key to re-index the array.)
* 
*      index_key:
*          The column to use as the index/keys for the returned array. This value may be the 
*          integer key of the column, or it may be the string key name. The value is 
*          cast as usual for array keys.
* 
* Return: 
*      Returns an array of values representing a single column from this input array.
*/
</pre>

    <?php
    include "array_extra.php";
    /**
     * In this section we will learn about the array_column function. array_column 
     *   function takes the multi-dimensional array.
     * 
     * array_column:returns the values from a single column of the array, identified 
     *      by the column_key. Optionally, an index_key may be provided to index the values
     *      in the returned array by the values from the index_key column of the input array. 
     * 
     * Syntax:
     *      array_column(array $array, int|string|null $column_key, int|string|null $index_key = null): array
     * 
     * Parameters:
     * 
     *      array:
     *          A multi-dimensional array or an array of objects from which to pull a column of
     *          values from. if an array of objects is provided, then public properties cna be 
     *          directly pulled. in order for protected or private properties to be pulled, the 
     *          class must implement both the __get() and __isset() magic methods.
     *      
     *      column_key: 
     *          The column of values to return. This value may be integer key  or the column
     *          we wish to retrieve, or it may be string key name for an associative array or
     *          property name. it may also be `null` to return complete array or object (this
     *          is useful together with index_key to re-index the array.)
     * 
     *      index_key:
     *          The column to use as the index/keys for the returned array. This value may be the 
     *          integer key of the column, or it may be the string key name. The value is 
     *          cast as usual for array keys.
     * 
     * Return: 
     *      Returns an array of values representing a single column from this input array.
     */

    //  suppose that we have
    $records = array(
        array(
            'id' => 2135,
            'first_name' => 'John',
            'last_name' => 'Doe',
        ),
        array(
            'id' => 3245,
            'first_name' => 'Sally',
            'last_name' => 'Smith',
        ),
        array(
            'id' => 5342,
            'first_name' => 'Jane',
            'last_name' => 'Jones',
        ),
        array(
            'id' => 5623,
            'first_name' => 'Peter',
            'last_name' => 'Doe',
        )
    );
    ?>

    <?php

    echo "<h2>Example 1: Get the column of first name from a record set</h2><br>";

    // now we will apply the array_column function on the record set and 
    // will get the first names.

    $first_name = array_column($records, "first_name");

    // Now we will print the record

    show_array($first_name);

    heading(2, "Get the column of last names from a record set, indexed by the 'id' column.");

    $last_name = array_column($records, "last_name", "id");

    show_array($last_name);

    ?>
</body>

</html>