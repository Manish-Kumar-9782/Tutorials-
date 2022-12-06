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

    <!-- Now we will create a table inside a abhi_database -->
    <?php
    // creating a table person


    // Now we will make or query string to make a table
    $sql_query = "INSERT INTO person (Name, Age, Height) VALUES 
    ('Narendra', 21, 5.6),
    ('Gotam', 19, 5.7),
    ('suraj', 22, 5.8);";

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