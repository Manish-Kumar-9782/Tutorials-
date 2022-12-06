<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>mysqli_close</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn that how to use the `mysqli_close` function.
     *
     * mysqli_close: Close a previously opened database connection.
     *      
     *      Open non-persistent MySQL connections and results sets are automatically closed
     *      when their objects are destroyed. Explicitly closing open connections and freeing
     *      result set is optional.
     * 
     *      However, it's a good idea to close the connection as soon as the script finishes
     *      performing all of its database operations, if it still has a lot of processing to do
     *      after getting the results. 
     * 
     * Syntax:
     *      mysqli_close(mysqli $mysql): bool
     * 
     * Parameters:
     * 
     *      mysql:
     *          A mysqli object returned by mysqli_connect() or mysqli_init().
     *     
     * Return: 
     *      Returns `true` on success or `false` on failure.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *    
     */
</pre>

    <?php
    include "../Utility.php";
    /**
     * In this section we will learn that how to use the `mysqli_close` function.
     *
     * mysqli_close: Close a previously opened database connection.
     *      
     *      Open non-persistent MySQL connections and results sets are automatically closed
     *      when their objects are destroyed. Explicitly closing open connections and freeing
     *      result set is optional.
     * 
     *      However, it's a good idea to close the connection as soon as the script finishes
     *      performing all of its database operations, if it still has a lot of processing to do
     *      after getting the results. 
     * 
     * Syntax:
     *      mysqli_close(mysqli $mysql): bool
     * 
     * Parameters:
     * 
     *      mysql:
     *          A mysqli object returned by mysqli_connect() or mysqli_init().
     *     
     * Return: 
     *      Returns `true` on success or `false` on failure.
     * 
     * Errors/Exception:
     *      ...
     * 
     * Note: 
     *    
     */
    ?>

    <?php
    // to disable the warning and error we can uncomment these two lines
    // error_reporting(0); // to set the error_reporting on php
    // mysqli_report(MYSQLI_REPORT_OFF); // to set the error reporting on mysql function.
    // Now we will try to make a connection with the SQL Server.

    $server_name = "localhost";
    $user_name = "root";
    $password = "";

    // Now connecting to the server.

    $con = mysqli_connect($server_name, $user_name, $password);

    // since we don't have any database right know so we will not pass any database name.

    // Now we need to test that our connection made or not

    // if $con is false it means connection not made.

    if ($con) {
        heading(4, "Connected To Database.");

        $con_closed = mysqli_close($con);
        // this will close the previously opened database connection.
        // it required the object returned by the mysqli_connect() on successfully 
        // establishing a connection.

        // mysqli_close will return true on success or false on failure
        if ($con_closed) {
            heading(4, "Connection has been closed with database.");
        } else {
            heading(4, "Unable to close the Connection with database.");
        }
    } else {
        die("<br>Connection failed: " . mysqli_connect_error() . "<br>");
        // here mysqli_connect_error() will show the error during making connection.
    }
    ?>
</body>

</html>