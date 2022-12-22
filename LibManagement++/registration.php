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

// This Registration section if for only admin account

$host = "localhost";
$user = "root";
$password = "";
$db_name = "libmanagement";
$table = "users";

if($_SERVER['REQUEST_METHOD'] == 'POST'){


    $fname = $_POST['firstname'];
    $lname = $_POST['lastname'];
    $gmail = $_POST['gmail'];
    $pass = $_POST['password'];
    $cpass = $_POST['cpassword'];
    $is_active = false;
    $is_super = true;
    $access_level = 3;
    $permissions = [
        'r' => 'read-only',
        'r+' => 'read & write',
        'w' => 'write-only',
        'w+' => 'write & update',
        'w-' => 'delete'
    ];

    

    $Regtypes = ['admin', 'student', 'teacher'];
    $type = 'admin';


    $gmail = filter_var($gmail, FILTER_VALIDATE_EMAIL);
    show_array($_POST);

    if($pass == $cpass){
        display("p", "Password Matched..", "success", "Result: ");

      $con =   connect_db($host, $user, $password, $db_name, true);

      if($con){
        $prs = join(",", array_keys($permissions));
        sql_insert_prepare($con, $table, ['FirstName', 'SecondName', 'LastName', 'Gmail', 'Password', 'IsSuper',
                'IsActive','AccessLevel', 'Permissions', 'Type'], 
                [$fname, '--', $lname, $gmail,$pass, $is_super, $is_active, $access_level, 
                "$prs", $type]);
        // sssssiiiss
      }
        
    }
    else{
        display("p", "Password MisMatched..", "error", "Result: ");
    }
}

?>
    
</body>
