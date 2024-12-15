import os
from config import *
from errors import *
from abc import ABC, abstractmethod


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

    def get_file_path(self, filename):
        if not isinstance(filename, str) or not filename.strip():
            raise ValueError("file name must be non-empty string type.")
        return self._gen_abs_file_path(filename)

    def set_file_path(self, filename):
        if not isinstance(filename, str) or not filename.strip():
            raise ValueError("file name must be non-empty string type.")

        self.file_path = self._gen_abs_file_path(filename)

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
            except FileNotFoundError:
                raise FileOpenError(f"File not found: {self.file_path}")
            except IsADirectoryError:
                raise FileOpenError(
                    f"Expected a file but found a directory: {self.file_path}")
            except OSError as e:
                raise FileOpenError(f"Error opening file: {e}")
            except Exception as e:
                raise DbIOError(
                    f"Unknown error encountered while opening file: \n{e.__class__.__name__}: {e}")

    def __closeFile__(self):
        try:
            if self.file and not self.file.closed:
                self.file.close()
                self.file = None

        except OSError as e:
            raise FileCloseError(f"Error closing file: {e}")
        except Exception as e:
            raise DbIOError(
                f"Unknown error encountered while closing file: \n{e.__class__.__name__}: {e}")

    def _create_data_dir(self):
        """
        Attempts to create the data directory if it does not exist.

        Returns:
            str: The path of the created or existing data directory.

        Raises:
            NotADirectoryError: If the root directory does not exist.
            DirectoryCreationError: If there is an error creating the directory.
        """
        if os.path.isdir(self.data_dir):
            return self.data_dir  # Directory already exists

        try:
            os.mkdir(self.data_dir)
            return self.data_dir  # Successfully created
        except OSError as e:
            raise DirectoryCreationError(
                f"Error creating data directory {self.data_dir}: {e}")

    # ====================================

    def _create_file(self, file):
        """
        Attempts to create a new file if it does not exist.

        Args:
            file (str): The path to the file to create.

        Returns:
            str: The path of the created or existing file.

        Raises:
            FileCreationError: If there is an error creating the file.
        """
        if os.path.isfile(file):
            return file  # File already exists
        try:
            with open(file, 'w') as f:
                pass
            return file  # Successfully created
        except OSError as e:
            raise FileCreationError(f"Error creating file {file}: {e}")

    # ====================================

    def _check_data_dir(self):
        """
        Verifies the existence of the specified data directory.

        Raises:
            NotADirectoryError: If the root directory or data directory does not exist.

        Returns:
            str: The path of the data directory if it exists.
        """
        if not os.path.isdir(self.root):
            raise NotADirectoryError(
                f"Root directory {self.root} is not found.")

        if not os.path.isdir(self.data_dir):
            raise NotADirectoryError(
                f"Data directory {self.data_dir} does not exist.")

        return self.data_dir

    # ====================================

    def _check_file(self, file):
        """
        Checks if a specified file exists.

        Raises:
            FileNotFoundError: If the file does not exist.

        Returns:
            str: The path of the file if it exists.
        """
        if not os.path.isfile(file):
            raise FileNotFoundError(f"File {file} not found.")

        return file

    # ====================================

    # ====================================

    def check_integrity(self, file, create_dir=False, create_file=False):
        """
        Verifies the existence and accessibility of a specified directory and file.

        Args:
            file (str): The path to the file to check.
            create_dir (bool): If True, attempts to create the data directory if it does not exist. Default is False.
            create_file (bool): If True, attempts to create the file if it does not exist. Default is False.

        Returns:
            bool: True if the data directory exists and the file check is successful, False otherwise.

        Raises:
            DirectoryNotFoundError: If the data directory does not exist and create_dir is False.
            FileNotFoundError: If the file does not exist and create_file is False.
        """
        # Check the data directory first
        try:
            self._check_data_dir()  # Ensure the data directory exists
        except NotADirectoryError as e:
            if create_dir:
                self._create_data_dir()  # Create the directory if specified
            else:
                raise NotADirectoryError(
                    f"Integrity Check Failed: {str(e)}")

        # If the data directory exists, check the file
        fpath = self._gen_abs_file_path(file)
        try:
            self._check_file(fpath)  # Check if the file exists
        except FileNotFoundError as e:
            if create_file:
                self._create_file(fpath)  # Create the file if specified
            else:
                raise FileNotFoundError(f"Integrity Check Failed: {str(e)}")

        self.set_file_path(fpath)
        return True

    def check(self, data_dir=True, file=None):

        result = {
            "file": {
                "status": "error",
                "message": "Data file not found"
            },
            "data_dir": {
                "status": "error",
                "message": "Data directory not found"
            }
        }

        if data_dir:
            x_dir = result["data_dir"]
            try:
                self._check_data_dir()
                x_dir["status"] = "success"
                x_dir["message"] = f"Data directory found.."
            except Exception as e:
                print(f"Error: {e}")

        if file is not None:
            if not isinstance(file, str) or not file.strip():
                raise ValueError(
                    "The 'file' argument must be non-empty string.")

            x_file = result["file"]
            fpath = self._gen_abs_file_path(file)
            try:
                self._check_file(fpath)
                x_file["status"] = "success"
                x_file["message"] = "Data file found.."
            except Exception as e:
                print(f"Error: {e}")

        return result

    def create(self, data_dir=True, file=None):
        result = {
            "data_dir": {
                "status": "error",
                "message": "Data directory creating error.."
            },
            "file": {
                "status": "error",
                "message": "Data file not creation error.."
            }
        }

        try:
            if data_dir:
                self._create_data_dir()
                result["data_dir"]['status'] = 'success'
                result["data_dir"]['message'] = "Data directory created successfully.."
        except Exception as e:
            print(f"Error: {e}")
            result["data_dir"]['message'] = e

        if file is not None:
            if not isinstance(file, str) or not file.strip():
                raise ValueError(
                    "The 'file' argument must be non-empty string.")

        fpath = self.get_file_path(file)

        try:
            self._create_file(fpath)
            result["file"]['status'] = "success"
            result["file"]['message'] = "Data file directory created successfully.."
            self.set_file_path(fpath)
        except Exception as e:
            print(f"Error {e}")
            result["file"]['message'] = e

        return result
