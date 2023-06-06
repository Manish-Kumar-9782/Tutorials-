from CSV import CSVReader, CSVWriter

def displaySep(sep="=", length=10):
    string = sep*length
    print(string)

class Book:

    def __init__(self, book_id, title, author, subject, pages, price):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.subject = subject
        self.pages = pages
        self.price = price

    def __str__(self):
        return f"Book<{self.book_id}:{self.title}>"

    def __repr__(self):
        return f"Book<{self.book_id}:{self.title}>"

    def show_details(self):
        header = ["Book Id", "Title", "Author", "Subject", "Pages" "Prices"]
        displaySep("-",100)
        for key, value in zip(header, self.to_list()):
            print(f"{key:15s}{value}")
        displaySep("-", 100)

    def to_list(self):
        return [str(self.book_id), self.title, self.author, self.subject, str(self.pages), str(self.price)]

    def row_display(self,columns_offset=10):
        row_string = ""
        for row_item in self.to_list():
            row_string += row_item.ljust(len(row_item)+columns_offset)
        print(row_string)

    @staticmethod
    def fInline_display(sequence, column_len=20, str_len=18):
        row_string = ""

        # f"{variable:width.precision format_specifier}"
        # f"{var:{width}.{pre}s}" --> f"{row_item:{column_width}.{str_len}s}"

        str_len = str_len if isinstance(str_len,(list,tuple)) else [str_len]*6
        column_len = column_len if isinstance(column_len,(list,tuple)) else [column_len]*6

        for row_item, col_size, str_size in zip(sequence,column_len, str_len):
            row_string += f"{row_item:{col_size}.{str_size}s}"
        print(row_string)


    def inline_display(self, format=None):
        print("%-4s %-20s %-20s %-30s %-10s %-10s" % tuple(self.to_list()))

class BookDatabase:

    def __init__(self, file, delimiter=',', initial=False):
        self.__file = file
        self.header = ["id", 'title', 'author', 'subject', 'pages', 'price']
        self.books = []  # in this we will store all the books
        self.current_id = 1  # to maintain the id for each book.
        self.writer = CSVWriter(file, self.header, filemode="a")
        self.reader = CSVReader(file, self.header)
        self.column_sizes = [4,20,15,20,7,7]
        self.str_lengths = [i-2 for i in self.column_sizes]

        if initial:
            self.writer.write_header()


    def createBook(self, title, author, subject, pages, price):
        # now create a new book
        try:
            book = Book(self.current_id, title, author, subject, pages, price)
            self.books.append(book)
            self.current_id += 1  # increasing the id for next book
            # save the book into the file
            self.writer.write_row(book.to_list())
            return True
        except Exception:
            return False

    def readBooks(self):
        for row in self.reader.read():
            bk = Book(*row)
            self.books.append(bk)
        return self.books

    def displayBooks(self):
        displaySep("=",100)
        Book.fInline_display(self.reader.header, self.column_sizes, self.str_lengths)
        displaySep("=", 100)
        for book in self.books:
            Book.fInline_display(book.to_list(),self.column_sizes, self.str_lengths)
            displaySep("-",100)
        print(f"Total Entries: {len(self.books)}")
        displaySep("=",100)


    def findBook(self,book_id):
        # book_id : an integer number as id of book
        book = False
        for book in self.books:
            if book.book_id == str(book_id):
                return book
        return False

    def deleteBook(self,book_id):
        book = self.findBook(book_id)
        if book:
            self.books.remove(book)
            self.__saveDatabase()
            return book
        return False



    def __saveDatabase(self):
        self.writer = CSVWriter(self.__file, self.header, 'w')
        self.writer.write_rows(list(map(lambda x: x.to_list(), self.books)), self.header)


if __name__ == "__main__":
    header = ["id", 'title', 'author', 'subject', 'pages', 'price']
    database = BookDatabase('books.csv')
    database.readBooks()
    book_id = 4
    print("All books: ", database.books)
    print("Book: ", database.findBook(book_id))
    print("Books after deleting: ", database.deleteBook(book_id))