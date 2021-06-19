# In this file we will cover all the widget defination which will be used many times on the dashboard.
from tkinter import ttk,Tk, Toplevel ,Frame, BOTTOM,LEFT,RIGHT,TOP , BOTH , Button, Label, PhotoImage

import Apps_func
from Apps import Tracks,Timer
from Widgets import Widgets
import DailyRoutine as dr
from Apps_func import Keep_Cards
from ExWid import ScrollFrame


class Sections:

    def __init__(self):
        self.Tracks = Tracks()

    def Tracks_Section(self, master=None):
        """
        This section well be used to make the Tracks Section in the Dashboard.
        :param master: master is the frame in which we will store the Track section.
        :return: None

        Note: this will create a top level window if master is None
        """

        # top level window for the add_timer_record.
        def create_add_timer_record_toplevel():
            root = Toplevel()
            self.Tracks.Add_Time_Record_master = root
            self.Tracks.Add_Time_Record(root)
            root.mainloop()


class Frames(Frame):
    """
    This class will contain different frames for different tabs and section. The need of this class is to make a new frame and put some specific
    widgets in that frame and after that put those frames inside the root window or a notebook.
    """
    def __init__(self , master=None):

        super().__init__(master)
        self.Tracks = Tracks()
        self.Wid = Widgets()
        self.Timer = Timer()

    def Tracks_Frame(self, master, height=100,width=100, cfg = None):

        # We need a Create_ProgressBar() object from a widgets module
        tracks = Frame(master, height=height, width=width, bg = '#bad5ff')
        # tracks.pack_propagate(False)

        # Top section
        top_section = Frame(tracks, height=20, bg = '#d9baff')
        top_section.pack(side=TOP, fill = 'x', expand = 0 , anchor = 'n')
        self.Wid.Activities.ACTIVITY_FRAME = top_section  # referencing teh
        #-------------------------------------------------------------------------------------------------#
        #------------------------------ SETTING THE ACTIVITIES--------------------------------------------#
        activity_bar = Frame(top_section,height = 25,width =200, bg='#d9baff')
        activity_bar.pack(side='left', anchor='nw')

        # Now we need to put activities in this frame.
        activity = self.Wid.Activities(activity_bar, self.Timer) # initiating the activity bar
        activity.ActivityMainMenuButton.pack_configure(side='left', anchor='nw') # packing ActivityClasses Menu
        activity.TracksActivities_MbButton.pack_configure(side='left', anchor='nw') # Packing Tracks Activities.
        activity.new_activity(Tracks) # if we need any other activity which is not present in the list then use this.
        activity.NewActivityButton.pack(side='left', anchor='nw') # Packing the new custom activity.
        activity.pack()  # putting all the activities.
        activity.theme_configure(bar_bg_color="#d9baff", bar_item_bg='#d9baff', bar_item_fg='black')

        # passing the top frame into instance object.

        # -------------------------------------------------------------------------------------------------#
        # Here in this top section we will put progress bar and set_today_target button
        # first we will set the set_target-button
        set_target_button = Button(top_section, text='Set', relief='groove', background=top_section.cget('bg'))
        set_target_button.pack(side=RIGHT, anchor='se', padx=(10,0))

        # Now in top section we need to put the tth_progressbar
        tth = self.Wid.TTH_ProgressBar(top_section)
        tth.pack(side=RIGHT, anchor='ne')
        tth.tth_theme_configure(head_bg_color=top_section.cget('bg'), head_text_color='black')
        top_section.update_idletasks()


        # now here we will make a top level window when the button is pressed
        def Set_Target():
            root = Toplevel()
            self.Tracks.Set_Today_target(root)
            self.Tracks.wait_window(root)

            for child in  top_section.winfo_children():
                if isinstance(child, self.Wid.TTH_ProgressBar):
                    child.destroy()

            tth = self.Wid.TTH_ProgressBar(top_section,self.Tracks.set_today_target_hour)
            tth.pack(side=RIGHT, anchor='ne')
            top_section.update_idletasks()
            # print("Target HOur",self.Tracks.set_today_target_hour)

        set_target_button.config(command = Set_Target)

