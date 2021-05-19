
import time, os , csv
from tkinter import messagebox


# This module will cover all the small application functionallity which will be used together in the dashboard and the main appication.
"""Apps:
1. Start_time
2. Countdown
3. Time
"""
class Time:

    def __init__(self):
        self.Idle_Time = 0
        self.Idle_init_time = time.mktime(time.localtime())
        self.Idle_Timer_status = None # it can be Running or Stopped.

    def time_to_seconds(self, time):
        # first separate the hour , minute and second.
        if isinstance(time,str):
            hr, mins, sec = [int(i) for i in time.split(":")]
            #print("spliting the time:",hr, mins, sec)
        elif isinstance(time,tuple) or isinstance(time, list):
            hr, mins, sec = [int(i) for i in time]
        # now convert them into second.
        return hr*3600 + mins*60 + sec

    def sec_to_time(self ,second , rt_str = False):
        """
        This function will take the seconds and it will return time in the form of hr:min:sec
        second: seconds which is needed to convert into time format.
        rt_str: by default False, if we want to return the time in string format this set this as string.`
        """
        if isinstance(second,str):
            second = int(second)
            Min, Sec = second // 60 , second % 60
            Hr, Min =  Min // 60 , Min % 60

        else:
            Min, Sec = second // 60, second % 60
            Hr, Min = Min // 60, Min % 60

        if rt_str:
            return f"{Hr:02d}:{Min:02d}:{Sec:02d}"
        else:
            return Hr,Min ,Sec

    @staticmethod
    def get_current_data():
        return time.strftime("%d-%b-%Y")

    @staticmethod
    def get_current_time():
        return time.strftime("%I:%M:%S %p")

    def idle_timer(self):
        """
        This function will be used to track the idle time of the
        :return: This will return the time in seconds.
        """
        # here we need to use the global instance to start and stop the idle time.
        if self.Idle_Timer_status == "Running":

            self.Idle_Time += time.mktime(time.localtime()) - self.Idle_init_time

        elif self.Idle_Timer_status == "Run":

            self.Idle_Time += time.mktime(time.localtime()) - self.Idle_init_time
            self.Idle_init_time = time.mktime(time.localtime())

        elif self.Idle_Timer_status == "Pause":
            self.Idle_init_time = time.mktime(time.localtime())

        elif self.Idle_Timer_status == 'Pause_Idle':
            self.Idle_Time += self.Idle_Time
            self.Idle_init_time = time.mktime(time.localtime())



    class StopWatch:

        def __init__(self):
            """In this we will initialize the seconds, minute and hours"""
            self.init_sec = time.time()
            self.Sec = int()
            self.Min = int()
            self.Hour = int()

        def stopwatch(self):
            """
            this function will return the time elapsed from the starting of the timer.
            :return: This will return the time elapsed after starting of the timer.
            """
            # NOw we will count the fresh seconds from the starting of the timer
            self.Sec = abs(int(time.time()) - int(self.init_sec))
            # now second will starts from the zero now we can count the Hour and minutes.

            # Now if the seconds are become 60 then we need to reset the seconds
            if self.Sec == 60:
                # need to reset the seconds
                self.init_sec = time.time()
                self.Sec = abs(int(time.time()) - int(self.init_sec))
                # now need to increase the minutes
                self.Min += 1

            # Now if minutes reach to the 60 minutes then we need to reset the minutes.
            if self.Min == 60:
                # need to increase the Hour
                self.Hour += 1
                self.Min = 0

            return f"{self.Hour:02d}:{self.Min:02d}:{self.Sec:02d}"

    class Countdown:

        def __init__(self,seconds):
            self.Hour = int()
            self.Min = int()
            self.Sec = int()
            self.seconds = seconds

        '''
        1. first we need to convert sec-to-min and it will return ---> (minute, seconds)
        2. Second we need to convert min-to-hr and it will return ----> (hour, minute)
        3. finally return --->(hour,minute,seconds)
        '''

        def _minutes_(self):
            # in this we will return the minutes and seconds
            # we used mod operator on the seconds to get the seconds
            # and we divided the seconds with 60 to get the minutes.
            return self.seconds // 60 , self.seconds % 60

        def _hour_(self):
            # in twe will return the hours and minutes , in this we need to use the _minutes_() method to get the minutes.
            minute, self.Sec = self._minutes_()
            # in this we need to divide the minute with 60 to get the time in hour and we need to use the % mod on the
            # minute to get the remaining minutes
            return minute // 60 , minute % 60

        def timer(self):
            # in this timer function we need to make to function one is for sec-to-min and another is for the min-to-hour
            self.Hour , self.Min = self._hour_()
            return self.Hour, self.Min , self.Sec


