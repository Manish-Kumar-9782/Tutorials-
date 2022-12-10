<?php
// ========================================================================//
// ========================================================================//

include "Utility.php";

function connect_db($host, $user, $password, $db_name, $info = False)
{
    // to make a connection we need to use mysqli_connect(host, user, password)

    $con = mysqli_connect($host, $user, $password, $db_name);

    if ($con) {

        if ($info) {
            display("p", "Connected To the Database successfully: ", "success", "Success: ");
        }
        return $con;
    } else {
        if ($info) {
            display("p", "Unable To connect to database: " . mysqli_connect_error(), "error", "Error: ");
        }
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


function sql_update($connection, $table_name, $id, $col, $values, $dtypes)
{

    $columns = null;
    $arr = [];

    // for ($i = 0; $i < count($col); $i++) {

    //     array_push($arr, $col[$i] . "=" . $values[$i]);
    //     $columns = join(",", $arr);
    // }

    foreach ($col as $cl) {
        array_push($arr, $cl . "=?");
    }

    $columns = join(",", $arr);

    // Title
    $query = "UPDATE $table_name  SET  $columns  WHERE id=$id";


    display("p", $columns, "data", "Cols: ");
    display("p", $query, "data", "Query: ");

    // $stmt = mysqli_query($connection, $query);
    $stmt = mysqli_prepare($connection, $query);

    if ($stmt) {
        $stmt->bind_param($dtypes, ...$values);
        $stmt->execute();
        return true;
    } else {
        display("p", "Unable to prepare query: " . mysqli_error($connection), "error", "Error");
    }
    return false;
}


// ===================================================================//


function sql_get($con, $table, $id)
{
    // this function will be used to get a single row form the database. (if found)

    $id = filter_var($id, FILTER_VALIDATE_INT);

    $stmt = mysqli_query($con, "SELECT Title, Author, Subject, Pages, Price FROM $table WHERE id=$id");

    if ($stmt) {
        $result = mysqli_fetch_row($stmt);
        if ($result) {
            return $result;
        } else {
            display("p", "Unable to execute query: " . mysqli_error($con), "error", "Error");
        }
    } else {
        display("p", "Unable to prepare query: " . mysqli_error($con), "error", "Error");
    }

    return false;
}


//======================================================================//
function sql_delete($con, $table, $id){

    $stmt = mysqli_prepare($con, "DELETE FROM $table WHERE id=?");
    if($stmt){
        $stmt->bind_param("i",$id);
        $result = $stmt->execute();
        if($result){
            return true;
        }
        else{
            display("p", "Unable to delete Data: ".mysqli_error($con), "error", "Error: ");
        }
    }
    else{
        display("p", "Unable to Prepare Query: ".mysqli_error($con), "error", "Error: ");
    }
    return false;
}
?>

<!-- Only for testing  -->

<?php

// $host = "localhost";
// $user = "root";
// $password = "";
// $db_name = "abhi_database";
// $table = "Books";

// $con = connect_db($host, $user, $password, $db_name, true);

// if ($con) {

//     // now after making the successful connection we need to read the data.
//     echo "connection has been made..";

//     sql_update(
//         $con,
//         $table,
//         2,
//         ["Title", "Author", "Subject", "Pages", "Price"],
//         ["IC Engine", "Manish Kumar", "V-Engine", 240, 20],
//         "sssid"
//     );

//     // we will test that result is good or bad.
// } else {
//     $result = false;
// }


?>