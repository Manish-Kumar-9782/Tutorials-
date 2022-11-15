<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Array Functions</title>
    <link rel="stylesheet" href="../Tutorials/style.css">
</head>

<body>

    <!-- Count the array length -->
    <?php

    include "array_extra.php";

    $array1 = [
        "manish", "gotam", "suraj", "narendra", "ashok", "abhi",
        "kushal", "ravi", "varsha", "komal", "saloni", "khushi"
    ];

    heading(1, "Count the array length");

    heading(3, "Array: ");
    show_array_values($array1, 5);
    $len = count($array1); // counting array length
    display("p", "length of the array: $len");

    put_sep();
    ?>

    <!-- Count the array_values: compute the frequency of items with the same values. -->

    <?php

    $array = [
        1, 3, 4, 6, 3, 6, 6, 3, 6, 2, 6, 7, 8, 2, 3,
        6, 7, 9, 2, 3, 4, 7, 6, 7, 8, 2, 1, 5, 6, 8, 9, 3, 9
    ];
    $len = count($array);
    display("p", "length of array: $len");

    heading(3, "Our Original array: ");
    show_array_values($array, 10);
    // show_array($array);
    $freq_array = array_count_values($array);
    heading(3, "frequency array: ");
    show_array($freq_array);
    put_sep();
    ?>

    <!-- array difference -->

    <?php

    $array1 = array("a" => "green", "red", "blue", "red");
    $array2 = array("b" => "green", "yellow", "red");

    heading(1, "Array Difference");

    heading(3, "Array 1");
    show_array($array1);

    heading(3, "Array 2");
    show_array($array2);

    heading(3, "Diff Array");

    show_array(array_diff($array1, $array2));
    // 
    put_sep();
    ?>

    <!-- Array filter function -->

    <?php
    heading(1, "Array Filter");

    heading(3, "Array to filter");

    $array1 = ['a' => 1, 'b' => 2, 'c' => 3, 'd' => 4, 'e' => 5];
    $array2 = [6, 7, 8, 9, 10, 11, 12];
    $array3 = [
        1, 3, 4, 6, 3, 6, 6, 3, 6, 2, 6, 7, 8, 2, 3,
        6, 7, 9, 2, 3, 4, 7, 6, 7, 8, 2, 1, 5, 6, 8, 9, 3, 9
    ];
    show_array($array1);
    show_array($array2);

    function odd($value)
    {

        if ($value % 2 != 0) {
            return true;
        }
    }

    function even($value)
    {

        if ($value % 2 == 0) {
            return true;
        }
    }

    $odd_result = array_filter($array1, "odd");
    heading(3, "filtered odd numbers");
    show_array_values(array_values($array1), 10);
    show_array($odd_result);


    $even_result = array_filter($array3, "even");
    heading(3, "filtered even numbers");
    show_array_values($array3, 10);
    // show_array($even_result);
    show_array_values(array_values($even_result), 5);
    put_sep();
    ?>

    <!-- Array Fill -->

    <?php
    heading(1, "Array Fill");
    heading(3, "Filled array");

    $array1 = array_fill(2, 4, "varsha");
    $array2 = array_fill(-2, 5, "abhishek");
    // start index: from where our index should start.
    // count: how many times our element should repeat.
    // value: value which to be filled in array.
    show_array($array1);
    show_array($array2);
    put_sep();
    ?>

    <?php

    heading(1, "Array keys");
    $array2 = [

        "color" => "red",
        "name" => "manish",
        "height" => 5.7,
        "blood group" => "O-",
        "hobby" => "Playing PC Games",
        "Profession" => "Teaching and Torture",

    ];

    show_array($array2);
    heading(3, "keys of array: ");
    show_array(array_keys($array2));
    // show_array_values(array_keys($array2), 10);
    put_sep();
    ?>


    <!-- Array values-->

    <?php

    heading(1, "Array Values");
    $array2 = [

        "color" => "red",
        "name" => "manish",
        "height" => 5.7,
        "blood group" => "O-",
        "hobby" => "Playing PC Games",
        "Profession" => "Teaching and Torture",

    ];

    show_array($array2);
    heading(3, "values of array: ");
    show_array(array_values($array2));
    // show_array_values(array_keys($array2), 10);

    ?>
</body>

</html>