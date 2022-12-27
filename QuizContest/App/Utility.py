import os

class Utility:

    def __init__(self):
        self.__root_dir = r"Apps/Contest"
        self.__section = None
        self.__section_path = None

    def setSection(self, section):
        self.__section = section + '.csv'
        self.__section_path = os.path.join(self.__root_dir, self.__section)

    def checkIntigrity(self):
        # first we will join the root_dir and section

        if not os.path.isfile(self.__section_path):
            file = open(self.__section_path, 'w')
            file.close()
            return True

    def getRootDir(self):
        return self.__root_dir

    def getSection(self):
        return self.__section

    def getDirPath(self):
        return self.__section_path


