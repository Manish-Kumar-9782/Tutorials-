import sqlite3 as sql


####################################################################################################################
def get_data(Database, table):

    """
    This function is used to retrieve a copy of a table from a database.
    in this we will make a copy of the data, since this function will return a copy of the function.
    """
    try:
        Data = []

        # connecting to the database
        connect = sql.connect(Database)

        # After connection we will make a cursor object to work on the file
        cursor = connect.cursor()

        # now we have cursor object, so we need to execute the select for all command.
        cursor.execute(f"SELECT * FROM {table}")

        # now we will make a copy of the current table from the database.
        for value in cursor.fetchall():
            Data.append(value)

        connect.close()

        return Data
    except:
        print("""
                Unable to connect the database:
                Possible reason:
                1. Database doesn't exist.
                2. Database is not in the current directory
                3. Database is locked.
                4. Don't have enough privilege.""")
#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#

####################################################################################################################
def get_columns(Database, table):

    """
    This method is used to retrieve a coulmns name of the table in a databse.
    In this mehtod we will use the cursor's description attribute which contains the Name of the column last
    accessed row.
    """
    try:
        columns = []
        # connecting to the database
        connect = sql.connect(Database)

        # After connection we will make a cursor object to work on the file
        cursor = connect.cursor()

        # now we have cursor object, so we need to execute the select for all command.
        cursor.execute(f"SELECT * FROM {table}")

        # Now we will fetch a singel row in the cursor object
        cursor.fetchone()

        # Now this cursor object has a attribute 'description' which contains the Name of columns of the row.
        for column in cursor.description:
            columns.append(column[0])
            # since column name is placed at the first postition  of the tuple.

        connect.close()
        return columns

    except:
        print("""
        Unable to connect the database:
        Possible reason:
        1. Database doesn't exist.
        2. Database is not in the current directory
        3. Database is locked.
        4. Don't have enough privilege.""")




#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#