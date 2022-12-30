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

    include "SQLUtility.php";

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "libmanagement";
    $table = "users";


    if ($_SERVER["REQUEST_METHOD"] == 'POST') {



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
            // show_array($data);
        }
    }


    ?>

</body>

</html>