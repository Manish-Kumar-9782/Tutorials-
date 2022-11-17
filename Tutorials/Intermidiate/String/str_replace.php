<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>str_replace</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `str_replace` function. 
     * 
     * str_replace: Replace all occurrences of the search string with the replacement string.
     *      
     *      This function returns a string or an array with all occurrences of `search`
     *      in subject replaced with the given `replace` value.
     * 
     * Syntax:
     *      str_replace(
     *       array|string $search,
     *       array|string $replace,
     *       string|array $subject,
     *       int &$count = null
     *       ): string|array
     * 
     * Parameters:
     *      
     *      if `search` and `replace` are arrays, the str_replace() takes a values from each
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
     * In this section we will learn about the `str_replace` function. 
     * 
     * str_replace: Replace all occurrences of the search string with the replacement string.
     *      
     *      This function returns a string or an array with all occurrences of `search`
     *      in subject replaced with the given `replace` value.
     * 
     * Syntax:
     *      str_replace(
     *       array|string $search,
     *       array|string $replace,
     *       string|array $subject,
     *       int &$count = null
     *       ): string|array
     * 
     * Parameters:
     *      
     *      if `search` and `replace` are arrays, the str_replace() takes a values from each
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
    ?>

    <?php
    heading(1, "replacing char/string form a string or array.");
    $str1   = htmlspecialchars("<body text='%body%'>");
    $str2 = "Hello World of PHP";
    $str3  = "You should eat fruits, vegetables, and fiber every day.";

    $healthy = array("fruits", "vegetables", "fiber");
    $yummy   = array("pizza", "beer", "ice cream");
    $vowels = array("a", "e", "i", "o", "u", "A", "E", "I", "O", "U");

    heading(2, "Example: 1 Replacing a word from a string.");

    heading(3, "Our strings: ");
    display("pre", $str1, "data", "Our Original String: ");
    // replacing %body% by `block` from $str1 string.
    $str1_replaced = str_replace("%body%", "block", $str1);
    heading(3, "Replaced String: ");
    display("pre", $str1_replaced, "data", "Replaced String: ");
    put_sep();
    ?>

    <!-- Example: 2 Replacing all characters from a string by using an array.-->
    <?php
    heading(2, "Example: 2 Replacing all characters from a string by using an array.");

    heading(3, "Our strings: ");
    display("pre", $str2, "data", "Our Original String: ");
    // replacing %body% by `block` from $str1 string.
    $str2_replaced = str_replace($vowels, ".", $str2);
    heading(3, "Replaced String: ");
    display("pre", $str2_replaced, "data", "Replaced String: ");
    put_sep();
    ?>

    <!-- Example: 3 Replacing all sequence of words with another sequence of words using arrays -->
    <?php
    heading(2, "Example: 3 Replacing all sequence of words with another sequence of words using arrays");

    heading(3, "Our strings: ");
    display("pre", $str3, "data", "Our Original String: ");
    // replacing %body% by `block` from $str1 string.
    $str3_replaced = str_replace($healthy, $yummy, $str3);
    heading(3, "Replaced String: ");
    display("pre", $str3_replaced, "data", "Replaced String: ");
    put_sep();
    ?>
</body>

</html>