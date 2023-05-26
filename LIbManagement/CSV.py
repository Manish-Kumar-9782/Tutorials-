import os
from config import *


class Utility:

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

    def __check_data_dir(self, create=False):

        if os.path.isdir(self.root):

            if os.path.isdir(self.data):
                # print("data dir is found")
                return True
            else:
                # print("data dir is not found")
                # print("creating a new data dir.")
                if create:
                    os.mkdir(self.data)
                    self.__check_data_dir()  # calling recursively
                return False
        else:
            # print("root dir is not found.")
            raise NotADirectoryError(DATA_PATH +" is not found..!")

    def __check_file(self, file, create=True):
        if os.path.isfile(file):
            return True
        else:
            if create:
                file = open(file, "w")
                file.close()
            return False

    def checkIntegrity(self, file, create_dir=False, create_file=False):
        if self.__check_data_dir(create_dir) and self.__check_file(file,  create_file):
            return True
        return False


class CSVReader(Utility):

    def __init__(self, file, header=None, delimiter=','):
        super().__init__()
        self.header = header
        self.delimiter = delimiter
        self.file_pos = 0
        if self.checkIntegrity(file):
            self.file = file   # it contains path for file
        else:
            raise Exception("file Integrity Error: file or root dir not found")

    def __readline__(self, header=False, reset=False):
        """
        this will read line from file and return as array by splitting using
        delimiter. if line is empty then it will return False, else we will have
        a list of single row data items.
        :return: list or False
        """
        temp = None
        if header:
            temp = self.file_pos

        if reset or header:
            self.file_pos = 0

        file = open(self.file, 'r')  ## opening file for each line
        file.seek(self.file_pos)  # save the file pointer position
        line = self.file.readline().strip("\n")  # read one line at a time
        self.file_pos = file.tell()  # updating the file position

        # if header is true then reassign the file_pos with temp
        if header:
            self.file_pos = temp

        if line:
            row = line.split(self.delimiter)
            return row
        return False

    def __getHeader__(self):
        # first we are going to save our output from readline into the
        # header
        header = self.__readline__(header=True)
        if header:  # if header is row
            self.header = header
        else:
            raise Exception("Header is not found, file might be empty..?")


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

    def __write_row(self,file, row):
        row = self.__parse_row(row)
        # first convert our seq into the string
        line = self.delimiter.join(row) + "\n"
        file.write(line)

    def write_row(self, row):
        file = open(self.file, self.filemode)
        self.__write_row(file,row)
        file.close()

    def write_rows(self, rows):
        file = open(self.file, self.filemode)
        for row in rows:
            self.__write_row(file, row)
        file.close()

    def write_header(self):
        self.write_row(self.header)


if __name__ == "__main__":
    # print("current file location: ", os.getcwd())
    writer = CSVWriter('books.csv', ['id', 'title', 'author'])
