<?php

function show_array(array $array)
{

    echo "<b>Array (</b>";
    foreach ($array as $key => $value) {
        echo "<p class='p-5'><span class='key'>[$key]</span>  => <span class='value'>$value</span></p>";
    }
    echo "<b>)</b><br><br>";
}

function show_array_values(array $array, int $rlen){
    echo"<b>Array [</b><br>";

    $len = count($array);

    echo"<p class = 'p-5'>";
    for ($i = 0; $i < $len; $i++) {

        // if $i%$rlen == 0 => make a new line

        if ($i % $rlen == 0  && $i > 0) {
            echo "<br>";
        }
        echo "<span class='arvalue'>" . $array[$i] . "</span>";
        if ($i != $len - 1) {
            echo ", ";
        }
    }
    echo "</p>";
    echo "<b>]</b><br><br>";


}

function heading(int $n, string $str)
{
    echo "<h$n>$str</h$n>";
}

function display(string $element, string $str)
{
    echo "<$element> $str</$element>";
}

function put_sep()
{
    echo "<br><hr><br>";
}

?>