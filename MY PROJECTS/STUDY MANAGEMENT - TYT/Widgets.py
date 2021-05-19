
# in this section we will make a small widget object which will be used in our application.
from tkinter import Tk, Frame, Label ,Button
from tkinter import ttk
class Widgets:

    def __init__(self, master = None):


        # now we need to define the master property
        # but in this case the master can be a frame of a root winodw.
        # but for now we will make some widget supposing that they will be put in a root window.
        pass

    class Create_ProgressBar(Frame):

        def __init__(self, master=None):

            super().__init__(master)
            self.style = ttk.Style()
            # Now here we need to define the master window property if needed.
            # and also here we will initiate some progressbar property.
            self.progress_after_id = None

        def progressbar(self,master,suffix='Progress' , prefix = 'Completed', increment=1 , length = 150 , theme = None):

            # now here we need to define the Frame , Label and a Progressbar.

            Progress_Frame = Frame(master, height = 5, width = 250)
            Progress_Frame.pack(side = 'right', anchor='e', padx = 10)


            # now in this frame we need to put some Label and a Progress bar
            # Note that we need to put the label and progress bar in order
            suffix_label = Label(Progress_Frame, text = suffix)
            Progress_Bar = ttk.Progressbar(Progress_Frame, length = length  )
            prefix_label = Label(Progress_Frame)

            suffix_label.pack(side = 'left', anchor='n')
            Progress_Bar.pack(side = 'left', anchor='n')
            prefix_label.pack(side = 'left', anchor='n')

            # Now we need to make a function to update the progress bar
            def update_progress():
                # this function will be run by a .after function.
                # Now here we need to add some increment value in the Progress_Bar['value']

                Progress_Bar['value'] += increment
                a = Progress_Bar['value']

                # Now we need to show this increment in the prefix label
                prefix_label.config(text = f"{a:.2f} " + prefix) # this formatting is to show two digits after decimal point.
                # now we need to make a .after() loop

                if a >= 100:
                    # then it means we have reached to 100% Now we need to stop the .after() loop
                    prefix_label.after_cancel(self.progress_after_id)

                else:
                    # Note: to track the .after() id we need to make a class instace.
                    self.progress_after_id  = prefix_label.after(1000,update_progress)
                    # Now this will update the progress bar in every seconds.


            update_progress()


    class Create_Notebook(Frame):

        def __init__(self, master = None):

            super().__init__(master)

        def Notebook(self,master, height, width , tabposition = 'wn'):
            """
            This function will be used to make a note book object.
            :param master: This Notebook will be place in this master.
            :return: NOne.
            """
            mygreen = "#3e4c63"
            white = "white"

            style = ttk.Style()

            style.theme_create("NewNotebook", parent="default", settings={
                "TNotebook": {"configure": {"tabmargins": [2, 5, 2, 0] , 'tabposition':'wn' , 'background':'#3e4c63'}  },

                "TNotebook.Tab": {
                    "configure": {"padding": [15, 15], "background": mygreen, 'font': ('sarif', 10, 'bold'),
                                  'foreground': 'blue'},
                    "map": {"background": [("selected", '#7d7f82')],
                            "expand": [("selected", [2, 1, 1, 0])]}}})

            style.theme_use("NewNotebook")


            #style = ttk.Style()

            #style.configure('Tracks.TNotebook', tabposition = tabposition, background='#3e4c63', tabmargins = (20,20,20,0))
            self.notebook = ttk.Notebook(master, height=height, width=width )
            self.notebook.pack(fill = 'both', expand=True)
            return self.notebook


        def Add_Tab(self,addInstance=None, sep=None , tabName = 'tab'):
            """
            This method will be used to add new tabs in the
            :param sep:
            :return:
            """
            self.notebook.add(addInstance , text = tabName)
            if sep != None:
                gap = ttk.Separator(self.notebook)
                self.notebook.add(gap, text='gap')



    class Create_Track_Record_Database(Frame):

        def __init__(self):
            super().__init__()

            self.Track_Record_Container = None
            self.Heading_Frame = dict()

        def Track_Record_Label(self, master=None, head=None, data=None, height=600, width=600):
            """
            This will be small frame in which we will display all the available target. In this we will make a new frame
                and in this frame we will put the some more frames like heading and the data.
            :return:
            """

            # first of all we need to make a new frame for all other frames.
            # Container Frame.
            self.Track_Record_Container = Frame(master, width=height, height=width, bg='red')
            self.Track_Record_Container.pack(fill='both', expand=1)
            self.Track_Record_Container.pack_propagate(False)

            # Now to put all the values of data row we need a loop. Now we will use this

            if data != None and head != None:

                # Heading frame.
                pass

                # after making the heading we need to set the

            else:
                # if we don't have data then we don't need to do any thing.
                print("No data Found.")


        def Create_Track_Row(self, master, frame, data):
            """
            This function will be used to create a frame in which we will put some labels and in those labels we will put some data.
            :param master: This is the master in which we will put our container frame,
            :param frame: This is the container frame which will be placed in the master window and in this we will make our rows.
            :param data: this is the data or row which will be placed in the row frame. it can be heading or data.
            :return: None
            """
            Heading_Frame = Frame(self.Track_Record_Container, height=10, bg='white')
            Heading_Frame.pack(fill='x', expand=1)

            # now we need to put the heading frame in this dict to track the record.
            self.Heading_Frame['Frame'] = Heading_Frame

            # NOw we need a function which will put all the values in the row.
            def put_heading():
                # This function will be used to put all heading columns
                row = []
                for i,value in enumerate(data): # here data is the heading row.
                    # now we need to make some temp label and those labels will be put the frame using the grid layout system
                    temp_label = Label(Heading_Frame, text = value )
                    temp_label.grid(row = 0 , column = i )
                    temp_label.grid_columnconfigure(index=i) # configure the width of the column.
                    row.append(temp_label)

                # Now after making row labels and appending them in the row variable we need to put this into the self.Heading_Frame.
                self.Heading_Frame['row'] = row

            def put_data():
                # Now this function will be used to put the data in the row of data
                # This will contain many things.
                # Possible columns:Date,Time,Name,Topic,SubTopic,CompletionBar,CompletedHour,TargetTime,ExpandTime.
                pass



