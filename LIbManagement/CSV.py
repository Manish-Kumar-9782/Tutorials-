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

    def __init__(self, file, header=None, delimiter=','):
        super().__init__()
        self.header = header
        self.delimiter = delimiter
        self.__header_length = 0
        self.file_pos = 0
        if self.checkIntegrity(file):
            self.file = file   # it contains path for file
        else:
            raise Exception("file Integrity Error: file or root dir not found")
        self.__getHeader()

    def __readline(self, header=False, reset=False):
        """
        this will read line from file and return as array by splitting using
        delimiter. if line is empty then it will return False, else we will have
        a list of single row data items.
        :return: list or False
        """
        temp = None
        if header:
            temp = self.file_pos
            self.file_pos = 0

        if reset:
            self.file_pos = 0 + self.__header_length

        file = open(self.file, 'r')  # opening file for each line
        file.seek(self.file_pos)  # save the file pointer position
        line = file.readline().strip("\n")  # read one line at a time
        self.file_pos = file.tell()  # updating the file position

        # if header is true then reassign the file_pos with temp
        if header:
            self.__header_length = self.file_pos
            self.file_pos = self.__header_length if reset else temp

        if line:
            row = line.split(self.delimiter)
            return row
        return False

    def __getHeader(self):
        # first we are going to save our output from readline into the
        # header
        header = self.__readline(header=True, reset=True)
        if header:  # if header is row
            self.header = header
        else:
            raise Exception("Header is not found, file might be empty..?")

    def read(self):
        line = self.__readline()
        data = []
        while line:
            data.append(line)
            line = self.__readline()

        return data

# =============================================================


class CSVWriter(Utility):

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


if __name__ == "__main__":
    # print("current file location: ", os.getcwd())
    reader = CSVReader('books.csv')
    print("header: ", reader.header)
    print("data: ", reader.read())
