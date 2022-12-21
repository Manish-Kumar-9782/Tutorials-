<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../Tutorials/style.css">
    <title>LibManagement Login</title>
</head>
<body>
<?php 

include "../php-Test/SQLUtility.php";
// first we need to test the post request.
// show_array($_SERVER);

if($_SERVER['REQUEST_METHOD'] == 'POST'){

    $fname = $_POST['firstname'];
    $lname = $_POST['lastname'];
    $gmail = $_POST['gmail'];
    $pass = $_POST['password'];
    $cpass = $_POST['cpassword'];

    show_array($_POST);

    if($pass == $cpass){
        display("p", "Password Matched..", "success", "Result: ");
        $type = 'admin';
    }
    else{
        display("p", "Password MisMatched..", "error", "Result: ");
    }
}

?>
    
</body>
