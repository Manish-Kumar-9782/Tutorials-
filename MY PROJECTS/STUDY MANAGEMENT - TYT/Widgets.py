# in this section we will make a small widget object which will be used in our application.
from tkinter import Tk, Frame, Label, Button, StringVar, IntVar, Spinbox, Toplevel, Entry, Text
from tkinter import ttk
from random import randint
import time, json
import Apps_func as apps
import calendar

apps_func_keep_card = apps.Keep_Cards()


class Misc:

    def __init__(self):
        pass

    def get_keep_card_position(self, KCL, columns=3):
        """
        This method will be used to define the position for new widget.
        :param KCL: Keep_Card_List we will hold all the Cards.
        :return: tuple, it will return new position.
        """
        row = 0
        col = 0
        poslist = []
        print("length of KCL: ", len(KCL))
        newest = None
        if len(KCL) > 0:
            for cp in range(len(KCL)):
                # print("length of cp: ",cp)
                cp += 1  # card position.
                # print("length of cp: ", cp)
                poslist.append((row, col))
                if cp % columns == 0:
                    row += 1
                    col = 0
                else:
                    col += 1

            newest = poslist[-1]
        return poslist, newest


misc = Misc()


class Widgets:

    def __init__(self, master=None):

        # now we need to define the master property
        # but in this case the master can be a frame of a root winodw.
        # but for now we will make some widget supposing that they will be put in a root window.

        pass

    def Time_Frame(self, master, f_cfg=None, s_cfg=None, sp_cfg=None):
        """
        This method will be used to make Time Frame which will show us a Hour, Min, Sec input section. it will use Spinbox as input of time.
        :param master: This will be master frame or window in which this frame will be placed.
        :param f_cfg: frame  configuration setting dictionary.
        :param s_cfg: Spinbox configuration setting dictionary.
        :param s_cfg: Spinbox pack configuration setting dictionary.
        :return: tuple, it will return a tuple of Spinbox variable.
        """
        Main_Frame = Frame(master, width=50, height=20)
        Main_Frame.update_idletasks()

        # Now in this frame we need to put hour, min, sec Spinbox
        self.Hr_var, self.Min_var, self.Sec_var = StringVar(), StringVar(), StringVar()

        Hour_entry = Spinbox(Main_Frame, text=f'00', width=3, from_=0, to=1000, textvariable=self.Hr_var,
                             format='%03.0f')
        Hour_entry.pack(side='left', anchor='nw')

        dash1 = Label(Main_Frame, text=":", bg=master.cget('bg'))
        dash1.pack(side='left', anchor='nw')

        Min_entry = Spinbox(Main_Frame, text=f'00', width=2, from_=0, to=60, textvariable=self.Min_var, format='%02.0f')
        Min_entry.pack(side='left', anchor='nw')

        dash2 = Label(Main_Frame, text=":", bg=master.cget('bg'))
        dash2.pack(side='left', anchor='nw')

        Sec_entry = Spinbox(Main_Frame, text=f'00', width=2, from_=0, to=60, textvariable=self.Sec_var, format='%02.0f')
        Sec_entry.pack(side='left', anchor='nw')

        if s_cfg:
            Hour_entry.config(cnf=s_cfg)
            Min_entry.config(cnf=s_cfg)
            Sec_entry.config(cnf=s_cfg)
            dash1.config(font=s_cfg['font'], fg=Hour_entry.cget('bg'))
            dash2.config(font=s_cfg['font'], fg=Hour_entry.cget('bg'))

        if sp_cfg:
            Hour_entry.pack_configure(cnf=sp_cfg)
            Min_entry.pack_configure(cnf=sp_cfg)
            Sec_entry.pack_configure(cnf=sp_cfg)

        if f_cfg:
            Main_Frame.config(cnf=f_cfg)

        return Main_Frame

    class Date_Frame(Frame):

        def __int__(self, master=None):
            super().__init__(master)
            self.Date_update_id = None
            self.Date = None

        def Date_Frame(self, master, Style=None):
            """
            This function will be used to create a date frame by using optionMenu and Entry widget
            :param master: This is the master in which we will put our Set time frame.
            :return: Date, this will return the date in the form of string.
            """
            cal = calendar.Calendar()
            wid = apps.Time()

            Main_Frame = Frame(master)
            # Main_Frame.pack()

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
            date_option = ttk.Combobox(Main_Frame, values=self.date_options, textvariable=date_var, width=3,
                                       style=Style)
            date_option.pack(side='left', anchor='w', padx=15)

            # Month
            month_option = ttk.Combobox(Main_Frame, values=self.month_options, textvariable=month_var, width=10,
                                        style=Style)
            month_option.pack(side='left', anchor='w', padx=10)

            # Year
            year_option = ttk.Combobox(Main_Frame, values=self.year_options, textvariable=year_var, width=5,
                                       style=Style)
            year_option.pack(side='left', anchor='w')

            # Now we need to update the year,month and date to get the accurate detail/date of the month of the year.

            def update_dates():
                # This method will be used to update the date after selecting the date.
                # Now after updating year and months we need to update the dates of the month of the year.
                # print("selected:",month,year)
                self.date_options = [i for i in
                                     cal.itermonthdays(int(year_var.get()), wid.get_month_number(month_var.get())) if
                                     i != 0]
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

        def progressbar(self, master, suffix='Progress', prefix='Completed', increment=1, length=150, theme=None):

            # now here we need to define the Frame , Label and a Progressbar.

            self.Progress_Frame = Frame(master, height=5, width=250)
            # Progress_Frame.pack(side = 'right', anchor='e', padx = 10)

            # now in this frame we need to put some Label and a Progress bar
            # Note that we need to put the label and progress bar in order
            suffix_label = Label(self.Progress_Frame, text=suffix)
            Progress_Bar = ttk.Progressbar(self.Progress_Frame, length=length)
            prefix_label = Label(self.Progress_Frame)

            suffix_label.pack(side='left', anchor='n')
            Progress_Bar.pack(side='left', anchor='n')
            prefix_label.pack(side='left', anchor='n')

            # Now we need to make a function to update the progress bar
            def update_progress():
                # this function will be run by a .after function.
                # Now here we need to add some increment value in the Progress_Bar['value']

                Progress_Bar['value'] += increment
                a = Progress_Bar['value']

                # Now we need to show this increment in the prefix label
                prefix_label.config(
                    text=f"{a:.2f} " + prefix)  # this formatting is to show two digits after decimal point.
                # now we need to make a .after() loop

                if a >= 100:
                    # then it means we have reached to 100% Now we need to stop the .after() loop
                    prefix_label.after_cancel(self.progress_after_id)

                else:
                    # Note: to track the .after() id we need to make a class instace.
                    self.progress_after_id = prefix_label.after(1000, update_progress)
                    # Now this will update the progress bar in every seconds.

            update_progress()

            return self.Progress_Frame

    class Create_Notebook(Frame):

        def __init__(self, master=None):
            super().__init__(master)

        def Notebook(self, master, height, width, tabposition='wn'):
            """
            This function will be used to make a note book object.
            :param master: This Notebook will be place in this master.
            :return: NOne.
            """
            mygreen = "#3e4c63"
            white = "white"

            style = ttk.Style()

            style.theme_create("NewNotebook", parent="vista", settings={
                "TNotebook": {"configure": {"tabmargins": [2, 5, 2, 0], 'tabposition': 'wn', 'background': '#3e4c63'}},

                "TNotebook.Tab": {
                    "configure": {"padding": [15, 15], "background": mygreen, 'font': ('sarif', 10, 'bold'),
                                  'foreground': 'blue'},
                    "map": {"background": [("selected", '#7d7f82')],
                            "expand": [("selected", [2, 1, 1, 0])]}},

                "TCheckbutton": {
                    "configure": {'background': '#bbc9c5', 'indicatorbackground': '#5f8278',
                                  'indicatorcolor': '#7a3ca6',
                                  "indicatormargin": 5, 'padding': 3, 'indicatorrelief': 'flat'},
                    "map": {"background": [("selected", '#7a3ca6')]}},

                "TProgressbar": {
                    "configure": {'background': 'green', 'troughcolor': 'white', 'bordercolor': 'red',
                                  'darkcolor': 'red', 'lightcolor': 'yellow'},
                    "map": {"background": [("selected", '#4fbd9d')]}}

            })

            style.theme_use("NewNotebook")

            # style = ttk.Style()

            # style.configure('Tracks.TNotebook', tabposition = tabposition, background='#3e4c63', tabmargins = (20,20,20,0))
            self.notebook = ttk.Notebook(master, height=height, width=width, takefocus=False)
            self.notebook.pack(fill='both', expand=True)
            print("Note book before returning. ", self.notebook)
            return self.notebook

        def Add_Tab(self, addInstance=None, tabName='tab'):
            """
            This method will be used to add new tabs in the
            :param sep:
            :return:
            """
            self.notebook.add(child=addInstance, text=tabName)

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

        def __init__(self, master=None):
            self.TCD = apps.Tracks_Cards()
            self.Tracks_Cards_Database = self.TCD.Read_Cards_Database(fileName="./Data/temp")
            self.Tracks_Cards_Frames = {}
            super().__init__(master)
            self.TypeName = None
            self.Name = None
            # self.id = None # id will be a key for every root object of the card.
            self.class_ids = dict()
            self.Cards = None
            self.NextParentTopic = None  # Not using
            self.Selected_Root = None  # Not using , This can be useful to Handle the currently selected Root Card
            self.SubDictData = None  # This will be used during adding a new data and this will store the sub card data information.
            self.App_Cards = apps.Tracks_Cards()

            # Sub card Details
            self.SubCard_Parent = None
            self.SubCard_Name = None
            self.SubCard_FullName = None
            self.Tcards = apps.Tracks_Cards()

            # Save location
            self.Save_location = './Data'  # some files will be saved according to the current date of working.

        def Create_Track_Record_Card(self, master, CardName, frame=None, data=None, use='create'):
            """
            This function will be used to create a frame in which we will put some labels and in those labels we will put some data.
            :param master: This is the master in which we will put our container frame,
            :param frame: This is the container frame which will be placed in the master window and in this we will make our rows.
            :param data: this is the data or row which will be placed in the row frame. data will be in json format.
            :return: None
            """
            # parent_topic = "TM-TYT"
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
                Data = Data[CardName]  # to get
            elif use == 'retrieve':
                Data = data
            else:
                print("unknown key error")

            self.Root_Card_Frame = Frame(master, width=800, height=30, bg='#7d7f82')
            self.Root_Card_Frame.pack(fill='x', expand=1, anchor='n', padx=50)
            self.Root_Card_Frame.pack_propagate(True)

            self.head_frame = Frame(self.Root_Card_Frame, width=800, height=30, bg='#f06d22')
            self.head_frame.pack(side='top', anchor='n', fill='x')

            self.content_frame = Frame(self.Root_Card_Frame, width=800, height=0, bg='#f52ceb')
            self.content_frame.pack(side='top', anchor='n', fill='both')
            # self.content_frame.pack_propagate(False)

            # Now we need to Project labels on the Root card.
            Type_label = Label(self.head_frame, text=Data['Type'])
            Type_label.pack(side='left', anchor='nw')

            Name_label = Label(self.head_frame, text=Data['Name'])
            Name_label.pack(side='left', anchor='nw', padx=5)

            # Now need to make completed, Thour, EndDate and AddButton
            # Note in completed we need a progress bar also
            bar = Widgets.Create_ProgressBar(self.head_frame)
            CompletedBar = bar.progressbar(self.head_frame, suffix="", prefix="")
            Thour_label = Label(self.head_frame, text=Data['Target Hour'])
            EndDate_label = Label(self.head_frame, text=Data['EndDate'])
            AddButton = Button(self.head_frame, text='+', font=('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(50, 0))

            # Now here we need to map the Parent name with the button Tracks_Card_Mapping
            self.Tracks_Cards_Mapping[AddButton] = "Root." + CardName
            self.Tracks_Cards_Frames.update({Data['FullPath']: self.content_frame})

            # Now we need to configure the AddButton
            def add_subcard(button):
                # print("add record button pressed")
                # Ok so when we press the button then we need to ask for new record data.
                # New record or sub record also need a Parent Name, its own Name (card name)
                root = Toplevel()

                # When we press the Add SubCard button then it wil make a top level window
                # and it will call the self.Add_SubRecord
                self.Add_SubRecord(root, Parent=self.Tracks_Cards_Mapping[button])
                self.Root_Card_Frame.wait_window(root)
                print(button)

                # Data.update(self.SubDictData) # This self.SubDictData Contains the SubCard information.
                print("Subcard Detail using self.SubDictData: ", self.SubDictData, )
                self.Cards = Data
                one_card_height = 70

                current_height = self.Root_Card_Frame.cget('height')

                self.Root_Card_Frame.config(height=current_height + one_card_height)

                self.Create_Track_Record_Sub_Card(self.content_frame,
                                                  Parent=self.SubCard_Parent,
                                                  CardName=self.SubCard_Name,
                                                  FullName=self.SubCard_FullName, Data=self.SubDictData)

                self.Root_Card_Frame.update_idletasks()
                # print(Data)

            AddButton.config(command=lambda x=AddButton: add_subcard(x))

        def Create_Track_Record_Sub_Card(self, master, Parent=None, CardName=None, FullName=None, Data=None,
                                         use='create',
                                         height=None, width=None, f_cfg=None):
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

            Subcard = Frame(master, width=800, height=50, bg='white', highlightbackground='#6f1787',
                            highlightcolor='#6f1787'
                            , highlightthicknes=2)
            Subcard.pack(fill='x', expand=1, anchor='n', pady=10, side='top', padx=(10, 0))
            # self.Subcard.pack_propagate(False)
            Subcard.update_idletasks()

            SubHead = Frame(Subcard, width=800, height=20, bg='green')
            SubHead.pack(fill='x', expand=True, anchor='n', side='top')

            SubContent = Frame(Subcard, width=800, height=0, bg='#2885b8')
            SubContent.pack(fill='both', expand=True, anchor='n', side='top', pady=(0, 10))
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
                sub_current_height = Subcard.cget('height')  # height of the sub card
                root_current_height = self.Root_Card_Frame.cget('height')  # height of Root card

                SubContent.config(height=sub_current_height + one_card_height)

                self.Root_Card_Frame.config(height=root_current_height + 70)

                # Now here after increasing the height of the subcard we need to call Add_SubCard function
                # This Add_SubCard metod need a top level window
                root = Toplevel()
                self.Add_SubRecord(root, self.Tracks_Cards_Mapping[button])
                # Parent = self.Tracks_Cards_Mapping[button]
                # Tracks_Cards_Mapping stores all the Card full name and map them to the button id.
                # Now when we will press the button then it will pick the full name of the selected Subcard Full name.
                Subcard.wait_window(root)  # this will wait window until end of the Add_SubCard process

                # Now we need to access self.SubDictData , which will be updated by the Add_SubCard method.
                # also self.SubDictData will update
                # self.SubCard_Parent , self.SubCard_Name, self.SubCard_FullName

                # Now we need to call the self.Create_Track_Record_Sub_Card
                # ok now tis Add_SubCard will update our self.
                self.Create_Track_Record_Sub_Card(SubContent, Parent=self.SubCard_Parent, CardName=self.SubCard_Name,
                                                  FullName=self.SubCard_FullName, Data=self.SubDictData)
                SubContent.update_idletasks()

                # Now we need to save the Data
                self.Tcards.SaveCard(CardName=self.SubCard_Name, Parent=self.SubCard_Parent,
                                     Database=self.Tracks_Cards_Database, Subcard=self.SubDictData,
                                     FullName=self.SubCard_FullName)

            # Now we need to track every new sub card with the help of the button.
            AddButton.config(command=lambda x=AddButton: add_subcard(x))
            # This button will be placed on the Subcard.

        def Retrieve_Cards(self, master, Database):
            """
            This method will be used to retrieve all the cards data from the local storage and pack them on the frame.
            :param master: This is the master in which all the cards are placed.
            :param Database:  This is the database of the data , in this database we have all cards information.
            :return: None
            """
            for key, card in self.Tcards.Retrieve_Cards(Database):
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

        def Add_SubRecord(self, master, Parent, Child=None):
            """
            This will be small top level application which will be used to add a new sub record which will be displayed on the Track Section.
            :param master: This will be the master/root window on which this application will be placed.
            :param Parent: This is the Parent of the Child , This Child widget will be placed inside this Parent section.
            :param Child: This is the child or SubCard which will be created by executing this method.This Child name Can be given by user Entry in this application.
            :return: None
            """
            ts = apps.Time()
            wid = Widgets()
            Current_Date = ts.get_current_date()
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
            Parent_label = Label(Main_Frame, text="Parent", cnf=l_cfg)
            Parent_Name = Label(Main_Frame, text=Parent, cnf=l_cfg)

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
            Date_Frame_Entry.config(
                bg=Main_Frame.cget('bg'))  # To change the Main Frame background of the Date_Frame_Entry object

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
                print(f"{'_' * 30}")
                # print("Save data Button:",button)
                # Note that subtopic can be manipulated by a Subtopic_frame object.
                # subtopic_frame object will contain the subtopics
                Hr_var, Min_var, Sec_var = wid.Hr_var.get(), wid.Min_var.get(), wid.Sec_var.get()
                # These time values are taken from the Time_Frame function which is defined in the Widgets class.

                SubCardData = {SubCard_entry.get(): {'Name': SubCard_entry.get(),
                                                     'Date': Current_Date,
                                                     'Time': Current_Time,
                                                     'Topic': {},
                                                     'Target Hour': f"{Hr_var}:{Min_var}:{Sec_var}",
                                                     'EndDate': wid2.Date,  # here we need to pass a end date of the
                                                     'Progress': 0,
                                                     'Parent': Parent,
                                                     'FullPath': '.'.join([Parent, SubCard_entry.get()]),
                                                     'Childs': 0}}

                # data_dict['FullName'] = ".".join([Parent,data_dict['Topic']])
                # defining the Subcard detail
                self.SubCard_Parent = Parent
                print("Sub card Parent in widgets.Create_Tracks.Add_SubCard: ", self.SubCard_Parent)
                self.SubCard_Name = SubCard_entry.get()
                self.SubCard_FullName = '.'.join([Parent, SubCard_entry.get()])

                self.NextParentTopic = SubCardData[self.SubCard_Name]
                self.SubDictData = SubCardData
                print("self.SubDictData =>", self.SubDictData)
                # Now after Sucessfully save and create a new NTR Card we need to close this root window
                # Now after saving the data we need to retrieve the data
                save = apps.Tracks_Cards()
                save.SaveCard(CardName=self.SubCard_Name, Parent=Parent, Database=self.Tracks_Cards_Database,
                              Subcard=SubCardData, FullName=self.SubCard_FullName)
                master.destroy()
                # print(".".join([parent_topic,data_dict['Topic']]))
                print(f"{'_' * 30}")

            Set_button.config(command=lambda x=Set_button: save_data(x))

    class Keeps_Card:
        """
        This class will be used to create a new keep card in a Keeps Notebook section.

        Create_Keep_Card: This a subclass of the Keep_Card in this we can create a keep card which can hold the KeepChecks.
        """
        Keep_Cards_List = []  # This will hold the all card with their data.
        Keep_Card_Data = None  # this will hold the all card information.
        Keep_Card_Ids = None  # this will hold the all cards ids.
        Keep_Card_Container = None  # this is the common container in which all the card will be placed.
        Keep_Card_Object = []  # This will hold all card objects.


        # SOME GLOABLE ATTRIBUTE FOR THEME AND COLOR
        KEEP_CARD_HEAD_COLOR = None
        KEEP_CARD_CONTENT_COLOR = None
        KEEP_CARD_HEAD_TEXT_COLOR = None
        KEEP_CARD_CONTENT_TEXT_COLOR = None

        class CreateKeepsCard(Frame):
            """
            This Class will be used to create create a new keep card , this keep card will hold all the information
            in its attributes.
            """

            def __init__(self, master=None, title=None):
                super().__init__(master)
                self.master = master
                self.title = title
                self.id = None
                self.init_date = None
                self.init_time = None
                self.Next_Check_Position = (1, 0)
                self.Next_AddButton_Postion = (1, 1)
                self.CheckList = []
                self.CheckContent = []
                # self.init_check = None

                self.Create_Keep_Card(self.master, self.title)
                # Create the Keep card when the object is created.
                # print("keep init method called")

            def Create_Keep_Card(self, master, title=None, data=None, cfg={}, **kw):
                """
                This method will be used to Create a new card with some extra additional ability.
                this method will allow us to add new to-do list reocrds.
                :param master: We will place our cards data in this Frame.
                :param title: str, this will be the  title of the keep Card.
                :return:

                Note: Note that card will be packed inside the Keeps Frame section not here. we will use grid layout-management
                        system.
                """

                self.CardMainFrame = Frame(master, height=100, width=20, bg='green', highlightbackground='black',
                                           highlightcolor='black', highlightthickness=2)
                # Now we need to add a title Label on the CardMainFrame
                if title != None:
                    self.HeadFrame = Frame(self.CardMainFrame, bg='red')
                    self.HeadFrame.pack(fill='x')

                    self.TitleLabel = Label(self.HeadFrame, text=title)
                    self.TitleLabel.pack(side='left', anchor='nw')
                    # now in this card we will make another fame which we will add all the to-do list record.

                self.CardContentFrame = Frame(self.CardMainFrame, bg='white')
                self.CardContentFrame.pack(fill='both')

                # This CardContentFrame will hold all the checks using a grid layout system.
                # Now in this we need to put a text box inside This CardContentFrame

                # This text box will help us to get the text during save time.
                self.Textbox = Widgets.Keeps_Card.KeepCardCheck(self.CardContentFrame)
                self.Textbox.grid(row=0, column=0)

                # now we will add a button to add new check label
                self.AddCheckbutton = Button(self.CardContentFrame, text='+', font=('sarif', 10, 'bold'))
                self.AddCheckbutton.grid(row=0, column=1, sticky='se')
                self.AddCheckbutton.config(command=lambda x=self.CardContentFrame, y=self.AddCheckbutton:
                self.Add_Keep_Check(master=x, bt=y))

            def Create_Keep_Card2(self, master, position, data, cfg={}, **kw):
                """
                This method will be used to crete the final Keep Card and it will place that card on the Keep Frame,
                    also this method will be used to create the keep card from saved data.
                :param master: This is the master window in which we will  place over keep card.
                :param position:tuple, if we are using grid then we will use this to define the position of the card.
                :param data: dict, this will be our data and this data will be passed to the object attributes.
                :param cfg: config attribute for the container frame of the keep card.
                :param kw: Additional keyword for the container frame.
                :return: None
                """
                # Now we need to define our card (object) data
                # NOte that data will be our dictionary of the data base.

                self.title = data['title']
                self.id = data['Id']
                self.init_date = data['date']
                self.init_time = data['time']
                self.checklist = data['content']  # This check list don't holds the object it holds the text data
                # and the mark value.
                # print("Card title: ", self.title)
                # print("Card id: ", self.id)
                # print("Card date: ",self.init_date)
                # print("Card time: ", self.init_time)
                # print("Card CheckList: ",self.checklist)

                self.CardMainFrame2 = Frame(master, height=100, width=20, bg='green', highlightbackground='black',
                                            highlightcolor='black', highlightthickness=2)
                # Now we need to add a title Label on the CardMainFrame

                self.HeadFrame2 = Frame(self.CardMainFrame2, bg='red')
                self.HeadFrame2.pack(fill='x')

                self.TitleLabel2_var = StringVar()
                self.TitleLabel2_var.set(self.title)
                self.TitleLabel2 = Label(self.HeadFrame2, textvariable=self.TitleLabel2_var)
                self.TitleLabel2.pack(side='left', anchor='nw')
                # now in this card we will make another fame which we will add all the to-do list record.

                self.CardContentFrame2 = Frame(self.CardMainFrame2, bg='white')
                self.CardContentFrame2.pack(fill='both')

                # This CardContentFrame2 will hold all the checks using a grid layout system.
                # Now in this we need to put all the check which are made.
                self.AddCheckbutton2 = Button(self.CardContentFrame2, text='+', font=('sarif', 10, 'bold'),
                                              )
                self.AddCheckbutton2.grid(row=0, column=1,
                                          sticky='se')
                self.Next_Check_Position = (0, 0)
                self.Next_AddButton_Postion = (0, 1)
                for check_text, check_mark in self.checklist:
                    Textbox = Widgets.Keeps_Card.KeepCardCheck(self.CardContentFrame2)
                    Textbox.text.insert(1.0, check_text)
                    Textbox.check_var.set(check_mark)

                    # after creating the checkbox inside the Keep Card we need to store the Textbox in the self.CheckList
                    # and also we need to store the text content and check mark in the self.CheckContent list.
                    self.CheckList.append(Textbox)
                    self.CheckContent.append((check_text, check_mark))

                    Textbox.grid(row=self.Next_Check_Position[0], column=self.Next_Check_Position[1])

                    # now we will add a button to add new check label

                    self.AddCheckbutton2.grid_configure(row=self.Next_AddButton_Postion[0],
                                                        column=self.Next_AddButton_Postion[1])

                    # now increase the position of the Check and button
                    self.Next_Check_Position = (self.Next_Check_Position[0] + 1, 0)
                    self.Next_AddButton_Postion = (self.Next_AddButton_Postion[0] + 1, 1)
                r, c = position
                print("Keep Card position: ", position)
                self.AddCheckbutton2.config(command=lambda x=self.CardContentFrame2,
                                                           y=self.AddCheckbutton2:
                self.Add_Keep_Check(master=x, bt=y))

                # Now we will add a save button on the to title frame to update the card
                self.Update_Button = Button(self.HeadFrame2, text='save', command=self.Update_Keep_Card)
                self.Update_Button.pack(side='right', anchor='e')

                # Now we will add a delete button which wil be used to delete the card from the database.
                self.DeleteCheckButton = Button(self.HeadFrame2, text='delete',
                                                command=lambda x=self: self.Delete_Keep_Card(x))
                self.DeleteCheckButton.pack(side='right', anchor='e')

                self.CardMainFrame2.grid(row=r, column=c, sticky='n', padx=5, pady=10)
                # print("In Create_Keep_Card2 self.CheckList: ", self.CheckList)

                # at last we will reconfigure the theme of the Card
                self.theme_configure()
            def Retrieve_Keep_Cards(self, master, keepcarddata):  # @ This method is not used yet.
                """
                This method will initiate the keep card from saved data. this method will be called during the initializing/opening
                the application.
                :param master: This will be the master in which we will place our keep cards.
                :param keepcarddata: This is the cara data which will be used to create initiate saved cards.
                :return:
                """
                # now we will pass a dummy list into the get_keep_card_position
                # this will give us the all position for our cards.
                List = [i for i in range(len(keepcarddata))]
                keepbar = Widgets.Keeps_Card.KeepCardBar(master)

                # get_keep_card_position will return two things
                # all card position and the recent card position.
                # we need all card position not the recent one.
                Pos, _ = keepbar.get_keep_card_position(List)
                for card, pos in zip(keepcarddata.items(), Pos):
                    _, card_detail = card
                    print("retrieved card detail: ", card_detail)
                    Widgets.Keeps_Card.Keep_Cards_List.append(card)
                    self.Create_Keep_Card2(master, pos, card_detail)
                # Now we need to iterate through all the cards.

            def Delete_Keep_Card(self, card_id):
                print("delete keep card called.")
                """
                This method will be used to delete a card from a database, and it will reconfigure all the cards.
                :param card_id: This is the card which is need to be deleted after pressing the delete button.
                :return: None
                """
                '''
                Steps to delete a card:
                    1. first of all we need to check that card_id (card) is present in the Keep_Card_object
                    2. if it is present then we need to destroy it using the tkinter w.destroy() method.
                    3. after this we need remove the data which is associate to that card.
                    4. and then we need to update the database with remaining card details.
                    5. save the card database.
                '''
                CardsFrame = Widgets.Keeps_Card.Keep_Card_Object  # this holds all the keepcardFrames.
                if card_id in CardsFrame:
                    # now if card_id present inside the card list then we need to delete that card.
                    # Now we will try to delete and refresh our database.
                    id_index = CardsFrame.index(card_id)  # getting the card id index
                    del Widgets.Keeps_Card.Keep_Card_Ids[id_index]  # deleting the card id by using its index.

                    CardsFrame.remove(card_id)  # 2. removing the card Card_Object lIst
                    # card_id.destroy() # removing the card from the Card_Container frame.
                    # Now we need to remove the data also.
                    del Widgets.Keeps_Card.Keep_Card_Data[card_id.title]  # removing the card data.
                    # Now we need to save the data into database locally.
                    file = './data/KeepCards.json'
                    card_data = {"Cards": {},
                                 "Card_ids": []}
                    List = [i for i in CardsFrame]
                    position, _ = misc.get_keep_card_position(List)

                    for child in Widgets.Keeps_Card.Keep_Card_Container.winfo_children():
                        # print("child going to destroy: ",child, child.winfo_ismapped())
                        child.destroy()

                    # Now we need to recreate cards
                    self.Reload_Keep_Card()

                    # Now we will save our new updated data.
                    card_data['Cards'].update(Widgets.Keeps_Card.Keep_Card_Data)
                    card_data['Card_ids'] = Widgets.Keeps_Card.Keep_Card_Ids
                    # Now we need to reconfigure the cards

                    with open(file, 'w') as f:
                        json.dump(card_data, f, indent=2)

                    # Now updating the card Container.
                    Widgets.Keeps_Card.Keep_Card_Container.update_idletasks()

                else:
                    print("No card found...")

            def theme_configure(self, head_bg_color='#4f485e',content_bg_color = '#488231' ,
                                head_text_color='white', content_text_color= 'white'):
                """
                This method will be used to configure the look of the Keep_Card object, in this we will change background,
                foreground, text size, font style, colors, active and disabled state.
                :return:
                """
                Widgets.Keeps_Card.KEEP_CARD_HEAD_COLOR = head_bg_color
                Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR = content_bg_color
                Widgets.Keeps_Card.KEEP_CARD_HEAD_TEXT_COLOR = head_text_color
                Widgets.Keeps_Card.KEEP_CARD_CONTENT_TEXT_COLOR = content_text_color
                # first of all removing the default border
                self.CardMainFrame2.config(highlightbackground=None, highlightcolor=None, highlightthickness = 0)

                # common
                hc_cfg = {'bg':head_bg_color, 'font':('snas-sarif',15,'bold'),'fg':head_text_color,'relief':'flat', 'takefocus':0}
                hb_cfg = {}

                # first of all we will configure the HeadFrame of the Keep_Card.
                self.HeadFrame2.config(bg=head_bg_color)
                for child in self.HeadFrame2.winfo_children():
                    child.config(cnf = hc_cfg)

                # Now we will work on the CardContentFrame
                self.CardContentFrame2.config(bg=content_bg_color)
                for child in self.CardContentFrame2.winfo_children():
                    if isinstance(child, Button):
                        child.config(bg=content_bg_color, takefocus=0, relief='flat', fg=content_text_color,
                                     font = ('sarif',11,'bold'))
                    else:
                        child.config(bg=content_bg_color, takefocus=0, relief='flat')


                # Now we need to config every checkbox, for that we need to config Textbox.
                style = ttk.Style()
                style.configure('TCheckbutton', background=content_bg_color, indicatorbackground = content_bg_color,
                                indicatorcolor = content_bg_color)
                for Textbox in self.CheckList:
                    Textbox.text.config(bg=content_bg_color, fg=content_text_color, takefocus=0, relief='flat',
                                        state='disabled', font = ('sarif', 12), pady=5)
                    Textbox.check.config(style='TCheckbutton', takefocus=0)

            def pack(self, cfg={}, **kw):
                """
                Put the card widget on the Frame using the pack layout management system.
                :return: None
                """
                self.CardMainFrame.pack(cfg, **kw)

            def grid(self, cfg={}, **kw):
                """
                put the card widget on the Frame using the grid layout management system.
                :return: None
                """
                self.CardMainFrame.grid(cfg, **kw)

            def Add_Keep_Check(self, master, bt=None, row=None, column=None):
                print("Add keep check called")
                """
                This method will be used to create a new Text box inside the Keep card.
                :return:
                """
                # Now in this we will be need to the position of the text box since we are using the grid
                # layout management so we need to track the row and column in a variable.
                # for that we will use the self.Next_Check_Position and self.Next_AddButton_Position
                if len(self.CheckList) == 0:
                    self.CheckList.append(self.Textbox)

                elif len(self.CheckList) > 0:
                    self.CheckList[-1].bind_Return(event=None)
                    # here bind return is used to perform the same task as it performed when enter is pressed.
                Trow, Tcol = self.Next_Check_Position
                Brow, Bcol = self.Next_AddButton_Postion
                # here we need to put the Frame according to need
                Textbox = Widgets.Keeps_Card.KeepCardCheck(master)
                Textbox.grid(row=Trow, column=Tcol)
                Textbox.focus_set()

                bt.grid_configure(row=Brow, column=Bcol)

                # Now we need to update the next Position for the Textbox and Add button.
                self.Next_Check_Position = (self.Next_Check_Position[0] + 1, 0)
                self.Next_AddButton_Postion = (self.Next_AddButton_Postion[0] + 1, 1)

                self.CheckList.append(
                    Textbox)  # this will append the new Textbox in the self.CheckList which contains all the check for self.
                self.CheckContent = [(check.text.get(1.0, 'end'), check.check_var.get()) for check in self.CheckList]

            def gen_card_unique_id(self, rng=(1000, 9999), idlist=None):
                """
                This function will be used to generate a
                :param rng:
                :param idlist:
                :return:
                """
                if idlist == None:
                    # then we will create new id list.
                    idlist = []
                    self.id = randint(rng[0], rng[1])
                    idlist.append(self.id)
                else:
                    while (1):
                        Id = randint(rng[0], rng[1])
                        if Id not in idlist:
                            idlist.append(Id)
                            self.id = Id
                            break
                return idlist

            def Update_Keep_Card(self):
                """
                This function will be used to resave the keep card when the save button is pressed. This will update the
                    keep database.
                :return:
                """
                keep_data = []
                for obj in self.CheckList:
                    check_text = obj.text.get(1.0, 'end')
                    check_text = check_text.splitlines()[0]
                    check_var = obj.check_var.get()
                    keep_data.append((check_text, check_var))

                Card = {self.title: {'title': self.title,
                                     'Id': self.id,
                                     'date': self.init_date,
                                     'time': self.init_time,
                                     'content': keep_data}}
                # Now if we want to resave an edited or modified keep then we need,
                # card title, Keep Card Database,
                # Now we will update the card detail
                Widgets.Keeps_Card.Keep_Card_Data.update(Card)

                # Now we need to save the card. for that we will use the save_keep_card from the Apps_func.Keep_Card class
                apps_func_keep_card.save_keep_card_data(Widgets.Keeps_Card.Keep_Card_Data,
                                                        Widgets.Keeps_Card.Keep_Card_Ids,
                                                        update=1)

            def Reload_Keep_Card(self):
                """
                This method will be used to used to reload the all cards.
                :return:
                """
                if bool(Widgets.Keeps_Card.Keep_Card_Data):
                    # if we have some keep in Keep_Card_Data then we need to make them and place them in Card Container.

                    # Now we need a dummy list whihc is equale in length with Keep_Card_Object.
                    List = [i for i in range(len(Widgets.Keeps_Card.Keep_Card_Data))]

                    # Now we have length so we need to get all the position for the keep card.
                    Pos, _ = misc.get_keep_card_position(List)

                    # Now we need to recreate all the available card.
                    # Now before making any appending we need to reset the Keep_Card_object
                    Widgets.Keeps_Card.Keep_Card_Object = []
                    Widgets.Keeps_Card.Keep_Cards_List = []
                    for card, pos in zip(Widgets.Keeps_Card.Keep_Card_Data.items(), Pos):
                        _, card_detail = card
                        Widgets.Keeps_Card.Keep_Cards_List.append(card)

                        # Now after getting the card detail and position we need to create object for each individual card.
                        # This card will be need to put in the Keep_Card_Container frame.
                        add_keep = Widgets.Keeps_Card.CreateKeepsCard(Widgets.Keeps_Card.Keep_Card_Container)
                        add_keep.Create_Keep_Card2(Widgets.Keeps_Card.Keep_Card_Container, pos, card_detail)
                        # Now we will append the card in Widgets.Keep_Card.Keep_Card_Objects list
                        Widgets.Keeps_Card.Keep_Card_Object.append(add_keep)

        # --------------------------------------------------------------------------------------------------------------------

        class KeepCardCheck(Frame):
            """
            This class will be used to create a check in a checklist. it will contain a checkbox and a Text widget, checkbox will be
            linked to the Text widget.
            """

            def __init__(self, master=None, cnf=None):
                super().__init__(master)
                self.lines = 1  # This will be used to increase the line of the Text widget.
                self.bg_color = 'white'
                self.keep_data = None
                # Now we will use the init constructor to create KeepCardCheck
                # we need a Frame which can hold both checkbox and Text widget
                self.MainFrame = Frame(master, width=40, cnf=cnf)
                # this will be the main frame in which we will put the checkbox and the Text widget
                self.check_var = IntVar()
                self.OverStrike = False  # This will be used to track the strike on the text.
                self.check_var.set(0)
                # making the checkbox
                self.check = ttk.Checkbutton(self.MainFrame, variable=self.check_var, text='',
                                             command=self.update_checkbutton_states)
                self.check.pack(side='left', anchor='nw')

                # now we need to put the text box
                self.text = Text(self.MainFrame, height=1, width=40, wrap='word', insertontime=700, insertofftime=500)
                self.text.pack(side='left', anchor='nw')
                self.event_binding()
                print("keep initiated")

            def pack(self, cnf={}, **packvalues):
                """
                put the card widget on the Frame using the pack layout management system.
                :return: None
                """
                self.MainFrame.pack(cnf, **packvalues)

            def grid(self, cnf={}, **packvalues):
                """
                Put the card widget on the Frame using the grid layout management system.
                :return: None
                """
                self.MainFrame.grid(cnf, **packvalues)

            def update_textheight(self, event):
                """
                This method will be used to update the height of the Textbox according to the check box current lines
                :return: None
                """
                if event.char != 'Return':
                    self.text_len = None
                    lchar = self.text.cget('width')
                    line = self.text.get(1.0, 'end')
                    lines = len(line) // lchar + 1
                    if self.lines + 1 == lines:
                        # print("line increased:", self.lines, lines)
                        self.text.config(height=lines)
                        self.lines += 1

                # self.text_after_id = self.MainFrame.after(700, self.update_textheight)

            def Check_Completed(self):
                """
                This method will be used to mark a check check as completed and it will cut the check by making a through-line or over-line
                    on a check text.
                :return:
                """
                self.text.tag_add("Completed", '1.0',
                                  'end')  # a tag will be added from starting to end of the content in the text box.
                # This will define that how much text should be cut.
                # To add a through-line or a over-strike property on a text we need to use overstrike=1 in a tag_config.
                self.text.tag_config("Completed", overstrike=1)
                # print("Text overstriked.")

            def Check_UnCompleted(self):
                """
                This will be used to remove the strikeline or throughline property form a text.
                :return:
                """
                self.text.tag_config("Completed", overstrike=0)
                # By setting overstrike as 0 we can remove the over line from the text.

            # After making Check_Completed and Check_UnCompleted method we need to bind them with checkbutton

            def update_checkbutton_states(self):
                """
                This function will be used to get the checkbutton current valuee and according to the values we will set the event.
                :return:
                """
                # Now first of all we need to get the value of the check_var
                Check_states = self.check_var.get()  # 0 means deselected and 1 means selected.
                # print("check_states",Check_states, type(Check_states))

                if Check_states:
                    # This condition shows that we have selected the check button.
                    # Now if we selected the button then we need to strike the text and stop the text update.
                    # print("Check button is selected.")
                    self.Check_Completed()
                    self.OverStrike = True
                else:
                    # This condition shows that we have deselected the check button.
                    # if the button is deselected then we need to remove the strike if it done.
                    if self.OverStrike:
                        # Now if we have made the overstrike on the text then we need to remove the over strike
                        # if the checkbutton is unchecked.
                        self.Check_UnCompleted()
                        self.OverStrike = False

            def bind_Return(self, event):
                # print(event)
                """
                This method will be execute when the Return button is pressed.
                :return:
                """
                self.text.config(state='disabled', relief='flat', bg=self.MainFrame.cget('bg'))
                self.keep_data = (self.text.get(1.0, 'end'), self.check_var.get())

                print("keep data: ", self.keep_data)

            def bind_bt_1(self, event):
                """
                This method will be used to bind the event to the mouse button-1
                :param event:
                :return:
                """
                self.text.config(state='normal', relief='sunken', bg=Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR,
                                 fg=Widgets.Keeps_Card.KEEP_CARD_CONTENT_TEXT_COLOR)

            def event_binding(self):
                """
                This function will have all the event binding.
                :return:
                """
                self.text.bind("<Return>", self.bind_Return)
                self.text.bind("<Button-1>", self.bind_bt_1)
                self.text.bind("<KeyPress>", self.update_textheight)

        class KeepCardBar(Frame):
            """
            This Keep card bar class will be used to create a bar in a Keeps tab and it will be used to create  a new KeepCard,
            It will be initiated with a Title and a single check.
            """

            def __init__(self, master=None, container_frame=None, cfg={}, **kw):

                super().__init__(master=master, cnf=cfg, **kw)
                self.master = master
                self.cfg = cfg
                self.kw = kw

                self.Create_Frame(master=self.master, cfg=self.cfg, **self.kw)
                # Now we need to initiate the Frame and other things.
                self.bind_envents()  # This method to initiate the binding of the events.
                self.Content = None
                self.KeepCardContainer = container_frame  # In this we will place over created Cards.
                self.BarActive = False
                print("Focused widget: ", self.MainFrame.focus_get())

            def Create_Frame(self, master, cfg, **kw):
                """
                This function will be used to create the Keep Bar which will be used to create new Keep Card.
                :param master: This is the master Frame or window in which the Bar will be placed.
                :param cfg: config parameters for the Frame.
                :param kw: other config keyword which will be passed through the wild parameter.
                :return: None
                """

                self.MainFrame = Frame(master=master, cnf=cfg, **kw)

                # Now we need to put a Entry box inside it
                self.Title_var = StringVar()
                self.Title_var.set("Title")
                self.Entry = Entry(self.MainFrame, textvariable=self.Title_var, font=("sarif", 15, 'bold'),
                                   relief='flat',
                                   fg="#8c8c8c", takefocus=0)
                self.Entry.pack(fill='y', anchor='nw')

                self.ChecksFrame = Frame(self.MainFrame, bg='red')
                self.ChecksFrame.pack(fill='y', anchor='nw')

                self.BottomFrame = Frame(self.MainFrame, bg='green')
                self.BottomFrame.pack(fill='y', anchor='se', side='bottom')

            def pack(self, cnf={}, **packvalues):
                """
                put the card widget on the Frame using the pack layout management system.
                :return: None
                """
                self.MainFrame.pack(cnf, **packvalues)

            def grid(self, cnf={}, **packvalues):
                """
                Put the card widget on the Frame using the grid layout management system.
                :return: None
                """
                self.MainFrame.grid(cnf, **packvalues)

            def bt1_active_state(self, event):
                """
                This method of the class will be bind to the mouse button-1. This method will be used to initiate the
                Keep card.
                :return:
                """
                print("Entry event responded")
                print("Focused widget: ", self.MainFrame.focus_get())
                if self.Entry.focus_get() != self.Entry and self.BarActive == False:
                    # Now since Bar has been activated so we need to make self.BarActive == True
                    self.BarActive = True
                    # Now if self.BarActive is True then it will be not recreated when we press again.

                    self.Title_var.set("")
                    self.Entry.config(fg='black')
                    self.Entry.pack_configure(fill='x', pady=5, padx=5)
                    # Now we need to initiate a Keep check
                    self.Content = Widgets.Keeps_Card.CreateKeepsCard(self.ChecksFrame, title=None)
                    self.Content.CardMainFrame.config(highlightbackground=None, highlightcolor=None,
                                                      highlightthickness=0)
                    self.Content.pack()
                    self.Content.CheckList.append(self.Content.Textbox)
                    # Now we need to put two button one for save the card and another for cancel the save of card
                    # delete all the card data.

                    self.save_button = Button(self.BottomFrame, text='Save')
                    self.save_button.pack(side='right', anchor='ne')

                    self.cancel_button = Button(self.BottomFrame, text='Cancel')
                    self.cancel_button.pack(side='right', anchor='ne')

                    self.cancel_button.config(command=self.reset_card_bar)
                    self.save_button.config(command=self.save_card)

            def bind_envents(self):
                self.Entry.bind("<Button-1>", self.bt1_active_state)

            def save_card(self):
                """
                This function will be used to store the card details and create a new card from those details and put it
                in the CardContainer frame, this process will reset the keepcardbar and recreate a new card to put it in
                the CardContainer frame.
                :return:
                """
                # CardList = Widgets.Keeps_Card.Keep_Cards_List
                # CardList will have all the cards , it will be used to get the all card by their index
                # and we will get the
                # apps_func_keep_card = apps.Keep_Cards()
                ts = apps.Time()
                # ts form apps_func to give time.

                CKC2 = Widgets.Keeps_Card.CreateKeepsCard(self.KeepCardContainer)
                # Now we will create an object of CreateKeepCard class to create a new card.
                # this card will be placed in the KeepCardContainer frame.

                idlist = apps_func_keep_card.get_unique_id()
                # This idlist will holds the all unique id of all the cards.

                self.Content.CardTitle = self.Title_var.get()  # # storing the card title
                self.id = self.Content.gen_card_unique_id(idlist=idlist)  # # storing the card id
                self.Content.init_date = ts.get_current_date()  # storing card init date
                self.Content.init_time = ts.get_current_time()  # storing card init time

                keep_data = self.unpack_card_text(
                    self.Content.CheckList)  # getting the content of the card and its states.(0 or 1)

                # saving the card detail and getting the full data of the card in a dict format.
                data = apps_func_keep_card.save_keep_card_data(Widgets.Keeps_Card.Keep_Card_Data,
                                                               Widgets.Keeps_Card.Keep_Card_Ids,
                                                               title=self.Content.CardTitle, Id=self.id,
                                                               time=self.Content.init_time, date=self.Content.init_date,
                                                               content=keep_data, idlist=idlist)
                # appending a new card in the CardList
                Widgets.Keeps_Card.Keep_Cards_List.append(CKC2)
                Widgets.Keeps_Card.Keep_Card_Object.append(CKC2)
                # Now we will get position for our new keep card
                print("In KeepCardBar: ")
                print("\t\t ", Widgets.Keeps_Card.Keep_Cards_List)

                # Now we will put the newly created card on the container frame, for this we need to get the position for
                # new card this will be done with get_keep_card_position() method.
                _, newpos = self.get_keep_card_position(Widgets.Keeps_Card.Keep_Cards_List)

                # Now we will save the keep card and put it in the KeepCardContainer frame.
                CKC2.Create_Keep_Card2(self.KeepCardContainer, position=newpos, data=data)

                # Updating the display and idle task.
                CKC2.CardContentFrame2.update_idletasks()
                # resetting the card bar.
                self.reset_card_bar()

            def reset_card_bar(self):
                """
                This method will be used to reset the Keep Card bar when we will cancel or reject to create a new card.
                :return:
                """
                self.BarActive = False
                self.MainFrame.destroy()
                self.Create_Frame(master=self.master, cfg=self.cfg, **self.kw)
                self.pack(pady=20)
                # Now we need to initiate the Frame and other things.
                self.bind_envents()  # This method to initiate the binding of the events.
                self.Content = None
                self.MainFrame.update_idletasks()

            def unpack_card_text(self, objList):
                """
                This method will be used to unpack the card text from object. object will an instance of the KeepCardCheck
                class which will have the text widget and its control variable.
                :return:
                """
                content = []

                for obj in objList:
                    check_text = obj.text.get(1.0, 'end')
                    check_text = check_text.splitlines()[0]
                    check_var = obj.check_var.get()
                    content.append((check_text, check_var))

                return content

            def get_keep_card_position(self, KCL, columns=3):
                """
                This method will be used to define the position for new widget.
                :param KCL: Keep_Card_List we will hold all the Cards.
                :return: tuple, it will return new position.
                """
                row = 0
                col = 0
                poslist = []
                print("length of KCL: ", len(KCL))
                if len(KCL) > 0:
                    for cp in range(len(KCL)):
                        # print("length of cp: ",cp)
                        cp += 1  # card position.
                        # print("length of cp: ", cp)
                        poslist.append((row, col))
                        if cp % columns == 0:
                            row += 1
                            col = 0
                        else:
                            col += 1

                newest = poslist[-1]
                return poslist, newest
