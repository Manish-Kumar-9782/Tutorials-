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



if __name__ == "__main__":
    header = ["id", 'title', 'author', 'subject', 'pages', 'price']
    bk_db = BookDatabase('books.csv', header)
    bk_db.createBook('python', "mansi", 'how to learn python', 235, 345)
    print("Totoal books: ", bk_db.books)
