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
    $db_name = "abhi_database";

    // to make a connection we need to use mysqli_connect(host, user, password)

    $con = mysqli_connect($host, $user, $password, $db_name);

    heading(2, "Connecting to Database");
    if ($con) {

        display("p", "Connected To the Database successfully: ", "success", "Success: ");
    } else {
        display("p", "Unable To connect to database: " . mysqli_connect_error(), "error", "Error: ");
    }
    ?>

    <!-- Now we will create a table inside a abhi_database -->
    <?php
    // creating a table person

    /**
     * CREATE TABLE person 
     * (
     * 'id' INT UNSIGNED NOT NULL AUTO_INCREMENT,
     * 'Name' VARCHAR(30) NOT NULL,
     * 'Age' INT UNSIGNED NOT NULL,
     * 'Height' FLOAT UNSIGNED NOT NULL,
     * 'Reg_Date' DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
     * 'Modify_Date'DATETIME NOT NULL on update CURRENT_TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
     * PRIMARY_KEY ('id')
     * );
     */

    // Now we will make or query string to make a table
    $sql_query = "INSERT INTO person (Name, Age, Height) VALUES 
    ('Abhishek', 21, 5.6),
    ('Manish', 34, 5.7);";

    heading(2, "Inserting data To table");

    $result = mysqli_query($con, $sql_query);

    if ($result) {
        display("p", "Entry successfully Inserted: ", "success", "Success: ");
    } else {
        display("p", "Unable To Insert Entry: " . mysqli_error($con), "error", "Error: ");
    }

    mysqli_close($con);
    ?>

</body>

</html>