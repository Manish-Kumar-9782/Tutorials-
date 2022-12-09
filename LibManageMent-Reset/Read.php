<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Read Data</title>
    <link rel="stylesheet" href="../Tutorials/style.css">
    <style>
        table,
        td,
        th {
            border: 1px solid;
            border-collapse: collapse;
            padding: 3px;
        }
    </style>
</head>

<body>

    <?php

    include "../php-Test/SQlUtility.php";

    // first of all we need connect the database and check the connection
    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "abhi_database";
    $table = "Books";

    $con = connect_db($host, $user, $password, $db_name, true);

    if ($con) {

        // now after making the successful connection we need to read the data.
        $result =  sql_read_database($con, $table);

        // we will test that result is good or bad.
    } else {
        $result = false;
    }
    ?>

    <!-- Now if we have result then only we will show the database. -->
    <?php if ($result) {
        $fields = mysqli_fetch_fields($result);
        array_pop($fields);
        array_pop($fields);
    ?>

        <table>
            <thead>

                <tr>
                    <?php foreach ($fields as $field) { ?>
                        <th><?= $field->name ?></th>
                    <?php } ?>
                </tr>

            </thead>

            <tbody>

                <?php while ($row = mysqli_fetch_row($result)) {

                    array_pop($row);
                    array_pop($row);
                    $book_id = $row[0];

                ?>

                    <tr>

                        <?php foreach ($row as $value) { ?>
                            <td><?= $value ?></td>
                        <?php } ?>

                        <td><button id="update_id-<?= $book_id ?>"><a href="update.php?id=<?= $book_id ?>">Update</a></button></td>
                        <td><button id="delete_id-<?= $book_id ?>"><a href="delete.php?id=<?= $book_id ?>">Delete</a></button></td>

                    </tr>
                <?php } ?>

            </tbody>
        </table>

    <?php } else { ?>

        <p>No data found...</p>

    <?php   } ?>



</body>

</html>