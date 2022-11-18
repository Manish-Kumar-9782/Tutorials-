<?php

include "Utility.php";

heading(3, "Get Method Data");
show_array($_GET);

heading(3, "Post method data");
show_array($_POST);

heading(3, "Both get and Post methods data");
show_array($_REQUEST);

// echo $_POST["adult"];

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
