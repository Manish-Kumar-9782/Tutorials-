<?php

if (isset($_GET['del'])) {
    $delete_id = $_GET['del'];
    echo "deleting the: " . $delete_id . "<br>";

    // now we need to make two  use two files again.
    $file = fopen("data.csv", "r");
    $temp = fopen("temp", "w");
    $count = 0;
    while (!feof($file)) {

        if ($count == $delete_id) {
            fgets($file);
        } else {
            fwrite($temp, fgets($file));
        }
        $count++;
    }

    fclose($file);
    fclose($temp);
    unlink("data.csv");
    rename("temp", "data.csv");

    echo "data removed...!<br>";
    header("Location:index.php");
}
