<?php

include "array_test_extra.php";

//=======================================================//

// function for connecting database
function connect_db($host, $user, $password, $db_name)
{
    $con = mysqli_connect($host, $user, $password, $db_name);

    return $con;

    if ($con) {
        display("p", "Connected To the Database successfully: ");
        return $con;
    } else {
        display("p", "Unable To connect to database: " . mysqli_connect_error());
        return false;
    }
}

//=======================================================//
function connect_database($host, $user, $password, $db_name, $info = False)
{
    // to make a connection we need to use mysqli_connect(host, user, password)

    $con = mysqli_connect($host, $user, $password, $db_name);

    if ($con) {

        // if ($info) {
        //     display("p", "Connected To the Database successfully: ");
        // }
        return $con;
    } else {
        // if ($info) {
        //     display("p", "Unable To connect to database: " . mysqli_connect_error());
        // }
        return false;
    }
}


//=======================================================//

// function for read database
function read_database($connection, $table_name, $columns = "*", $where = null)
{
    // first we will make the query string.

    if (is_array($columns)) {
        $columns = join(",", $columns);
    }

    $sql_query = "SELECT {$columns} FROM $table_name";

    if ($where != null) {
        $sql_query .= " WHERE {$where};";
    }


    // now we will run the query statement.
    $result = mysqli_query($connection, $sql_query);

    // if query is successfully then it will return 
    if ($result) {
        // display("p", "Database Successfully Read: ");
        return $result;
        // Now after getting $result pass this result into 
        // mysqli_fetch_row() or mysqli_fetch_all() function.
    } else {
        display("p", "Unable to Read Data: " . mysqli_error($connection));
        return False;
    }
}



//=======================================================//

// function for insert into database
function insert($connection, $table_name, $cols, $values)
{
    $column_string = null; // this will contain the cols values as string.
    $value_string = null; // this will contain the values of columns as string.

    if (is_array($cols)) {
        $column_string = join(",", $cols);
    }

    if (is_array($values)) {
        $value_string = join(",", $values);
    }

    $sql_query = "INSERT INTO $table_name ($column_string) VALUES ($value_string)";

    $result = mysqli_query($connection, $sql_query);

    // if query is successfully then it will return 
    if ($result) {
        display("p", "Database Successfully Inserted: ");
    } else {
        display("p", "Unable to Insert Data: " . mysqli_error($connection));
    }

    mysqli_close($connection);
}

//=======================================================//

function sql_insert_prepare($connection, $table_name, $cols, $values, $dataTypes)
{
    $column_string = null; // this will contain the cols value as string
    $value_string = null; // this will contain the values of column as string

    if (is_array($cols)) {
        $column_string = join(",", $cols);
    }

    if (is_array($values)) {
        $value_string = join(",", array_fill(0, count($cols), "?"));
    }

    $sql_query = "INSERT INTO $table_name ($column_string) VALUES ($value_string)";

    // display("code", '"' . $sql_query . '"');


    $stmt = mysqli_prepare($connection, $sql_query);

    if ($stmt) {
        $stmt->bind_param($dataTypes, ...$values);
        $result = $stmt->execute();

        if ($result) {
            display("p", "Data Inserted Successfully: " . mysqli_error($connection));
        } else {
            display("p", "Unable to Execute Sql Query: " . mysqli_error($connection));
        }
    } else {
        display("p", "Unable to Prepare Sql Query: " . mysqli_error($connection));
    }

    mysqli_close($connection);
}

//=======================================================//

// function for delete data from databaseq

function delete_data($connection, $table_name, $id)
{

    $stmt = mysqli_prepare($connection, "DELETE FROM $table_name WHERE id=?");
    if ($stmt) {
        $stmt->bind_param("i", $id);
        $result = $stmt->execute();
        if ($result) {
            return true;
        } else {
            display("p", "Unable to delete Data: " . mysqli_error($connection));
        }
    } else {
        display("p", "Unable to Prepare Query: " . mysqli_error($connection));
    }
    return false;
}
//=======================================================//

// function for delete data for notes project

function delete_data2($connection, $table_name, $id)
{

    $stmt = mysqli_prepare($connection, "DELETE FROM $table_name WHERE sno=?");
    if ($stmt) {
        $stmt->bind_param("i", $id);
        $result = $stmt->execute();
        if ($result) {
            return true;
        } else {
            display("p", "Unable to delete Data: " . mysqli_error($connection));
        }
    } else {
        display("p", "Unable to Prepare Query: " . mysqli_error($connection));
    }
    return false;
}

//=======================================================//

// function for update data from database

function update_data($connection, $table_name, $id, $col, $values, $dataTypes)
{

    $column = null;
    $arr = [];

    foreach ($col as $cl) {
        array_push($arr, $cl . "=?");
    }

    $column = join(",", $arr);

    $sql_query = "UPDATE $table_name SET $column WHERE id=$id";

    display("p", $column);
    display("p", $sql_query);

    $stmt = mysqli_prepare($connection, $sql_query);

    if ($stmt) {
        $stmt->bind_param($dataTypes, ...$values);
        $stmt->execute();
        return true;
    } else {
        display("p", "unable to prepare query: " . mysqli_error($connection));
    }
    return false;
}

