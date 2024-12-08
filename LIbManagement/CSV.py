import os
from config import *


class Utility:
    """
    Utility class for managing data directory and file operations in a CSV-based application.

    This class provides methods for creating and checking the existence of data directories
    and files, ensuring that the necessary resources are available for the application to function
    correctly. It also handles error management related to file and directory operations.

    Methods:
        __createDataDir__():
            Checks if the data directory exists and attempts to create it if it does not.
            Returns True if the directory exists or was successfully created, otherwise False.

        __createFile__(file):
            Checks if a specified file exists and attempts to create it if it does not.
            Returns True if the file exists or was successfully created, otherwise False.

        __checkDataDir__(create=False):
            Verifies the existence and accessibility of the specified data directory.
            Optionally creates the directory if it does not exist, returning True if successful.

        __check_file(file, create=True):
            Checks if a specified file exists and optionally creates it if it does not.
            Returns True if the file exists or was successfully created, otherwise False.

        checkIntegrity(file, create_dir=False, create_file=False):
            Verifies the existence and accessibility of a specified directory and file.
            Optionally creates the directory and/or file if they do not exist, returning True
            if both checks are successful.
    """

    def __init__(self, root=None, data=None):
        self.error = None

        if root:
            self.root = root
        else:
            self.root = ROOT

        if data:
            self.data = data
        else:
            self.data = DATA_PATH

    def __createDataDir__(self):
        """
        Checks if the data directory exists.

        Args:
            create (bool): If True, attempts to create the data directory if it does not exist.

        Returns:
            bool: True if the data directory exists (or was successfully created), False otherwise.

        Raises:
            NotADirectoryError: If the root directory does not exist.
        """
        try:
            os.mkdir(self.data)
            return True
        except OSError as e:
            print(f"Error creating data directory {self.data}: {e}")
            return False

    # ====================================

    def __createFile__(self, file):
        """
        Checks if a file exists.

        Args:
            file (str): The path to the file to check.
            create (bool): If True, attempts to create the file if it does not exist.

        Returns:
            bool: True if the file exists (or was successfully created), False otherwise.
        """
        try:
            with open(file, 'w') as f:
                pass
            return True
        except OSError as e:
            print(f"Error creating file {file} : {e}")
            return False

    # ====================================

    def __checkDataDir__(self, create=False):
        """
        Verifies the existence and accessibility of a specified directory and file.

        Args:
            file (str): The path to the file to check.
            create_dir (bool): If True, attempts to create the data directory if it does not exist.
            create_file (bool): If True, attempts to create the file if it does not exist.

        Returns:
            bool: True if both the data directory and file checks are successful, False otherwise.
        """
        if os.path.isdir(self.root):
            if os.path.isdir(self.data):
                # print("data dir is found")
                return True
            else:
                return self.__createDataDir__() if create else False
        else:
            # print("root dir is not found.")
            raise NotADirectoryError(DATA_PATH + " is not found..!")

    # ====================================

    def __check_file(self, file, create=True):
        """
        Checks if a specified file exists and optionally creates it if it does not.

        Args:
            file (str): The path to the file to check.
            create (bool): If True, attempts to create the file if it does not exist. Default is True.

        Returns:
            bool: True if the file exists or was successfully created, False otherwise.

        Raises:
            OSError: If there is an error creating the file.

        Notes:
            This method is intended for internal use only (indicated by the leading underscore).
        """

        if os.path.isfile(file):
            return True
        else:
            return self.__createFile__() if create else False

    # ====================================

    def checkIntegrity(self, file, create_dir=False, create_file=False):
        """
        Verifies the existence and accessibility of a specified directory and file.

        Args:
            file (str): The path to the file to check.
            create_dir (bool): If True, attempts to create the data directory if it does not exist. Default is False.
            create_file (bool): If True, attempts to create the file if it does not exist. Default is False.

        Returns:
            bool: True if both the data directory and file checks are successful, False otherwise.

        Notes:
            This method combines checks for both the data directory and the specified file.
        """
        if self.__checkDataDir__(create_dir) and self.__check_file(file,  create_file):
            return True
        else:
            print("Integrity check failed: Directory or file not found..")
            return False

# =============================================================


class CSVReader(Utility):

    def __init__(self, file, header=True, delimiter=','):
        super().__init__()
        self.header = header
        self.delimiter = delimiter
        if self.checkIntegrity(file):
            self.file_path = file   # it contains path for file
        else:
            raise Exception("file Integrity Error: file or root dir not found")

        self.file = None  # to contain the a File object.

    def __openFile__(self):

        if not self.file or self.file.closed:

            try:
                self.file = open(self.file_path, "r")
            except OSError as e:
                print(f"Error opening file: {e}")
                # self.__closeFile__()
            except Exception as e:
                print(f"Unknown error encounter while opening file: {e}")

    def __closeFile__(self):
        try:
            if self.file and not self.file.closed:
                self.file.close()
                self.file = None

        except OSError as e:
            print(f"Error closing file: {e}")
        except Exception as e:
            print(f"Unknown error encounter while closing file: {e}")

    def read_headers(self):
        self.__openFile__()
        if self.file:
            try:
                header = self.file.readline().strip().split(self.delimiter)
                if header:
                    self.header = header
            except OSError as e:
                print(f"Error reading header: {e}")
            except Exception as e:
                print(f"Unknown error encounter while reading header: {e}")
            finally:
                self.__closeFile__()

    def readRow(self):
        self.__openFile__()
        if self.file:
            try:
                self.file.readline()  # skipping first line as it is header
                while True:
                    line = self.file.readline()
                    if not line:
                        break
                    yield line.strip().split(self.delimiter)

            except OSError as e:
                print(f"Error reading line: {e}")
            finally:
                self.__closeFile__()


# =============================================================


class CSVWriterX(Utility):

    def __init__(self, file, header: list = None, filemode="w", delimiter=','):
        super().__init__()
        self.filemode = filemode
        self.header = self.__parse_row(header)
        self.delimiter = delimiter

        if self.checkIntegrity(file, True):
            self.file = file
        else:
            wfile = open(file, 'w')
            self.__write_row(wfile, header)
            wfile.close()
            self.file = file

    def __parse_row(self, row: list or tuple):
        if not isinstance(row, (list, tuple)):
            raise TypeError("row must be an instance of list or tuple")
        return row

    def __write_row(self, file, row):
        row = self.__parse_row(row)
        # first convert our seq into the string
        line = self.delimiter.join(row) + "\n"
        file.write(line)

    def write_row(self, row, header=None):
        file = open(self.file, self.filemode)
        if header:
            self.__write_row(header)
        self.__write_row(file, row)
        file.close()

    def write_rows(self, rows, header=None):
        file = open(self.file, self.filemode)

        if header:
            self.__write_row(file, header)

        for row in rows:
            self.__write_row(file, row)
        file.close()

    def write_header(self):
        self.write_row(self.header)


class CSVWriter(Utility):

    def __init__(self, filename, header=None, delimiter=','):
        super().__init__()
        self.filename = filename
        self.rows = []
        if header:
            self.header = self.set_header(header)

    def set_header(self, header):
        if not isinstance(header, (list, tuple, set)):
            raise TypeError("header must be an instance of list, tuple or set")
        self.header = header


if __name__ == "__main__":
    # print("current file location: ", os.getcwd())
    reader = CSVReader('books.csv')
    print("header: ", reader.header)
    print("data: ", reader.read())
