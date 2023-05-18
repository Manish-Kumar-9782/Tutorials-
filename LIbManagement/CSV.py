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
                print("data dir is found")
                return True
            else:
                print("data dir is not found")
                print("creating a new data dir.")
                if create:
                    os.mkdir(self.data)
                    self.__check_data_dir()  # calling recursively
                return False
        else:
            print("root dir is not found.")

    def __check_file(self, file, create=True):
        if os.path.isfile(file):
            return True
        else:
            if create:
                file = open(file, "w")
                file.close();
            return False

    def checkIntegrity(self,file, create_dir=False, create_file=False):
        if self.__check_data_dir(create_dir) and self.__check_file(file, create_file):
            return True
        return False



class CSVReader(Utility):

    def __init__(self,file,header=None,delimiter=','):
        super().__init__()
        self.header = header
        self.delimiter = delimiter
        if self.checkIntegrity(file):
            self.file = open(file)
        else:
            print("file Integrity Error: file or root dir not found")

    def __readline__(self):
        """
        this will read line from file and return as array by splitting using
        delimiter. if line is empty then it will return False, else we will have
        a list of single row data items.
        :return: list or False
        """

        line = self.file.readline().strip("\n")
        if line:
            row = line.split(self.delimiter)
            return row
        return False

    def __getHeader__(self):
        # first we are going to save our output from readline into the
        # header
        header = self.__readline__()
        if header: # if header is row
            self.header = header
        else:
            raise Exception("Header is not found, file might be empty..?")


if __name__ == "__main__":
    print("current file location: ", os.getcwd())
    utility   = Utility()
    print("root dir: ", utility.root)
    print("Data dir: ", utility.data)
    utility._Utility__check_data_dir()