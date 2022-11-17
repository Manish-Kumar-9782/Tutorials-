<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>substr_replace</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `substr_replace` function. 
     * 
     * substr_replace: Replace text within a portion of a string
     *      
     *      Replaces a copy of string delimited by the `offset` and (optionally) `length` 
     *      parameters with the string given in `replace`.
     * 
     * Syntax:
     *      substr_replace(
     *       array|string $string,
     *       array|string $replace,
     *       array|int $offset,
     *       array|int|null $length = null
     *      ): string|array
     * 
     * Parameters:
     *      
     *      string:
     *          The input string.
     * 
     *          An array of strings can be provided, in which case the replacements will occur
     *          on each string in turn. In this case, the `replace`, `offset` and `length` 
     *          parameters may be provided either as scalar values to be applied to each input 
     *          string in turn, or as array, in which case the corresponding array element will 
     *          be sued for each input string.
     * 
     *      replace:
     *          The replacement string.
     * 
     *      offset:
     *          If `offset` is non-negative, the replacing will begin at the offset'th offset into
     *          `string`.
     * 
     *          if `offset` is negative, the replacing will begin at the offset'th character the
     *          end of `string`.
     * 
     *      length: 
     *          if given and is positive, it represents the length of the portions of string which 
     *          is to be replaced. if it is negative, it represents the number of characters form 
     *          the end of `string` at which to stop replacing. if it is not given, then it will 
     *          default to strlen(`string`); i.e end the replacing at the end of `string`.
     * 
     *          if `length` is zero than this function will have the effect of inserting replace 
     *          into string at the given `offset` offset.  
     *          
     * Return: 
     *      The result string is returned. If string is an array then array is returned.
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
     * In this section we will learn about the `substr_replace` function. 
     * 
     * substr_replace: Replace text within a portion of a string
     *      
     *      Replaces a copy of string delimited by the `offset` and (optionally) `length` 
     *      parameters with the string given in `replace`.
     * 
     * Syntax:
     *      substr_replace(
     *       array|string $string,
     *       array|string $replace,
     *       array|int $offset,
     *       array|int|null $length = null
     *      ): string|array
     * 
     * Parameters:
     *      
     *      string:
     *          The input string.
     * 
     *          An array of strings can be provided, in which case the replacements will occur
     *          on each string in turn. In this case, the `replace`, `offset` and `length` 
     *          parameters may be provided either as scalar values to be applied to each input 
     *          string in turn, or as array, in which case the corresponding array element will 
     *          be sued for each input string.
     * 
     *      replace:
     *          The replacement string.
     * 
     *      offset:
     *          If `offset` is non-negative, the replacing will begin at the offset'th offset into
     *          `string`.
     * 
     *          if `offset` is negative, the replacing will begin at the offset'th character the
     *          end of `string`.
     * 
     *      length: 
     *          if given and is positive, it represents the length of the portions of string which 
     *          is to be replaced. if it is negative, it represents the number of characters form 
     *          the end of `string` at which to stop replacing. if it is not given, then it will 
     *          default to strlen(`string`); i.e end the replacing at the end of `string`.
     * 
     *          if `length` is zero than this function will have the effect of inserting replace 
     *          into string at the given `offset` offset.  
     *          
     * Return: 
     *      The result string is returned. If string is an array then array is returned.
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
    $str1_replaced = substr_replace("%body%", "block", $str1);
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
    $str2_replaced = substr_replace($vowels, ".", $str2);
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
    $str3_replaced = substr_replace($healthy, $yummy, $str3);
    heading(3, "Replaced String: ");
    display("pre", $str3_replaced, "data", "Replaced String: ");
    put_sep();
    ?>
</body>

</html>