#----------------------------------------------------------------------------------------------------------------------##
#----------------------------------------------------------------------------------------------------------------------##
        # Mid Section, this mid section will be put in a scroll frame which has the ability to scroll items
        scroll_mid_section = ScrollFrame(tracks, height=900)
        mid_section = Frame(scroll_mid_section.ContentFrame, bg='#bad5ff', height=900, width=1200)
        # mid_section.pack_propagate(False)
        # here we need to retrieve the data and need to make the Cards.
        self.Tcards = Widgets.Track_Card(mid_section)
        # print("Databse", self.Tcards.Tracks_Cards_Database)
        self.Tcards.Retrieve_Cards(mid_section,self.Tcards.Tracks_Cards_Database)
        # wid.Create_Track_Record_Card(mid_section)
        scroll_mid_section.pack(fill='both', anchor='nw')
        mid_section.pack(fill='both', expand=1, anchor='nw')
        # Now here we need to

        #------------------------------------------------------------|
        # creating a after loop to check the update in the Database. |
        def update_database():
            Widgets.Track_Card.reload_Database()
            mid_section.after(1000, update_database)
        update_database()
        #-------------------------------------------------------------


#----------------------------------------------------------------------------------------------------------------------##
#----------------------------------------------------------------------------------------------------------------------##
        # Bottom Section
        bottom_section = Frame(tracks, height=30, bg='white')
        bottom_section.pack(side=BOTTOM, fill='x', anchor='s')

        # Now here we need to put a button on the bottom section
        # here in this section we will put the button for adding the new time record.
        add_time_record_button = Button(bottom_section, text='ADD')
        add_time_record_button.pack(side=RIGHT, anchor='se')
        # now this button will be linked to the new toplevel application which will be used to add new time record.

        def create_add_timer_record_toplevel():
            root = Toplevel()
            self.Tracks.Add_Time_Record_master = root
            self.Tracks.Add_Time_Record(root)
            root.mainloop()

        add_time_record_button.config(command = create_add_timer_record_toplevel)

        # Adding a new button For Add New Track Record, This will create a new card.
        ANTR_Button = Button(bottom_section, text = 'ANTR')
        ANTR_Button.pack(side=RIGHT, anchor='se')
        # Now we need to configure this button

        def add_new_track_record():
            root = Toplevel()
            self.Tracks.Add_Record(root)
            root.wait_window(root)
            print("Data Track Record: ",self.Tracks.Add_Record_Data)
            # This self record will give us some data. and this data will be used to create a new Track Record..
            # now we need to use a Track_Card class from widgets module and we need to add a new card.
            # In this method we will create only a root card.

            # Now this  track record information should be stored in local storage
            # Every Root card will have its own new database file.

            RootCard = self.Wid.Track_Card()
            # Now to create a root card on the notebook we need to give it Frame,CardName, data
            # Frame: In this we will put our Root Card
            # CardName: The Name of the Card.
            # data: Additional information about the Card.
            card_name = self.Tracks.Add_Record_Card_Name
            RootCard.Create_Track_Record_Card(mid_section,card_name, data = self.Tracks.Add_Record_Data )

            # Now from here we need to define the Add_SubRecord topics.

        # Now we need to configure this button.
        ANTR_Button.config(command = add_new_track_record)

        # Need to define that why we are returning the tracks object.
        return tracks


    def Keeps_Frame(self , master, height=100,width=100, cfg = None):

        """
        This function will be used to create a tab for Keeps
        :param master: this master is the master/parent window at which it will be placed
        :param height: height of the Keeps frame.
        :param width: Width of the Keeps frame.
        :param cfg: config dict for the frame.
        :return: This will return a Keeps Frame/tab for a toplevel/Notebook object.
        """
        keep = Keep_Cards()
        Widgets.Keeps_Card.Keep_Card_Data, Widgets.Keeps_Card.Keep_Card_Ids =  keep.load_keep_card_data()

        print("Keep_Card_Data: ",Widgets.Keeps_Card.Keep_Card_Data)
        print("Keep_Card_Ids: ",Widgets.Keeps_Card.Keep_Card_Ids)

        self.Main_Keeps_Frame = Frame(master = master, height=height, width=width, bg = 'white')
        self.Main_Keeps_Frame.pack(fill = 'both', expand = True)
        if cfg:
            self.Main_Keeps_Frame.config(cnf=cfg)

        self.Keep_Bar_Frame = Frame(self.Main_Keeps_Frame, height = 100)
        self.Keep_Bar_Frame.pack(fill='x')
        #self.Keep_Bar_Frame.pack_propagate(False)
        # Now we will put the Keep bar in this frame
        # Now we will make another frame in which we will put the created Keep Card,

        self.ScrollFrame = ScrollFrame(self.Main_Keeps_Frame)
        self.Keep_Card_Container = Frame(self.ScrollFrame.ContentFrame, bg='white', relief='groove', bd=5)
        self.keepbar = Widgets.Keeps_Card.KeepCardBar(self.Keep_Bar_Frame,container_frame=self.Keep_Card_Container,
                                                      height = 200, width =50, relief = 'groove', bd=5)
        Widgets.Keeps_Card.KEEP_CARD_TITLE_BAR = self.keepbar


