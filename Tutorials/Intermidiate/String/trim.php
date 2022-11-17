<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>trim</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `trim` function. 
     * 
     * trim: Strip whitespace (or the other character form the beginning and end of a 
     *      string)
     * 
     *      This function returns a string with whitespace stripped form the beginning 
     *      and end of `string`. Without the second parameter, trim() will strip these 
     *      characters:
     * 
     *      -> " "  :  (ASCII 32 (0x20)), an ordinary space.
     *      -> "\t" :  (ASCII 9 (0x09)), a tab.
     *      -> "\n" :  (ASCII 10 (0x0A)), a new line (line feed).
     *      -> "\r" :  (ASCII 13 (0x0D)), a carriage return.
     *      -> "\0" :  (ASCII 0 (0x00)), the NUL-byte.
     *      -> "\v" :  (ASCII 11 (0x0B)), a vertical tab.
     * 
     * Syntax:
     *      trim(string $string, string $characters = " \n\r\t\v\x00"): string
     * 
     * Parameters:
     * 
     *      string:
     *          The string that will be trimmed.
     * 
     *      characters:
     *          Optionally, the stripped characters can also be specified using the 
     *          characters parameters. Simply list all characters that we want to be 
     *          stripped. Whit
     *          
     * Return: 
     *      The trimmed string.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      Note trim() function is case-sensitive. For case-insensitive searches 
     *      we must use stristr() function.
     */
</pre>

    <?php
    include "../Utility.php";
    /**
     * In this section we will learn about the `trim` function. 
     * 
     * trim: Strip whitespace (or the other character form the beginning and end of a 
     *      string)
     * 
     *      This function returns a string with whitespace stripped form the beginning 
     *      and end of `string`. Without the second parameter, trim() will strip these 
     *      characters:
     * 
     *      -> " "  :  (ASCII 32 (0x20)), an ordinary space.
     *      -> "\t" :  (ASCII 9 (0x09)), a tab.
     *      -> "\n" :  (ASCII 10 (0x0A)), a new line (line feed).
     *      -> "\r" :  (ASCII 13 (0x0D)), a carriage return.
     *      -> "\0" :  (ASCII 0 (0x00)), the NUL-byte.
     *      -> "\v" :  (ASCII 11 (0x0B)), a vertical tab.
     * 
     * Syntax:
     *      trim(string $string, string $characters = " \n\r\t\v\x00"): string
     * 
     * Parameters:
     * 
     *      string:
     *          The string that will be trimmed.
     * 
     *      characters:
     *          Optionally, the stripped characters can also be specified using the 
     *          characters parameters. Simply list all characters that we want to be 
     *          stripped. Whit
     *          
     * Return: 
     *      The trimmed string.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      Note trim() function is case-sensitive. For case-insensitive searches 
     *      we must use stristr() function.
     */
    ?>

    <?php
    heading(1, "Trim character from both ends of string.");
    $text   = "\t\tThese are a few words :) ...  ";
    $binary = "\x09Example string\x0A\t";
    $hello  = "   Hello World  ";
    heading(2, "Example: 1 Removing space, tab and new line characters.");

    heading(3, "Our strings: ");
    display("pre", $text, "data data-bg", "string1: ");
    display("pre", $binary, "data data-bg", "string2: ");
    display("pre", $hello, "data data-bg", "string3: ");


    heading(3, "Trimming strings");
    display("pre", trim($text), "data data-bg", "string1 trimmed: ");
    display("pre", trim($binary), "data data-bg", "string2 trimmed: ");
    display("pre", trim($hello), "data data-bg", "string3 trimmed: ");
    put_sep();
    ?>

    <!-- trim only left portion by using ltrim -->
    <?php

    heading(2, "Example 2: Trimming string only from left side.");
    heading(3, "Our String: ");
    display("pre", $binary, "data data-bg", "String2: ");
    heading(3, "Left Trimmed String:");
    display("pre", ltrim($binary), "data data-bg", "Left Trimmed String2: ");

    ?>

    <!-- trim only right portion by using rtrim -->
    <?php

    heading(2, "Example 2: Trimming string only from Right side.");
    heading(3, "Our String: ");
    display("pre", $binary, "data data-bg", "String2: ");
    heading(3, "Right Trimmed String:");
    display("pre", rtrim($binary), "data data-bg", "Right Trimmed String2: ");

    ?>
</body>

</html>