# in this module/file we will define the AddBook class which will have the tkinter Frame.

from tkinter import Frame, Label, Entry, Button, messagebox, StringVar, IntVar
from Database import PySQL as pysql
from MyExceptions import DuplicateEntryFound

# Now first of all we will make a new class with the name of the AddBook this will inherit the Frame class

class AddBook(Frame):

    def __init__(self, master=None):
        Frame.__init__(self, master=master)
        # Now our Frame name becomes AddBook by overriding and inheriting all the properties.
        self.config(bg="#3a778a")
        self.pack(expand=True, fill='both')

        # Adding a new Heading on this Frame.
        self.heading = Label(self, text="Add A New Book", bg="#3a778a", fg="white", font="arial 15 bold")
        self.heading.pack(pady=10)

        # Now we will make an object of the AddBookEntries child Frame.
        self.Entries = AddBookEntries(master=self)  # An instance of AddBookEntries.
        self.Entries.pack(pady=(100, 0))

        # Now we will make a Submit and Cancel Button
        self.CancelButton = Button(self, text="Cancel", font="arial 14 bold")
        self.CancelButton.place(x=180, y=500)

        self.SubmitButton = Button(self, text="Submit", font="arial 14 bold", command=self.submit_entry)
        self.SubmitButton.place(x=320, y=500)
        # Label(self, text="Record saved Successfully", font="arial 15 bold", fg='red').place(x=160, y=550)

    def submit_entry(self):
        """
        Submit the all the entries from the AddBookEntries widgets.
        :return: None
        """
        try:
            cur = pysql(host='localhost', user='root', password='ManishKumar@9782')
            cur.insert_row(database_name='libdata', table_name='books',
                           columns=['BOOK_ID', 'BOOK_TITLE', 'BOOK_AUTHOR', 'BOOK_STATUS'],
                           values=[self.Entries.BookId.get(), self.Entries.BookTitle.get(),
                                   self.Entries.Author.get(), self.Entries.Status.get()])
            cur.del_cursor()  # closing the cursor.
            Label(self, text="Record saved Successfully", font="arial 15 bold", fg='red').place(x=160, y=550)
        except DuplicateEntryFound:
            Label(self, text="Record Not Saved!", font="arial 15 bold", fg='red').place(x=160, y=550)
            messagebox.showerror("Error", f"Duplicate Entry Found in BOOK_ID with value {self.Entries.BookId.get()}")
        #except:
         #   Label(self, text="Unable to save the Record", font="arial 15 bold", fg='red').place(x=300, y=550)


# ================================================================================================== #
# Now we will make a new class for another small frame whose master will be AddBook class Frame.


class AddBookEntries(Frame):

    def __init__(self, master=None):
        Frame.__init__(self, master=master)
        # setting the a new master Frame to the child frame.
        self.config(bg="#294366", width=450, height=250)
        # self.pack_propagate(False) # setting the grid propagate will disable the auto resize the Frame.

        # some variables for entries.
        self.BookId = IntVar()
        self.BookTitle = StringVar()
        self.Author = StringVar()
        self.Status = StringVar()

        # Now we will make some Label and Entries.
        self.BookId_Label = Label(self, text='Book Id: ', font="arial 12 bold", bg='#294366', fg='white')
        self.BookId_Label.place(x=20, y=20)

        self.BookId_Entry = Entry(self, textvariable=self.BookId, font="arial 12", width=25)
        self.BookId_Entry.place(x=150, y=20)

        self.BookTitle_Label = Label(self, text="Book Title: ", font="arial 12 bold", bg='#294366', fg='white')
        self.BookTitle_Label.place(x=20, y=80)

        self.BookTitle_Entry = Entry(self, textvariable=self.BookTitle, font='arial 12', width=25)
        self.BookTitle_Entry.place(x=150, y=80)

        self.BookAuthor_Label = Label(self, text="Book Author: ", font="arial 12 bold", bg='#294366', fg='white')
        self.BookAuthor_Label.place(x=20, y=140)

        self.BookAuthor_Entry = Entry(self, textvariable=self.Author, font='arial 12', width=25)
        self.BookAuthor_Entry.place(x=150, y=140)

        self.BookStatus_Label = Label(self, text="Book Status: ", font="arial 12 bold", bg='#294366', fg='white')
        self.BookStatus_Label.place(x=20, y=200)

        self.BookStatus_Entry = Entry(self, textvariable=self.Status, font='arial 12', width=25)
        self.BookStatus_Entry.place(x=150, y=200)
