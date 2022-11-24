<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create Database</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">


    <!-- ===================================================================== -->

    <!-- Connecting to The MySQL Server -->
    <?php
    include "../Utility.php";

    // to disable the warning and error we can uncomment these two lines
    // error_reporting(0); // to set the error_reporting on php
    // mysqli_report(MYSQLI_REPORT_OFF); // to set the error reporting on mysql function.
    // Now we will try to make a connection with the SQL Server.

    $server_name = "localhost";
    $user_name = "root";
    $password = "";

    // Now connecting to the server.
    heading(3, "Connecting to the MySQL Server..!");
    // sleep(3);
    $con = mysqli_connect($server_name, $user_name, $password);

    // since we don't have any database right know so we will not pass any database name.

    // Now we need to test that our connection made or not

    // if $con is false it means connection not made.

    if ($con) {
        display("p", "Connected To Database.", "success", "Success: ");
    } else {
        die(display("p", mysqli_connect_error(), "error", "Connection Failed: "));
        // here mysqli_connect_error() will show the error during making connection.
    }
    ?>

    <!-- ===================================================================== -->

    <!-- Creating database -->
    <?php
    // Now after making the successful connection with the database we need to 
    // work on some queries.

    // we can store our SQL query string in a variable or we can pass that directly 
    // to the function.
    heading(3, "Creating database..");

    $query = "create database testDB";

    // Now we need to pass that string into the query function.
    // Note: query function will return a result object on success, else false.

    $result = mysqli_query($con, $query);

    // Now we will test that our database created or there is an error 

    if ($result) {
        display("p", "Database Created Successfully..!", "success", "Success: ");
    } else {
        display("p", "Error during creating database, " . mysqli_error($con), "error", "Error: ");
    }
    ?>

    <!-- ===================================================================== -->

    <!-- Closing the connection -->
    <?php

    // Now success or failure we will close the connection.

    heading(3, "Closing Connection..");
    // sleep(2);
    $close_status = mysqli_close($con);

    if ($close_status) {
        display("p", "MySQL Server has been Closed.", "success", "Connection Closed: ");
    } else {
        display("p", "Error during closing the MySQL Server," . mysqli_error($con), "error", "Error: ");
    }
    ?>
</body>

</html>