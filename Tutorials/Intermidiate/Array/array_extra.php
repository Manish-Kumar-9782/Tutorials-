<?php

function show_array(array $array)
{

    echo "<b>Array (</b>";
    foreach ($array as $key => $value) {
        echo "<p class='p-5'><span class='key'>[$key]</span>  => <span class='value'>$value</span></p>";
    }
    echo "<b>)</b>";
}

function heading(int $n, string $str)
{
    echo "<h$n>$str</h$n>";
}

function display(string $element, string $str)
{
    echo "<$element>$str</$element>";
}

function put_sep()
{
    echo "<br><hr><br>";
}
