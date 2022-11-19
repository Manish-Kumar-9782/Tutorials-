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
        <form action="action.php" method="POST" id="library">


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

            <input type="submit" value="add book">
        </form>
        <!-- showDatabase form -->

        <div id="showdatabase">

            <table>

                <thead id="showdatabase-thead">
                    <!-- here we need to put the our columns -->
                    <!-- here first we need to read the header data from the
                    'data.csv' file. 
                
                    file opeartion mode: 

                    r: read the file
                    w: write/overwrite/create a file.
                    a: write file at the end of the file.
                
                -->

                    <?php
                    // first we need to get the data from the file.
                    // we need only the header data.
                    $file_row_number = -1;
                    // opeing the data.csv file to read
                    $file = fopen('data.csv', "r");

                    // getting the first line as the header
                    $header = fgets($file);

                    // if file is not empty and we get the header then we will increase the number of 
                    // read lines.
                    if ($header) {
                        $file_row_number++; // line 0
                    }
                    $header_array = str_getcsv($header); // str_getcsv will return the array of value
                    //  Now array header contains all the column heading values separately.

                    ?>
                    <!-- php tag closed. -->

                    <!-- putting all the header_array value to the first row of thead as the 
                    column of table.-->
                    <tr>
                        <th><?= $header_array[0] ?></th>
                        <th><?= $header_array[1] ?></th>
                        <th><?= $header_array[2] ?></th>
                        <th><?= $header_array[3] ?></th>
                        <th><?= $header_array[4] ?></th>
                    </tr>

                </thead>
                <!-- thead data compleleted -->

                <tbody id="showdatabase-tbody">
                    <!-- here we need to put the book details  -->
                    <?php while (!feof($file)) : ?>

                        <!-- Now we will read the file until the file does not read
                        at the end of the file. -->


                        <?php
                        // Now reading each line per iteration
                        $data_str = fgets($file);

                        if ($data_str) {
                            // increasing the row number
                            $file_row_number++; // line 1
                            //  getting each column value from the string line
                            $data = str_getcsv($data_str);
                        } else {
                            // 
                            $data = null;
                        }

                        ?>
                        <?php if ($data != null) { ?>

                            <tr>
                                <td><?= $data[0] ?></td>
                                <td><?= $data[1] ?></td>
                                <td><?= $data[2] ?></td>
                                <td><?= $data[3] ?></td>
                                <td><?= $data[4] ?></td>
                                <td>
                                    <button type="submit" name="edit"><a href="<?= "edit.php" . "?edit=true&&uid=$file_row_number" ?>">edit</a></button>
                                </td>
                                <td>
                                    <button type="submit" name="delete"><a href="<?= "delete.php" . "?del=$file_row_number" ?>">delete</a></button>
                                </td>

                            </tr>

                        <?php } ?>

                    <?php endwhile; ?>
                </tbody>

            </table>

        </div>

        <!-- ========================================================== -->

        <div class="buttons">
            <button id="addBook">AddBook</button>
            <button id="showBook">ShowDatabase</button>
            <button id="updateBook">UpdateBook</button>
            <button id="deleteBook">DeleteBook</button>
        </div>
    </div>

    <script src="script.js"></script>
</body>

</html>