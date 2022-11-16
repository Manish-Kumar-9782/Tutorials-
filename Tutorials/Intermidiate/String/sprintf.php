<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>sprintf</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `sprintf` function. 
     * 
     * sprintf: Write a formatted string to a stream.
     * 
     *      Write a string produced according to `format` to the stream resource 
     *      specified by `stream`.
     * 
     * Syntax:
     *      sprintf(string $format, mixed ...$values): string
     * 
     * Parameters:
     * 
     *      format:
     *          The format string is composed of zero or more directive: ordinary characters
     *          (excluding %) that are copied directly to result and conversion specifications,
     *          each of which results in fetching its own parameters.
     * 
     *          A conversion specification follows this prototype: 
     *              %[argnum$][flag][width][.precision]specifier.
     * 
     *          argnum:
     *              An integer followed by a dollar sign $, to specify which number argument
     *              to treat in the conversion.
     * 
     *          Flags: 
     * 
     *              -> - : Left-justify within the given field width; default right justified
     *              -> * : Prefix positve number iwth a plus sign +; default negative are 
     *                      prefixed with a negative sign.
     *              -> (space) : Pads the result with spaces. This is the default.
     *              -> 0 : Only left-pads numbers with zeros. With s specifies this can also
     *                      right-pas with zeros.
     *              -> '(char) : Pads the result with the character
     * 
     *          Width:
     *               
     *              An integer that says how many characters (minimum) this conversion should 
     *              result in.
     * 
     *          Precision:
     *  
     *              A period . followed by an integer who's meaning depends on the specifier.
     * 
     *              -> For, `e`, `E`, `f` and `F` specifiers: this is th number of digits to be 
     *                  printed after the decimal point (by default, this is 6)
     * 
     *              -> For `g`, `G`, `h` and `H` specifiers: this is the maximum number of 
     *                  significant digits to be printed.
     * 
     *              -> For `s` specifier: it acts as a cutoff point, setting a maximum character 
     *                  limit to the string.
     * 
     *   -> %:	A literal percent character. No argument is required.
     *   -> b:	The argument is treated as an integer and presented as a binary number.
     *   -> c:	The argument is treated as an integer and presented as the character with that ASCII.
     *   -> d:	The argument is treated as an integer and presented as a (signed) decimal number.
     *   -> e:	The argument is treated as scientific notation (e.g. 1.2e+2).
     *   -> E:	Like the e specifier but uses uppercase letter (e.g. 1.2E+2).
     *   -> f:	The argument is treated as a float and presented as a floating-point number (locale aware).
     *   -> F:	The argument is treated as a float and presented as a floating-point number (non-locale aware).
     *   -> g:	
     *          General format.
     *
     *          Let P equal the precision if nonzero, 6 if the precision is omitted, or 1 if the precision is zero.\
     *           Then, if a conversion with style E would have an exponent of X:
     *
     *          If P > X ≥ −4, the conversion is with style f and precision P − (X + 1). Otherwise, the conversion \
     *          is with style e and precision P − 1.
     *
     *   ->G:   Like the g specifier but uses E and f.
     *   ->h:   Like the g specifier but uses F. Available as of PHP 8.0.0.
     *   ->H:   Like the g specifier but uses E and F. Available as of PHP 8.0.0.
     *   ->o:   The argument is treated as an integer and presented as an octal number.
     *   ->s:   The argument is treated and presented as a string.
     *   ->u:   The argument is treated as an integer and presented as an unsigned 
     *          decimal number.
     *   ->x:   The argument is treated as an integer and presented as a hexadecimal 
     *          number (with lowercase letters).
     *   ->X:   The argument is treated as an integer and presented as a hexadecimal 
     *          number (with uppercase letters).
     * 
     *      Warning: The c type specifier ignores padding and width;
     * 
     *      Warning: Attempting to use a combination of the string and width specifiers
     *          with character sets that require more than one byte per character may 
     *          result in unexpected result. 
     * 
     *      Suitable type specifier:
     * 
     *      ->string:   s
     *      ->int:      d, u, c, o, x, X, b
     *      ->float:    e, E, f, F, g, G, h, H
     *        
     * Return: 
     *      Returns the length of the string written.
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
     * In this section we will learn about the `sprintf` function. 
     * 
     * sprintf: Write a formatted string to a stream.
     * 
     *      Write a string produced according to `format` to the stream resource 
     *      specified by `stream`.
     * 
     * Syntax:
     *      sprintf(string $format, mixed ...$values): string
     * 
     * Parameters:
     * 
     *      format:
     *          The format string is composed of zero or more directive: ordinary characters
     *          (excluding %) that are copied directly to result and conversion specifications,
     *          each of which results in fetching its own parameters.
     * 
     *          A conversion specification follows this prototype: 
     *              %[argnum$][flag][width][.precision]specifier.
     * 
     *          argnum:
     *              An integer followed by a dollar sign $, to specify which number argument
     *              to treat in the conversion.
     * 
     *          Flags: 
     * 
     *              -> - : Left-justify within the given field width; default right justified
     *              -> * : Prefix positve number iwth a plus sign +; default negative are 
     *                      prefixed with a negative sign.
     *              -> (space) : Pads the result with spaces. This is the default.
     *              -> 0 : Only left-pads numbers with zeros. With s specifies this can also
     *                      right-pas with zeros.
     *              -> '(char) : Pads the result with the character
     * 
     *          Width:
     *               
     *              An integer that says how many characters (minimum) this conversion should 
     *              result in.
     * 
     *          Precision:
     *  
     *              A period . followed by an integer who's meaning depends on the specifier.
     * 
     *              -> For, `e`, `E`, `f` and `F` specifiers: this is th number of digits to be 
     *                  printed after the decimal point (by default, this is 6)
     * 
     *              -> For `g`, `G`, `h` and `H` specifiers: this is the maximum number of 
     *                  significant digits to be printed.
     * 
     *              -> For `s` specifier: it acts as a cutoff point, setting a maximum character 
     *                  limit to the string.
     * 
     *   -> %:	A literal percent character. No argument is required.
     *   -> b:	The argument is treated as an integer and presented as a binary number.
     *   -> c:	The argument is treated as an integer and presented as the character with that ASCII.
     *   -> d:	The argument is treated as an integer and presented as a (signed) decimal number.
     *   -> e:	The argument is treated as scientific notation (e.g. 1.2e+2).
     *   -> E:	Like the e specifier but uses uppercase letter (e.g. 1.2E+2).
     *   -> f:	The argument is treated as a float and presented as a floating-point number (locale aware).
     *   -> F:	The argument is treated as a float and presented as a floating-point number (non-locale aware).
     *   -> g:	
     *          General format.
     *
     *          Let P equal the precision if nonzero, 6 if the precision is omitted, or 1 if the precision is zero.\
     *           Then, if a conversion with style E would have an exponent of X:
     *
     *          If P > X ≥ −4, the conversion is with style f and precision P − (X + 1). Otherwise, the conversion \
     *          is with style e and precision P − 1.
     *
     *   ->G:   Like the g specifier but uses E and f.
     *   ->h:   Like the g specifier but uses F. Available as of PHP 8.0.0.
     *   ->H:   Like the g specifier but uses E and F. Available as of PHP 8.0.0.
     *   ->o:   The argument is treated as an integer and presented as an octal number.
     *   ->s:   The argument is treated and presented as a string.
     *   ->u:   The argument is treated as an integer and presented as an unsigned 
     *          decimal number.
     *   ->x:   The argument is treated as an integer and presented as a hexadecimal 
     *          number (with lowercase letters).
     *   ->X:   The argument is treated as an integer and presented as a hexadecimal 
     *          number (with uppercase letters).
     * 
     *      Warning: The c type specifier ignores padding and width;
     * 
     *      Warning: Attempting to use a combination of the string and width specifiers
     *          with character sets that require more than one byte per character may 
     *          result in unexpected result. 
     * 
     *      Suitable type specifier:
     * 
     *      ->string:   s
     *      ->int:      d, u, c, o, x, X, b
     *      ->float:    e, E, f, F, g, G, h, H
     *        
     * Return: 
     *      Returns the length of the string written.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      ...
     */
    ?>

    <!-- Example 1: Argument swapping -->
    <?php
    put_sep();
    heading(1, "Example: Argument Swapping");
    $format  = "Hi, My name is %s and i'm %d years old.";
    heading(3, "String:");
    display("p", $format, "data p-5");

    // Now we will put the name and years value by using the sprintf() function.

    heading(3, "Formatted result");
    display("p", sprintf($format, "Manish", 27), "data-output p-5");


    // using the [number]$[specifier] format to specify the location for the 
    // variable.

    heading(3, "Formatted result with location placeholder.");
    $format = 'Hi, My name is %2$s and i\'m %1$d years old.';
    display("p", sprintf($format, 27, "Manish"), "data-output p-5");
    put_sep();
    ?>

    <!-- specifying the padding characters. -->
    <?php

    heading(1, "Specifying the padding characters");
    heading(3, "padding with .");
    display("p", sprintf("%'.20s %'.10s", "Hello", "Jello"), "data-output");

    heading(3, "padding with *");
    display("p", sprintf("%'*20s %'*10s", "Hello", "Jello"), "data-output");

    heading(3, "Zero padding integer");
    display("p", sprintf("%04d-%02d-%02d", 2022, 11, 15), "data-output p-5");

    heading(3, "Formatting currency");
    display("p", sprintf("%01.3f", 3.145296), "data-output p-5");

    heading(3, "Scientific Notation");
    display("p", sprintf("%.2e", 3145296), "data-output p-5");


    ?>
</body>

</html>