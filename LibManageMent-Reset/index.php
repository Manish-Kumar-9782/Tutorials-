<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library Management</title>
    <link rel="stylesheet" href="style.css">
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
        <form action="addbook.php" method="POST" id="library">


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

            <input type="submit" value="add book">
        </form>
    </div>

    <script src="script.js"></script>
</body>

</html>