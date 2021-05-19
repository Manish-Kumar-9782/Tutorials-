
# in this section we will make a small widget object which will be used in our application.
from tkinter import Tk, Frame, Label ,Button , StringVar , Spinbox
from tkinter import ttk
class Widgets:

    def __init__(self, master = None):


        # now we need to define the master property
        # but in this case the master can be a frame of a root winodw.
        # but for now we will make some widget supposing that they will be put in a root window.
        pass

    def Time_Frame(self, master, f_cfg=None, s_cfg=None, sp_cfg = None):
        """
        This method will be used to make Time Frame which will show us a Hour, Min, Sec input section. it will use Spinbox as input of time.
        :param master: This will be master frame or window in which this frame will be placed.
        :param f_cfg: frame  configuration setting dictionary.
        :param s_cfg: Spinbox configuration setting dictionary.
        :param s_cfg: Spinbox pack configuration setting dictionary.
        :return: tuple, it will return a tuple of Spinbox variable.
        """
        Main_Frame = Frame(master, width = 50, height = 20)
        Main_Frame.update_idletasks()

        # Now in this frame we need to put hour, min, sec Spinbox
        self.Hr_var, self.Min_var, self.Sec_var = StringVar(), StringVar(), StringVar()

        Hour_entry = Spinbox(Main_Frame, text = f'00', width = 3 , from_ = 0, to = 1000, textvariable = self.Hr_var,  format = '%03.0f')
        Hour_entry.pack(side='left' , anchor='nw')

        dash1 = Label(Main_Frame, text = ":" , bg = master.cget('bg'))
        dash1.pack(side='left', anchor='nw')

        Min_entry = Spinbox(Main_Frame, text = f'00', width = 2, from_ = 0, to = 60, textvariable = self.Min_var,  format = '%02.0f')
        Min_entry.pack(side='left' , anchor='nw')

        dash2 = Label(Main_Frame, text=":", bg = master.cget('bg') )
        dash2.pack(side='left' , anchor='nw')

        Sec_entry = Spinbox(Main_Frame, text = f'00', width = 2, from_ = 0, to = 60, textvariable = self.Sec_var,  format = '%02.0f')
        Sec_entry.pack(side='left' , anchor='nw')

        if s_cfg:
            Hour_entry.config(cnf=s_cfg)
            Min_entry.config(cnf=s_cfg)
            Sec_entry.config(cnf=s_cfg)
            dash1.config(font=s_cfg['font'] , fg= Hour_entry.cget('bg'))
            dash2.config(font=s_cfg['font'], fg= Hour_entry.cget('bg'))

        if sp_cfg:
            Hour_entry.pack_configure(cnf=sp_cfg)
            Min_entry.pack_configure(cnf=sp_cfg)
            Sec_entry.pack_configure(cnf=sp_cfg)

        if f_cfg:
            Main_Frame.config(cnf = f_cfg)

        return Main_Frame




    class Create_ProgressBar(Frame):

        def __init__(self, master=None):

            super().__init__(master)
            self.style = ttk.Style()
            # Now here we need to define the master window property if needed.
            # and also here we will initiate some progressbar property.
            self.progress_after_id = None

        def progressbar(self,master,suffix='Progress' , prefix = 'Completed', increment=1 , length = 150 , theme = None):

            # now here we need to define the Frame , Label and a Progressbar.

            self.Progress_Frame = Frame(master, height = 5, width = 250)
            #Progress_Frame.pack(side = 'right', anchor='e', padx = 10)


            # now in this frame we need to put some Label and a Progress bar
            # Note that we need to put the label and progress bar in order
            suffix_label = Label(self.Progress_Frame, text = suffix)
            Progress_Bar = ttk.Progressbar(self.Progress_Frame, length = length  )
            prefix_label = Label(self.Progress_Frame)

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

            return self.Progress_Frame

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


    class Track_Card(Frame):

        def __init__(self, master= None):

            super().__init__(master)
            self.TypeName = None
            self.Name = None
            self.id = None # id will be a key for every root object of the card.
            self.class_ids = dict()

        def Create_Track_Record_Card(self, master, frame=None, data=None):
            """
            This function will be used to create a frame in which we will put some labels and in those labels we will put some data.
            :param master: This is the master in which we will put our container frame,
            :param frame: This is the container frame which will be placed in the master window and in this we will make our rows.
            :param data: this is the data or row which will be placed in the row frame. data will be in json format.
            :return: None
            """

            # so what will it contain
            # id, TypeName, cardName,Subcard,completed, Thour, EndDate.
            # And also it will have a add button to add subcards.
            Data = {"001":{"TypeName":"Project",
                           "Name":"TM-TYT",
                           "Date":"current",
                           "Time":'current',
                           "Topic":[], # Not in this topic we need a list.
                           "Completed":80,
                           "Thour":100,
                           "EndDate":"tomorrow"}
                    }

            self.Root_Card_Frame = Frame(master, width = 800, height = 30, bg = '#7d7f82')
            self.Root_Card_Frame.pack(fill='x', expand=1, anchor='n', padx=50)
            self.Root_Card_Frame.pack_propagate(False)

            self.head_frame = Frame(self.Root_Card_Frame, width = 800, height = 30, bg = '#f06d22')
            self.head_frame.pack(side = 'top',anchor ='n',fill ='x')

            self.content_frame = Frame(self.Root_Card_Frame, width = 800, height = 0, bg = '#f52ceb')
            self.content_frame.pack(side = 'top',anchor='n',fill ='both')
            #self.content_frame.pack_propagate(False)

            # Now we need to Project labels on the Root card.
            Type_label = Label(self.head_frame, text = 'Project')
            Type_label.pack(side = 'left', anchor = 'nw')

            Name_label = Label(self.head_frame, text ="TM-TYT")
            Name_label.pack(side ='left', anchor = 'nw', padx = 5)

            # Now need to make completed, Thour, EndDate and AddButton
            # Note in completed we need a progress bar also
            bar = Widgets.Create_ProgressBar(self.head_frame)
            CompletedBar = bar.progressbar(self.head_frame,suffix="", prefix="")
            Thour_label = Label(self.head_frame, text = 'Thour')
            EndDate_label = Label(self.head_frame, text ='31-May-2021')
            AddButton = Button(self.head_frame, text = '+', font = ('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(50, 0))



            # Now we need to configure the AddButton
            def add_subcard(button):
                print("add record button pressed")
                one_card_height = 70
                current_height = self.Root_Card_Frame.cget('height')
                self.Root_Card_Frame.config(height = current_height + one_card_height)
                self.Create_Track_Record_Sub_Card(self.content_frame)
                self.Root_Card_Frame.update_idletasks()
                Data['001']['Topic'].append(self.content_frame)
                self.class_ids[]
                print(Data)
                print(button)

            AddButton.config(command = lambda x=AddButton: add_subcard(x))

        def Create_Track_Record_Sub_Card(self,master,height= None, width = None,f_cfg = None):
            """
            This Method will be used to create a frame in the
            :param master: This will the master in which it will be displayed.
            :param height: height of the SubCard.
            :param width:width of the SubCard.
            :param f_cfg: f_cfg is the frame configuration dictionary.
            :return: This will not return any thing.
            """
            Data = {"Card1": {"Name": "Create Add Track Record Function",
                            "Date": "current",
                            "Time": 'current',
                            "Topic": ["SubCard1", "SubCard2", "SubCard3", "SubCard4"],  # Not in this topic we need a list.
                            "Completed": 80,
                            "Thour": 100,
                            "EndDate": "tomorrow"}
                    }

            Subcard = Frame(master, width=800, height=50, bg='white', highlightbackground = '#6f1787', highlightcolor = '#6f1787'
                               ,highlightthicknes = 2)
            Subcard.pack(fill='x', expand=1, anchor='n', pady=10, side='top', padx = (10,0))
            #self.Subcard.pack_propagate(False)
            Subcard.update_idletasks()

            SubHead = Frame(Subcard, width=800, height=20, bg='green')
            SubHead.pack(fill='x', expand=True, anchor = 'n', side = 'top')

            SubContent = Frame(Subcard, width=800, height=0, bg='#2885b8')
            SubContent.pack(fill='both', expand=True,  anchor = 'n', side ='top', pady = (0,10))
            # Now we need to Project labels on the Root card.

            Name_label = Label(SubHead, text="Create Add Track Record Function")
            Name_label.pack(side='left', anchor='nw', padx=5)

            # Now need to make completed, Thour, EndDate and AddButton
            # Note in completed we need a progress bar also
            bar = Widgets.Create_ProgressBar(SubHead)
            CompletedBar = bar.progressbar(SubHead, suffix="", prefix="")
            Thour_label = Label(SubHead, text='Thour')
            EndDate_label = Label(SubHead, text='31-May-2021')
            AddButton = Button(SubHead, text='+', font=('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(50, 0))

            def add_subcard(button):
                print("add record button pressed")
                one_card_height = 80
                sub_current_height = Subcard.cget('height')
                root_current_height = self.Root_Card_Frame.cget('height')
                SubContent.config(height = sub_current_height + one_card_height)
                self.Root_Card_Frame.config(height = root_current_height + 70)
                self.Create_Track_Record_Sub_Card(SubContent)
                SubContent.update_idletasks()

                print(button)
            # Now we need to track every new sub card with the help of the button.
            AddButton.config(command = lambda x=AddButton: add_subcard(x))


        def SaveCard(self, data,subcard = False):
            """
            This function will be used to save the card detail in json format. if the card is root then will save a with typname and id.
                but if the card is subcard then it will be saved inside the existing card.
            :param data: This is the data which will saved in json format.
            :param subcard: If it is true then we will save the card in the existing card.
            :return: None.
            """



