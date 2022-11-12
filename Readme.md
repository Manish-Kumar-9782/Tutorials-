# PHP Tutorial

This section covers the basic application of php and tutorials on the php basic to advance feature.

## What is php

PHP is a server scripting language, and a powerful tool for making dynamic and interactive Web pages.

PHP is a general-purpose scripting language geared toward web development. PHP originally stood for `Personal Home Page`, but it now stands for the PHP: Hypertext Preprocessor. PHP code is usually processed on a web server by PHP `interpreter` implemented as a `module`, a `daemon` or as a `Common Gateway interface (CGI)` executable.

On a web server, the result of the interpreted executed PHP code - which may be any type of data, such as generated HTML or binary image data - would form the whole or part of an HTTP response.


php can be embed with the html content, this feature allow us to process the dynamic content and put them into the html content with a simple php tag. 

**PHP File**
* PHP file can contain text, HTML, CSS, JavaScript and PHP code.
* PHP code is executed on the server, and the result is returned to the browser as plain HTML.
* PHP file have extension '.php'.

**What we can do by using PHP**

* it can generate dynamic page content.
* it can collect form data.
* it can send and receive cookies.
* it can add, delete, modify data in our database.
* it can create, open, read, write, delete and close files on the server.
* it can be used to control user-access.
* it can encrypt data. 

Note: A PHP is executed on the web server, and the plain HTML result is sent back to the browser.

* a php script can be placed anywhere in the document.
* a php script starts with `<?php` and ends with `?>`.

**Basic PHP Syntax:**

```php
<?php
    // php code is here
?>
```

A PHP file normally contains HTML tags, and some PHP scripting code.

**A Simple PHP example with HTML tags**
```php
<!DOCTYPE html>
<html>
<body>

<h1>PHP Example</h1>

<?php
    echo "Hello World!";
?>

</body>
</html>

```

Note: keywords (e.g `if`, `else`, `while`, `echo`, etc.), classes, functions, and user-defined functions are not case-sensitive. All variable names are case-sensitive.

**PHP Comments**

A comment in PHP code is a line that is not executed as a part of the program. Its only purpose is to read by someone who is looking at the code.

For single line comment: comment is written after `//` (double forward slash).
Multiline comment: we can write a multiline comment by using `/** comment lines */`.

[PHP Docs](https://devdocs.io/php/)

## Tutorial Section

Tutorial Section is divided in three section basic, intermediate, advance. each section contain multiple sub section which is described in their own sections.

**PHP Basics**

1. Creating Variables.
2. echo vs print keyword/function.
3. Data Types.
4. Operators
5. if-else and if-elseif-else statements.
6. switch statements.
7. Loops (for and while loop).
8. Functions
9. Arrays
10. SuperGlobals

**Intermediate**

1. String functions
2. Array functions
3. Request Methods.
4. PHP Form
5. Some Useful in-built functions.
6. Filters
7. Date and Time
8. json

**Advance**

1. PHP OPPs
2. Database Connectivity
3. PHP AJAX
4. PHP File Handling
5. Cookies
6. Sessions
7. Include and require
8. Exceptions.
