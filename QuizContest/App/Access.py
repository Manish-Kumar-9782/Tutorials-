
class Access:

    READONLY = 'r+'

    def __init__(self, access_level):

        if not access_level < 1 or not access_level > 3:
            self.__accessLevel = access_level
        else:
            raise Exception(f"Access Level {access_level} Not Defined..")

        self.__perm = {
            'r': False,     # read-only
            'r+': False,    # read & write
            'w+': False,    # update
            'w-': False,    # delete
            'w': False,     # create
        }

    def __set_access(self):

        if self.__accessLevel == 3:
            self.__perm['r'] = True
            self.__perm['r+'] = True
            self.__perm['w'] = True
            self.__perm['w+'] = True
            self.__perm['w-'] = True
        elif self.__accessLevel == 2:
            self.__perm['r'] = True
            self.__perm['r+'] = True
        elif self.__accessLevel == 1:
            self.__perm['r'] = True

    def has_permission(self,code):
        return self.__perm[code]

    def getlevel(self):
        return self.__accessLevel


