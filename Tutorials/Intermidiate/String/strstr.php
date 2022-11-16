<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>strstr</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `strstr` function. 
     * 
     * strstr: Find the first occurrence of a string.
     * 
     *      Returns part of `haystack` string starting from and including the first 
     *      occurrence of needle to the end of `haystack`.
     * 
     * Syntax:
     *      strstr(string $string): int
     * 
     * Parameters:
     * 
     *      haystack:
     *          The input string.
     * 
     *      needle:
     *          Prior to PHP 8.0.0, if needle is not a string, it is converted to an 
     *          integer and applied as the ordinal value of a character. This behavior
     *          is deprecated as of PHP 7.3.0, and relying on it is highly discouraged.
     *          Depending on the intended behavior, the needle should either be explicitly 
     *          cast to string, or an explicit call to chr() should be performed.
     * 
     *      before_needle:
     *          if true, strstr() returns the part of the haystack before the first 
     *          occurrence of the needle (excluding the needle)
     *          
     * Return: 
     *      Returns the portion of string, or `false` if `needle` is not found.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      Note strstr() function is case-sensitive. For case-insensitive searches 
     *      we must use stristr() function.
     */
</pre>

    <?php
    include "../Utility.php";
    /**
     * In this section we will learn about the `strstr` function. 
     * 
     * strstr: Find the first occurrence of a string.
     * 
     *      Returns part of `haystack` string starting from and including the first 
     *      occurrence of needle to the end of `haystack`.
     * 
     * Syntax:
     *      strstr(string $string): int
     * 
     * Parameters:
     * 
     *      haystack:
     *          The input string.
     * 
     *      needle:
     *          Prior to PHP 8.0.0, if needle is not a string, it is converted to an 
     *          integer and applied as the ordinal value of a character. This behavior
     *          is deprecated as of PHP 7.3.0, and relying on it is highly discouraged.
     *          Depending on the intended behavior, the needle should either be explicitly 
     *          cast to string, or an explicit call to chr() should be performed.
     * 
     *      before_needle:
     *          if true, strstr() returns the part of the haystack before the first 
     *          occurrence of the needle (excluding the needle)
     *          
     * Return: 
     *      Returns the portion of string, or `false` if `needle` is not found.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      Note strstr() function is case-sensitive. For case-insensitive searches 
     *      we must use stristr() function.
     */
    ?>

    <?php
    put_sep();

    heading(1, "strstr() function");

    $mail = "my_mail_address@domain.com";
    heading(3, "Our string");
    display('p', "my_mail_address@domain.com", "data p-5");

    heading(3, "needle result");
    $result = strstr($mail, "@");
    display('p', "haystack result: " . $result, "data-output p-5");


    ?>
</body>

</html>