
<?php
// ========================================================================//
// ========================================================================//

include "Utility.php";

function connect_db($host, $user, $password, $db_name)
{
    // to make a connection we need to use mysqli_connect(host, user, password)

    $con = mysqli_connect($host, $user, $password, $db_name);

    if ($con) {
        display("p", "Connected To the Database successfully: ", "success", "Success: ");
        return $con;
    } else {
        display("p", "Unable To connect to database: " . mysqli_connect_error(), "error", "Error: ");
        return false;
    }
}


function sql_insert($connection, $table_name, $cols, $values)
{
    $column_string = null; // this will contain the cols values as string.
    $values_string = null; // this will contain the values of columns as string.

    if (is_array($cols)) {
        $column_string = join(",", $cols);
    }

    if (is_array($values)) {
        $values_string = join(",", $values);
    }

    $sql_query = "INSERT INTO $table_name ($column_string) VALUES ($values_string)";

    // echo $sql_query; // displaying the sql_query string on page.
    display("code", '"' . $sql_query . '"', "data", "Query: ");

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

?>