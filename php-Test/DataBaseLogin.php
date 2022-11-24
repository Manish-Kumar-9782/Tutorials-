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
    $db_name = "varsha_database";

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
     * CREATE TABLE `varsha_database`.`person` 
     * (`id` INT NOT NULL AUTO_INCREMENT , 
     * `Name` VARCHAR(30) NOT NULL , 
     * `Age` INT UNSIGNED NOT NULL , 
     * `Height` FLOAT UNSIGNED NOT NULL , 
     * `Reg_date` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP , 
     * `Modify_date` TIMESTAMP on update CURRENT_TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP , 
     * PRIMARY KEY (`id`)) ENGINE = InnoDB;
     */
    heading(2, "Creating a table..");
    $result = mysqli_query($con, "CREATE TABLE  Person");

    if ($result) {
        display("p", "Table successfully Created: ", "success", "Success: ");
    } else {
        display("p", "Unable To create Table: " . mysqli_error($con), "error", "Error: ");
    }
    ?>

</body>

</html>