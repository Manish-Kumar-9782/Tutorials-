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

    mysqli_store_result(): This function must be called after calling the mysqli_real_query() or 
        mysqli_multi_query() method.

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

        // Now we will initiate the result for fetching 
        $result = mysqli_use_result($con);

        // This will initiate the result to be fetched. 

        if ($result) {
            display("p", "Data Initiated To fetch: ", "success", "Storing data: ");

            // Note: if we using unbuffered result set then we can't use mysqli_num_rows
            // display("p", "Number of rows Found " . mysqli_num_rows($result), "data", "Row: ");
            display("p", "Number of Fields Found " . mysqli_num_fields($result), "data", "Columns: ");

            $fields = array();

            // Now we will get the each filed name with the help of mysqli_fetch_field function.
            while ($field = mysqli_fetch_field($result)) {
                array_push($fields, $field->name);
            }

            show_array_values($fields);
            // print_r

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