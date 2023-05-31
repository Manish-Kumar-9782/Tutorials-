from CSV import CSVReader, CSVWriter


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

    def show_details(self):
        print(f"""id: {self.book_id} \
        title: {self.title}\
        author: {self.author}\
        subject : {self.subject} \
        pages: {self.pages}\
        price: {self.price}
""")

    def to_list(self):
        return [str(self.book_id), self.title, self.author, self.subject, str(self.pages), str(self.price)]

    def row_display(self,columns_offset=10):
        row_string = ""
        for row_item in self.to_list():
            row_string += row_item.ljust(len(row_item)+columns_offset)
        print(row_string)

    def inline_display(self, format=None):
        print("%-4s %-20s %-20s %-30s %-10s %-10s" % tuple(self.to_list()))

class BookDatabase:

    def __init__(self, file, header, delimiter=',', initial=False):
        self.__file = file
        self.books = []  # in this we will store all the books
        self.current_id = 1  # to maintain the id for each book.
        self.writer = CSVWriter(file, header, filemode="a")
        self.reader = CSVReader(file, header)

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



if __name__ == "__main__":
    header = ["id", 'title', 'author', 'subject', 'pages', 'price']
    bk_db = BookDatabase('books.csv', header)
    books =  bk_db.readBooks()
    for book in books:
        book.inline_display()