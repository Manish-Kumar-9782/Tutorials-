<?php
require_once "SQLUtility.php";
// first we will test for any existing Cookies
$host = "localhost";
$user = "root";
$password = "";
$db_name = "libmanagement";
$table = "users";


// echo "<pre>", print_r($_COOKIE), "</pre>";
if (isset($_COOKIE['user']) && !empty($_COOKIE["user"])) {
    // echo "user cookie is found";
    use_cookies_login($host, $user, $password, $db_name, $table, $_COOKIE["user"]);
} else {
    // echo "user cookies not found..";

}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LogIn</title>
    <link rel="stylesheet" href="style.css">

</head>

<body>

    <div id="logincontainer">
        <div class="leftpart">
            <h2>Library Management</h2>
            <p>Begin with the books</p>
        </div>
        <div class="rightpart">
            <form action="<?= $_SERVER["PHP_SELF"] ?>" id="login" method="POST">
                <table>
                    <tr>
                        <td>
                            <input type="text" id="email" autocomplete="off" name="lemail" placeholder="Email address or phone number" required>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <input type="password" autocomplete="off" name="lpassword" id="password" placeholder="Password" required>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <input type="submit" value="submit" class="submit" name="login">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <hr>
                            <br>
                        </td>
                    </tr>
                </table>
                <button><a href="reg.php" id="signupbutton">Create New Account</a></button>

            </form>
        </div>
    </div>

    <?php

    if ($_SERVER["REQUEST_METHOD"] == 'POST') {
        // setcookie("userName", "Manish");
        process_login($host, $user, $password, $db_name, $table);
    }


    ?>

</body>

</html>