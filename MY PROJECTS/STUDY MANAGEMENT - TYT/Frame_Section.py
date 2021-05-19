# In this file we will cover all the widget defination which will be used many times on the dashboard.
from tkinter import Tk, Toplevel ,Frame, BOTTOM,LEFT,RIGHT,TOP , BOTH , Button
from Apps import Tracks
from Widgets import Widgets


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


    def Tracks_Frame(self ,master, height=100,width=100, cfg = None):

        # We need a Create_ProgressBar() object from a widges module
        self.Wid = Widgets.Create_ProgressBar()

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
        self.Wid.progressbar(top_section)
        # Now we need to put the progress bar




#----------------------------------------------------------------------------------------------------------------------##
#----------------------------------------------------------------------------------------------------------------------##
        # Mid Secion
        mid_section = Frame(tracks , bg = 'blue')
        mid_section.pack( fill = BOTH, expand = True)

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
        _Keeps_Frame = Frame(master = master, height=height, width=width, bg = 'white')
        _Keeps_Frame.pack(fill = 'both', expand = True)
        if cfg:
            _Keeps_Frame.config(cnf=cfg)



        return _Keeps_Frame