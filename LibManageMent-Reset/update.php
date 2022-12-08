<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update</title>
</head>

<body>
    <!-- first we will  -->
    <?php

    include "../php-test/SQLUtility.php";

    $_SUBMIT = false; // a variable to show that we can submit the result for sql database.
    $pages = null;
    $price = null;


    if (isset($_POST["submit"])) {

        $pages = filter_var($_POST['pages'], FILTER_VALIDATE_INT);
        $price = filter_var($_POST['price'], FILTER_VALIDATE_FLOAT);

        if ($pages && $price) {
            $_SUBMIT = true;
        }
    }


    ?>
    <div class="main-container">

        <!-- add book form section. -->
        <form action="<?= $_SERVER['PHP_SELF'] ?>" method="POST" id="library">

            <table>

                <tr>
                    <td>
                        <label for="title">Enter Book Title</label>
                    </td>
                    <td>
                        <?php if (!$_SUBMIT && isset($_POST['submit'])) { ?>
                            <input type="text" id="title" name="title" value="<?= $_POST['title'] ?>" required>
                        <?php } else { ?>
                            <input type="text" id="title" name="title" required>
                        <?php } ?>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="author">Enter Book Author Name:</label>
                    </td>
                    <td>
                        <?php if (!$_SUBMIT && isset($_POST['submit'])) { ?>
                            <input type="text" id="author" name="author" value="<?= $_POST['author'] ?>" required>
                        <?php } else { ?>
                            <input type="text" id="author" name="author" required>
                        <?php } ?>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="subject">Enter Book Subject</label>
                    </td>
                    <td>
                        <?php if (!$_SUBMIT && isset($_POST['submit'])) { ?>
                            <input type="text" id="subject" name="subject" value="<?= $_POST['subject'] ?>" required>
                        <?php } else { ?>
                            <input type="text" id="subject" name="subject" required>
                        <?php } ?>
                    </td>
                </tr>

                <tr>
                    <td>
                        <!-- if $_SUBMIT is not true then we need to put data in that -->
                        <label for="pages">Enter Book Pages</label>
                    </td>
                    <td>
                        <?php if (isset($_POST['submit'])) { ?>
                            <input type="text" id="pages" class="<?= $pages ? 'valid' : 'invalid' ?>" name="pages" value="<?= $_POST['pages'] ?>" required>
                        <?php } else { ?>
                            <input type="text" id="pages" name="pages" required>
                        <?php } ?>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="prices">Enter Book Prices</label>

                    </td>
                    <td>
                        <?php if (isset($_POST['submit'])) { ?>
                            <input type="text" id="price" class="<?= $price ? 'valid' : 'invalid' ?>" name="price" value="<?= $_POST['price'] ?>" required>
                        <?php } else { ?>
                            <input type="text" id="price" name="price" required>
                        <?php } ?>

                    </td>
                </tr>
            </table>


            <input type="hidden" name="id" value="<?= $_GET['id'] ?>">
            <input type="submit" value="add book" name="submit">
        </form>
    </div>


    <?php

    if (isset($_POST['submit']) && $_SUBMIT) {

        // if form is submit then we need to get the id from the hidden input.
        $id = $_POST['id'];

        $Title = $_POST['title'];
        $Author = $_POST['author'];
        $Subject = $_POST['subject'];

        sql_update(
            $connection,
            $table_name,
            $id,
            ["Title", "Author", "Subject", "Pages", "Price"],
            [$Title, $Author, $Subject, $pages, $price],
            "sssid"
        );
    }


    ?>

</body>

</html>