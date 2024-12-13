import os
from config import *
from errors import *


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

    def __init__(self, root=None, data_dir=None, filemode='r'):
        self.error = None
        self.filemode = filemode
        self.file_path = None
        self._set_root_dir(root)
        self._set_data_dir(data_dir)

        self.__is_data_dir_missing = False
        self.__is_data_file_missing = False

    def _gen_abs_path(self, path):
        if os.path.isabs(path):
            return os.path.normpath(path)
        else:
            fpath = os.path.join(self.root, path)
            return os.path.normpath(fpath)

    def _gen_abs_file_path(self, file):
        fpath = os.path.join(self.data_dir, file)
        return os.path.normpath(fpath)

    def _set_data_dir(self, data_dir):

        # data_dir is not provided then use the default one
        if not data_dir:
            self.data_dir = DATA_PATH
            return

        # if data_dir is provided then it must a type of string.
        if not isinstance(data_dir, str):
            raise TypeError("Data directory must be a path string.")

        self.data_dir = self._gen_abs_path(data_dir)

    def _set_root_dir(self, root):

        # root is not provided then use the default one
        if not root:
            self.root = ROOT
            return

        # if root is provided then it must a type of string.
        if not isinstance(root, str):
            raise TypeError("Root directory must be a path string.")

        self.root = self._gen_abs_path(root)

    def __set_write_mode__(self, append=True):
        if append:
            self.filemode = 'a'
        else:
            self.filemode = 'w'

    def __openFile__(self):

        if not self.file or self.file.closed:

            try:
                self.file = open(self.file_path, self.filemode)
            except OSError as e:
                raise FileOpenError(f"Error opening file: {e}")

            except Exception as e:
                DB_IOError(f"Unknown error encounter while opening file: {e}")

    def __closeFile__(self):
        try:
            if self.file and not self.file.closed:
                self.file.close()
                self.file = None

        except OSError as e:
            FileCloseError(f"Error closing file: {e}")
        except Exception as e:
            DB_IOError(f"Unknown error encounter while closing file: {e}")

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
            os.mkdir(self.data_dir)
            self.__is_data_dir_missing = False
            return True
        except OSError as e:
            raise DirectoryCreationError(
                f"Error creating data directory {self.data_dir}: {e}")

    # ====================================

    def __createFile__(self, file):
        """
        Creates a new file in writing mode.

        Args:
            file (str): The path to the file to check.
            create (bool): If True, attempts to create the file if it does not exist.

        Returns:
            bool: True if the file  was successfully created, raise Error otherwise.
        """
        try:
            with open(file, 'w') as f:
                pass
            self.__is_data_file_missing = False
            return True
        except OSError as e:
            raise FileCreationError(f"Error creating file {file} : {e}")

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
            if os.path.isdir(self.data_dir):
                # print("data dir is found")
                return True
            else:
                self.__is_data_dir_missing = True
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
            if create:
                self.__createFile__()
            else:
                self.__is_data_file_missing = True
                raise FileNotFoundError(f"File {file} not found..")

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
        fpath = self._gen_abs_file_path(file)
        if self.__checkDataDir__(create_dir) and self.__check_file(fpath,  create_file):
            self.file_path = fpath
            return True
        else:
            if self.__is_data_dir_missing:
                raise NotADirectoryError(
                    "Integrity Check Failed: Data directory not found...")

            elif self.__is_data_file_missing:
                raise FileNotFoundError(
                    "Integrity Check Failed: Data file not found...")

            else:
                raise DB_IOError(
                    "Integrity Check Failed: Unknown Error occurred while checking data integrity...")

    def check(self, data_dir=True, file=None):

        if data_dir:
            self.__checkDataDir__()

        if file and isinstance(file, str):
            fpath = self._gen_abs_file_path(file)
            self.__check_file(fpath)
        elif file is None:
            return
        else:
            raise TypeError("argument file must type of string.")

    def create(self, data_dir=True, file=None):

        if data_dir:
            self.__createDataDir__()

        if file and isinstance(file, str):
            fpath = self._gen_abs_file_path(file)
            self.__createFile__(fpath)
        elif file is None:
            return
        else:
            raise TypeError("argument file must type of string.")


# =============================================================


class CSVReader(Utility):

    def __init__(self, file, headers=True, delimiter=',', root=None, data_dir=None, checkIntegrity=False):
        super().__init__(root, data_dir)
        self.headers = headers
        self.delimiter = delimiter
        self.filemode = 'r'
        self.file = None  # to contain the a File object.

        if checkIntegrity:
            self.checkIntegrity(file)
        if headers:
            self.read_headers()

    def read_headers(self):
        self.__openFile__()

        if self.file:
            try:
                headers = self.file.readline().strip().split(self.delimiter)
                if headers:
                    self.headers = headers
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


class CSVWriter(Utility):

    def __init__(self, filename, headers=None, first_row_header=False,  delimiter=',', root=None, data_dir=None, checkIntegrity=False, ):
        super().__init__(root, data_dir, "w")

        if checkIntegrity:
            self.checkIntegrity(filename)

        self.file = None
        self.delimiter = delimiter
        self.rows = []

        self._process_headers(headers, first_row_header)

    def _process_headers(self, headers, first_row_header):

        if headers and first_row_header:
            raise ValueError(
                "Arguments headers and first_row_header are mutually exclusive. please use one of the argument to set header.")

        if headers:
            self.set_headers(headers)
        elif first_row_header:
            self.read_headers()
        else:
            self.headers = []

    def read_headers(self):
        headers = CSVReader(self.file, True, self.delimiter,
                            self.root, self.data_dir).headers
        self.set_headers(headers)

    def set_headers(self, headers):
        if not isinstance(headers, (list, tuple, set)):
            raise TypeError("header must be an instance of list, tuple or set")
        self.headers = headers

    def add_row(self, row):

        if isinstance(row, (list, tuple)):
            if len(row) != len(self.headers):
                raise ValueError("row length must be equal to header length")
            self.rows.append(row)

        elif isinstance(row, dict):
            if not set(row.keys()).issubset(set(self.headers)):
                raise ValueError("Row keys must match the headers keys")

            ordered_row = [row.get(header, "") for header in self.headers]
            self.rows.append(ordered_row)

        else:
            raise TypeError("Row must be a list, tuple or dictionary")

    def save(self, append=False):
        self.__set_write_mode__(append)
        self.__openFile__()

        if self.file:
            try:
                if self.headers:
                    header_row = self.delimiter.join(self.headers)+'\n'
                    self.file.write(header_row)

                for row in self.rows:
                    line = self.delimiter.join(
                        (str(item) for item in row)) + '\n'
                    self.file.write(line)

            except OSError as e:
                print(f"Error while saving the records: {e}")
            except Exception as e:
                print(f"Unknown error encounter while saving the records: {e}")

            finally:
                self.__closeFile__()


if __name__ == "__main__":
    # print("current file location: ", os.getcwd())
    reader = CSVReader('book_x1.csv')

    for row in reader.readRow():
        print(row)
