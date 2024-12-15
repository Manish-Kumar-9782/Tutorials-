from Database import BaseDatabase
from CSV import CSVReader, CSVWriter
from bk import Book


class BookDatabase(BaseDatabase):
    headers = ["id", 'title', 'author', 'subject', 'pages', 'price']

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

    def getAll(self):
        return self._books

    def add(self):


if __name__ == "__main__":
    db = BookDatabase()
    db.load()
    print(db.getAll())
