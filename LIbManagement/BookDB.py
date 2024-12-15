from Database import BaseDatabase
from CSV import CSVReader, CSVWriter
from bk import Book
from errors import BookFieldKeyError, EntryNotFound


class BookDatabase(BaseDatabase):

    id_key = "book_id"
    headers = [id_key] + ['title', 'author', 'subject', 'pages', 'price']

    def __init__(self, filename=None, delimiter=',', root=None, data_dir=None):
        # first set the headers
        super().__init__(filename if filename else "books_db.csv",
                         delimiter, root, data_dir)
        self.initDB()
        self._books = []

    def load(self):

        try:
            if self.reader is None or not isinstance(self.reader, CSVReader):
                self.reader = self.get_db_reader()

            for row in self.reader.readRow():
                book = Book(*row)
                self._books.append(book)
        except Exception as e:
            print(f"Error loading book database: {e}")

    def get(self, book_id):
        for book in self._books:
            if book.book_id == str(book_id):
                return book

    def update(self, book_id, **book_info):
        book = self.get(book_id)
        if book is None:
            raise EntryNotFound("Book not found")

        _book = vars(book)
        _book.update(**book_info)
        self.delete(book_id)
        self.add(Book(**_book))

    def getAll(self):
        return self._books

    def delete(self, book_id):

        for book in self._books:
            if book.book_id == str(book_id):
                self._books.remove(book)

    def add(self, book):
        if not isinstance(book, Book):
            raise ValueError("Invalid book object")

        self._books.append(book)

    def insert(self, **book_info):

        if set(book_info.keys()).issubset(set(self.headers)):

            if not book_info.get(self.id_key, False):
                book_info[self.id_key] = str(self.c_id)
                self.c_id += 1

            book = Book(**book_info)
            self._books.append(book)
        else:
            diff_keys = set(book_info.keys()).difference(self.headers)
            raise BookFieldKeyError(
                f"Invalid key's: {diff_keys}, use : {self.headers} book headers keys only as field of entry")


if __name__ == "__main__":
    db = BookDatabase()
    db.load()

    new_book = {'book_id': '3', 'title': '"Python Introduction"',
                'author': '"Manish"', 'subject': '"Python"', 'pages': '300', 'price': 525}

    db.insert(**new_book)
