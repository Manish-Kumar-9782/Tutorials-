<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library Management</title>
    <link rel="stylesheet" href="../Tutorials/style.css">
</head>

<body>
    <!-- 
        <label>: it used to provide the text for input, it is bound with input element
            with the help of input name.

        <input>: it is an element which is used to get the input from the user  by providing the input field.

        Attribute:

        label::for -> name of the input to which it will bound. 

            title, author, subject, pages, prices
     -->




    <div class="main-container">

        <!-- add book form section. -->
        <form action="<?= $_SERVER["PHP_SELF"] ?>" method="POST" id="library">


            <table>

                <tr>
                    <td>
                        <label for="title">Enter Book Title</label>
                    </td>
                    <td>
                        <input type="text" id="title" name="title" required>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="author">Enter Book Author Name:</label>
                    </td>
                    <td>
                        <input type="text" id="author" name="author" required>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="subject">Enter Book Subject</label>
                    </td>
                    <td>
                        <input type="text" id="subject" name="subject" required>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="pages">Enter Book Pages</label>
                    </td>
                    <td>
                        <input type="text" id="pages" name="pages" required>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="prices">Enter Book Prices</label>

                    </td>
                    <td>
                        <input type="text" id="price" name="price" required>
                    </td>
                </tr>
            </table>

            <input type="submit" value="add book" name="submit">
        </form>
    </div>

    <?php

    include "../php-test/SQLUtility.php";

    // testing that our submit button is pressed...
    // if pressed then we will run the if block.
    if (isset($_POST["submit"])) {
        // show_array($_POST);

        $host = "localhost";
        $user = "root";
        $password = "";
        $db_name = "abhi_database";


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

        if ($con && $pages && $price) {
            // sql_insert($con, "Books", ["Title", "Author", "Subject", "Pages", "Price"], []);

            $stmt = mysqli_prepare($con, "INSERT INTO Books (Title, Author, Subject, Pages, Price) VALUES (?,?,?,?,?)");

            $stmt->bind_param("sssid", $Title, $Author, $Subject, $pages, $price);

            $result = $stmt->execute();

            if ($result) {
                display("p", "Inserted To the Database successfully: ", "success", "Success: ");
                display("p", "Form Submitted...", "success", "Result: ");
            } else {
                display("p", "Unable To Insert to database: " . mysqli_errno($con), "error", "Error: ");
            }
        } else {
            display("p", "Unable To Insert to database: " . mysqli_errno($con), "error", "Error: ");
        }
    }


    ?>

    <script src="script.js"></script>
</body>

</html>