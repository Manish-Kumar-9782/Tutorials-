<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../Tutorials/style.css">
    <title>Database Intro</title>
</head>

<body>
    <?php

    include "Utility.php";

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "xyz2";

    // to make a connection we need to use mysqli_connect(host, user, password)

    $con = mysqli_connect($host, $user, $password, $db_name);

    heading(2, "Connecting to Database");
    if ($con) {

        display("p", "Connected To the Database successfully: ", "success", "Success: ");
    } else {
        display("p", "Unable To connect to database: " . mysqli_connect_error(), "error", "Error: ");
    }
    ?>

    <!-- Now we will delete some entry from  xyz2  database-->
    <?php
    // Deleting some entries from person table


    // Now we will make or query string to make a table
    $sql_query = "DELETE FROM person WHERE id = 2";

    heading(2, "Deleting an Entry");

    $result = mysqli_query($con, $sql_query);

    if ($result) {
        display("p", "Entry Successfully Deleted: ", "success", "Success: ");
    } else {
        display("p", "Unable to delete Entry: " . mysqli_error($con), "error", "Error: ");
    }

    mysqli_close($con);
    // finally we close the database.
    ?>

</body>

</html>