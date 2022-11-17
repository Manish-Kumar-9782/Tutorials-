<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>String Test 1</title>
    <link rel="stylesheet" href="../Tutorials/style.css">
</head>

<body>
    <!-- String  -->
    <?php
    include "Utility.php";
    heading(1, "String Test");
    heading(2, "String length:");
    $str = "Hello, this is web development class.";

    heading(3, "Our String:");
    display("p", $str, "data");

    // To compute the length of the string we need to use strlen().

    heading(3, "Length of the string.");
    $len = strlen($str); // to compute the string length
    display('p', "length: " . $len, "data-output p-5");
    put_sep();
    ?>

    <!-- strstr -->

    <?php
    heading(2, "First occurrence of the substring: ");

    $mail = "HelloMailAddress@mailEaxample.com";
    heading(3, "Our Mail Address");
    display('p', $mail, 'data');
    $output = strstr($mail, "@");

    heading(3, "strstr operation output");
    display('p', "Portion after needle: ");
    display("p", $output, 'data');
    put_sep();
    ?>

    <!-- explode or split  -->
    <?php

    heading(2, "Splitting/Exploding our string");
    heading(3, "Our String having some delimiter");
    $str = "Name,Age,Height,BloodGroup";

    display("p", $str, "data");

    // Now we need to split our string
    $arr = explode(",", $str);
    heading(3, "Our splitted/exploded string: ");
    show_array_values($arr);
    show_array($arr);
    put_sep();
    ?>

    <!-- strcmp compare two string. -->
    <?php
    heading(1, "Comparing two string: ");
    heading(2, "Example 1: both string are equal");

    $str1 = "hello";
    $str2 = "hello";
    $str3 = "abcdef";
    $str4 = "fedcba";

    heading(3, "First string");
    display('p', "<b>String: </b>: " . $str1, "data");
    heading(3, "Second string");
    display('p', "<b>String: </b>: " . $str2, "data");

    heading(4, "Result of compared strings: ");
    $result = strcmp($str1, $str2);
    display("p", "Result: " . $result, "data-output p-5");

    /**
     * 0: both string are equal.
     * 1/ >0: string1 is greater than string2 
     * -1/ <0: string1 is less than string2
     */

    heading(2, "Example 2: string1 > string2");
    heading(3, "First string");
    display('p', "<b>String: </b>: " . $str2, "data");
    heading(3, "Second string");
    display('p', "<b>String: </b>: " . $str3, "data");

    heading(4, "Result of compared strings: ");
    $result = strcmp($str2, $str3);
    display("p", "Result: " . $result, "data-output p-5");



    heading(2, "Example 3: string1 < string2");
    heading(3, "First string");
    display('p', "<b>String: </b>: " . $str3, "data");
    heading(3, "Second string");
    display('p', "<b>String: </b>: " . $str4, "data");

    heading(4, "Result of compared strings: ");
    $result = strcmp($str3, $str4);
    display("p", "Result: " . $result, "data-output p-5");
    put_sep();
    ?>

    <!-- strpos -->
    <!-- Finding Position of substring with strpos function  -->
    <?php
    heading(1, "Finding position of substring: ");
    // strpos()
    heading(3, "Our string: ");
    $str = "Hello, i M NoOne, and who are you.!!!!";

    display('p', "<b>String: </b> " . $str, "data");
    // Now we will find the position of the NoOne;

    $pos = strpos($str, "NoOne");
    heading(3, "Result of strpos function: ");
    display('p', "<b>Output: </b> Position of 'NoOne': " . $pos, "data");
    put_sep();
    ?>

    <!-- trim -->
    <!-- Remove whitespace by using the trim function. -->
    <?php

    heading(1, "Remove leading edge whitespace");
    heading(3, "Our string");

    $str = "    Jello, Hello,   ";

    display('pre', $str, "data data-bg", "String: ");
    // Now we will remove additional leading edge whitespace form the string.
    // using the trim method.

    $trimmed_str = trim($str);
    heading(3, "Result of trim operation: ");
    display('pre', $trimmed_str, "data data-bg", "Output: ");
    put_sep();
    ?>

    <!-- count chars -->
    <?php
    heading(1, "Counting each character frequency from a string.");
    heading(3, "Our String");
    $str = "HelloMailAddress@mailEaxample.com";
    display('pre', $str, "data", "String: ");


    $result = count_chars($str, 3); // by default mode 0;
    heading(3, "Output: ");
    // show_array($result);
    display('pre', $result, "data", "All Unique Chars: ");
    put_sep();
    ?>

    <!-- string reverse -->

    <?php
    heading(1, "Reverse a String.");
    heading(3, "Our String");
    $str = "HelloMailAddress@mailEaxample.com";
    display('pre', $str, "data", "String: ");


    $result = strrev($str);
    heading(3, "Output: ");
    // show_array($result);
    display('pre', $result, "data", "Reversed String: ");
    put_sep();
    ?>

    <?php
    heading(1, "Replacing a String");
    heading(3, "Our String");
    $str = "HelloMailAddress@mailEaxample.com";
    display('pre', $str, "data", "String: ");


    $result = str_replace("Address", "Gotam", $str); //
    heading(3, "Output: ");
    // show_array($result);
    display('pre', $result, "data", "Reversed String: ");


    echo "<br><br>";

    // a,e,i,o,u

    $items = ['a', 'e', 'i', 'o', 'u'];
    heading(2, "Replacing characters: ");
    display('pre', $str, "data", "String: ");
    heading(3, "Replace These character by .");

    $replaced = str_replace($items, ".", $str);
    display('pre', $replaced, "data", "String: ");

    put_sep();

    // Replacing a sequence of word with another sequence of words.


    heading(2, "Replacing a sequence of word with another sequence of word.");
    $str = "Gotam,21,5.7,B+";
    $seq1 = ["Gotam", "21", "5.7", "B+"];
    $seq2 = ["Narendra", "22", "5.6", "A+"];

    display('pre', $str, "data", "Subject String: ");

    heading(3, "Search Sequence:");
    show_array_values($seq1);

    heading(3, "Replace Sequence");
    show_array_values($seq2);

    heading(3, "Output: ");
    $replaced = str_replace($seq1, $seq2, $str);
    display('pre', $replaced, "data", "Replaced String: ");

    ?>
</body>

</html>