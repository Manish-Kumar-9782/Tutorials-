# This module contains the user-defined Exception Class which will be used in Database project.

class AlreadyExist(Exception):
    """Exception class if an object is already exist in the system."""

    def __init__(self, exists=None, custom_message=None):
        self.exists = exists
        self.custom_message = custom_message
        Exception.__init__(self)

    def __str__(self):

        if self.custom_message:
            return self.custom_message
        else:
            return f"File '{self.exists}' is already exist!"


class DuplicateEntryFound(Exception):
    """Exception class if an duplicate object is found in the system"""

    def __init__(self, file=None, custom_message=None):
        self.file = file
        self.custom_message = custom_message
        Exception.__init__(self)

    def __str__(self):

        if self.custom_message:
            return self.custom_message
        else:
            return f"Duplicate Entry of file '{self.file}' is found!"


class NotFound(Exception):
    """Exception class if an object in the system is not found."""

    def __init__(self, file=None, custom_message=None):
        self.file = file
        self.custom_message = custom_message
        Exception.__init__(self)

    def __str__(self):

        if self.custom_message:
            return self.custom_message
        else:
            return f"File '{self.file}' is not found!"


class MisMatchSize(Exception):
    """Exception class if size or length of two object are not equal."""

    def __init__(self, obj1=None, obj2=None, custom_message=None):
        self.obj1 = obj1
        self.obj2 = obj2
        self.custom_message = custom_message
        Exception.__init__(self)

    def __str__(self):
        obj_name1 = 'None'
        obj_name2 = 'None'
        if self.custom_message:
            return self.custom_message
        else:
            return f"Size of '{self.obj1}' does not match to '{self.obj2}'!"


class DatabaseNotFound(Exception):
    """Exception class to raise the exeption if a database is not found."""

    def __init__(self, database=None, message=None):
        self.database = database
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return f"Database '{self.database}' is not found!";


class DatabaseTableNotFound(Exception):
    """Exception class to raise the exeption if a database is not found."""

    def __init__(self, database=None, table=None, message=None):
        self.database = database
        self.table = table
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return f"Database table '{self.database}.{self.table}' is not found!";


class NoPrimaryKey(Exception):
    """Exception class to raise the exception if a database does not have primary"""

    def __init__(self, database=None, table=None, message=None):
        self.database = database
        self.table = table
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return f"There No PRIMARY KEY found in database '{self.database}.{self.table}'! ";


class ColumnValueError(Exception):
    """ An Exception is raised due to the error in column of a datbase table, it can happen, mismatch of keys,
        providing No data to the database to access the columns, undefined value etc."""

    def __init__(self, database=None, table=None, message=None):
        self.database = database
        self.table = table
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return f"Column Value Error in '{self.database}.{self.table}', please check the input values\
            don't give empty, undefined, duplicate column values! "


class RowValueError(Exception):
    """ An Exception is raised due to the error in row  of a database table, it can happen, mismatch of keys, value
        pairs parsing mismatch information to system which can cause  wrong information retrieval."""

    def __init__(self, database=None, table=None, message=None):
        self.database = database
        self.table = table
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return f"Row Value Error in '{self.database}.{self.table}', please check the input values\
don't give empty, undefined, duplicate, Unsupported value etc.! "


class IntegrityError(Exception):
    """An Exception raised due to incomplete value and their wrong formatted patterns, this exception can be
        raised by misplaced values, wrong formatted values, wrong values, wrong object types etc. """

    def __init__(self, message=None):
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return "Please Check your input values it must be misplaced values, wrong formatted values, wrong values!"


class OperatorError(Exception):
    """An Exception raised due to invalid operator, misplaced operator, undefined operator etc."""

    def __init__(self, message=None):
        self.message = message

    def __str__(self):
        if self.message:
            return self.message
        else:
            return "Please Check your input operator, there is something wrong with it!"