#-----------------------------------------------------------------------------------------------------------------------#
        #   RETRIEVING THE SAVED DATA
#-----------------------------------------------------------------------------------------------------------------------#
        # Now we will store the keep_card_container in the class variable
        Widgets.Keeps_Card.Keep_Card_Container = self.Keep_Card_Container
        # Now after storing the container frame we need to add existed keeps.
        if bool(Widgets.Keeps_Card.Keep_Card_Data):
            # Now we have something in data dict , in this we have stored card data

            List = [i for i in range(len(Widgets.Keeps_Card.Keep_Card_Data))]
            keepbar = Widgets.Keeps_Card.KeepCardBar(self.Keep_Bar_Frame)
            # get_keep_card_position will return two things
            # all card position and the recent card position.
            # we need all card position not the recent one.
            Pos, _ = keepbar.get_keep_card_position(List)

            for card, pos in zip(Widgets.Keeps_Card.Keep_Card_Data.items(), Pos):
                _, card_detail = card
                Widgets.Keeps_Card.Keep_Cards_List.append(card)

                # Now after getting the card detail and position we need to create object for each individual card.
                # This card will be need to put in the Keep_Card_Container frame.
                add_keep = Widgets.Keeps_Card.CreateKeepsCard(self.Keep_Card_Container)
                add_keep.Create_Keep_Card2(self.Keep_Card_Container,pos,card_detail)
                # Now we will append the card in Widgets.Keep_Card.Keep_Card_Objects list
                Widgets.Keeps_Card.Keep_Card_Object.append(add_keep)
                Widgets.Keeps_Card.KEEP_NEW_CHECK_TEXTBOX = add_keep
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
        self.keepbar.pack()
        self.ScrollFrame.pack(fill = 'both')
        self.Keep_Card_Container.pack(fill = 'both', expand=1, ipadx = 50)

        # Now we need data to create the Keeps.
        return self.Main_Keeps_Frame

    class DailyRoutineFrame(dr.DailyRoutine):
        """
        This class in Frame Frame_section will be used to create a frame in Notebook for DaliRoutine widgets.
            In this we will inherit our dr.DailyRotation ttk.Frame class which will hold all the functionality.
        """
        def __init__(self, master=None):
            """
            This will construct the ttk.Frame object which is held by the the notebook object it means that its parent will
                be a notebook object.
            :param master:
            """
            super().__init__(master)
            self.style = ttk.Style()
            self.style.configure("Routine.TFrame", background='#ebccff')
            self.style.configure("RoutineHead.TFrame", background='#ccd0ff')
            self.style.configure("RoutineContent.TFrame", background='#ffe7cc')
            self.style.configure("RoutineButton.TButton", shiftrelief=2, highlightcolor='red', highlighthickness='5')
            self.configure(style='Routine.TFrame')

            self.daily_app_func.init_daily_tasklist()  # initiating the daily tasklist data if they are not present
            self.daily_app_func.init_dailyroutine()  # initiating the daily routine data if it is not present
            # self.daily_app_func.retrieve_tasklists()  # retrieving the local task list data from the storage.
            # self.daily_app_func.retrieve_dailyroutine()  # retrieving the local daily routine dat from the storage.
            self.daily_app_func.filter_tasklist_items()

            self.scrollframe = ScrollFrame(self)
            self.contentframe = self.ContentFrame(self.scrollframe.ContentFrame, utility=self)
            self.headframe = self.HeadFrame(self, self.contentframe)
            self.headframe.pack(side='top', anchor='n', fill='x')
            self.contentframe.pack(side='top', fill='both', anchor='n', expand=1)

            self.scrollframe.pack(fill='both')

        class HeadFrame(ttk.Frame):
            """
            This class will be used to define all the HeadFrame functionality which is placed inside the DailyRoutineFrame class.
            """
            def __init__(self, master=None, container=None):
                super().__init__(master)
                self.master = master  # master is the object of DailyRoutine object
                self.container = container
                self.utility = self.master.daily_app_func
                self.configure(width=50, height=50, style='RoutineHead.TFrame')
                self.master.style.map("RoutineButton.TButton",
                                      background=[('hover', 'white')],
                                      relief=[('hover', 'raised'), ('pressed', 'sunken')],
                                      shiftrelief=[('pressed', 10)],
                                      highlightcolor = [('hover','black')],
                                      highlightthickness=[('hover',5)])

                # Now we will add a button which will be used to create a TaskList inside the content frame.
                self.add_tasklist_image = PhotoImage(file= './Resources/icons/icons8_tasks_32.png')
                self.add_tasklist = ttk.Button(self, text='add', takefocus=False, command=self.add_tasklist_command,
                                               image=self.add_tasklist_image, style="RoutineButton.TButton")

                self.add_tasklist.pack(side='right', anchor='e')


            def add_tasklist_command(self):
                """
                This method will be executed when the self.add_tasklist button is pressed.
                :return:
                """
                pos = len(self.master._taskcards_list_)  # getting the the length of the
                # Now we need to create a tasklist
                if pos % 3 == 0:
                    self.container.next_row += 1
                    self.container.next_col = 0
                else:
                    self.container.next_col += 1
                self.tasklist = self.master.TaskList(self.container)
                self.tasklist.grid(row=self.container.next_row, column=self.container.next_col, pady=20, padx=20, sticky='n')
                self.master._taskcards_list_.append(self.tasklist)

                # Now we need to generate a ids for every tasklist
                self.utility.get_tasklist_ids2()
                new_id = self.utility.gen_tasklist_id(self.tasklist.tasklist_title.get())

                data = {"Title":self.tasklist.tasklist_title.get(),
                        "Id":new_id}

                self.utility.add_daily_tasklist(data, new_id)

        class ContentFrame(ttk.Frame):
            """
            This class will be used to define all the content functionality which is placed inside the DailyRoutineFrame class.
            """
            def __init__(self, master=None, utility=None):
                super().__init__(master)
                self.master = master
                self.configure(width=50, height=50, style='RoutineContent.TFrame')
                self.next_row = 0
                self.next_col = 0
                self.parent = utility
                self.utility = utility.daily_app_func
                self.utility.retrieve_tasklists()
                self.utility.retrieve_dailyroutine()
                self.utility.filter_tasklist_items()
                self.retrieve_tasklist_cards()
            # Now we need to retrieve all the cards.
            # self.daily_routine_database_csv = DailyRoutine.CSV_DATABASE
            # self.daily_routine_database_json = DailyRoutine.JSON_DATABASE

            def retrieve_tasklist_cards(self):
                """
                This method will be used to retrieve all the cards which are saved on the local storage.
                :return:
                """
                self.task_db = self.utility.TASKLIST_DATABASE

                for key, value in self.utility.JSON_DATABASE.items():
                    # Now we need to create cards by using the current details.
                    pos = len(self.parent._taskcards_list_)  # getting the the length of the
                    if pos % 3 == 0:
                        self.next_row += 1
                        self.next_col = 0
                    else:
                        self.next_col += 1

                    self.tasklist = self.parent.TaskList(self)
                    self.tasklist.heading.label_var.set(value['Title'])
                    self.tasklist.tasklist_title = value["Title"]
                    self.tasklist.tasklist_id = key
                    self.retrieve_tasklist_card_tasks()
                    self.tasklist.grid(row=self.next_row, column=self.next_col, pady=20, padx=20,
                                       sticky='n')
                    self.parent._taskcards_list_.append(self.tasklist)

            def retrieve_tasklist_card_tasks(self):
                """
                This method will be used to retrieve tasklist card task from DailyRoutine.TASKLIST_DATABASE
                :return:
                """
                Id = self.tasklist.tasklist_id
                alltask = self.task_db.get(Id, {})

                for data in alltask:
                    if bool(data):
                        task = dr.DailyRoutine.CheckTask(self.tasklist.content)
                        task.textvariable.set(data["Task"])
                        task.TaskTitle = data["TaskTitle"]
                        task.notify = data["Notify"]
                        task.notify_time = data["NotifyTime"]
                        task.alert_time = data["AlertTime"]
                        task.alert_start_time = data["StartTime"]
                        task.completed = data["TaskCompleted"]
                        task.alert_end_time = data["EndTime"]
                        task.notify_day = data["NotifyDay"]
                        self.tasklist.heading.insert_task(task)
                        self.tasklist.tasklists_data.append(data)
                        if task not in self.tasklist.tasklist:
                            self.tasklist.tasklist.append(task)