//=======================================================//
function sql_get($con, $table, $col, $col_value, $dtype)
{
    // this function will be used to get a single row form the database. (if found)

    $stmt = mysqli_prepare($con, "SELECT * FROM $table WHERE $col=?");

    if ($stmt) {
        $stmt->bind_param($dtype, $col_value);
        $result = $stmt->execute();
        if ($result) {
            $result =  $stmt->get_result();
            return mysqli_fetch_assoc($result);
        } else {
            display("p", "Unable to execute query: " . mysqli_error($con));
        }
    } else {
        display("p", "Unable to prepare query: " . mysqli_error($con));
    }

    return false;
}

function init_session($assoc_values)
{
    /**
     * this Function will be used to initiate a session by providing the given information.
     */
    if (is_array($assoc_values)) {

        // first we need to start a session
        session_start();

        // Now we need to set the session variables
        foreach ($assoc_values as $key => $value) {
            $_SESSION[$key] = $value;
        }
    } else {
        display("p", "Required Assocative array of values");
    }
}

function validate_user()
{
    // first we need to retrieve the session
    session_start();
    if (isset($_SESSION["user-auth"])) {
        // first we will see the user-auth property
        if (!$_SESSION["user-auth"]) {
            // if user-auth is set to the session
            // if user is not authenticated then we need to die 
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

function has_permission($perm)
{
    // first we will get the array of permission then we will test the 
    // presence of that permission in array 
    foreach (explode(",", $_SESSION["user-Permissions"]) as $perm) {
        if ($perm == $perm) {
            // if permission is present then return true
            return true;
        }
    }

    // if permission
    return false;
}

function process_login($host, $user, $password, $db_name, $table)
{
    $con = connect_db($host, $user, $password, $db_name);

    if ($con) {
        // first we will escape our string
        $email = mysqli_real_escape_string($con, $_POST['lemail']);

        // Now we will validate our email
        filter_var($_POST['lemail'], FILTER_VALIDATE_EMAIL);

        // getting password form post method.
        $pass = $_POST['lpassword'];

        // Now we will get data using the given information.
        $data = sql_get($con, $table, 'Gmail', $email, 's');

        // now if we have data then we need to verify the data.
        if ($data) {

            // Now we will match the data

            if ($data['Password'] == $pass) {

                // Now we will create a Session
                init_session([
                    "user-id" => $data['id'],
                    "user-FirstName" => $data['FirstName'],
                    "user-LastName" => $data['LastName'],
                    "user-IsSuper" => $data['IsSuper'] ? true : false,
                    "user-IsActive" => true,
                    "user-AccessLevel" => $data["AccessLevel"],
                    "user-Type" => $data["Type"],
                    "user-Permissions" => $data["Permissions"],
                    "user-auth" => true
                ]);

                assert(setcookie("user", $data['Gmail'], time() + 3600, "/re", "localhost", false, true));

                // after setting all these setting to the session we will redirect to the dashboard 
                header("Location: dashboard.php");
            } else {
                display("p", "UserName or Password is not Matched.");
                die();
            }
        } else {
            display("p", "UserName or Password is not Matched.");
            die();
        }
    }
}

function use_cookies_login($host, $user, $password, $db_name, $table, $email)
{
    $con = connect_db($host, $user, $password, $db_name);

    if ($con) {
        // Now we will get data using the given information.
        $data = sql_get($con, $table, 'Gmail', $email, 's');

        // now if we have data then we need to verify the data.
        if ($data) {
            // Now we will create a Session
            try {
                init_session([
                    "user-id" => $data['id'],
                    "user-FirstName" => $data['FirstName'],
                    "user-LastName" => $data['LastName'],
                    "user-IsSuper" => $data['IsSuper'] ? true : false,
                    "user-IsActive" => true,
                    "user-AccessLevel" => $data["AccessLevel"],
                    "user-Type" => $data["Type"],
                    "user-Permissions" => $data["Permissions"],
                    "user-auth" => true
                ]);
                // after setting all these setting to the session we will redirect to the dashboard 
                header("Location: dashboard.php");
            } catch (Exception $e) {
                echo $e;
            }
        } else {
            display("p", "UserName or Password is not Matched.");
            die();
        }
    } else {
        display("p", "UserName or Password is not Matched.");
        die();
    }
}


?>

<?php

// $host = "localhost";
// $user = "root";
// $password = "";
// $table = "books";
// $db_name = "abhi_database";

// $con = connect_db($host, $user, $password, $db_name);

// if($con){

//     $delete = delete_data($con, $table, 6);
// }
// else{
//     display("p", "Unable to delete data" . mysqli_error($con));
// }

?>