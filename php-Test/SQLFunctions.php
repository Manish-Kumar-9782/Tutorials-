<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../Tutorials/style.css">
    <title>SQLFunction</title>
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



<?php

include "Utility.php";

// ========================================================================//
// ========================================================================//


function sql_insert($connection, $table_name, $cols, $values)
{
    $str1 = null;
    $str2 = null;

    show_array($cols);
    show_array($values);

    if (is_array($cols)) {
        $str1 = join(",", $cols);
    }

    if (is_array($values)) {
        $str2 = join(",", $values);
    }

    $sql_query = "INSERT INTO $table_name ($str1) VALUES ($str2)";

    echo $sql_query;

    // Now Making query and storing the result of query inside the $result variable.
    $result = mysqli_query($connection, $sql_query);

    // if query is successfully then it will return 
    if ($result) {
        display("p", "Database Successfully Inserted: ", "success", "Success: ");
    } else {
        display("p", "Unable to Insert Data: " . mysqli_error($connection), "error", "Error: ");
    }

    mysqli_close($connection);
}

// ========================================================================//
// ========================================================================//

function sql_read_database($connection, $table_name)
{
    // first we will make the query string.
    $sql_query = "SELECT * FROM $table_name";

    // now we will run the query statement.
    $result = mysqli_query($connection, $sql_query);

    // if query is successfully then it will return 
    if ($result) {
        display("p", "Database Successfully Read: ", "success", "Success: ");
        return $result;
        // Now after getting $result pass this result into 
        // mysqli_fetch_row() or mysqli_fetch_all() function.
    } else {
        display("p", "Unable to Read Data: " . mysqli_error($connection), "error", "Error: ");
        return False;
    }
}


// ========================================================================//
// ========================================================================//



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

// sql_insert($con, "person", ["Name", "Age", "Height"], ["'Varsha'", 21, 5.6]);

// Now we will read and display data by using the tables.

$result = sql_read_database($con, "persona");
?>

<body>

    <?php if ($result) { ?>

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

    <?php } ?>
</body>

</html>