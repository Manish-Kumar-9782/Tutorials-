<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>number_format</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `number_format` function. 
     * 
     * number_format: Replace all occurrences of the search string with the replacement string.
     *      
     *      This function returns a string or an array with all occurrences of `search`
     *      in subject replaced with the given `replace` value.
     * 
     * Syntax:
     *      number_format(
     *       array|string $search,
     *       array|string $replace,
     *       string|array $subject,
     *       int &$count = null
     *       ): string|array
     * 
     * Parameters:
     *      
     *      if `search` and `replace` are arrays, the number_format() takes a values from each
     *      array and uses them to search and replace on `subject`. 
     * 
     *      if `replace` has fewer values than `search`, then an empty string is used for 
     *      the rest of replacement values. 
     * 
     *      if `search` is an array and replace is string, then this replacement string is 
     *      used for every value of `search`. The converse would not make sense. though.
     * 
     *      if search or replace are arrays, their elements are processed first to last.
     * 
     *      search:
     *          The value being searched for, otherwise known as the needle. An array may
     *          be used to designate multiple needles.
     * 
     *      replace:
     *          The replacement value that replaces found `search` values. An array may be
     *          be used to designate multiple replacement.
     * 
     *      subject:
     *          The string or array being searched and replaced on, otherwise knowns as the 
     *          haystack.
     * 
     *          if `subject` is an array, then the `search` and `replace` is performed with 
     *          every entry of subject, and the return value is an array as well.
     * 
     *      count: 
     *          if passed, this will be set to the number of replacement performed.
     *          
     * Return: 
     *      This function returns a string or an array with the replaced values.
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
     * In this section we will learn about the `number_format` function. 
     * 
     * number_format: Format a number with grouped thousand.
     *      
     *      Formats a number with a grouped thousands and optionally decimal digits.
     * 
     * Syntax:
     *      number_format(
     *       float $num,
     *       int $decimals = 0,
     *       ?string $decimal_separator = ".",
     *       ?string $thousands_separator = ","
     *      ): string
     * 
     * Parameters:
     *      
     *      num:
     *          The number being formatted.
     * 
     *      decimals:
     *          Sets the number of decimal digits. if 0, the decimal_separator is omitted from
     *          the return value.
     * 
     *      decimal_separator:
     *          Sets the separator for the decimal point.
     * 
     *      thousands_separator: 
     *          Sets the thousands separator.
     *          
     * Return: 
     *      A formatted version of `num`.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      ...
     */
    ?>

    <?php
    heading(1, "Formatting Number");
    $number = 1234789456.56;

    heading(2, "Example: English Notation.");

    heading(3, "Our Number: ");
    display("pre", $number, "data", "Our Number: ");
    // Formatting the number
    $formatted = number_format($number);

    heading(3, "Formatted Number: ");
    display("pre", $formatted, "data", "Formatted Number: ");
    put_sep();
    ?>



</body>

</html>