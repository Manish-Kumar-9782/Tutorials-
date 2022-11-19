<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LibManagement: Update Entry</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="../Tutorials/style.css">
</head>

<body>

    <?php
    include "../php-Test/Utility.php";
    show_array($_GET);
    echo "<br>";
    ?>

    <form action="update.php" method="POST" id="library">


        <label for="title">Enter Book Title</label>
        <input type="text" id="title" name="title"><br>

        <label for="author">Enter Book Author Name:</label>
        <input type="text" id="author" name="author"><br>

        <label for="subject">Enter Book Subject</label>
        <input type="text" id="subject" name="subject"><br>

        <label for="pages">Enter Book Pages</label>
        <input type="text" id="pages" name="pages"><br>

        <label for="prices">Enter Book Prices</label>
        <input type="text" id="price" name="prices"><br>

        <input type="hidden" name="uid" id="uid" value="<?= $_GET['uid'] ?>">
        <input type="submit" value="update">
    </form>

</body>

</html>