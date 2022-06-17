# this module  will de define the structure of the returning a book to the librarian

from tkinter import Tk, Frame, Label, Entry, StringVar, Button, messagebox
import tkinter as tk
from Database import PySQL as pysql
from pymysql.err import OperationalError
from MyExceptions import DatabaseNotFound, DatabaseTableNotFound, AlreadyExist


class ReturnBook(Frame):

    """A class to return a book to the librarian """

    def __init__(self, master=None):
        Frame.__init__(self, master=master)

        self.master = master
        self.background = "#d67158"
        self.foreground = "white"
        self.config(bg=self.background)
        self.pack(expand=True, fill='both')
        self.pysql = None
        self.host = 'localhost'
        self.user = 'root'
        self.password = 'ManishKumar@9782'
        self.DatabaseName = 'libdata'
        self.LibraryTable = 'books'
        self.ReturnedTable = 'returned'

        # variable for entries
        self.BookId_var = StringVar()
        self.Person_var = StringVar()

        # heading of Issued interface
        self.heading = Label(self, text="Return A Book", font='arial 20 bold', bg=self.background, fg=self.foreground)
        self.heading.pack()

        # Now we will place labels and entries for the book IDs and the person whose going to be issued the book.
        self.EntriesFrame = Frame(self, width=500, height=300, relief=tk.GROOVE, bg='#e8c79b',
                                  highlightcolor='#7a5443', highlightthickness=5, highlightbackground='white')
        self.EntriesFrame.place(x=50, y=100)

        self.BookId_Label = Label(self.EntriesFrame, text="BookId: ", font="arial 13 bold", bg='#e8c79b', fg="#4c5c7d")
        self.BookId_Label.place(x=100, y=50)

        self.Person_Label = Label(self.EntriesFrame, text='Returned By: ', font='arial 13 bold', bg="#e8c79b",
                                  fg="#4c5c7d")
        self.Person_Label.place(x=100, y=130)

        # Now place entries
        self.BookId_Entry = Entry(self.EntriesFrame, textvariable=self.BookId_var, width=30, fg='#4c5c7d')
        self.BookId_Entry.place(x=230, y=50)

        self.Person_Entry = Entry(self.EntriesFrame, textvariable=self.Person_var, width=30, fg='#4c5c7d')
        self.Person_Entry.place(x=230, y=130)

        self.Cancel_Button = Button(self, text="Cancel", font='arial 13 bold', command=self.cancel)
        self.Cancel_Button.place(x=130, y=500)

        self.Submit_Button = Button(self, text="Submit", font='arial 13 bold',command=self.submit)
        self.Submit_Button.place(x=380, y=500)

        # initiating the database
        self._init_Database()

    def _init_Database(self):

        """ A function to initiate the database with the given information """

        try:
            self.pysql = pysql(self.host, self.user, self.password)

            try:
                self.pysql.create_table(self.DatabaseName, self.ReturnedTable,
                                        ("BOOK_ID", "RETURNED_BY", "DATE_TIME"),
                                        ("INT NOT NULL", "VARCHAR(200) NOT NULL",
                                         "TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP"),
                                        primary_key=None, user=self.user, password=self.password, host=self.host)
                # Not if we are not defining the primary_key then don't use Auto Increment statement in the script
                # if table is not exist then we need to create a table for issuing books.
            except AlreadyExist:
                # This exception will occur only if above defined database table is already exist.
                # we will ignore this exception
                # print(f"Table {self.TableName} is already exist")
                pass
        except RuntimeError:
            messagebox.showerror("Connection Error", "Unable to connect to the database server!")

        except OperationalError:
            # this error will raise if there is incorrect table definition
            messagebox.showerror("Operational Error", "Unable to create the table incorrect table information")
            self.master.destroy()
            return

    def submit(self):

        """A function to submit the Entries"""
        try:
            # Since we are returning a book so we just need to insert the book in the database
            # we found a match in our library then we can issue a book to a person
            self.pysql.insert_row(self.DatabaseName, self.ReturnedTable, columns=("BOOK_ID", "RETURNED_BY"),
                                  primary_key=False, primary_key_value=None, allow_duplicate=True,
                                  values=(self.BookId_var.get(), self.Person_var.get()))

        except RuntimeError:
            messagebox.showerror("Connection Error", "Unable to connect to the database server!")
        except DatabaseNotFound:
            messagebox.showerror("DatabaseError",
                                 f"Database '{self.DatabaseName}' not found in the localhost database server!")
        except DatabaseTableNotFound:
            messagebox.showerror("DatabaseTableError",
                                 f"Table '{self.DatabaseName}.{self.LibraryTable}' not found in the {self.host} database server!")

    def cancel(self):
        self.master.destroy()


if __name__ == "__main__":
    root = Tk()
    root.title("Issue Book")
    root.geometry("600x600")
    root.resizable(0, 0)

    issued_frame = ReturnBook(root)
    root.mainloop()