
import time, os , csv
from tkinter import messagebox
import calendar
import json
from collections.abc import Mapping
from calendar import Calendar


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
        This function will be used to track the idle time of the of the Tracks this will be in running mode always but
            it will paused during the stopwatch and the countdown of the Tracks
        :return: This will return the time in seconds.

        Note: The motive of the idle_timer is to moniter the idle time of the user during a day. This will be useful to monitor
            the idle time through out the day, week, month, year.
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

    def  get_month_number(self,month, abbr= False):
        """
        This will return the number of the month, in this we will provide the month name and it will give as the number
            of the month.
        :param month: str, This will be the full or short name of the month.
        :param abbr: bool, if this option is True it means we are give an abbreviated name of the name  of the month.
        :return: int, this will return the number of the month.
        """
        Months_Names = None
        if abbr:
            Months_Names = calendar.month_abbr
        else:
            Months_Names = calendar.month_name

        for month_number , month_name in enumerate(Months_Names):

            if month_name == month:
                return month_number




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
            
    def Save_data(self, file, data):
        """
        This function will be used to save the data in a file. this function will use the csv.dictwriter to save the data in a file.
        :param file: file in which we want to save the data. Please provide full path of the file.
        :param data: This is the data which will be passed in the csv.dictwriter to write the data. it must be a dictionary.
        :return:
        """
        if data != None:
            cols = data.keys()
            if os.path.isfile(file):
                with open(file, 'a', newline='') as file:
                    writer = csv.DictWriter(file, delimiter = ',', fieldnames = cols)
                    writer.writerow(data)
            else:
                with open(file, 'a', newline='') as file:
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