# =============================================================


class CSVBase(Utility, ABC):

    def __init__(self, filename, headers=None, first_row_headers=None, delimiter=',', root=None, data_dir=None, filemode='r', checkIntegrity=False):
        super().__init__(root, data_dir, filemode)
        self.filename = filename
        self.delimiter = delimiter
        self.headers = None
        self._check_integrity_test_result = None

        if checkIntegrity:
            self._check_integrity_test_result = self.check_integrity(
                self.filename)

        self.set_headers(headers, first_row_headers)

    @abstractmethod
    def read_headers(self):
        """Abstract method to read headers from the CSV file. Must be implemented by subclasses."""
        pass

    def _set_first_row_as_headers(self, first_row_headers=None):

        if not isinstance(first_row_headers, bool):
            raise ValueError("first_row_headers must be boolean")

        if first_row_headers:
            reader = self.get_reader()
            if reader and isinstance(reader, CSVBase):
                reader.read_headers()  # Get headers from the file if not set
                self.headers = reader.headers
            else:
                raise ValueError(
                    "reader must be CSVBase object, that has read_headers method.")

    def _set_headers(self, headers=None):

        if isinstance(headers, (list, tuple, set)):
            if not headers:  # Check if the headers list is empty
                raise ValueError(
                    "Headers cannot be an empty list, tuple, or set.")
            self.headers = list(headers)  # Convert to list for consistency
        else:
            raise TypeError("Headers must be a list, tuple, set,")

    def set_headers(self, headers=None, first_row_header=None):
        """Set the headers for the CSV file."""
        if headers is None and first_row_header is None:
            return

        if headers and first_row_header:
            raise ValueError(
                "Arguments 'headers' and 'first_row_header' are mutually exclusive. please use one of the argument to set header.")

        if first_row_header:
            if self._check_integrity_test_result is None:
                try:
                    self._check_integrity_test_result = self.check_integrity(
                        self.filename)

                    if self._check_integrity_test_result:
                        self._set_first_row_as_headers(first_row_header)

                except NotADirectoryError as e:
                    raise DBIntegrityError(
                        f"Unable to read headers from reader because Database directory not found during integrity check \nError:{e}")

                except FileNotFoundError as e:
                    raise DBIntegrityError(
                        f"Unable to read headers from reader because Database file not found during integrity check \nError:{e}")

                except Exception as e:
                    raise DBIntegrityError(
                        f"Unable to read headers from reader..\n{e.__class__.__name__}: {e}")

            elif self._check_integrity_test_result:
                self._set_first_row_as_headers(first_row_header)

        elif headers:
            self._set_headers(headers)

    def get_reader(self):
        """Return an instance of CSVReader."""
        raise NotImplementedError("get_reader is not implemented")

    def get_writer(self):
        """Return an instance of CSVWriter."""
        raise NotImplementedError("get_writer is not implemented")


# =============================================================
# =============================================================


class CSVReader(CSVBase):

    def __init__(self, filename, headers=True, first_row_headers=False, delimiter=',', root=None, data_dir=None, checkIntegrity=False):

        super().__init__(filename, headers, first_row_headers, delimiter,
                         root, data_dir, "r", checkIntegrity)
        self.file = None  # to contain the a File object.

    def get_reader(self):
        return self

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


class CSVWriter(CSVBase):

    def __init__(self, filename, headers=None, first_row_header=False,  delimiter=',', root=None, data_dir=None, checkIntegrity=False):
        super().__init__(filename, headers, first_row_header,
                         delimiter, root, data_dir, "w", checkIntegrity)
        self.file = None
        self.rows = []

    def read_headers(self):
        reader = CSVReader(self.filename, None, True,
                           self.delimiter, self.root, self.data_dir, "r", True)
        self.headers = reader.headers

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
        else:
            print("No file IO Object created during open file process..")


if __name__ == "__main__":
    # print("current file location: ", os.getcwd())
    reader = CSVReader('book_x1.csv')

    for row in reader.readRow():
        print(row)
