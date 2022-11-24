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
    $test = mysqli_real_query($con, "SELECT * FROM person");
    // will return ---> true or false

    // test if we get any result or nothing.
    if ($test) {
        display("p", "Reading Database", "success", "Success: ");

        // now first we will store the data 
        $result = mysqli_store_result($con);

        // This Transfers a result set from the last query 
        // Now we can use the mysqli_data_seek() and mysqli_use_result() method.

        if ($result) {
            display("p", "Data stored: ", "success", "Storing data: ");

            display("p", "Number of row stored " . mysqli_num_rows($result), "data", "Row: ");
            display("p", "Number of Fields are Found " . mysqli_num_fields($result), "data", "Columns: ");

            $data = mysqli_fetch_all($result);

            echo "<div class='p-5'>";
            foreach ($data as $row) {
                show_array($row);
            }
            echo "</div>";
        } else {
            display("p", "No Data stored" . mysqli_error($con), "error", "Storing data: ");
        }

        // Now before closing or executing another query or after fetching all the values 
        // we need to free all the values.

        mysqli_free_result($result); // freeing the memory

        mysqli_close($con); // closing the data
    } else {
        display("p", "Unable To fetch any data: " . mysqli_error($con), "error", "Error: ");
    }
    ?>

</body>

</html>