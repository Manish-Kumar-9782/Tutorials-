# Thi module will be used to view the books stored in the database.
from tkinter import Frame, Label, Button, messagebox
from tkinter import TOP
from Database import Book


# Now we will make a new Frame in which we will show our books.

class DisplayBooks(Frame):

    def __init__(self, master=None, Database=None):
        """
        A constructor to Initiate the DisplayBooks object with given master and Database to Display on the Frame
        :param master:
        :param Database:
        """
        Frame.__init__(self, master=master)
        self.config(bg='#4db099')
        self.pack(expand=True, fill='both')
        self.BookCards = []
        self.BookInstance = []
        # Now we will place a heading on the Frame
        self.heading = Label(self, text="Library Database", font='arial 20 bold', bg='#4db099', fg='white')
        self.heading.pack(side=TOP)

        for index, book in enumerate(Database):
            bookinstance = Book(Id=book[0], Title=book[1], Author=book[2], Status=book[3], Name=None)
            self.BookInstance.append(bookinstance)
            # after creating the bookInstance we need to create a book card.
            bookcard = BookCard(master=self, BookData=bookinstance, row_index=index)
            self.BookCards.append(bookcard)


# Now we will make another class in this which will contain the books related infomation.

class BookCard(Frame):
    def __init__(self, master=None, BookData=None, row_index=0):
        """
        A Frame card to Display the Book information on the Frame.
        :param master: master window on which this BookCard will be placed or packed.
        :param BookData: BookData to display on BookCard.
        """
        Frame.__init__(self, master=master)
        self.config(bg='#6d5bc9', height=60)
        self.pack(expand=False, fill='x', padx=20, side=TOP, pady=5)
        if isinstance(BookData, Book):
            self.Book = BookData
        else:
            print("Book instance not found.")

        self.SetBooksDetails()
        self.BookDetails = []  # it will contain the Label of book Details.

    def SetBooksDetails(self):

        label_bg = '#6d5bc9'
        label_fg = 'white'

        id_label = Label(self, text="%-20s" % f"Id: {self.Book.id}", font="arial 10 bold", fg=label_fg, bg=label_bg)
        id_label.place(x=10, y=0)

        name_label = Label(self, text="%-20s" % f"Name: {self.Book.name}", font="arial 10 bold", fg=label_fg,
                           bg=label_bg)
        name_label.place(x=10, y=30)

        title_label = Label(self, text="%-20s" % f"Title: {self.Book.title}", font="arial 10 bold", fg=label_fg,
                            bg=label_bg)
        title_label.place(x=180, y=0)

        author_label = Label(self, text="%-20s" % f"Author: {self.Book.author}", font="arial 10 bold", fg=label_fg,
                             bg=label_bg)
        author_label.place(x=180, y=30)

        status_label = Label(self, text="%-20s" % f"Status: {self.Book.status}", font="arial 10 bold", fg=label_fg,
                             bg=label_bg)
        status_label.place(x=440, y=0)
