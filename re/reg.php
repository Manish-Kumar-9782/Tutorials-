<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration</title>
    <link rel="stylesheet" href="style.css">
   
</head>

<body>

<div id="signupcontainer">
        <form action="<?= $_SERVER["PHP_SELF"] ?>" method="POST" id="signupform">
            <div class="head">
                <div>
                    <h2>Sign Up</h2>
                    <p>It's quick and easy</p>
                </div>
                <div>
                    <button class="button" onclick="login()">X</button>
                </div>
            </div>
            <hr>
            <br>
            <table>
                <tr>
                    <td>
                        <input type="text" placeholder="first Name" id="fname" name="fname" required>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="text" placeholder="Last Name" id="lname" name="lname" required>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="email" name="email" id="email" placeholder="Mobile number or email address"
                            required>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="password" name="password" id="password" placeholder="Password" required>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="password" name="cpassword" id="cpassword" placeholder="Conform password" required>
                    </td>
                </tr>
            </table>
            <input type="submit" name="submit" class="submit" value="Sign Up">
        </form>
    </div>

    <?php
    require "SQLUtility.php";

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "libmanagement";
    $table = "users";


    if($_SERVER['REQUEST_METHOD'] == 'POST'){

    $_SUBMIT = false;
    $tpassword = $_POST["password"];
    $cpassword = $_POST["cpassword"];
    
    $fname = $_POST["fname"];
    $lname = $_POST["lname"];
    $email = $_POST["email"];
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

    
    if($tpassword == $cpassword){
        
        $_SUBMIT= true;

        $con = connect_db($host, $user, $password, $db_name);
        
                if($con && $_SUBMIT){
        
                    $prs = join(",", array_keys($permissions));

                    sql_insert_prepare($con, $table, ['FirstName', 'LastName', 'Gmail', 'Password', 'IsSuper', 'IsActive', 'AccessLevel', 'Permissions', 'Type'],
                    [$fname, $lname, $email, $cpassword, $is_super, $is_active, $access_level, "$prs", $type], "ssssiiiss");

                    header("Location: login.php");
                    
                }
                else{
                display("p", "Unable to connect to the database" . mysqli_error($con));
                }
                
    }else{
        display("p", "Password MisMatched..");
    }
     


    }
    
    ?>
</body>

</html>