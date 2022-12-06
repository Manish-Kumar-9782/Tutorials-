<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>mysqli_query</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * In this section we will learn that how to use the `mysqli_query` function.
     *
     * mysqli_query: Performs a query on the database.
     *      
     *      Performs a query against the database.
     * 
     *      For non-DML queries (not INSERT, UPDATE or DELETE), this function is similar to 
     *      calling mysqli_real_query() followed by either mysqli_use_result() or   
     *      mysqli_store_result().
     * 
     *      In the case where we pass a statement to mysqli_query() that is longer than 
     *      max_allowed_packet of the server, the returned error codes are different depending
     *      on whether we are using MySQL Native Driver (mysqlnd) or MySQL Client Library
     *      (libmysqlclient). The behavior is follows.
     * 
     *      -> `mysqlnd` on Linux returns an error code of 1153. The error message means "got 
     *          a packet bigger than max_allowed_packet bytes".
     * 
     *      -> `mysqlnd` on Windows returns an error code 2006. This error message means "server
     *          has gone away"
     * 
     *      -> `ibmysqlclient` on all platforms returns an error code 2006. This error message means
     *          "server has gone away". 
     * 
     * Syntax:
     *      mysqli_query(mysqli $mysql, string $query, int $result_mode = MYSQLI_STORE_RESULT): mysqli_result|bool
     * 
     * Parameters:
     * 
     *      mysql:
     *          A mysqli object returned by mysqli_connect() or mysqli_init()
     * 
     *      query:
     *          The query string.
     * 
     *          Warning: Security Warning: SQL injection
     * 
     *              if the query contains any variable input then `parameterized prepared statement`
     *              should be used instead.
     * 
     *              Alternatively, the data must be properly formatted and all strings must be escaped 
     *              using the mysqli_real_escape_string() function.
     * 
     *      result_noe:
     *          The result mode can one of 3 constant indicating how the result will be returned from the
     *          MySQL server.
     * 
     *          -> MYSQLI_STORE_RESULT (default): returns a `mysqli_result` object with buffered result set.
     * 
     *          -> MYSQLI_USE_RESULT: returns a `mysqli_result` object with unbuffered result set. As long 
     *              as there are are pending records waiting to be fetched, the connection line will be busy 
     *              and all subsequent call will return error `Commands out of sync`. 
     *              
     *              To avoid the error all records must be fetched from the server or the result set must be
     *              discarded by calling mysqli_free_result().
     * 
     *          -> MYSQLI_ASYNC (available with mysqlnd): the query is performed asynchronously and no result
     *              set is immediately returned. `mysqli_poll()` is then used to get results from such queries.
     *              Used in combination with either "MYSQLI_STORE_RESULT" or "MYSQLI_USE_RESULT" constant.
     *     
     * Return: 
     *      Returns false on failure. For Successful queries which produce a result set, such as SELECT, SHOW, 
     *      DESCRIBE or EXPLAIN, mysqli_query() will return a `mysqli_result` object. For other
     *      successfully queries, mysqli_query() will return true.
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
     * In this section we will learn that how to use the `mysqli_query` function.
     *
     * mysqli_query: Performs a query on the database.
     *      
     *      Performs a query against the database.
     * 
     *      For non-DML queries (not INSERT, UPDATE or DELETE), this function is similar to 
     *      calling mysqli_real_query() followed by either mysqli_use_result() or   
     *      mysqli_store_result().
     * 
     *      In the case where we pass a statement to mysqli_query() that is longer than 
     *      max_allowed_packet of the server, the returned error codes are different depending
     *      on whether we are using MySQL Native Driver (mysqlnd) or MySQL Client Library
     *      (libmysqlclient). The behavior is follows.
     * 
     *      -> `mysqlnd` on Linux returns an error code of 1153. The error message means "got 
     *          a packet bigger than max_allowed_packet bytes".
     * 
     *      -> `mysqlnd` on Windows returns an error code 2006. This error message means "server
     *          has gone away"
     * 
     *      -> `ibmysqlclient` on all platforms returns an error code 2006. This error message means
     *          "server has gone away". 
     * 
     * Syntax:
     *      mysqli_query(mysqli $mysql, string $query, int $result_mode = MYSQLI_STORE_RESULT): mysqli_result|bool
     * 
     * Parameters:
     * 
     *      mysql:
     *          A mysqli object returned by mysqli_connect() or mysqli_init()
     * 
     *      query:
     *          The query string.
     * 
     *          Warning: Security Warning: SQL injection
     * 
     *              if the query contains any variable input then `parameterized prepared statement`
     *              should be used instead.
     * 
     *              Alternatively, the data must be properly formatted and all strings must be escaped 
     *              using the mysqli_real_escape_string() function.
     * 
     *      result_noe:
     *          The result mode can one of 3 constant indicating how the result will be returned from the
     *          MySQL server.
     * 
     *          -> MYSQLI_STORE_RESULT (default): returns a `mysqli_result` object with buffered result set.
     * 
     *          -> MYSQLI_USE_RESULT: returns a `mysqli_result` object with unbuffered result set. As long 
     *              as there are are pending records waiting to be fetched, the connection line will be busy 
     *              and all subsequent call will return error `Commands out of sync`. 
     *              
     *              To avoid the error all records must be fetched from the server or the result set must be
     *              discarded by calling mysqli_free_result().
     * 
     *          -> MYSQLI_ASYNC (available with mysqlnd): the query is performed asynchronously and no result
     *              set is immediately returned. `mysqli_poll()` is then used to get results from such queries.
     *              Used in combination with either "MYSQLI_STORE_RESULT" or "MYSQLI_USE_RESULT" constant.
     *     
     * Return: 
     *      Returns false on failure. For Successful queries which produce a result set, such as SELECT, SHOW, 
     *      DESCRIBE or EXPLAIN, mysqli_query() will return a `mysqli_result` object. For other
     *      successfully queries, mysqli_query() will return true.
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
    } else {
        die("<br>Connection failed: " . mysqli_connect_error() . "<br>");
        // here mysqli_connect_error() will show the error during making connection.
    }
    ?>

    <?php
    // Now after making the successful connection with the database we need to 
    // work on some queries.

    // we can store our SQL query string in a variable or we can pass that directly 
    // to the function.

    $query = "create database testDB";

    // Now we need to pass that string into the query function.
    // Note: query function will return a result object on success, else false.

    $result = mysqli_query($con, $query);

    // Now we will test that our database created or there is an error 

    if ($result) {
        display("p", "Database Created Successfully..!", "success", "Success: ");
    } else {
        display("p", "Error during creating database, " . mysqli_error($con), "error", "Error: ");
    }

    // Now success or failure we will close the connection.

    mysqli_close($con);

    ?>
</body>

</html>