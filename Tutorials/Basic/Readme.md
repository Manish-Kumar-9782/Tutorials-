# PHP Basic Section

In php, a variable starts with the `$` sign, followed by the name of the variable.

PHP has no command for declaring a variable. it is created the moment we first assign a value to it.

PHP Variables Points to remember:

* A variable starts with the `$` sign, followed by the name of the variable.
* A variable name must start with a letter or the underscore character.
* A variable name cannot start with a number.
* A variable name can only contain alpha-numeric characters and underscores. (A-z, 0-9 and _)
* Variable name are case-sensitive ($age and $Age are two Variable names are different variables.)

```php
<?php

    //  a variable with only characters.
    $name = "my name";
    // a variable with characters with numbers. 
    $value1 = 10;

    // a variable with two word joined by underscore
    // Note we cannot leave blank space in b/w the two words for a variable name. 
    $first_name = "first name";

    // a variable with prefixed by (_) underscore.
    $_name = "my name";
?>
```

Note: PHP automatically associates a data type to the variable, depending on its value. Since the data types are not set in a strict sense, we can do things like adding a string to an integer without causing an error.

Note: In PHP 7, type declarations were added. This gives an option to specify the data type expected when declaring a function, and by enabling the strict requirement, it will throw a "Fatal Error" on a type mismatch.

PHP is a Loosely Typed Language.
____
<br>

## >> Variable Scope

Variables can be declared anywhere in the script, The scope of a variable is the part of the script where the variable can be referenced/used.

In PHP we have three different variable scopes:

* local
* global
* static

### Global Scope

A variable declared outside a function has a Global Scope and can only be accessed outside a function.

Note: if we want to use global variable inside the function we need to use global keyword inside the functions.

```php
<?php

$name = "myName";

function showName(){
    echo "<p>Name: $name</p>"
}
showName();// Note this will raise an error. we need to use global inside the function

function showName2(){
    global $name;
    echo "<p>Name: $name</p>"
}

showName2(); // ok..
?>
```

### Local Scope

A variable declared within a function has a `Local Scope` and can only be accessed within a function.

```php
<?php
function showName(){
    // a variable local to function.
    $name = "myName";
    echo "<p>Name: $name</p>"
}
showName();
?>
```

Note: we can have multiple variable with the same name in different functions, because local variable are only recognized by the functions in which they are declared.

### global keyword

The `global` keyword is used to access a global variable from within a function.

```php
<?php

$name = "myName";
function showName(){
    global $name; // global keyword before the global variable name.
    echo "<p>Name: $name</p>"
}
showName(); // ok..
?>
```

Note: in PHP we stores all global variables in an array called `$GLOBALS[name]`. The `name` holds the name of the variable. This array is also accessible from within functions and can be used to update global variables directly.

### static keyword

static keyword is used to define the `static` variable, static variable a special kind of variable which does not destroyed after executing the function, they maintain their state for further operation.

Declaration: we use `static` keyword before the variable name;

```php
<?php

function showName(){
    static $run_count = 0; // it is initialized only one time
    echo "<p>run count: $run_count</p>"
    $run_count++;
}
showName(); // $run_count is 0
showName(); // $run_count is 1
showName(); // $run_count is 2
?>
```

Note: In above example, each time the function is called, `$run_count` variable will still have the information it contained from the last time the function was called. *The variable is still local to the function.*

____
<br>

## >> echo and print Statement

in php, we can produce output on the screen by using the two basic methods: `echo` and `print` statement.

`echo` and `print` are more or less the same. They are both used to output data to the screen.

There are small difference in b/w `echo` and `print`:

* `echo` has now return value while `print` has a return value of 1 so it can be used in expression.
* `echo` can take multiple parameters while `print` can take one argument.
* `echo` is marginally faster than `print`.

Note: both `echo` and `print` can be used with or without parentheses. like `echo/echo()` or `print/print()`.

```php
<?php
$name = "my name";
print "<h2>PHP is Fun!</h2>";
echo "<p>My name is $name</p>";
?>
```

_____
<br>

## >> Data Types

Variable can store data of different types, and different data types can do different things. php supports the following data types.

* String
* Integer
* Float
* Boolean
* Array
* Object
* NULL
* Resource

### String 

A string is a sequence of character. A string can be any text inside quotes. we can use single or double quotes.

double quotes string allow us to use variables inside the string.

### Integer

An integer data type is a non-decimal number between -2,147,483,648 and 2,147,483,647.

* An integer must have at least one digit.
* An integer must not have a decimal point.
* An integer can be either positive or negative.
* Integers can be specified in: decimal (base 10), hexadecimal (base 16), octal (base 8), or binary (base 2) notation.

### Float

A float (floating point number) is a number with a decimal point or a number in exponential form. e.g 129.345;

### Boolean

A Boolean represents two possible states: True or False

Boolean are generally used in conditional testing e.g. if-else, while or for loop conditional testing.

### Array

