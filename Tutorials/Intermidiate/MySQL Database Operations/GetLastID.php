<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Insert Row</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">

    <!-- 

        In this section we will first insert a single row and then we will get the 
        recently inserted record id by using the mysqli_insert_id() function.

     -->


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

    heading(3, "Inserting a Row in testDB database..");

    //  Now we want to create a table
    $query = "INSERT INTO MyTable 
            (first_name, last_name, email)
            VALUES ('Abhishek', 'Sharma', 'abhisharma@example.com')";

    // The above query will create 5 column table with given name
    // id, first_name, last_name, email, reg_date.

    // Now we need to pass that string into the query function.
    // Note: query function will return a result object on success, else false.

    $result = mysqli_query($con, $query);

    // Now we will test that our database created or there is an error 

    if ($result) {
        $last_id = mysqli_insert_id($con);
        display("p", "Row data successfully inserted to database $db.MyTable! with id -> $last_id", "success", "Success: ");
    } else {
        display("p", "Unable to insert data, " . mysqli_error($con), "error", "Error: ");
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