<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create Table</title>
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
    $db = "testDB";

    // Now connecting to the server.
    heading(3, "Connecting to the MySQL Server..!");
    // sleep(3);
    $con = mysqli_connect($server_name, $user_name, $password, $db);

    // here we will pass the bd name, here we are considering that we have a 
    // database 

    // Now we need to test that our connection made or not

    // if $con is false it means connection not made.

    if ($con) {
        display("p", "Connected To Database. ($db)", "success", "Success: ");
    } else {
        die(display("p", mysqli_connect_error(), "error", "Connection Failed: "));
        // here mysqli_connect_error() will show the error during making connection.
    }
    ?>

    <!-- ===================================================================== -->

    <!-- Creating Table -->
    <?php
    // Now after making the successful connection with the database we need to 
    // work on some queries.

    // we can store our SQL query string in a variable or we can pass that directly 
    // to the function.

    heading(3, "Creating Table..");

    //  Now we want to create a table
    $query = "CREATE TABLE MyTable(
            id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
            first_name VARCHAR(30) NOT NULL,
            last_name VARCHAR(30) NOT NULL,
            email VARCHAR(50),
            reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
            );";

    // The above query will create 5 column table with given name
    // id, first_name, last_name, email, reg_date.

    // Now we need to pass that string into the query function.
    // Note: query function will return a result object on success, else false.

    $result = mysqli_query($con, $query);

    // Now we will test that our database created or there is an error 

    if ($result) {
        display("p", "Table Created Successfully..!", "success", "Success: ");
    } else {
        display("p", "Unable to Create the table, " . mysqli_error($con), "error", "Error: ");
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