<?php

/**
 * FILTER_VALIDATE_INT
 * FILTER_VALIDATE_FLOAT
 * FILTER_VALIDATE_EMAIL
 * FILTER_VALIDATE_BOOL
 * FILTER_VALIDATE_URL
 * FILTER_VALIDATE_REGEX
 * 
 */


include "Utility.php";

heading(3, "Get Method Data");
show_array($_GET);

heading(3, "Post method data");
show_array($_POST);

heading(3, "Both get and Post methods data");
show_array($_REQUEST);

echo "Are you adult:  ";
// echo $_POST["adult"];

// filter_var($_POST["age"], FILTER_VALIDATE_INT)

heading(3, "Validation section");
echo "is age validate: ";
var_dump(filter_var($_POST["age"], FILTER_VALIDATE_INT));
echo "<br>";

echo "is Height validate: ";
var_dump(filter_var($_POST["height"], FILTER_VALIDATE_FLOAT));
echo "<br>";

echo "is Email validate: ";
var_dump(filter_var($_POST["mail"], FILTER_VALIDATE_EMAIL));
echo "<br>";
