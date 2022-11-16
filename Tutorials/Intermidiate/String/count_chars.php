<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>count_chars</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `count_chars` function. 
     * 
     * count_chars: Returns information about characters used in a string.
     * 
     *      Counts the number of occurrences of every byte-value(0, 255) in string and returns
     *      it in various ways.
     * 
     * Syntax:
     *      count_chars(string $string, int $mode = 0): array|string
     * 
     * Parameters:
     * 
     *      string:
     *          The examined string.
     * 
     *      mode:
     *          See return values.
     *     
     * Return: 
     *      Depending on mode returns one of the following.
     * 
     *      -> 0: an array with byte-value as key and the frequency of every byte 
     *              as value.
     *      -> 1: same as 0 but only byte-values with a frequency greater than zero 
     *              are listed.
     *      -> 2: same as 0 but only byte-values with a frequency equal to zero 
     *              are listed.
     *      -> 3: a string containing all unique characters is returned.
     *      -> 4: a string containing all not used characters is returned.
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
     * In this section we will learn about the `count_chars` function. 
     * 
     * count_chars: Returns information about characters used in a string.
     * 
     *      Counts the number of occurrences of every byte-value(0, 255) in string and returns
     *      it in various ways.
     * 
     * Syntax:
     *      count_chars(string $string, int $mode = 0): array|string
     * 
     * Parameters:
     * 
     *      string:
     *          The examined string.
     * 
     *      mode:
     *          See return values.
     *     
     * Return: 
     *      Depending on mode returns one of the following.
     * 
     *      -> 0: an array with byte-value as key and the frequency of every byte 
     *              as value.
     *      -> 1: same as 0 but only byte-values with a frequency greater than zero 
     *              are listed.
     *      -> 2: same as 0 but only byte-values with a frequency equal to zero 
     *              are listed.
     *      -> 3: a string containing all unique characters is returned.
     *      -> 4: a string containing all not used characters is returned.
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

    <!-- Count chars with mode 0 -->
    <?php

    $data = "Two Ts and one F.";
    $result = count_chars($data, 1); // default mode is 0;

    heading(1, "String: ");
    display("p", $data);
    heading(3, "count_char result with mode 0:");
    show_array($result);
    ?>

    <!-- Count chars with mode 3 -->
    <?php

    $data = "Two Ts and one F.";
    $result = count_chars($data, 3); // default mode is 0;
    // here result will be a string.
    heading(1, "String: ");
    display("p", $data);
    heading(3, "count_char result with mode 3: All unique characters");
    display("p", $result);
    ?>

    <!-- Count chars with mode 4 -->
    <?php

    $data = "Two Ts and one F.";
    $result = count_chars($data, 4); // default mode is 0;
    // here result will be a string.
    heading(1, "String: ");
    display("p", $data);
    heading(3, "count_char result with mode 4: All not used characters");
    display("p", $result);
    ?>
</body>

</html>