class SaveTime:

    """
    This class will be used to save the time on the local storage, local disk.
    """
    def __init__(self):
        pass

    def save_countdown_time(self,fp, data=None):
        """
        This function is used to save the time. This function will take single day data at once. if we are getting the
        data multiple times then it will store the data in same row but it will use different columns.

        :param data: Data is dict which contains the datetime, time, restart time, idle time etc.
        :param fp: file path at which the time need to be stored.
        :return: Nothing.
        """
        if data != None:
            columns = data.keys()
        time_data = list()
        isdata = False
        if os.path.isfile(fp):
            # if there is already a time_data then first we need to read it.
            with open(fp,'r' , newline='') as tfile:
                reader = csv.reader(tfile , delimiter = ',')
                # now after reading the file we need to put the new data in the file.
                for value in reader:
                    time_data.append(value)
            print(time_data)


        # now we have the old time data , if there was.
        if len(time_data) == 0 :
            # if data is none then we have some data in the file.
            # so now we need to add new data.
            # fisrt of all we need to separate the columns.
            with open(fp, 'w', newline='') as tfile:
                write = csv.writer(tfile, delimiter=',')
                write.writerow(columns)  # writing the columns
                write.writerow(data.values())  # writing the first line data.
        else:
            print("old data: ",time_data[0])
            print("new data: ",data.keys())
            if len(time_data[0] ) < len(data.keys()):
                # if new data has more column then we need add them in our existing data.
                time_data[0] = data.keys()
                time_data.append(data.values())
            else:
                time_data.append(data.values())
                
            with open(fp, 'w', newline='') as file:
                write = csv.writer(file, delimiter =',')
                for row in time_data:
                    write.writerow(row)

    def save_today_target_time(self , data = None):
        
        """
        This function will be used to set the working time target on and it will be monitored by a progress bar.
        :param data: this will be dictionary in which all the values will be passed to csv writer.
        :return: None
        """

        if data != None:
            cols = data.keys()
            if os.path.isfile("./data/daily_target.csv"):
                with open("./data/daily_target.csv", 'a', newline='') as file:
                    writer = csv.DictWriter(file, delimiter = ',', fieldnames = cols)
                    writer.writerow(data)
            else:
                with open("./data/daily_target.csv", 'a', newline='') as file:
                    writer = csv.DictWriter(file, delimiter = ',', fieldnames = cols)
                    writer.writeheader()
                    writer.writerow(data)

        else:
            messagebox.showerror(title="Save Error", message="Can't save the target time.\nwe got a None value to save the data.")
            
            
        

class widget:

    def __init__(self):
        pass

    def Position_Timer(self, master, pos="Center"):
        """
        This method will be set the position of the timer widget.
        :param x: x value at which we want to set the timer.
        :param y: y value at which we want to set the timer.
        :return: ----> str  ,this will return the desired geometry of the top level window.
        """
        master.update_idletasks()
        # getting the widow geometry
        window_height = master.winfo_height()
        window_width = master.winfo_width()
        print("Screen Info: ", master.winfo_geometry())
        # now we will get the dpi and screen size
        dpi = int(master.winfo_fpixels('1i'))
        screen_width = master.winfo_screenwidth()
        screen_height = master.winfo_screenheight()

        screen_width = screen_width * dpi // 96
        screen_height = screen_height * dpi // 96

        # now we have got the screen_size so we need to get the center point of the screen.
        # Note that we also need the center point of the window, this will be subtracted from the screen_center

        # NOw we will define the screen_center points as sc_x, sc_y
        # and the window center points as wc_x, wc_y
        sc_x, sc_y = screen_width // 2, screen_height // 2
        wc_x, wc_y = window_width // 2, window_height // 2

        # Now to make the center we need to do this
        # center_height = cneter_of_screen_height - center_of_window_height
        # cneter_width  = center_of_screen_width  - center_of_window_width

        Height_center = sc_y - wc_y
        Width_center =  sc_x - wc_x  # Now we have got the center of the window.

        # Now we need to put this window at one position from (Top, Bottom, Left, Right,Center, TopLeft, TopRight, BottomLeft, BottomRight)

        # now we have got our center point from now we can move this window at any position from above list.
        # For this we need use the position dictionary.
        '''
         Now we will define a relative position directory, it will contain this locations (Top, Bottom, 
         Left, Right,Center, TopLeft, TopRight, BottomLeft, BottomRight) 
        '''
        # Now we need to put this center
        _Y_ = sc_y - wc_y
        _X_ = sc_x - wc_x
        bmg = 70
        # Note: WE need to set some margin for the bottom position, our window positioned just above the taskbar

        Positon = {"Top": (Width_center, Height_center - _Y_),
                   "Bottom": (Width_center, Height_center + _Y_ - bmg),
                   "Left": (Width_center - _X_, Height_center),
                   "Right": (Width_center + _X_, Height_center),
                   "Center": (Width_center, Height_center),
                   "TopLeft": (Width_center - _X_, Height_center - _Y_),
                   "TopRight": (Width_center + _X_, Height_center - _Y_),
                   "BottomLeft": (Width_center - _X_, Height_center + _Y_ - bmg),
                   "BottomRight": (Width_center + _X_, Height_center + _Y_ - bmg),
                   }
        print("Center is :", Width_center, Height_center)

        return window_width, window_height, Positon[pos][0], Positon[pos][1]

    def Label_config(self, label ):
        pass

