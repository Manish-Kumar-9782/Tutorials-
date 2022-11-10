<?php

// here we need to use the POST global variable to get the data
// from the page.

$PHP_EOL = "\n";

function save_data($name, $author, $subject, $pages, $price)
{
    global $PHP_EOL;
    $file_name = "data.csv";

    if (file_exists("data.csv")) {
        // if file is exist then first open the file.
        $file = fopen("data.csv", 'a');
        // Now write the new data.
        // Now we need to write the data into the file.
        fwrite($file, "$name,$author,$subject,$pages,$price ${PHP_EOL}");
        fclose($file);
        echo "book has been added...!";
    } else {
        // first create a new file to save the data.
        $file = fopen("data.csv", 'w');
        // now write the header of the file.
        fwrite($file, "title,author,subject,pages,price ${PHP_EOL}");
        // Now we need to write the data into the file.
        fwrite($file, "$name,$author,$subject,$pages,$price ${PHP_EOL}");
        fclose($file);
    }
}

$name = $author = $subject = $pages = $price = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $name = $_POST['title'];
    $author = $_POST['author'];
    $subject = $_POST['subject'];
    $pages = $_POST['pages'];
    $price = $_POST['prices'];
    save_data($name, $author, $subject, $pages, $price);
} else {
    echo "Unable to process the data";
}

// after getting the data from the user input we need to save the 
// getting values to a file.

?>

<a href="index.html">add book</a>