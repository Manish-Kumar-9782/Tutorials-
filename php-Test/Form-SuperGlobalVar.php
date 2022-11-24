<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form and SuperGlobal variables</title>
</head>

<body>

    <!-- 
        $_GET: which is used with the get method of request.
        $_POST: which is used with the post method of request.
        $_REQUEST: which is used with both post and get method.


        Validation of input : 

            filter_var()
     -->

    <form action="actionTest.php" method="post">

        <!-- String Name -->
        <label for="name">Name: </label>
        <input type="text" id="name" name="name"><br><br>

        <!-- integer -->
        <label for="age">Age: </label>
        <input type="text" id="age" name="age"><br><br>

        <!-- float -->
        <label for="height">Height: </label>
        <input type="text" id="height" name="height"><br><br>

        <!-- Email -->
        <label for="mail">Email: </label>
        <input type="email" id="mail" name="mail"><br><br>

        <!-- bool -->
        <label for="adult">Adult: </label>
        <input type="checkbox" id="adult" name="adult"><br><br>

        <!-- 
            for checkbox or boolean values.    
        
        true: true, 1, on, yes
        false: false, 0, off, no
    
    -->
        <input type="submit">
    </form>

</body>

</html>