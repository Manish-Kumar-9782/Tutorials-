```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library Management System</title>



    <style>
        input {
            margin: 10px 5px;
        }

        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 550px;
        }

        .container {
            border: 1px solid dodgerblue;
            padding: 20px;
        }

        #buttons {
            padding: 10px;
            margin: 10px;
            text-align: center;
            border: 5px groove rgb(101, 101, 147);
        }

        #buttons button {
            margin-left: 10px;
        }

        #showdatabase {
            display: none;
        }

        #showdatabase table {
            border: 1px solid dodgerblue;
            border-collapse: collapse;
        }

        th,
        td {
            border: 1px solid dodgerblue;
            padding: 10px;
        }

        thead th {
            background-color: dodgerblue;
            color: whitesmoke;
        }
    </style>

</head>

<body>

    <div class="container">

        <h1>Library Management System</h1>

        <form action="#" name="LibManagement" id="LibManagement">

            <label for="title"> Book Title</label>
            <input type="text" , id="title" name="title" placeholder="Enter Book Title" value=""><br>


            <label for="author"> Book Author</label>
            <input type="text" , id="author" name="author" placeholder="Enter Book Author"><br>

            <label for="subject"> Book Subject</label>
            <input type="text" , id="subject" name="subject" placeholder="Enter Book Subject"><br>

            <label for="pages"> Book Pages</label>
            <input type="text" , id="pages" name="pages" placeholder="Enter Book Pages"><br>

            <label for="price"> Book Price</label>
            <input type="text" , id="price" name="price" placeholder="Enter Book Price"><br>

            <input id="cbook" type="button" onclick="add_book()" value="add">
            <input id="ebook" type="button" style="display:none;" value="save">
            <!-- cbook: create book, ebook: edit book -->

        </form>

        <div id="showdatabase">

            <table>

                <thead id="showdatabase-thead">
                    <!-- Here we will put our heading row -->
                </thead>

                <tbody id="showdatabase-tbody">
                    <!-- Here we will put the book database details rows. -->
                </tbody>

            </table>


        </div>



        <div id="buttons">

            <button id="addbook">AddBook</button>
            <button id="showbooks">ShowBooks</button>
            <button id="updatebook">UpdateBook</button>
            <button id="deletebook">DeleteBook</button>

        </div>

    </div>


    <script src="LibManagement.js"></script>
</body>

</html>
```