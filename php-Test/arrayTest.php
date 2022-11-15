<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Array Test</title>
    <link rel="stylesheet" href="../Tutorials/style.css">

</head>

<body>

    <?php

    include "array_extra.php";

    heading(1, "Array Chunk");

    $array1 = ["manish", "gotam", "suraj", "narendra", "ashok", "abhi", "kushal", "ravi", "varsha", "komal", "saloni", "khushi"];

    heading(3, "Array to be Chunked: ");
    show_array($array1);
    // print_r($array1);

    $chunks = array_chunk($array1, 4);
    heading(3, "Chunked arrays: ");

    echo "<div style='padding-left:15px;'> <b style='margin-top:30px;'><br>Array (</br>";

    foreach ($chunks as $chunk) {
        show_array($chunk);
    }

    echo "<b>)</b> </div>";


    $array2 = [

        "color" => "red",
        "name" => "manish",
        "height" => 5.7,
        "blood group" => "O-",
        "hobby" => "Playing PC Games",
        "Profession" => "Teaching and Torture",

    ];


    heading(3, "Chunking Associative array");

    show_array($array2);

    heading(3, "chunked Associative array");
    $chunks = array_chunk($array2, 3, true);
    echo "<div style='padding-left:15px;'> <b style='margin-top:30px;'><br>Array (</br>";

    foreach ($chunks as $chunk) {
        show_array($chunk);
    }

    echo "<b>)</b> </div>";

    ?>


    <?php
    // array column
    put_sep();
    heading(1, "Array_column");

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

    heading(3, "Records with associative array");

    echo "<div style='padding-left:15px;'> <b style='margin-top:30px;'><br>Array (</br>";
    foreach ($records as $record) {
        show_array($record);
    }

    echo "<b>)</b> </div>";

    heading(4, "Example 1: Get the all id from the record data set.");
    $data  = array_column($records, 'id', 'first_name');

    heading(4, "Retrieved ids from records");
    show_array($data);

    ?>

    <?php
    put_sep();
    heading(1, "array_combine function");

    // suppose that we have two array one contains keys and other contains values.

    $colors = array('green', 'red', 'yellow'); // key
    $fruits = array('avocado', 'apple', 'banana'); // values

    heading(3, "array which contains keys: ");
    show_array($colors);

    heading(3, "array which contains values: ");
    show_array($fruits);


    heading(2, "Combined array");
    $combined = array_combine($colors, $fruits);
    show_array($combined);

    ?>
</body>

</html>