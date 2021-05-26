
# in this section we will make a small widget object which will be used in our application.
from tkinter import Tk, Frame, Label ,Button , StringVar , Spinbox, Toplevel, Entry, OptionMenu
from tkinter import ttk
import time
import Apps_func as apps
import calendar

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

    class Date_Frame(Frame):

        def __int__(self, master = None):

            super().__init__(master)
            self.Date_update_id = None
            self.Date = None

        def Date_Frame(self, master, Style = None ):
            """
            This function will be used to create a date frame by using optionMenu and Entry widget
            :param master: This is the master in which we will put our Set time frame.
            :return: Date, this will return the date in the form of string.
            """
            cal = calendar.Calendar()
            wid = apps.Time()

            Main_Frame = Frame(master)
            #Main_Frame.pack()

            # Now in this we need to put three entries and Optionmenu alternatively
            date_var = StringVar()
            month_var = StringVar()
            year_var = StringVar()

            self.date_options = [i for i in range(1, 32)]
            self.month_options = [i for i in calendar.month_name][1:]
            self.year_options = [i for i in range(1980, 2031)]

            date_var.set('1')
            month_var.set(self.month_options[0])
            year_var.set('2021')

            # Date
            date_option = ttk.Combobox(Main_Frame, values=self.date_options, textvariable=date_var, width = 3, style = Style)
            date_option.pack(side='left', anchor='w', padx=15)

            #Month
            month_option = ttk.Combobox(Main_Frame, values=self.month_options, textvariable=month_var, width = 10,style = Style)
            month_option.pack(side='left', anchor='w', padx=10)

            # Year
            year_option = ttk.Combobox(Main_Frame, values=self.year_options, textvariable=year_var, width = 5,style = Style)
            year_option.pack(side='left', anchor='w')

            # Now we need to update the year,month and date to get the accurate detail/date of the month of the year.


            def update_dates():

                # This method will be used to update the date after selecting the date.
                # Now after updating year and months we need to update the dates of the month of the year.
                # print("selected:",month,year)
                self.date_options = [i for i in cal.itermonthdays(int(year_var.get()), wid.get_month_number(month_var.get())) if i != 0]
                date_option.config(values=self.date_options)

                # This self.Date_update_id will will be used to stop this loop when the DateFrame object is created.
                self.Date_update_id = Main_Frame.after(500, update_dates)
                # this id will be stopped by using the Main_Frame.after_cancel() method.

                # Now we need to update the end date which will be stored in the DateFrame class instance.
                self.Date = f"{date_var.get()}-{month_var.get()}-{year_var.get()}"


            update_dates()

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

        """
        This class will be used to Root Track Card and SubTrack Cards widgets/Frames and those widgets/Frames can be put
            in any application.
        """
        Tracks_Cards_Mapping = {}

        def __init__(self, master= None):
            self.TCD = apps.Tracks_Cards()
            self.Tracks_Cards_Database = self.TCD.Read_Cards_Database(fileName="./Data/temp")
            self.Tracks_Cards_Frames = {}
            super().__init__(master)
            self.TypeName = None
            self.Name = None
            #self.id = None # id will be a key for every root object of the card.
            self.class_ids = dict()
            self.Cards = None
            self.NextParentTopic = None # Not using
            self.Selected_Root = None # Not using , This can be useful to Handle the currently selected Root Card
            self.SubDictData  = None  # This will be used during adding a new data and this will store the sub card data information.
            self.App_Cards = apps.Tracks_Cards()

            # Sub card Details
            self.SubCard_Parent = None
            self.SubCard_Name = None
            self.SubCard_FullName = None
            self.Tcards = apps.Tracks_Cards()

            # Save location
            self.Save_location = './Data'  # some files will be saved according to the current date of working.

        def Create_Track_Record_Card(self, master,CardName,frame=None, data=None, use='create'):
            """
            This function will be used to create a frame in which we will put some labels and in those labels we will put some data.
            :param master: This is the master in which we will put our container frame,
            :param frame: This is the container frame which will be placed in the master window and in this we will make our rows.
            :param data: this is the data or row which will be placed in the row frame. data will be in json format.
            :return: None
            """
            #parent_topic = "TM-TYT"
            print("Inside the Create Track Record.")
            # here we will get the data and we will retrieve some important information for next cards.
            # so what will it contain
            # id, TypeName, cardName,Subcard,completed, Thour, EndDate.
            # And also it will have a add button to add subcards.

            # Now form data we will retrieve some information which will be displayed on the track cards
            '''Like: Card Name, Card title, Card progress, card target hour, card parent , card child.
            '''
            Data = data
            if use == 'create':
                Data = data['Root']
                Data = Data[CardName] # to get
            elif use == 'retrieve':
                Data = data
            else:
                print("unknown key error")


            self.Root_Card_Frame = Frame(master, width = 800, height = 30, bg = '#7d7f82')
            self.Root_Card_Frame.pack(fill='x', expand=1, anchor='n', padx=50)
            self.Root_Card_Frame.pack_propagate(True)

            self.head_frame = Frame(self.Root_Card_Frame, width = 800, height = 30, bg = '#f06d22')
            self.head_frame.pack(side = 'top',anchor ='n',fill ='x')

            self.content_frame = Frame(self.Root_Card_Frame, width = 800, height = 0, bg = '#f52ceb')
            self.content_frame.pack(side = 'top',anchor='n',fill ='both')
            #self.content_frame.pack_propagate(False)

            # Now we need to Project labels on the Root card.
            Type_label = Label(self.head_frame, text = Data['Type'])
            Type_label.pack(side = 'left', anchor = 'nw')

            Name_label = Label(self.head_frame, text =Data['Name'])
            Name_label.pack(side ='left', anchor = 'nw', padx = 5)

            # Now need to make completed, Thour, EndDate and AddButton
            # Note in completed we need a progress bar also
            bar = Widgets.Create_ProgressBar(self.head_frame)
            CompletedBar = bar.progressbar(self.head_frame,suffix="", prefix="")
            Thour_label = Label(self.head_frame, text = Data['Target Hour'])
            EndDate_label = Label(self.head_frame, text =Data['EndDate'])
            AddButton = Button(self.head_frame, text = '+', font = ('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(50, 0))

            # Now here we need to map the Parent name with the button Tracks_Card_Mapping
            self.Tracks_Cards_Mapping[AddButton] = "Root." +CardName
            self.Tracks_Cards_Frames.update({Data['FullPath']:self.content_frame})
            # Now we need to configure the AddButton
            def add_subcard(button):
                #print("add record button pressed")
                # Ok so when we press the button then we need to ask for new record data.
                # New record or sub record also need a Parent Name, its own Name (card name)
                root = Toplevel()

                # When we press the Add SubCard button then it wil make a top level window
                # and it will call the self.Add_SubRecord
                self.Add_SubRecord(root, Parent = self.Tracks_Cards_Mapping[button])
                self.Root_Card_Frame.wait_window(root)
                print(button)

                #Data.update(self.SubDictData) # This self.SubDictData Contains the SubCard information.
                print("Subcard Detail using self.SubDictData: ",self.SubDictData,)
                self.Cards = Data
                one_card_height = 70


                current_height = self.Root_Card_Frame.cget('height')

                self.Root_Card_Frame.config(height = current_height + one_card_height)

                self.Create_Track_Record_Sub_Card(self.content_frame,
                                                  Parent=self.SubCard_Parent,
                                                  CardName = self.SubCard_Name,
                                                  FullName = self.SubCard_FullName, Data = self.SubDictData)

                self.Root_Card_Frame.update_idletasks()
                #print(Data)
            AddButton.config(command =lambda x=AddButton:add_subcard(x))

        def Create_Track_Record_Sub_Card(self,master,Parent=None, CardName = None, FullName = None ,Data = None, use ='create',
                                         height= None, width = None,f_cfg = None):
            """
            This Method will be used to create a frame in the
            :param master: This will the master in which it will be displayed.
            :param height: height of the SubCard.
            :param width:width of the SubCard.
            :param f_cfg: f_cfg is the frame configuration dictionary.
            :return: This will not return any thing.
            """

            if use == 'create':
                Data = Data[CardName]
            elif use == 'retrieve':
                pass
            else:
                print("wrong keyword")

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

            Name_label = Label(SubHead, text=CardName)
            Name_label.pack(side='left', anchor='nw', padx=5)

            # Now need to make completed, Thour, EndDate and AddButton
            # Note in completed we need a progress bar also
            # We also need to define all the Labels with their Associted data from the incoming Data
            # which coming from the Add_SubCard method.
            bar = Widgets.Create_ProgressBar(SubHead)
            CompletedBar = bar.progressbar(SubHead, suffix="", prefix="")
            Thour_label = Label(SubHead, text=Data['Target Hour'])
            EndDate_label = Label(SubHead, text=Data['EndDate'])
            AddButton = Button(SubHead, text='+', font=('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(50, 0))

            # Now here we need to add the SubCard Full Name in the global Tracks_Card_Mapping dictionary
            self.Tracks_Cards_Mapping[AddButton] = FullName
            self.Tracks_Cards_Frames.update({Data['FullPath']: SubContent})

            def add_subcard(button):
                # This method will be called from a subcard button
                print("add record button pressed")
                one_card_height = 80
                sub_current_height = Subcard.cget('height') # height of the sub card
                root_current_height = self.Root_Card_Frame.cget('height') # height of Root card

                SubContent.config(height = sub_current_height + one_card_height)

                self.Root_Card_Frame.config(height = root_current_height + 70)

                # Now here after increasing the height of the subcard we need to call Add_SubCard function
                # This Add_SubCard metod need a top level window
                root = Toplevel()
                self.Add_SubRecord(root, self.Tracks_Cards_Mapping[button])
                # Parent = self.Tracks_Cards_Mapping[button]
                # Tracks_Cards_Mapping stores all the Card full name and map them to the button id.
                # Now when we will press the button then it will pick the full name of the selected Subcard Full name.
                Subcard.wait_window(root) # this will wait window until end of the Add_SubCard process

                # Now we need to access self.SubDictData , which will be updated by the Add_SubCard method.
                # also self.SubDictData will update
                # self.SubCard_Parent , self.SubCard_Name, self.SubCard_FullName

                # Now we need to call the self.Create_Track_Record_Sub_Card
                # ok now tis Add_SubCard will update our self.
                self.Create_Track_Record_Sub_Card(SubContent, Parent=self.SubCard_Parent, CardName=self.SubCard_Name,
                                                  FullName=self.SubCard_FullName, Data =self.SubDictData )
                SubContent.update_idletasks()

                # Now we need to save the Data
                self.Tcards.SaveCard(CardName=self.SubCard_Name, Parent=self.SubCard_Parent ,
                                     Database=self.Tracks_Cards_Database, Subcard=self.SubDictData,
                                     FullName=self.SubCard_FullName)

            # Now we need to track every new sub card with the help of the button.
            AddButton.config(command = lambda x=AddButton: add_subcard(x))
            # This button will be placed on the Subcard.


        def Retrieve_Cards(self,master,Database):
            """
            This method will be used to retrieve all the cards data from the local storage and pack them on the frame.
            :param master: This is the master in which all the cards are placed.
            :param Database:  This is the database of the data , in this database we have all cards information.
            :return: None
            """
            for key , card in self.Tcards.Retrieve_Cards(Database):
                # Now we are getting all the availabel card insidea database.

                if key != "Root":
                    # we are ignoring the initial Root,
                    if key != "Topic":
                        # since we will get a same card twice, one in Topic and one card itself
                        # in topic we will get all the sub card available that we don't want but the single card will be got
                        # if we ignore the Topic data,
                        # Now we are getting individual cards, but still we need to differentiate that which card is Root Card and
                        # which one is child/SubCard, This can be done by accessing the Parent of the Card
                        if card['Parent'] == 'Root':
                            # if this condition satisfy then it means this is a Root card
                            name = card['Name']
                            parent = card['FullPath']
                            print('Root card parent name:', parent)
                            self.Create_Track_Record_Card(master, name, data=card, use='retrieve')

                        else:
                            # if Card is not a root card then it is a child/SubCard.
                            name = card['Name']
                            parent = card['Parent']
                            fullpath = card['FullPath']
                            parent_frame = self.Tracks_Cards_Frames.get(parent, None)

                            # print("child Card info:")
                            # print("Child Card Name: ", name)
                            # print("child Card parent:", parent)
                            # print("Child Card frame:", parent_frame)
                            # print("Child Card own frame:", fullpath)

                            self.Create_Track_Record_Sub_Card(master=parent_frame, Parent=parent, CardName=name,
                                                               FullName=fullpath, Data=card, use='retrieve')
            # after getting all the things done we will update the our display.
            master.update()


        def Add_SubRecord(self, master,Parent,Child=None):
            """
            This will be small top level application which will be used to add a new sub record which will be displayed on the Track Section.
            :param master: This will be the master/root window on which this application will be placed.
            :param Parent: This is the Parent of the Child , This Child widget will be placed inside this Parent section.
            :param Child: This is the child or SubCard which will be created by executing this method.This Child name Can be given by user Entry in this application.
            :return: None
            """
            ts = apps.Time()
            wid = Widgets()
            Current_Date = ts.get_current_data()
            Current_Time = ts.get_current_time()
            l_cfg = {'bg': 'green', 'fg': 'white', 'font': ('sarif', 10, 'bold')}
            e_cfg = {'bg': "white", 'fg': 'blue', 'highlightbackground': 'black', 'highlightcolor': 'black',
                     'highlightthickness': 2, 'relief': 'flat', 'width': 30}

            # Now we need to make the applicaton layout.
            Main_Frame = Frame(master, width=350, height=220, bg='green')
            Main_Frame.pack()
            Main_Frame.pack_propagate(False)
            Main_Frame.grid_propagate(False)
            Main_Frame.update_idletasks()

            l_cfg['bg'] = Main_Frame.cget('bg')

            if master.winfo_class() == 'Tk' or master.winfo_class == 'Toplevel':
                # here if we get master as a toplevel or root window then we will set the size of the window.
                h = Main_Frame.cget('height')
                w = Main_Frame.cget('width')
                print(h, w)
                master.geometry(f"{w}x{h}")
                master.update_idletasks()

            # Now we need to make the Entries and labels.
            Parent_label = Label(Main_Frame, text = "Parent", cnf=l_cfg)
            Parent_Name = Label(Main_Frame, text = Parent, cnf=l_cfg)

            # Now we need to do put other things.

            # Topic / This will be the name of the child card.
            SubCard_label = Label(Main_Frame, text='SubCard Name', cnf=l_cfg)
            SubCard_entry = Entry(Main_Frame, cnf=e_cfg)


            # Target houre
            # Now we need a frame to put three spinbox for time
            s_cfg = {'font': ('sarif', 15, 'bold')
                     }
            sp_cfg = {'padx': 6}
            f_cfg = {'bg': Main_Frame.cget('bg')}

            TargetHour_Frame_entry = wid.Time_Frame(Main_Frame, s_cfg=s_cfg, sp_cfg=sp_cfg, f_cfg=f_cfg)
            TargetHour_Frame_label = Label(Main_Frame, text='Target Hour', cnf=l_cfg)

            # Now we need to make a End Date Frame
            wid2 = Widgets.Date_Frame()
            Date_Frame_Label = Label(Main_Frame, text='End Date:', cnf=l_cfg)
            Date_Frame_Entry = wid2.Date_Frame(Main_Frame)
            Date_Frame_Entry.config(bg= Main_Frame.cget('bg')) # To change the Main Frame background of the Date_Frame_Entry object

            c_pady = 10
            c_padx = 10
            # Now we need to put all thing using the grid system layout.
            Parent_label.grid(row=0, column=0, pady=c_pady, padx=c_padx, sticky='e')
            Parent_Name.grid(row=0, column=1, pady=c_pady, padx=c_padx)


            SubCard_label.grid(row=2, column=0, pady=c_pady, padx=c_padx, sticky='e')
            SubCard_entry.grid(row=2, column=1, pady=c_pady, padx=c_padx)

            TargetHour_Frame_label.grid(row=4, column=0, pady=c_pady, padx=c_padx, sticky='e')
            TargetHour_Frame_entry.grid(row=4, column=1, pady=c_pady, padx=c_padx)

            Date_Frame_Label.grid(row=5, column=0, pady=c_pady, padx=c_padx, sticky='e')
            Date_Frame_Entry.grid(row=5, column=1, pady=c_pady, padx=c_padx)

            # Now finally we need to make a button ti submit the and save the data.
            Set_button = Button(Main_Frame, text='Set', width=10)
            Set_button.place(x=130, y=180)

            # Now we will set a function for this set_button in this we will save our data in a file.
            data_dict = dict()
            def save_data(button):
                print(f"{'_'*30}")
                #print("Save data Button:",button)
                # Note that subtopic can be manipulated by a Subtopic_frame object.
                # subtopic_frame object will contain the subtopics
                Hr_var, Min_var, Sec_var = wid.Hr_var.get(), wid.Min_var.get(), wid.Sec_var.get()
                # These time values are taken from the Time_Frame function which is defined in the Widgets class.

                SubCardData = {SubCard_entry.get(): {'Name': SubCard_entry.get(),
                                               'Date':Current_Date,
                                               'Time':Current_Time,
                                               'Topic': {},
                                               'Target Hour': f"{Hr_var}:{Min_var}:{Sec_var}",
                                               'EndDate': wid2.Date,  # here we need to pass a end date of the
                                               'Progress': 0,
                                               'Parent': Parent,
                                               'FullPath':'.'.join([Parent,SubCard_entry.get()]),
                                               'Childs': 0}}

                #data_dict['FullName'] = ".".join([Parent,data_dict['Topic']])
                # defining the Subcard detail
                self.SubCard_Parent = Parent
                print("Sub card Parent in widgets.Create_Tracks.Add_SubCard: ",self.SubCard_Parent)
                self.SubCard_Name = SubCard_entry.get()
                self.SubCard_FullName = '.'.join([Parent,SubCard_entry.get()])

                self.NextParentTopic = SubCardData[self.SubCard_Name]
                self.SubDictData = SubCardData
                print("self.SubDictData =>",self.SubDictData)
                # Now after Sucessfully save and create a new NTR Card we need to close this root window
                # Now after saving the data we need to retrieve the data
                save = apps.Tracks_Cards()
                save.SaveCard(CardName=self.SubCard_Name,Parent = Parent, Database=self.Tracks_Cards_Database,
                              Subcard=SubCardData, FullName=self.SubCard_FullName)
                master.destroy()
                #print(".".join([parent_topic,data_dict['Topic']]))
                print(f"{'_' * 30}")
            Set_button.config(command= lambda x=Set_button:save_data(x))
