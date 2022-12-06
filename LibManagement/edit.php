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
    $update_id = $_GET["uid"];
    // echo "updating the content of row number " . $update_id . " data"

    // Now we need to read the csv file and get the data from that.
    $file = fopen("data.csv", "r");
    $count = 0;
    $row_data = null;
    while ($count <= $update_id) {
        $row_data = fgets($file);
        $count++;
    }

    $row_data = str_getcsv($row_data, ',');

    $title = $row_data[0];
    $author = $row_data[1];
    $subject = $row_data[2];
    $pages = $row_data[3];
    $price = $row_data[4];


    ?>

    <?php
    include "../php-Test/Utility.php";
    show_array($_GET);
    echo "<br>";
    ?>

    <div>
        <form action="update.php" method="POST" id="library">


            <label for="title">Enter Book Title</label>
            <input type="text" id="title" name="title" value="<?= $title ?>"><br>

            <label for="author">Enter Book Author Name:</label>
            <input type="text" id="author" name="author" value="<?= $author ?>"><br>

            <label for="subject">Enter Book Subject</label>
            <input type="text" id="subject" name="subject" value="<?= $subject ?>"><br>

            <label for="pages">Enter Book Pages</label>
            <input type="text" id="pages" name="pages" value="<?= $pages ?>"><br>

            <label for="prices">Enter Book Prices</label>
            <input type="text" id="price" name="prices" value="<?= $price ?>"><br>

            <input type="hidden" name="uid" id="uid" value="<?= $_GET['uid'] ?>">
            <input type="submit" value="update">
        </form>
    </div>

</body>

</html>