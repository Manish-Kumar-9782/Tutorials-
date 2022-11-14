# Array and its Functions

An array is a special variable, which can hold more than one value at a time. An array can hold many values under a single name, and we can access the values by referring to an index number.

## Creating an Array 

The `array()` function is used to create an array or we can use `[]` "brackets".

Here we have three different types of arrays:

* Indexed arrays - Arrays with a numeric index.
* Associative arrays - Arrays with named keys.
* Multidimensional arrays - Arrays containing one or more arrays.

```php
<?php

// Indexed array
$fruits = array("apple", "mango", "grapes","pineapple", "strawberry");

// Associative array.
$data = [
    "name" => "my name",
    "age" => 21,
    "height" => 5.6
]

// Multidimensional array.

$data = [
    [
        "name" => "Gotam",
        "age" => 21,
        "height" => 5.6
    ],
    [
        "name" => "Suraj",
        "age" => 22,
        "height" => 5.7
    ],
    [
        "name" => "Narendra",
        "age" => 22,
        "height" => 5.5
    ],
    [
        "name" => "Manish",
        "age" => 27,
        "height" => 5.6
    ]

];
?>
```

## Array Functions

In this section we will work on some pre-defined array function which can be used during performing operation on the array.

* array()
* count()
* array_chunk()
* array_column()
* array_combine()
* array_count_values()