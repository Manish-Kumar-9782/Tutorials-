# show all optons
from Book import BookDatabase


def displaySep(sep="=", length=10):

    string = sep*length
    print(string)

def addBook():
    displaySep('-', 100)
    print("Enter Book Details: ")
    title = input("Book Title: ")
    author = input("Book Author: ")
    subject = input("Book Subject: ")
    pages = input("Book Pages: ")
    price = input("Book Price: ")

    header = ["id", 'title', 'author', 'subject', 'pages', 'price']
    bk_db = BookDatabase('books.csv', header)
    if bk_db.createBook(title, author, subject, pages, price):
        print("one book successfully added.")
    else:
        print("Unable to create a new book entry.")

    choice = input("Do you want to add another book  Yes/No !!").lower()
    if choice in ["yes", 'y']:
        addBook()
    displaySep('-', 100)
    return

def showOptions():

    print("Select an Option...")
    print("1. show all books")
    print("2. add a book")
    print("3. delete a book")
    print("4. view a book")


def displayTitle(title,length):
    if not isinstance(title, str):
        raise TypeError("title must be an string..")
    print(title.center(length))

def selectOption(option):
    """
    This function is used to select and run the given option.
    :param option:
    :return:
    """
    if option == 1:
        pass
    elif option == 2:
        # id,title,author,subject,pages,price
        addBook()
    else:
        print("wrong option")
