<?php

function show_array(array $array)
{

    echo "<b>Array (</b>";
    foreach ($array as $key => $value) {
        echo "<p class='p-5'><span class='key'>[$key]</span>  => <span class='value'>$value</span></p>";
    }
    echo "<b>)</b><br><br>";
}


function show_array_values(array $array, int $rlen = 10)
{
    $gap = true;
    if (count($array) < $rlen) {
        // global $gap;
        $gap = false;
    }


    $len = count($array);
    // echo "found length: $len";
    echo "<p class='p-5'>";
    if ($gap)
        echo "<b>Array [</b><br>";
    else
        echo "<b>Array [</b> ";
    for ($i = 0; $i < $len; $i++) {

        // if $i%$rlen == 0 => make a new line

        if ($i % $rlen == 0  && $i > 0) {
            echo "<br>";
        }
        // echo "<span class='arvalue'>" . $array[$i] . "</span>";
        if ($i != $len - 1) {
            echo "<span class='arr_item'>" . $array[$i] . "</span>";
        } else {
            echo "<span class='arr_last_item arr_item'>" . $array[$i] . "</span>";
        }
    }
    if ($gap)
        echo "<br><b> ]</b><br><br>";
    else
        echo "<b> ]</b><br><br>";
    echo "</p>";
}

function heading(int $n, string $str)
{
    echo "<h$n>$str</h$n>";
}

function display(string $element, string $str = NULL, string $class = NULL, string $head = '')
{
    if ($class != NULL) {
        echo "<$element class='$class'><b>$head</b>$str</$element>";
    } else {
        echo "<$element><b>$head</b>$str</$element>";
    }
}

function put_sep()
{
    echo "<br><hr><br>";
}
