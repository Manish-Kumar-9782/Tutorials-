<?php 

require "../php-test/SQLUtility.php";

// Now first test the POST request.




if(isset($_GET['id'])){
    $id  = $_GET['id'];

    // now we need to send the delete request to sql sever
    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "abhi_database";
    $table = "Books";

    $con = connect_db($host, $user, $password, $db_name, true);


    if($con){
        $result = sql_delete($con, $table, $id);
        if($result){
            header("Location: Read.php");
        }
    }

}

?>