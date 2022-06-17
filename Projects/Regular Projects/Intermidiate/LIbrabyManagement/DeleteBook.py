# In this module we will make an interface with user which will provide the deletion operation functionality
# to user to delete an entry from the database.

from tkinter import Frame, Label, Button, Entry, StringVar
from Database import PySQL as pysql


# first of all we will make an Delete Interface Frame.

class DeleteBook(Frame):

    def __init__(self, master=None):
        Frame.__init__(self, master=master)
        self.Database = pysql(host='localhost', user='root', password='ManishKumar@9782')
        self.master = master
        self.label_fg = 'white'
        self.label_bg = '#692e3b'
        self.config(bg='#632e69')
        self.pack(expand=True, fill='both')
        self.BookId = StringVar()  # to store the book id value
        self.Book = None
        self.refresh_widgets = []  # a list containing those widgets who needs to destroy before refresh master widgets.

        # heading for the Deletion interface\
        self.heading = Label(self, text="Delete A Book Entry", font="arial 20 bold", bg='#632e69', fg='white')
        self.heading.pack(side='top')

        # Now we will make a label and entry To get the detail of the Book
        self.BookId_Label = Label(self, text="Book Id: ", font="font 12 bold", bg=self.label_bg, fg=self.label_fg)
        self.BookId_Label.place(x=100, y=100)

        self.BookId_Entry = Entry(self, textvariable=self.BookId, font='font 12')
        self.BookId_Entry.place(x=200, y=100)

        self.Search_Button = Button(self, text="Search", font='arial 9', command=self.search_entry)
        self.Search_Button.place(x=450, y=100)

        self.Cancel_Button = Button(self, text="Cancel", font='arial 12', command=self.cancel)
        self.Cancel_Button.place(x=180, y=500)

        self.Delete_Button = Button(self, text="Delete", font='arial 12', state='disabled', command=self.delete_entry)
        self.Delete_Button.place(x=350, y=500)

    def search_entry(self):

        self.Book = self.Database.get_book_instance('libdata', 'books', 'BOOK_ID', self.BookId.get())

        if self.refresh_widgets:
            for wid in self.refresh_widgets:
                wid.destroy()
            self.Delete_Button.config(state="disabled")

        self.update()  # after deleting the recent widget we will update the application

        if self.Book != -1:
            BookFrame = BookDetails(master=self, BookData=self.Book)
            BookFrame.place(x=100, y=150)
            self.refresh_widgets.append(BookFrame)
            self.Delete_Button.config(state="normal")
        else:
            err_label = Label(self, text=f"There is no entry with Book Id : {self.BookId.get()}",
                              bg=self.label_bg, fg='red')
            err_label.place(x=100, y=450)
            self.refresh_widgets.append(err_label)

    def cancel(self):
        self.master.destroy()

    def delete_entry(self):
        try:
            self.Database.delete_entry('libdata', 'books', where=(f"BOOK_ID = '{self.BookId.get()}'",))
            success_label = Label(self, text="Book Entry Deleted SuccessFully", font='arial 12 bold',
                              bg=self.label_bg, fg=self.label_fg)
            success_label.place(x=100, y=400)
            self.refresh_widgets.append(success_label)
        except:
            err_label = Label(self, text="Unable to delete Book entry", font='arial 12 bold',
                  bg=self.label_bg, fg=self.label_fg)
            err_label.place(x=100, y=400)
            self.refresh_widgets.append(err_label)

# ========================================================================================================== #
# ========================================================================================================== #


class BookDetails(Frame):

    def __init__(self, master=None, BookData=None):
        Frame.__init__(self, master=master)
        self.config(bg='#2e4069', width=400, height=300)
        self.Book = BookData
        self.x1 = 10
        self.y1 = 10
        self.x2 = 100
        self.y2 = 10
        # Now place some label on the
        for pair in self.Book.get_dict().items():
            key, value = pair
            if value is not None:
                Label(self, text=f"{key}: ", font="arial 15 bold", bg='#2e4069', fg='white').place(x=self.x1, y=self.y1)
                Label(self, text=f"{value}", font="arial 15 bold", bg='#2e4069', fg='white').place(x=self.x2, y=self.y2)
                self.y1 += 30
                self.y2 += 30


