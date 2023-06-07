# show all optons
import os

from Book import BookDatabase


def displaySep(sep="=", length=10):

    string = sep*length
    print(string)


def showBook(database,book_id):
    os.system("cls")
    offset = 20
    flag = False  # if flat is set then only we will show the edit, delete, update options.
    bookObject = None
    for book in database.books:
        if book.book_id == book_id:
            book.show_details()
            bookObject = book
            flag = True
            break
    if flag:
        print("u:update".ljust(offset), "d:delete".ljust(offset), "q:quit".ljust(offset))
        displaySep("-", 100)
        cmd = input("Select Option: ").lower()

        if(cmd == "q"):
            database.saveDatabase()
            return
        elif(cmd == "u"):
            bookObject.edit()
        return showBook(database,book_id)

    return

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


def delete_book(database):
    book_id = input("Enter book id to delete: ")
    result = database.deleteBook(book_id)
    if result:
        print(f"----------------------<<<  Deleted: {result} >>>----------------------")
    else:
        print("Unable to delete the book with id: ",book_id)

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

def selectOption(option, database):
    """
    This function is used to select and run the given option.
    :param option:
    :return:
    """
    os.system("cls")
    if option == 1:

        database.displayBooks()
    elif option == 2:
        # id,title,author,subject,pages,price
        addBook()

    elif option == 3:
        # delete a book with given id.

        delete_book(database)

    elif option == 4:
        # view
        bookId = input("Enter Book id to view: ")
        showBook(database, bookId)

    else:
        print("wrong option")
