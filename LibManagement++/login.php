<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../Tutorials/style.css">
    <title>Login</title>
</head>
<body>

    <?php

        include "../php-Test/SQLUtility.php";

        $host = "localhost";
        $user = "root";
        $password = "";
        $db_name = "libmanagement";
        $table = "users";

        if($_SERVER["REQUEST_METHOD"]== 'POST'){

            $email = filter_var($_POST['email'], FILTER_VALIDATE_EMAIL);
            $pass = $_POST['password'];

            $con = connect_db($host, $user, $password, $db_name, true);

            if($con){
                $data = sql_get($con, $table, 'Gmail', $email, 's');
                show_array($data);
            }

        }
    
    ?>


    
    <form action="<?= $_SERVER["PHP_SELF"]?>" method="post">
        <input type="email" placeholder="Enter email address" name="email"><br>
        <input type="password" placeholder="login password" name="password"><br>
        <input type="submit">
    </form>

</body>
</html>