<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../Tutorials/style.css">
    <title>Database Intro</title>

    <style>
        table,
        td,
        th {
            border: 1px solid;
            border-collapse: collapse;
        }

        td,
        th {
            padding: 4px 8px;
        }
    </style>
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


    // Now we will make or query string to make a table
    $sql_query = "SELECT * FROM person";
    heading(2, "Reading Database...");

    $result = mysqli_query($con, $sql_query);

    if ($result) {
        display("p", "Found Rows In Person :" . mysqli_num_rows($result), "success", "Rows: ");
        display("p", "Found Fields In Person " . mysqli_num_fields($result), "success", "Fields: ");
    } else {
        display("p", "Unable to update: " . mysqli_error($con), "error", "Error: ");
    }



    ?>

    <table>

        <thead>
            <tr>

                <?php while ($field = mysqli_fetch_field($result)) { ?>

                    <th><?= $field->name ?></th>

                <?php } ?>

            </tr>
        </thead>

        <tbody>

            <?php while ($row = mysqli_fetch_row($result)) { ?>

                <tr>
                    <?php foreach ($row as $value) { ?>
                        <td><?= $value ?></td>
                    <?php } ?>
                </tr>

            <?php }

            mysqli_close($con);
            ?>

        </tbody>
    </table>


</body>

</html>