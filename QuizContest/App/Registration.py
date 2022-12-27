from Access import Access
from Utility import Utility
import os, csv


class Registration(Utility):
    def __init__(self, firstname, lastname, dob, address, phone_number):
        super().__init__()
        self.firstName = firstname
        self.secondName = lastname
        self.dateOfBirth = dob
        self.address = address
        self.phoneNumber = phone_number
        self.filedNames = ['FirstName', 'LastName', "DateOfBirth",
                           "Address", "MobileNumber", "AccessLevel"]
        self.__file = None
        self.writer = csv.DictWriter(self.__file, self.filedNames)

    def register(self, access_level):
        # first of all we will check our section
        if super().getSection():
            self.__prepareRegistration(access_level)
        else:
            raise Exception("Section is not defined for registration..!")

    def __prepareRegistration(self, access_level):
        """
        This Function must be overridden from the subclass
        :param access_level: to set the access mode for registration
        :return:
        """
        self.__Access = Access(access_level)    #

        # first we will check our integrity
        if self.checkIntigrity():
            self.__file = open(self.getDirPath(), 'a')
            self.__writeData()

        # Now we will open our file

    def __writeData(self):


        data = {
            'FirstName': self.firstName,
            'LastName': self.secondName,
            "DateOfBirth":self.dateOfBirth,
            "Address": self.address,
            "MobileNumber":self.phoneNumber,
            "AccessLevel": self.__Access.getlevel()
        }

        self.writer.writerow(data)


