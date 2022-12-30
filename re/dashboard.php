<?php
// here before loading the page first we need to verify the user authentication
require "SQLUtility.php";

// now validating user, if user is validated then we will set some variable
// to store user record 
if (validate_user()) {
    $user_FirstName = $_SESSION["user-FirstName"];
    $user_LastName = $_SESSION["user-LastName"];
    $user_IsSuper = $_SESSION["user-IsSuper"];
    $user_IsActive = $_SESSION["user-IsActive"];
    $user_Type = $_SESSION["user-Type"];
    $user_Permission = $_SESSION["user-Permissions"];
    $user_name = join(" ", [$user_FirstName, $user_LastName]);
} else {
    header("Location: login.php");
    die();
}
?>

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
    <div class="">
        <!-- aside bar -->
        <!-- ================================================================================ -->
        <div class="navigation">
            <ul>
                <li>
                    <a href="#">
                        <span class="icon">
                            <ion-icon name="library-outline"></ion-icon>
                        </span>
                        <span class="title">Lib Management</span>
                    </a>
                </li>
                <li>
                    <a href="#">
                        <span class="icon">
                            <ion-icon name="home-outline"></ion-icon>
                        </span>
                        <span class="title">Dashboard</span>
                    </a>
                </li>
                <li>
                    <a href="#">
                        <span class="icon">
                            <ion-icon name="book-outline"></ion-icon>
                        </span>
                        <span class="title">Issue Book</span>
                    </a>
                </li>
                <li>
                    <a href="#">
                        <span class="icon">
                            <ion-icon name="bookmarks-outline"></ion-icon>
                            </ion-icon>
                        </span>
                        <span class="title">Book List</span>
                    </a>
                </li>
                <li>
                    <a href="#">
                        <span class="icon">
                            <ion-icon name="help-circle-outline"></ion-icon>
                        </span>
                        <span class="title">Help</span>
                    </a>
                </li>
                <li>
                    <a href="#">
                        <span class="icon">
                            <ion-icon name="information-circle-outline"></ion-icon>
                        </span>
                        <span class="title">About</span>
                    </a>
                </li>
                <li>
                    <a href="signout.php">
                        <span class="icon">
                            <ion-icon name="log-in-outline"></ion-icon>
                        </span>
                        <span class="title">Sign Out</span>
                    </a>
                </li>
            </ul>
        </div>
        <!-- main ================================================================================ -->
        <div class="main">
            <!-- topbar ============================================================================== -->
            <div class="topbar">
                <!-- menu =========== -->
                <div class="toggle">
                    <ion-icon name="menu-outline"></ion-icon>
                </div>
                <!-- search =========== -->
                <div class="search">
                    <label>
                        <input type="text" placeholder="Search here">
                        <ion-icon name="search-outline"></ion-icon>
                    </label>
                </div>
                <!-- user =========== -->
                <div class="user">
                    <i class="bi bi-person-circle" style="font-size: 2rem;"> <?= $user_name ?></i>

                </div>
            </div>
            <!-- show information ==================================================================== -->
            <div class="topbar">
                <!-- menu =========== -->
                <div class="heading">
                    <h3>Users</h2>
                </div>
                <!-- search =========== -->
                <div class="filter">
                    <button class="btn btn-dark">Filter <ion-icon name="funnel-outline"></ion-icon></button>
                </div>
                <!-- user =========== -->
                <div class="create">
                    <button class="btn btn-dark"><a class="text-light p-2" href="create.php">Create</a></button>
                </div>
            </div>

            <div class="tecaher_table">
                <?php


                $host = "localhost";
                $user = "root";
                $password = "";
                $db_name = "libmanagement";
                $table = "users";

                $con = connect_db($host, $user, $password, $db_name);


                if ($con) {

                    // now after making the successful connection we need to read the data.
                    $result = read_database(
                        $con,
                        $table,
                        ["id", "FirstName", "SecondName", "LastName", "Gmail", "Permissions", "Type"],
                        "Type='admin'"
                    );

                    // we will test that result is good or bad.
                } else {
                    $result = false;
                }

                ?>

                <!-- Now if we have result then only we will show the database. -->
                <?php if ($result) {
                    $fields = mysqli_fetch_fields($result);

                ?>

                    <!--  Table only for Admin-Users -->
                    <!-- =============================================================================== -->
                    <table class="table table-hover table-striped table-primary table-borderless">
                        <thead>

                            <tr>
                                <?php foreach ($fields as $field) { ?>
                                    <th scope="col" class="pb-4 bg-secondary text-light"><?= $field->name ?></th>
                                <?php } ?>
                                <th class="pb-4 bg-secondary text-light"></th>
                                <th class="pb-4 bg-secondary text-light"></th>
                            </tr>

                        </thead>

                        <tbody>

                            <?php while ($row = mysqli_fetch_row($result)) {
                                $book_id = $row[0]
                            ?>

                                <tr>

                                    <?php foreach ($row as $value) { ?>
                                        <td><?= $value ?></td>
                                    <?php } ?>

                                    <td><button type="button" class="btn btn-primary" id="update_id-<?= $book_id ?>">
                                            <a class="text-light text-decoration-none" href="update.php?id=<?= $book_id ?>">Update</a></button></td>

                                    <td><button type="button" class="btn btn-danger" id="delete_id-<?= $book_id ?>">
                                            <a class="text-light text-decoration-none" href="delete.php?id=<?= $book_id ?>">Delete</a></button></td>

                                </tr>
                            <?php } ?>

                        </tbody>
                    </table>

                    <!-- Table only for Student-User -->
                    <!-- =============================================================================== -->
                    <?php
                    if ($con) {

                        // now after making the successful connection we need to read the data.
                        $result = read_database(
                            $con,
                            $table,
                            ["id", "FirstName", "SecondName", "LastName", "Gmail", "Permissions", "Type"],
                            "Type='student'"
                        );

                        // we will test that result is good or bad.
                    } else {
                        $result = false;
                    }
                    ?>
                    <h3 class="mt-5">Students</h3>
                    <table class="table table-hover table-striped table-primary table-borderless">
                        <thead>

                            <tr>
                                <?php foreach ($fields as $field) { ?>
                                    <th scope="col" class="pb-4 bg-secondary text-light"><?= $field->name ?></th>
                                <?php } ?>
                                <th class="pb-4 bg-secondary text-light"></th>
                                <th class="pb-4 bg-secondary text-light"></th>
                            </tr>

                        </thead>

                        <tbody>

                            <?php while ($row = mysqli_fetch_row($result)) {
                                $book_id = $row[0]
                            ?>

                                <tr>

                                    <?php foreach ($row as $value) { ?>
                                        <td><?= $value ?></td>
                                    <?php } ?>

                                    <td><button type="button" class="btn btn-primary" id="update_id-<?= $book_id ?>">
                                            <a class="text-light text-decoration-none" href="update.php?id=<?= $book_id ?>">Update</a></button></td>

                                    <td><button type="button" class="btn btn-danger" id="delete_id-<?= $book_id ?>">
                                            <a class="text-light text-decoration-none" href="delete.php?id=<?= $book_id ?>">Delete</a></button></td>

                                </tr>
                            <?php } ?>

                        </tbody>
                    </table>


                    <!-- Table only for Teacher-User -->
                    <!-- =============================================================================== -->

                    <?php

                    if ($con) {

                        // now after making the successful connection we need to read the data.
                        $result = read_database(
                            $con,
                            $table,
                            ["id", "FirstName", "SecondName", "LastName", "Gmail", "Permissions", "Type"],
                            "Type='teacher'"
                        );

                        // we will test that result is good or bad.
                    } else {
                        $result = false;
                    }
                    ?>
                    <h3 class="mt-5">Teachers</h3>
                    <table class="table table-hover table-striped table-primary table-borderless">
                        <thead>

                            <tr>
                                <?php foreach ($fields as $field) { ?>
                                    <th scope="col" class="pb-4 bg-secondary text-light"><?= $field->name ?></th>
                                <?php } ?>
                                <th class="pb-4 bg-secondary text-light"></th>
                                <th class="pb-4 bg-secondary text-light"></th>
                            </tr>

                        </thead>

                        <tbody>

                            <?php while ($row = mysqli_fetch_row($result)) {
                                $book_id = $row[0]
                            ?>

                                <tr>

                                    <?php foreach ($row as $value) { ?>
                                        <td><?= $value ?></td>
                                    <?php } ?>

                                    <td><button type="button" class="btn btn-primary" id="update_id-<?= $book_id ?>">
                                            <a class="text-light text-decoration-none" href="update.php?id=<?= $book_id ?>">Update</a></button></td>

                                    <td><button type="button" class="btn btn-danger" id="delete_id-<?= $book_id ?>">
                                            <a class="text-light text-decoration-none" href="delete.php?id=<?= $book_id ?>">Delete</a></button></td>

                                </tr>
                            <?php } ?>

                        </tbody>
                    </table>


                <?php } else { ?>

                    <p>No data found...</p>

                <?php } ?>
            </div>
        </div>
    </div>




    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
    <script src="script.js"></script>
</body>

</html>