
# In this file we will cover all the widget defination which will be used many times on the dashboard.
from tkinter import Tk, Toplevel
from Apps import Tracks

class widgets:
    
    def __init__(self):
        self.Tracks = Tracks()


    def Tracks_Section(self , master = None):
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

        def init_tracks(master):
            tracks = Tracks(master)
            tracks.BottomSection(master)
            tracks.add_time_record_button.config(command=create_add_timer_record_toplevel)

        if master != None:
            tracks = Tracks(master)
            tracks.BottomSection(master)
            tracks.add_time_record_button.config(command=create_add_timer_record_toplevel)

        else:
            root = Toplevel()
            self.Tracks.BottomSection(root)
            self.Tracks.Add_Time_Record(root)
            self.Tracks.add_time_record_button.config(command = create_add_timer_record_toplevel)
            root.mainloop()
        
        
        