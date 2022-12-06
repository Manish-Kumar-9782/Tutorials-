<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="../Tutorials/style.css">
</head>

<body>
    <?php

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "abhi_database";

    // include "../php-Test/Utility.php";
    include "../php-test/SQLUtility.php";

    show_array($_POST);

    $pages = null;
    $price = null;

    if (!($pages = filter_var($_POST['pages'], FILTER_VALIDATE_INT))) {
        display("p", "pages values is invalid", "error", "Error: ");
    }

    if (!($price = filter_var($_POST['price'], FILTER_VALIDATE_FLOAT))) {
        display("p", "pages values is invalid", "error", "Error: ");
    }

    $Title = $_POST["title"];
    $Author = $_POST["author"];
    $Subject = $_POST["subject"];

    $con = connect_db($host, $user, $password, $db_name);

    if ($con) {
        // sql_insert($con, "Books", ["Title", "Author", "Subject", "Pages", "Price"], []);

        $stmt = mysqli_prepare($con, "INSERT INTO Books (Title, Author, Subject, Pages, Price) VALUES (?,?,?,?,?)");

        $stmt->bind_param("sssid", $Title, $Author, $Subject, $pages, $price);

        $result = $stmt->execute();
        if ($result) {
            display("p", "Inserted To the Database successfully: ", "success", "Success: ");
            header("Location: index.php");
            die;
        } else {
            display("p", "Unable To Insert to database: " . mysqli_errno($con), "error", "Error: ");
        }
    }


    ?>
</body>

</html>