An array is a stores multiple value in one single variable. Array stores multiple values in a consecutive order, it means each values has its own indexing number by which we can access that value instantly.

### NULL

NULL is a special data type which can have only on value: NULL.

A variable of data type NULL is a variable that has no value assigned to it. Variables can also be emptied by setting the value to NULL.

if a variable is created without a value, it is automatically assigned a value of NULL.

### Resource

The special resource type is not an actual data type. it is the storing a reference to functions and resources external to PHP.

A common example of using the resource data type is a database call.

_______
<br>

## >> Constants

A constants is an identifier (name) for a simple value. The value of constant cannot be changed during the script. 

A Valid constant name starts with a letter or underscore (no `$` sign before the constant name).

Note: constants are automatically global across the entire script.

### Create a constant

To create a constant, we use `define()` function.

Syntax:
```
define(name, value, case-insensitive)
```
Parameters: 
* name: Specifies the name of the constant.
* value: Specifies the value of the constant.
* case-insensitive: Specifies whether the constant name should be case-insensitive. Default is false.

```php
<?php
define('PI', 3.14);
echo PI;
?>
```

### Constant Array

Since PHP7, we can create a constant Array using the `define()` function.

```php
<?php
define("cars", [
  "Alfa Romeo",
  "BMW",
  "Toyota"
]);
echo cars[0];
?>
```

_____
<br>

## >> Operators

Operators are used to perform operations on variables and values. In php we have divided the operators in the following groups.

* Arithmetic operators.
* Assignment operators.
* Comparison operators.
* Increment/Decrement operators.
* String operators.
* Array Operators.
* Conditional Assignment operators.

<br>

### Arithmetic Operators

Arithmetic operators are used with numeric values to perform common arithmetical operations, such as addition, subtraction, multiplication etc.

<table>
        <tr>
            <th>Operator</th>
            <th>Name</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>+</td>
            <td>Addition</td>
            <td>To add two numeric values.</td>
        </tr>
        <tr>
            <td>-</td>
            <td>Subtraction</td>
            <td>To subtract two numeric values.</td>
        </tr>
        <tr>
            <td>*</td>
            <td>Multiplication</td>
            <td>To multiply two numeric values. </td>
        </tr>
        <tr>
            <td>/</td>
            <td>Division</td>
            <td>To Divide two numeric values.</td>
        </tr>
        <tr>
            <td>%</td>
            <td>Modulus</td>
            <td>To get the remainder.</td>
        </tr>
        <tr>
            <td>**</td>
            <td>Exponentiation</td>
            <td>To compute the exponent of numeric base value.</td>
        </tr>
</table>
<br>

###  Assignment Operators

Assignment operators are used with numeric values to write a value to a variable.

The basic assignment operator in PHP is "=". 

<table>
        <tr>
            <th>Operator</th>
            <th>Notation</th>
            <th>Same as...</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>=</td>
            <td>x = y</td>
            <td>x = y</td>
            <td>Right value (expression) is assigned to the left operand.</td>
        </tr>
        <tr>
            <td>+=</td>
            <td> x += y</td>
            <td> x = x + y</td>
            <td>Add a value to the left operand's value and assign to itself.</td>
        </tr>
        <tr>
            <td>-=</td>
            <td>x -= y</td>
            <td>x = x - y</td>
            <td>Subtract a value from the left operand's value and assign to itself. </td>
        </tr>
        <tr>
            <td>*=</td>
            <td>x *= y</td>
            <td>x = x * y</td>
            <td>Multiply a value with the left operand's value and assign to itself.</td>
        </tr>
        <tr>
            <td>%=</td>
            <td>x %= y</td>
            <td>x = x % y</td>
            <td>Compute the remainder with the left operand's value and assign to itself.</td>
        </tr>
</table>
<br>

### Comparison Operators

The php comparison operators are used to compare two values (number or string).

 <table>
        <tr>
            <th>Operator</th>
            <th>Name</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>==</td>
            <td>Equal</td>
            <td>To check that two variable has the same value. Return true if both are equal.</td>
        </tr>
        <tr>
            <td>===</td>
            <td>Identical</td>
            <td>To check that two variable are same type and they have same value. Return true or false.</td>
        </tr>
        <tr>
            <td>!=</td>
            <td>Not equal</td>
            <td>To check that if two variables has different values. Return true or false.</td>
        </tr>
        <tr>
            <td>&lt;&gt;</td>
            <td>Not equal</td>
            <td>To check that if two variables has different values. Return true or false.</td>
        </tr>
        <tr>
            <td>!==</td>
            <td>Not identical</td>
            <td>To check that if two variable does not have same type and does not have same value.</td>
        </tr>
        <tr>
            <td>&lt;</td>
            <td>Less than</td>
            <td>To check that left value is less than the right value. Return true or false.</td>
        </tr>
        <tr>
            <td>&gt;</td>
            <td>Greater than</td>
            <td>To check that left value is greater than the right value. Return true or false.</td>
        </tr>
        <tr>
            <td>&gt;=</td>
            <td>Greater than or equal to</td>
            <td>To check that right value is greater than or equal to the left value. Return true or false.</td>
        </tr>
        <tr>
            <td>&lt;=</td>
            <td>Less than or equal to</td>
            <td>To check that right value is less than or equal to the left value. Return true or false.</td>
        </tr>
        <tr>
            <td>&lt;=&gt;</td>
            <td>Spaceship</td>
            <td> Returns an integer less than, equal to, or greater than zero, depending on if 'left value' is less
                than, equal to, or greater than 'right value'.</td>
        </tr>
