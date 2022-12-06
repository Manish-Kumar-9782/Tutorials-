<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>mysqli_connect</title>
    <link rel="stylesheet" href="../../style.css">
</head>

<body class="p-5">
    <pre class="code-block">
    /**
     * /**
     * In this section we will learn how to make connection with the MySQL Database server.
     * 
     * To make a connection with the database we need three things 
     * 
     * 1. servername : localhost
     * 2. usernmae: root
     * 3. password: admin
     * 
     * after gathering all the required information we need to make a connection
     * by using the mysqli_connect() function.
     * 
     * if connection is successful then it will return an object else it will return
     * the `false`. The mysqli_connect_error() function error function can be used to
     * fetch the connection error.
     *
     * $server_name = "localhost";
     * $user_name = "root";
     * $password = "admin";
     *
     * Now after saving all the information we need to make a connection 
     *
     * Syntax:
     *     mysqli_connect(
     *           string $hostname = ini_get("mysqli.default_host"),
     *           string $username = ini_get("mysqli.default_user"),
     *           string $password = ini_get("mysqli.default_pw"),
     *           string $database = "",
     *           int $port = ini_get("mysqli.default_port"),
     *           string $socket = ini_get("mysqli.default_socket")
     *          ): mysqli|false
     * 
     * Parameters:
     * 
     *      hostname:
     *          Can be either a host name or IP address. The local host assumed when passing the
     *          null value or the string "localhost" to this parameter. When Possible, pipes will
     *          be used instead of the TCP/IP protocol. The TCP/IP protocol is used if a host name
     *          and port number are provided together e.g localhost:3308.
     * 
     *      username:
     *          The MySQL user name.
     * 
     *      password:
     *          if not provided or null, the MySQL server will attempt to authenticate the user against
     *          those user records which have no password only. This allows one username to be used with 
     *          different permission (depending on if a password is provided or not).
     * 
     * 
     *      database:
     *          if provided will specify the default database to be used when performing queries.
     * 
     * 
     *      port:
     *          Specifies the port number to attempt to connect to the MySQL server.
     * 
     * 
     *      socket:
     *          Specifies the socket or named pipe that should be used.
     * 
     *          Note: Specifying  the socket parameter will not explicitly determine the type of connection
     *          to be sued when connecting to the MySQL server. How the connection is made to the 
     *          MySQL database is determined by the hostname parameter.
     * 
     *      
     *     
     * Return: 
     *      it returns an object which represents the connection to a MySQL Server, or `false` on failure.
     * 
     * Errors/Exception:
     *      if MYSQLI_REPORT_STRICT is enabled and the attempt to connect to the requested database fails,
     *      a `mysqli_sql_exception` is thrown.
     * 
     * Note: 
     *    
     */
</pre>

    <?php
    include "../Utility.php";
    /**
     * /**
     * In this section we will learn how to make connection with the MySQL Database server.
     * 
     * To make a connection with the database we need three things 
     * 
     * 1. servername : localhost
     * 2. usernmae: root
     * 3. password: admin
     * 
     * after gathering all the required information we need to make a connection
     * by using the mysqli_connect() function.
     * 
     * if connection is successful then it will return an object else it will return
     * the `false`. The mysqli_connect_error() function error function can be used to
     * fetch the connection error.
     *
     * $server_name = "localhost";
     * $user_name = "root";
     * $password = "admin";
     *
     * Now after saving all the information we need to make a connection 
     *
     * Syntax:
     *     mysqli_connect(
     *           string $hostname = ini_get("mysqli.default_host"),
     *           string $username = ini_get("mysqli.default_user"),
     *           string $password = ini_get("mysqli.default_pw"),
     *           string $database = "",
     *           int $port = ini_get("mysqli.default_port"),
     *           string $socket = ini_get("mysqli.default_socket")
     *          ): mysqli|false
     * 
     * Parameters:
     * 
     *      hostname:
     *          Can be either a host name or IP address. The local host assumed when passing the
     *          null value or the string "localhost" to this parameter. When Possible, pipes will
     *          be used instead of the TCP/IP protocol. The TCP/IP protocol is used if a host name
     *          and port number are provided together e.g localhost:3308.
     * 
     *      username:
     *          The MySQL user name.
     * 
     *      password:
     *          if not provided or null, the MySQL server will attempt to authenticate the user against
     *          those user records which have no password only. This allows one username to be used with 
     *          different permission (depending on if a password is provided or not).
     * 
     * 
     *      database:
     *          if provided will specify the default database to be used when performing queries.
     * 
     * 
     *      port:
     *          Specifies the port number to attempt to connect to the MySQL server.
     * 
     * 
     *      socket:
     *          Specifies the socket or named pipe that should be used.
     * 
     *          Note: Specifying  the socket parameter will not explicitly determine the type of connection
     *          to be sued when connecting to the MySQL server. How the connection is made to the 
     *          MySQL database is determined by the hostname parameter.
     * 
     *      
     *     
     * Return: 
     *      it returns an object which represents the connection to a MySQL Server, or `false` on failure.
     * 
     * Errors/Exception:
     *      if MYSQLI_REPORT_STRICT is enabled and the attempt to connect to the requested database fails,
     *      a `mysqli_sql_exception` is thrown.
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