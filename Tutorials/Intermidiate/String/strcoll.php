<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>strcoll</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `strcoll` function. 
     * 
     * strcoll: Locale based string comparison.
     *      
     *      Note that this comparison is case sensitive, and unlike `strcmp()` this function
     *      is not binary safe.
     *      
     *      strcoll() uses the current locale for doing the comparisons. if the current locale 
     *      is C or POSIX, this function is equivalent to strcmp().
     * 
     * Syntax:
     *      strcoll(string $string1, string $string2): int
     * 
     * Parameters:
     *      
     *      string1:
     *          The first string.
     * 
     *      string2:
     *          The second string.
     * 
     * Return: 
     *      if 0    : both are equal.
     *      if &gt;0   : string1 is greater than string2
     *      if &lt;0   : string1 is less than string2 
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
     * In this section we will learn about the `strcoll` function. 
     * 
     * strcoll: Locale based string comparison.
     *      
     *      Note that this comparison is case sensitive, and unlike `strcmp()` this function
     *      is not binary safe.
     *      
     *      strcoll() uses the current locale for doing the comparisons. if the current locale 
     *      is C or POSIX, this function is equivalent to strcmp().
     * 
     * Syntax:
     *      strcoll(string $string1, string $string2): int
     * 
     * Parameters:
     *      
     *      string1:
     *          The first string.
     * 
     *      string2:
     *          The second string.
     * 
     * Return: 
     *      if 0    : both are equal.
     *      if >0   : string1 is greater than string2
     *      if <0   : string1 is less than string2 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      ...
     */
    ?>

    <?php
    heading(1, "String Comparison Non binary safe");
    $str1 = "web";
    $str2 = "web\0x00Development";

    heading(2, "Example: Comparing strings.");

    heading(3, "Our Strings: ");
    display("pre", $str1, "data", "String1: ");
    display("pre", $str2, "data", "String2: ");
    // Formatting the number
    $result = strcoll($str1, $str2);

    heading(3, "Formatted Number: ");
    display("pre", $result, "data", "Formatted Number: ");
    put_sep();
    ?>



</body>

</html>