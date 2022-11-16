<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>strlen</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn about the `strlen` function. 
     * 
     * strlen: Get string length
     * 
     *      Returns the length of the given string.
     * 
     * Syntax:
     *      strlen(string $string): int
     * 
     * Parameters:
     * 
     *      string:
     *          The string being measured for length.
     *          
     * Return: 
     *      The length of the `string` on success, and 0 if the string is empty.
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
     * In this section we will learn about the `strlen` function. 
     * 
     * strlen: Get string length
     * 
     *      Returns the length of the given string.
     * 
     * Syntax:
     *      strlen(string $string): int
     * 
     * Parameters:
     * 
     *      string:
     *          The string being measured for length.
     *          
     * Return: 
     *      The length of the `string` on success, and 0 if the string is empty.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *      ...
     */
    ?>

    <?php
    put_sep();
    heading(1, "strlen function");

    heading(3, "Our String: ");
    $str = "hello my name is noOne and who are you";
    display('p', $str, "data p-5");

    // Now we will compute the length of the string.
    $len = strlen($str);

    display("p", "Length of the string: " . $len, "data-output p-5");


    ?>
</body>

</html>