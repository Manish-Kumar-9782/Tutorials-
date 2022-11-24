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

    // to make a connection we need to use mysqli_connect(host, user, password)

    $con = mysqli_connect($host, $user, $password);

    heading(2, "Connecting to Database");
    if ($con) {

        display("p", "Connected To the Database successfully: ", "success", "Success: ");
    } else {
        display("p", "Unable To connect to database: " . mysqli_connect_error(), "error", "Error: ");
    }
    ?>

    <!-- Now we will make a new Database by using the sql query -->
    <?php
    // create database abhi_database
    heading(2, "Creating Database");
    $result = mysqli_query($con, "CREATE DATABASE abhi_database");

    if ($result) {
        display("p", "Database successfully Created: ", "success", "Success: ");
    } else {
        display("p", "Unable To create Database: " . mysqli_error($con), "error", "Error: ");
    }
    ?>

</body>

</html>