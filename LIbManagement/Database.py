from CSV import CSVReader, CSVWriter
from bk import Book
from errors import *
from enum import Enum


class DBStatus:
    INITIAL = 'INITIAL'
    LOADED = 'LOADED'
    UPDATED = 'UPDATED'
    ERROR = 'ERROR'


class BookDatabase:

    def __init__(self, filename, delimiter=',', root=None, data_dir=None):
        self.headers = ["id", 'title', 'author', 'subject', 'pages', 'price']
        self.filename = filename
        self.writer = CSVWriter(filename, self.headers, False,
                                delimiter, root, data_dir)
        self.reader = CSVReader(filename, True, delimiter, root, data_dir)
        self.books = []  # to hold the books in memory
        self.c_id = 0  # current id for each book

        # flag variables.
        self._CREATE_DB_DIRECTORY = False
        self._CREATE_DB_FILE = False
        self._DATABASE_INIT_STATUS = None

    def initDB(self):
        self._DATABASE_INIT_STATUS = DBStatus.INITIAL
        self.__setup_initial__()
        print("Book Database successfully initiated..")

    def _set_initial_id(self, _id=None):
        if _id is None:
            self.c_id = 1
        else:
            if isinstance(_id, int):
                self.c_id = _id + 1
                return
            raise ValueError("book id must be an integer")

    def _initialize_database(self):
        self.writer.set_headers(self.headers)
        self.writer.save()
        self._set_initial_id()

    def _handle_initialization_error(self, error):
        if isinstance(error, NotADirectoryError):
            print(f"Database Data Directory Not Found: {error}")
            self._CREATE_DB_DIRECTORY = True
            self._CREATE_DB_FILE = True
        elif isinstance(error, FileNotFoundError):
            print("Database File Not Found: ", error)
            self._CREATE_DB_FILE = True

    def _suggest_manual_creation(self):
        if self._CREATE_DB_DIRECTORY:
            print("Please create the database directory manually: ",
                  self.writer.data_dir)
        if self._CREATE_DB_FILE:
            print("Please create the file manually: ", self.filename)

    def _create_database(self):
        try:
            self.writer.create(
                self._CREATE_DB_DIRECTORY,
                self.filename if self._CREATE_DB_FILE else None
            )

        except (FileCreationError, DirectoryCreationError) as e:

            if isinstance(e, FileCreationError):
                print("Unable to create database file: ", e)
            else:
                print("Unable to create database directory: ", e)
            self._DATABASE_INIT_STATUS = DBStatus.ERROR

        except Exception as e:
            print("Unable to create database due to some unknown error: ", e)
            self._DATABASE_INIT_STATUS = DBStatus.INITIAL

    def __setup_initial__(self):

        try:
            self.writer.checkIntegrity(self.filename,
                                       create_dir=self._CREATE_DB_DIRECTORY,
                                       create_file=self._CREATE_DB_FILE)

            # try to initialize the database if integrity check is success
            self._initialize_database()

        except (NotADirectoryError, FileNotFoundError) as e:
            self._handle_initialization_error(e)
        except FileCreationError as e:
            print("Database Data File Creating Error")
        except DirectoryCreationError as e:
            print("Database Data Directory Creation Error..")

        except Exception as e:
            print(
                "There was a problem during check database integrity and initializing database. \nError:", e)

        finally:
            if self._CREATE_DB_DIRECTORY or self._CREATE_DB_FILE:
                self._create_database()

            if self._DATABASE_INIT_STATUS == DBStatus.ERROR:
                return self._suggest_manual_creation()

    # def addBook(self, title, author, subject, pages, price):

    #     try:
    #         bk = Book(self.c_id, title, author, subject, pages, price)
    #         self.books.append(bk)
    #         self.c_id += 1
    #     except Exception as e:
    #         print(f"Error: {e}")

    # def loadBooks(self):
    #     try:
    #         for row in self.reader.readRow():
    #             self.books.append(Book(*row))
    #     except Exception as e:
    #         print("Book Database load error: ", e)


if __name__ == "__main__":

    db = BookDatabase('test_bk.csv', data_dir="mydb")
    db.initDB()