</table>
<br>

### Increment/Decrement Operators

The PHP increment operators are used to increment a variable's value by one. Decrement operators are used to decrement a variable's value by one.

<table>
        <tr>
            <th>Operator</th>
            <th>Name</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>++$var</td>
            <td>Pre-Increment</td>
            <td>First increment $var by one, then return $var.</td>
        </tr>
        <tr>
            <td>$var++</td>
            <td>Post-Increment</td>
            <td>First Return $var, then increment $var by one.</td>
        </tr>
        <tr>
            <td>--$var</td>
            <td>Pre-decrement</td>
            <td>First Decrement $var by one, then return $var.</td>
        </tr>
        <tr>
            <td>$var--</td>
            <td>Post-decrement</td>
            <td>First return $var, then decrement $var by one.</td>
        </tr>
</table>
<br>

### Logical Operators

Logical operators are used to combine conditional statements.

<table>
        <tr>
            <th>Operator</th>
            <th>Name</th>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>and</td>
            <td>And</td>
            <td>$x and $y</td>
            <td>true: if both $x and $y are true.</td>
        </tr>
        <tr>
            <td>or</td>
            <td>Or</td>
            <td>$x or $y</td>
            <td>true: if either $x or $y is true.</td>
        </tr>
        <tr>
            <td>xor</td>
            <td>Xor</td>
            <td>$x xor $y</td>
            <td>true: if either $x or $y is true, bot not both.</td>
        </tr>
        <tr>
            <td>&&</td>
            <td>and</td>
            <td>$x && $y</td>
            <td>true: if both $x and $y true.</td>
        </tr>
        <tr>
            <td>||</td>
            <td>or</td>
            <td>$x || $y</td>
            <td>true: if either $x or $y is true.</td>
        </tr>
        <tr>
            <td>!</td>
            <td>Not</td>
            <td>!$x</td>
            <td>true if $x is not true else false.</td>
        </tr>
</table>
<br>

### String Operators

In php we have two operators that are specially designed for strings.

<table>
        <tr>
            <th>Operator</th>
            <th>Name</th>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>.</td>
            <td>Concatenation</td>
            <td>$x . $y</td>
            <td>Concatenation of $x and $y.</td>
        </tr>
        <tr>
            <td>.=</td>
            <td>Concatenation assignment</td>
            <td>$x .= $y</td>
            <td>Appends $y to $x.</td>
        </tr>
</table>
<br>

### Array Operators

In PHP we also have array operators, which are used to compare arrays.

<table>
    <tr>
        <th>Operator</th>
        <th>Name</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>+</td>
        <td>Union</td>
        <td>$x + $y</td>
        <td>Union of $x and $y.</td>
    </tr>
    <tr>
        <td>==</td>
        <td>Equality</td>
        <td>$x == $y</td>
        <td>true: if $x and $y have the same key/value pairs.</td>
    </tr>
    <tr>
        <td>===</td>
        <td>Identity</td>
        <td>$x === $y</td>
        <td>true: if $x and $y have the same key/value pairs and their type also matches in the same order.</td>
    </tr>
    <tr>
        <td>!=</td>
        <td>Inequality</td>
        <td>$x != $y</td>
        <td>true: true if $x is not equal to $y.</td>
    </tr>
    <tr>
        <td>&lt;&gt;</td>
        <td>Inequality</td>
        <td>$x &lt;&gt; $y</td>
        <td>true: true if $x is not equal to $y.</td>
    </tr>
    <tr>
        <td>!==</td>
        <td>Non-identity</td>
        <td>$x !== $y</td>
        <td>true if $x is not identical to $y.</td>
    </tr>
</table>
<br>

### Conditional Assignment Operators

Conditional Assignment operators are used to set a value depending on conditions.

<table>
    <tr>
        <th>Operator</th>
        <th>Name</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>?:</td>
        <td>Ternary</td>
        <td>$x = expr1 ? expr2 : expr3</td>
        <td>Returns the value of $x.
            The value of $x is expr2 if expr1 = TRUE.
            The value of $x is expr3 if expr1 = FALSE</td>
    </tr>
    <tr>
        <td>??</td>
        <td>Null coalescing</td>
        <td>$x = expr1 ?? expr2</td>
        <td>Returns the value of $x.
            The value of $x is expr1 if expr1 exists, and is not NULL.
            If expr1 does not exist, or is NULL, the value of $x is expr2.
            Introduced in PHP 7</td>
    </tr>
<table>