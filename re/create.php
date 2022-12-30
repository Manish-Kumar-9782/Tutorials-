<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lib Management Dashboard</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.3/font/bootstrap-icons.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="dashboard.css">

</head>

<body>

    <div id="signupcontainer" class="container d-flex justify-content-center align-items-center vh-100">

        <form action="<?= $_SERVER["PHP_SELF"] ?>" method="POST" class="row g-3 w-50 border bg-secondary px-5 py-3 text-light rounded">

            <div class="col-md-12">
                <label for="firstName" class="form-label">First Name</label>
                <input type="text" class="form-control" id="firstName" name="firstName" required>
            </div>

            <div class="col-md-12">
                <label for="secondName" class="form-label">Second Name</label>
                <input type="text" class="form-control" id="secondName" name="secondName">
            </div>

            <div class="col-md-12">
                <label for="LastName" class="form-label">Last Name</label>
                <input type="text" class="form-control" id="LastName" name="LastName">
            </div>

            <div class="col-md-12">
                <label for="email" class="form-label">Email</label>
                <input type="email" class="form-control" id="email" name="email" required>
            </div>
            <div class="col-md-12">
                <label for="password" class="form-label">Password</label>
                <input type="password" class="form-control" id="password" name="password" required>
            </div>

            <div class="col-md-12">
                <label for="confirm-password" class="form-label">Confirm Password</label>
                <input type="password" class="form-control" id="confirm-password" name="confirm-password" required>
            </div>

            <div class="col-12">
                <div class="form-check d-inline-block">
                    <input class="form-check-input" type="radio" name="account-type" id="gridRadios1" value="student" checked>
                    <label class="form-check-label" for="gridRadios1">Student</label>
                </div>

                <div class="form-check d-inline-block px-5">
                    <input class="form-check-input" type="radio" name="account-type" id="gridRadios2" value="teacher">
                    <label class="form-check-label" for="gridRadios2">Teacher</label>
                </div>
            </div>
            <div class="col-12">
                <input type="submit" class="btn btn-success" value="Register">
            </div>
        </form>
    </div>

    <?php
    include "SQLUtility.php";

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "libmanagement";
    $table = "users";


    if ($_SERVER['REQUEST_METHOD'] == 'POST') {

        echo "post request detected";

        $_SUBMIT = false;
        $tpassword = $_POST["password"];
        $cpassword = $_POST["confirm-password"];

        $fname = $_POST["firstName"];
        $sname = $_POST["secondName"];
        $lname = $_POST["LastName"];
        $email = $_POST["email"];
        $type  = $_POST["account-type"];
        $is_active = false;

        if ($type == 'student') {
            $access_level = 1;
            $permissions = [
                'r' => 'read-only'
            ];
            $is_super = false;
        } else if ($type == 'teacher') {
            $access_level = 2;
            $permissions = [
                'r' => 'read-only',
                'r+' => 'read & write',
                'w+' => 'write & update'
            ];
            $is_super = false;
        } else {
        }


        if ($tpassword == $cpassword) {

            $_SUBMIT = true;

            $con = connect_db($host, $user, $password, $db_name);

            if ($con && $_SUBMIT) {

                $prs = join(",", array_keys($permissions));

                sql_insert_prepare(
                    $con,
                    $table,
                    ['FirstName', "SecondName", 'LastName', 'Gmail', 'Password', 'IsSuper', 'IsActive', 'AccessLevel', 'Permissions', 'Type'],
                    [$fname, $sname, $lname, $email, $cpassword, $is_super, $is_active, $access_level, "$prs", $type],
                    "sssssiiiss"
                );

                header("Location: dashboard.php");
            } else {
                // display("p", "Connected not successfull" . mysqli_error($con));
            }
        } else {
            display("p", "Password MisMatched..");
        }
    }

    ?>
</body>

</html>