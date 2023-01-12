<?php
// in this section we will sign-out from the dashboard
echo "Logging Out...";
// first we will retrieve the session and then we will delete all session data and destroy the session.

// getting the session
session_start();

// deleting all session fields
session_unset();

// destroying the session
session_destroy();

if (isset($_COOKIE['user'])) {
    assert(setcookie("user", "", time() - 60), '/re');
    unset($_COOKIE['user']);
}



// Now we will redirect to the login page

// print_r($_SESSION);
header("Location: login.php");
die();
