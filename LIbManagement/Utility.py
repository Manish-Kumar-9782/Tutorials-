# show all optons

def showOptions():

    print("Select an Option...")
    print("1. show all books")
    print("2. add a book")
    print("3. delete a book")
    print("4. view a book")

def displaySep(sep="=", length=10):

    string = sep*length
    print(string)

def displayTitle(title,length):
    if not isinstance(title, str):
        raise TypeError("title must be an string..")
    print(title.center(length))