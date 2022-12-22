

<?php 

    require "../../../php-Test/SQLUtility.php";

    $host = "localhost";
    $user = "root";
    $password = "";
    $db_name = "abhi_database";
    $table = "Books";

    $con = connect_db($host, $user, $password, $db_name, true);


    /**
     * Escaping a string means to reduce ambiguity in quotes (and other characters) used in that string. 
     * For instance, when you're defining a string, you typically surround it in either double quotes or 
     * single quotes:

     *   "Hello, World."
     *   
     *   But what if the string had double quotes within it?
     *   
     *   "Hello "World.""
     *   
     *   Now we have ambiguity - the software doesn't know where my string ends. one solution is to use single quotes 
     *  around the string:
     *   
     *   'Hello "World."'
     *   
     *   Or I can escape my quotes:
     *   
     *   "Hello \"World.\""
     *   
     *   Any quote that is preceded by a slash is escaped and understood to be part of the value of the string.
     *   
     *   Character combinations consisting of a backslash (\) followed by a letter or by a combination of 
     *      digits are called "escape sequences." To represent a newline character, single quotation mark, 
     *      or certain other characters in a character constant, you must use escape sequences. An escape 
     *      sequence is regarded as a single character and is therefore valid as a character constant.
    */

    $string = "Hello world's";    
    // Now here we have a single quote extra in this section so if we pass this to mysqli_real_escape_string
    // then this will convert this single quote into the escape sequence character.
    $str = mysqli_real_escape_string($con, $string);
    display("pre", $str, "data", "String: ");

    $id = 5;
    $stmt = mysqli_prepare($con, "SELECT * FROM $table WHERE id=?");
    $stmt->bind_param("i", $id);
    $stmt->execute();

    // Now get the stmt result
    $result = mysqli_stmt_get_result($stmt);

    // Now this will give you the mysqli_result object
    $row = mysqli_fetch_assoc($result);

    show_array($row);


?>