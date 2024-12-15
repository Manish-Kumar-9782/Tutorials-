from CSV import CSVReader, CSVWriter
from bk import Book
from errors import *
from enum import Enum


class DBStatus(Enum):
    INITIAL = 'INITIAL'
    INITIALIZED = "INITIALIZED"
    LOADED = 'LOADED'
    UPDATED = 'UPDATED'
    ERROR = 'ERROR'


class BaseDatabase:

    def __init__(self, filename, delimiter=',', root=None, data_dir=None):
        self.filename = filename
        self.delimiter = delimiter
        self.root = root
        self.data_dir = data_dir
        self.writer = None
        self.reader = None

        self.books = []  # to hold the books in memory
        self.c_id = 0  # current id for each book

        # flag variables.
        self._CREATE_DB_DIRECTORY = False
        self._CREATE_DB_FILE = False
        self._DATABASE_INIT_STATUS = None

    def get_db_writer(self):
        return self._init_writer(self.filename, self.headers, False,
                                 self.delimiter, self.root, self.data_dir)

    def get_db_reader(self):
        return self._init_reader(self.filename, self.headers, self.delimiter, self.root, self.data_dir)

    def initDB(self):
        self._DATABASE_INIT_STATUS = DBStatus.INITIAL
        try:
            self.__setup_initial__()

        except Exception as e:
            error_name = e.__class__.__name__
            print(
                f"Unable to initialize the database setup. \nError {error_name}: {e}")

    def _init_reader(self, filename, headers, delimiter, root, data_dir):
        try:
            # Attempt to create a CSVReader instance
            self.reader = CSVReader(
                filename, headers, False, delimiter, root, data_dir, True)
            print(
                f"Database reader initialized successfully for database file: {self.filename}")
            return self.reader  # Return the created CSVReader instance

        except FileNotFoundError as e:
            raise FileOpenError(
                f"CSV file not found: {self.filename}. Error: {e}")
        except IsADirectoryError as e:
            raise FileOpenError(
                f"Expected a file but found a directory: {self.filename}. Error: {e}")
        except DbIOError as e:
            raise DbIOError(
                f"Database I/O error while initializing CSVReader: {e}")
        except Exception as e:
            raise DbIOError(
                f"An unexpected error occurred while initializing CSVReader: {e}")

    def _init_writer(self, filename, headers=False, first_row_header=False, delimiter=',', root=None, data_dir=None):
        try:
            # Attempt to create a CSVWriter instance
            self.writer = CSVWriter(
                filename, headers, first_row_header, delimiter, root, data_dir)
            print(
                f"Database writer initialized successfully for database file: {self.filename}")
            return self.writer  # Return the created CSVWriter instance

        except FileNotFoundError as e:
            raise FileOpenError(
                f"CSV file not found: {self.filename}. Error: {e}")
        except IsADirectoryError as e:
            raise FileOpenError(
                f"Expected a file but found a directory: {self.filename}. Error: {e}")
        except DbIOError as e:
            raise DbIOError(
                f"Database I/O error while initializing CSVWriter: {e}")
        except Exception as e:
            raise DbIOError(
                f"An unexpected error occurred while initializing CSVWriter: {e}")

    def _set_initial_id(self, _id=None):
        if _id is None:
            self.c_id = 1
        else:
            if isinstance(_id, int):
                self.c_id = _id + 1
                return
            raise ValueError("book id must be an integer")

    def _initialize_database(self):

        try:
            self.writer.set_headers(self.headers)
            self.writer.save()
            self._set_initial_id()
            print("Book Database successfully initiated..")
        except FileOpenError as e:
            print(f"Failed to open database file: {e}")
            self._DATABASE_INIT_STATUS = DBStatus.ERROR
        except DbIOError as e:
            print(f"Database I/O error: {e}")
            self._DATABASE_INIT_STATUS = DBStatus.ERROR
        except Exception as e:
            print(
                f"An unexpected error occurred during database initialization: {e}")
            self._DATABASE_INIT_STATUS = DBStatus.ERROR

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
            if self._CREATE_DB_DIRECTORY and self._CREATE_DB_DIRECTORY:
                print("Trying to create database dir and file...")
            elif self._CREATE_DB_FILE:
                print("Trying to create database file...")

            result = self.writer.create(
                self._CREATE_DB_DIRECTORY,
                self.filename if self._CREATE_DB_FILE else None
            )
        except Exception as e:
            print("Unable to create database due to some unknown error: ", e)
            self._DATABASE_INIT_STATUS = DBStatus.ERROR
            return

        for key, detail in result.items():
            print(f"{key}::{detail['status']} : {detail['message']}")

            if key == "file" and detail['status'] == "success":
                self._DATABASE_INIT_STATUS = DBStatus.INITIALIZED

    def __setup_initial__(self):

        try:
            if not self.writer or not isinstance(self.writer, CSVWriter):
                self.writer = self.get_db_writer()

            self.writer.check_integrity(self.filename,
                                        create_dir=self._CREATE_DB_DIRECTORY,
                                        create_file=self._CREATE_DB_FILE)

        except (NotADirectoryError, FileNotFoundError) as e:
            self._handle_initialization_error(e)
        except FileCreationError as e:
            print("Database Data File Creating Error")
        except DirectoryCreationError as e:
            print("Database Data Directory Creation Error..")

        except DbIOError as e:
            print(f"Database Operation Error: \n{e}")
            self._CREATE_DB_DIRECTORY = False
            self._CREATE_DB_FILE = False
            self._DATABASE_INIT_STATUS = DBStatus.ERROR

        except Exception as e:
            print(
                "There was a problem during check database integrity and initializing database. \nError:", e)

        finally:
            if self._CREATE_DB_DIRECTORY or self._CREATE_DB_FILE:
                print("Trying to creating a new database record....")
                self._create_database()

             # try to initialize the database if integrity check is success
            if self._DATABASE_INIT_STATUS == DBStatus.INITIALIZED:
                self._initialize_database()

            elif self._DATABASE_INIT_STATUS == DBStatus.ERROR:
                return self._suggest_manual_creation()


if __name__ == "__main__":

    db = BaseDatabase('test_bk.csv', data_dir="mydb")
    db.initDB()
