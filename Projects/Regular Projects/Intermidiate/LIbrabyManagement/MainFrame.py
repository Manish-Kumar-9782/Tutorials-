# main frame is the main front body of the library in which we will see all the
# available options.

# now first of all we will make a class of the application.
from tkinter import Tk, Label, Button, messagebox
from tkinter import Toplevel
from AddBook import AddBook
from DeleteBook import DeleteBook
from ViewBooks import DisplayBooks
from IssuedTo import IssuedTo as IssueBook
from Database import PySQL as pysql


class App(Tk):

    # Now we will call the init constructor of the tk.Tk in this class to inherit all the functionality Note Here
    # self denote the main application which name is App which will contain the Main (Initial Frame of the
    # application.)

    def __init__(self):
        Tk.__init__(self)
        self.geometry("600x600")
        self.title("Welcome to Library")
        self.resizable(0, 0)
        self.database = pysql(host='localhost', user='root', password='ManishKumar@9782')
        self.config(bg="#4278f5")
        self.AddBook_root_window = None
        self.viewBook_root_window = None
        self.deleteBook_root_window = None
        self.issueBook_root_window = None
        self.returnBook_root_window = None

        self.heading = Label(self, text="Welcome to Library",
                             font="arial 20 bold", fg='white', bg="#4278f5")
        self.heading.pack(pady=10)

        # Now we need to add the remaining thing like add book delete book, view book etc
        # first of all we will make the Add book button which will call the AddBook Frame.
        # AddBook is defined in the AddBook.py module.

        self.AddBook_Button = Button(self, text="AddBook", font='aial 15 bold', fg='white', bg='#7632cf')
        self.AddBook_Button.place(x=250, y=100)

        self.DeleteBook_Button = Button(self, text="DeleteBook", font='arial 15 bold', fg='white', bg='#7632cf')
        self.DeleteBook_Button.place(x=240, y=160)

        self.ViewBooks_Button = Button(self, text="ViewBooks", font='arial 15 bold', fg='white', bg='#7632cf')
        self.ViewBooks_Button.place(x=240, y=220)

        self.IssueBooks_Button = Button(self, text="IssueBook", font='arial 15 bold', fg='white', bg='#7632cf')
        self.IssueBooks_Button.place(x=240, y=280)

        self.ReturnBooks_Button = Button(self, text="ReturnBook", font='arial 15 bold', fg='white', bg='#7632cf')
        self.ReturnBooks_Button.place(x=240, y=340)

        # after defining all the button we will configure the buttons other attributes.
        self.config_buttons()
        # ==================================================================================================== #
        # Now we will make function to provide add new book functionality to the AddBook Button

    def addBook(self):
        """
        This function will call a new Toplevel window.
        :param self:
        :return:
        """
        # Now we will make a new Toplevel window which will handle all the widgets of AddBook Frame.
        if self.AddBook_root_window is None:
            self.AddBook_root_window = Toplevel()
            self.AddBook_root_window.title("Add Book")
            self.AddBook_root_window.resizable(0, 0)
            self.AddBook_root_window.geometry("600x600")

            self.AddBook_root_Frame = AddBook(master=self.AddBook_root_window)
            # Now this toplevel window will be master window for the AddBook Frame.

            self.AddBook_root_window.protocol("WM_DELETE_WINDOW", self.exit_wm_addbook)

    def viewBooks(self):
        """
        To show the library Database
        :return: None.
        """
        if self.viewBook_root_window is None:
            self.viewBook_root_window = Toplevel()
            self.viewBook_root_window.title("Library Database")
            self.viewBook_root_window.resizable(0, 0)
            self.viewBook_root_window.geometry("600x600")

            self.viewBook_root_Frame = DisplayBooks(master=self.viewBook_root_window,
                                                    Database=self.database.get_all_entries('libdata', 'books'))

            self.viewBook_root_window.protocol("WM_DELETE_WINDOW", self.exit_wm_viewbook)

    def deleteBook(self):

        if self.deleteBook_root_window is None:
            self.deleteBook_root_window = Toplevel()
            self.deleteBook_root_window.title("Delete A Book Entry")
            self.deleteBook_root_window.geometry("600x600")
            self.deleteBook_root_window.resizable(0, 0)

            self.deleteBook_root_Frame = DeleteBook(master=self.deleteBook_root_window)
            self.deleteBook_root_window.protocol("WM_DELETE_WINDOW", self.exit_wm_deletebook)

    def issueBook(self):

        if self.issueBook_root_window is None:
            self.issueBook_root_window = Toplevel()
            self.issueBook_root_window.title("Delete A Book Entry")
            self.issueBook_root_window.geometry("600x600")
            self.issueBook_root_window.resizable(0, 0)

            self.issueBook_root_Frame = IssueBook(master=self.issueBook_root_window)
            self.issueBook_root_window.protocol("WM_DELETE_WINDOW", self.exit_wm_issuebook)

    def returnBook(self):

        if self.returnBook_root_window is None:
            self.returnBook_root_window = Toplevel()
            self.returnBook_root_window.title("Delete A Book Entry")
            self.returnBook_root_window.geometry("600x600")
            self.returnBook_root_window.resizable(0, 0)

            self.returnBook_root_Frame = IssueBook(master=self.returnBook_root_window)
            self.returnBook_root_window.protocol("WM_DELETE_WINDOW", self.exit_wm_returnbook)

    def exit_wm_addbook(self):
        self.AddBook_root_window.destroy()
        self.AddBook_root_window = None

    def exit_wm_deletebook(self):
        self.deleteBook_root_window.destroy()
        self.deleteBook_root_window = None

    def exit_wm_viewbook(self):
        self.viewBook_root_window.destroy()
        self.viewBook_root_window = None

    def exit_wm_issuebook(self):
        self.issueBook_root_window.destroy()
        self.issueBook_root_window = None

    def exit_wm_returnbook(self):
        self.returnBook_root_window.destroy()
        self.returnBook_root_window = None

    def config_buttons(self):
        """
        This is a simple function which will be used to config all the Buttons.
        :return:
        """
        self.AddBook_Button.config(command=self.addBook)
        self.ViewBooks_Button.config(command=self.viewBooks)
        self.DeleteBook_Button.config(command=self.deleteBook)
        self.IssueBooks_Button.config(command=self.issueBook)
        self.ReturnBooks_Button.config(command=self.returnBook)
