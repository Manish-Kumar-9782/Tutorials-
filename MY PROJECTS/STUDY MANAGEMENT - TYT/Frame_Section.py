# In this file we will cover all the widget defination which will be used many times on the dashboard.
from tkinter import Tk, Toplevel ,Frame, BOTTOM,LEFT,RIGHT,TOP , BOTH , Button
from Apps import Tracks
from Widgets import Widgets
from Apps_func import Keep_Cards

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

    def Tracks_Frame(self ,master, height=100,width=100, cfg = None):

        # We need a Create_ProgressBar() object from a widges module
        tracks = Frame(master,height=height,width=width , bg = 'red')
        tracks.pack_propagate(False)

        # Top section
        top_section = Frame(tracks , height = 20, bg = 'white')
        top_section.pack(side=TOP, fill = 'x', expand = 0 , anchor = 'n')

        # Here in this top section we will put progress bar and set_today_target button
        # first we will set the set_target-button
        set_target_button = Button(top_section,text='Set')
        set_target_button.pack(side=RIGHT, anchor='e')

        # now here we will make a top level window when the button is pressed
        def Set_Target():
            root = Toplevel()
            self.Tracks.Set_Today_target(root)

        set_target_button.config(command = Set_Target)
        progressbar= self.Wid.Create_ProgressBar()
        progressbar.progressbar(top_section)
        # Now we need to put the progress bar

#----------------------------------------------------------------------------------------------------------------------##
#----------------------------------------------------------------------------------------------------------------------##
        # Mid Secion
        mid_section = Frame(tracks , bg = 'blue')


        # here we need to retrieve the data and need to make the Cards.
        self.Tcards = Widgets.Track_Card(mid_section)
        print("Databse",self.Tcards.Tracks_Cards_Database)
        self.Tcards.Retrieve_Cards(mid_section,self.Tcards.Tracks_Cards_Database)
        # wid.Create_Track_Record_Card(mid_section)

        mid_section.pack(fill=BOTH, expand=True)
        # Now here we need to

#----------------------------------------------------------------------------------------------------------------------##
#----------------------------------------------------------------------------------------------------------------------##
        # Bottom Section
        bottom_section = Frame(tracks , height = 20, bg = 'white')
        bottom_section.pack(side=BOTTOM, fill = 'x', expand = 0 , anchor = 's')

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
        self.Keep_Card_Container = Frame(self.Main_Keeps_Frame, bg='white', relief='groove', bd=5)
        self.keepbar = Widgets.Keeps_Card.KeepCardBar(self.Keep_Bar_Frame,container_frame=self.Keep_Card_Container,
                                                      height = 200, width =50, relief = 'groove', bd=5)


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
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
        self.keepbar.pack()
        self.Keep_Card_Container.pack(fill = 'both', expand=1, ipadx = 50)

        # Now we need data to create the Keeps.

        return self.Main_Keeps_Frame