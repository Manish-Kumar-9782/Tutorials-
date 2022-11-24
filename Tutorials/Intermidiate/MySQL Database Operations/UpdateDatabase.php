<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../../style.css">
    <title>Database Intro</title>
</head>

<!-- In this section we will learn about how to read data by using the mysqli_real_query() method.

mysqli_real_query(): It executes a single query against the database result can then be retrieved
    or stored using the mysqli_store_result() or mysqli_use_result() functions.

    mysqli_use_result(): 

-->

<body>
    <?php

    include "../Utility.php";

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "varsha_database";

    // first of all we will make connection with a SQL server with given database.

    $con = mysqli_connect($host, $user, $password, $db_name);

    heading(2, "Connecting to Database");
    if ($con) {

        display("p", "Connected To the Database successfully: ", "success", "Success: ");
    } else {
        display("p", "Unable To connect to database: " . mysqli_connect_error(), "error", "Error: ");
    }
    ?>

    <!-- Now we will get the data from database-->
    <?php
    // Getting all the data

    heading(2, "Getting data from database");
    // first we will run a query with mysqli_real_query function
    $test = mysqli_query($con, "UPDATE person SET Name='Komal' WHERE id=4");
    // will return ---> true or false

    // test if we get any result or nothing.
    if ($test) {
        display("p", "Database Entry Updated", "success", "Success: ");

        // Now we will close the database 
        mysqli_close($con); // closing the database connection
        mysqli_commit($con);
    } else {
        display("p", "Unable To update the record." . mysqli_error($con), "error", "Error: ");
    }
    ?>

</body>

</html>