class Tracks_Cards:

    """
    This class will contain all the functionality to manipulate cards and their information.
    like it will have add_card, del_card, get_card, get_card_info, get_card_address etc.
    """
    def __init__(self, Card_key ="Topic" ):

        self.card_key = Card_key # This is the key for the parent database in which we will put the new SubCard Data.

    def SaveCard(self, CardName,Parent, Database, Subcard=None, FullName=None):
         # we need to import the json to work on the json files
        """
        This function will be used to save the card detail in json format. if the card is root then will save a with typname and id.
            but if the card is subcard then it will be saved inside the existing card.
        :param Database: This is the data which will saved in json format.
        :param Subcard: If it is true then we will save the card in the existing card.
        :param FullName: This is the full path of the Subcard, this will help us tho save the sub card.
        :return: None.
        """

        if Subcard:
            # if are saving the sub-cards then this section will be followed.
            filename = './Data/temp'
            Database = self.Add_SubCard(Parent = Parent, Child=CardName,Data = Subcard, Database=Database)
            with open(filename, 'w') as file:
                json.dump(Database,file, indent=2)

        else:
         # if we are saving the root-card then we will follow this section.
            # To save a root card what we will need
                # first the location and the name of the file on which we want to save the data
                # Second, In which format we need to save the data.
            filename = './Data/temp'
            with open(filename, 'w') as file:
                json.dump(Database,file, indent=2)

    def Read_Cards_Database(self, fileName = './Data/temp'):

        if os.path.isfile(fileName):
            if os.path.getsize(fileName) != 0:

                with open(fileName, 'r') as file:
                    Database = json.load(file)
                return Database
            else:
                print("File is empty")
                return {'Root':{}}
        else:
            print("File Not found")
            file = open('./Data/temp','w')
            file.close()
            return None

    def Add_Root_Card(self,CardName, **Cardinfo):

        # These are some standard card information there can be more info keys in future
        RootCard = {"Root":{CardName:{'Type':'Project',
                              'Name':CardName,
                              'Date': time.strftime("%d-%b-%Y"),
                              'Time':time.strftime("%I:%M:%S %p"),
                              'Topic':{}, #
                              'Target Hour':0,
                              'Progress':0,
                              'Parent':CardName,
                              'FullPath':'RootCard',
                              'Childs':0}}}

        for InfoKey in Cardinfo:
            # Now we will update our default card information as it given.
            RootCard["Root"][CardName][InfoKey] = Cardinfo[InfoKey]

        return RootCard

    def Add_SubCard(self, Parent, Child, Data, Database):
        """
        This function will be used to add a new sub card in the inside an existing card, the existing card will
            be a parent card and a Child card will be placed inside this parent card.
        :param Parent: Parent Card can be a root card in which all the other cards are placed or it can be a Child card which is also used
            a parent of another child cards.
        :param Child: This is the Child which will be put inside the parent card.
        :param Data: This is the Data of the Child card.
        :param Database: This must be the Database of whole tracks not of an individual card database.
        :return : None
        """
        ParentList = Parent.split('.')

        def deep_update(parentlist, child,data,database):
            self.database = database
            self.key = None
            if len(parentlist) == 0:
                # if we are end of the parent list then we need to update the Databse
                #print("Adding new card in databse:- ",list(self.database.keys())[0],self.database)
                self.database[self.card_key].update(data)
                return self.database

            else:
                self.key = parentlist[0]
            if isinstance(self.database.get(self.key, None), Mapping):
                # Now if we are in Card dir then we need to remove used parent and return to the method again.
                parentlist.pop(0)
                self.database = deep_update(parentlist, child,data,self.database.get(self.key,None))

            else:

                if isinstance(self.database.get(self.card_key, None), Mapping):
                    self.database = deep_update(parentlist, child, data, self.database.get(self.card_key, None))


                return self.database
            #print("Database:",self.database)
            #print(f"{'_'*100}\n{'_'*100}\n{'_'*100}")
            return database
        return deep_update(ParentList, Child, Data, Database)

    def Get_Card(self,Parent, Child,Database):
        """
        This function will be used to get the details associated with a card.
        :param Parent: This will be the name/fullpath of the parent of the Child.
        :param Child: This is the child name for which we are looking for.
        :param Database: This is the Database more like nested dictionaries.
        :return: it will return the Child data information in the form of dictionary.
        """
        Parents = Parent.split('.')

        for parent in Parents:
            Database = Database[parent][self.card_key]
            # This loop will help us to reach final or direct parent of the child.
            # Now after reaching at the direct parent of the child we need to return the Child Database.
        return Database[Child]
        # by this line we will update our existing Database with a new Child/subcard.

    def Get_Card_Address(self,Parent, Child,Database):
        """
                This function will be used to get the details associated with a card.
                :param Parent: This will be the name/fullpath of the parent of the Child.
                :param Child: This is the child name for which we are looking for.
                :param Database: This is the Database more like nested dictionaries.
                :return: it will return the Child data information in the form of dictionary.
                """

        # This function will be define later.

        # Now
        # by this line we will update our existing Database with a new Child/subcard.


    def Delete_SubCard(self,Parent,Child,Database):
        """
        This function will be used to delete a subcard which is placed inside a root card or in subcards, This function
            will only delete the SubCard which is passed in the child argument.
        :param Parent: This is the parent address of the child which is need to delete.
        :param Child: This is the child Name which is to be deleted.
        :param Database: This is the database in which we want to look for the child.
        :return: None
        """
        Parents = Parent.split('.')

        for parent in Parents:
            Database = Database[parent][self.card_key]
            # This loop will help us to reach final or direct parent of the child.
            # Now after reaching at the direct parent of the child we need to return the Child Database.
        del Database[Child]

    def Retrieve_Cards(self,Database):
        """
        This method will be used to retrieve all the card information in a database and it will be use to make cards.
        :param Database: dict object, Database which contains all the card information.
        :return: This will return a generator---> yield.
        """
        for key, value in Database.items():
            # Now we need to check that an item with associated key is a dict or not
            # for that we will use Mapping class from collections.abc
            if isinstance(Database.get(key, None), Mapping):
                # this condition will check that an incoming object is a dict or not.
                # Now we need to yield the key and values
                yield (key, value) # This will return every sub dictionary in a dict.

                yield from self.Retrieve_Cards(Database.get(key, None))
                # after yielding and object we need to recall the our method again so it can yield more values.
