
import time, os , csv
import tkinter.messagebox
from tkinter import messagebox
import calendar
import json
from collections.abc import Mapping
from calendar import Calendar


# This module will cover all the small application functionality which will be used together in the dashboard and the main application.
"""Apps:
1. Start_time
2. Countdown
3. Time
"""
class Misc:
    """
    This class will hold some basic and common operation on data
    """
    def is_key_present(self,dict, key):
        """
        This method will be used to check that a key is present in a dictionary or not. this method does not work on a nested key.
        :return: bool, this will return True if key is present else False.
        """
        return key in dict.keys()

    def is_content(self,object):
        """
        This method will be used to check that if an object contains something or not.
        :return: bool, This will return True if content is present else Flase.
        """
        if bool(object):
            return True
        else: return False


class Time:

    def __init__(self):
        self.Idle_Time = 0
        self.Idle_init_time = time.mktime(time.localtime())
        self.Idle_Timer_status = None # it can be Running or Stopped.

    def time_to_seconds(self, time):
        # first separate the hour , minute and second.
        hr, mins, sec = 0, 0, 0
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
    def get_current_date():
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
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
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
        self.file = './data/Timer_Data.csv'
        self.existing_fields =None
        self.existing_data = None
        self.New_fields = None
        temp_data = []
        # Now first of all we need to check the data is coming or not to save in local storage
        if data != None:
            self.input_fields = data.keys()

            # Now if we get the data then first we need to check old data if it exist.
            if os.path.isfile(self.file):
                # now we will check is file empty or not
                if os.path.getsize(self.file) != 0 :
                    # if file is not empty then we will need to retrieve old data
                    # Now in this condition first we will retrieve old data new we will merge this our new data into old
                    # data.
                    with open(self.file, 'r', newline='') as read:
                        reader = csv.DictReader(read)
                        self.existing_fields = reader.fieldnames
                        # Now we need to update old data with
                        for row in reader:
                            if len(self.input_fields) > len(self.existing_fields):
                                for key in self.input_fields:
                                    if key not in self.existing_fields:
                                        row.update({key:None})
                                self.New_fields = row.keys()
                            else:
                                 for key in self.existing_fields:
                                     if key not in self.input_fields:
                                         data.update({key:None})

                            # Now here we need to store the data for temporary
                                 self.New_fields = data.keys()

                            temp_data.append(row)
                    # Now after getting all the data we need to write new data into file after
                    with open(self.file, 'w', newline='') as write:
                        write = csv.DictWriter(write, fieldnames=self.New_fields)

                        # writing the heading/columns of files.
                        write.writeheader()

                        # first we will write old data into file
                        for row in temp_data:
                            write.writerow(row)

                        # Now at the end we will write new data.
                        write.writerow(data)

                    # Now after doing all work we need to delete the temp data from memory
                    del temp_data

                else:
                    # if file is empty then we need to insert new data.
                    with open(self.file, 'r', newline='') as write:
                        writer = csv.DictWriter(write, fieldnames=self.input_fields)
                        writer.writerow(data)
        else:
            print("No Countdown timer data to save...")

    def save_today_target_time(self , data = None):

        """
        This function will be used to set the working time target on and it will be monitored by a progress bar.
        :param data: this will be dictionary in which all the values will be passed to csv writer.
        :return: None
        """
        self.file = "./data/daily_target.csv"
        self.current_date_data = None
        self.today_fields = data.keys()
        self._today_target = False
        temp_data = []  # in this we will store our daily_target data for temp time.
        if data != None:  #
            # Now data has a values in dictionary format
            # Now we need to check that if there is current date data exist or not because there is only line can exist
            # for a day.
            if os.path.isfile(self.file):
                if os.path.getsize(self.file) != 0:
                    # file no empty then we need to get current date data

            ##=============================  FIRST GETTING THE EXISTING DATA===========================
                    with open(self.file, 'r', newline='') as read:
                        reader = csv.DictReader(read)
                        self.today_fields = reader.fieldnames
                        for row in reader:
                            if row['Date']== Time.get_current_date():
                                temp_data.append(data)  # modifying the current date time
                                self._today_target = True  #
                            else:
                                temp_data.append(row)  # if we dont have curr

                    if not self._today_target:
                        # if dont found any entry indie the database then we will add new entry
                        temp_data.append(data)

            ##=============================  UPDATING THE DATABASE WITH NEW ENTRY ===========================
                    with open(self.file, 'w',newline = '') as write:
                        writer = csv.DictWriter(write, fieldnames=self.today_fields)
                        writer.writeheader()
                        for row in temp_data:
                            writer.writerow(row)

                    del temp_data

                else:
                    # if we found an empty file then we need to write the very first entry
                    with open(self.file, 'w', newline='') as write:
                        writer = csv.DictWriter(write, fieldnames=self.today_fields)
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
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
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
        #print("Screen Info: ", master.winfo_geometry())
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
        #print("Center is :", Width_center, Height_center)

        return window_width, window_height, Positon[pos][0], Positon[pos][1]

    def Label_config(self, label ):
        pass
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
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
                              'Completed Hour':0,
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
        data = Database
        parents = Parent.split('.')

        for parent in parents:
            if Parent != 'Root' and parent != 'Root':
                data = data[parent]['Topic']
            else:
                data = data[parent]

        return data[Child]
        # by this line we will update our existing Database with a new Child/subcard.

    def update_card(self,cardName,cardParent,carddata, Database):
        """
        This method will be used to update a card data.
        :param cardName: str,this is the card name which is need to update.
        :param cardParent: str, card parent name.
        :param carddata: dict, updated card data.
        :param Database: dict, Cards Database.
        """
        data = Database
        parents = cardParent.split('.')

        for parent in parents:
            if cardParent != 'Root' and parent != 'Root':
                data = data[parent]['Topic']
            else:
                data = data[parent]

        data[cardName].update(carddata)
        return Database
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

    def Retrieve_Cards_Names(self,Database):
        """
        This method will only return the Card Names form the Database.
        :param Database: dict, Database from which we need cards.
        :return: list, it will return a list of tuples
        """
        for key ,card in self.Retrieve_Cards(Database):

            if key != 'Root':
                if key != "Topic":
                    yield key,card['FullPath']

    def Get_Card_Type(self,Database,parent,child):
        """
        This method will be used to get the card type by using its parent.
        :param parent: parent card name of child card.
        :param child: child name
        :return: str, this will return the card type
        """
        db = Database.get('Root')
        if parent == 'Root':
            return  db[child]['Type']

        elif len(parent.split('.'))>=2:

            root_parent = parent.split('.')[:2][1]
            print(f"parent to root_Parent:",parent,"\t",parent.split('.'))
            return db[root_parent]['Type']

    def Insert_Key(self,key, value,Database):
        """
        This method will be used to insert a key in Track Card Database.
        :param key: str, Name of the key which need to be inserted in the database.
        :param value: any, value associated with the key,
        :param Database:dict or json object, Database in which we need to insert the key.
        :return:
        """
        file = './data/temp'
        for element_key, cardetail in self.Retrieve_Cards(Database):

            if element_key != 'Root':
                if element_key != 'Topic':
                    cardetail[key] = value

        # Now we need to save the database.
        with open(file, 'w') as write:
            json.dump(Database, write, indent = 2)


#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
class Keep_Cards:
    """
    this class will be used to manage the logical functionality of the Keep section of the application.
    """
    def __init__(self):
        self.Unique_ids = None
        self.KeepCards_Data = None

    def get_unique_id(self, file ='./data/KeepCards.json' ):

        """
        This method will be used to retrieve the unique ids stored in a file.
        :return:
        """
        self.card_data = {"Cards":{},
                          "Card_ids":[]}
        # we will store all card inside the Cards and we will store all ids inside the Card_ids.
        if os.path.isfile(file):
            # then we need to check the file is empty or not.
            if os.path.getsize(file) != 0:
                with open(file,'r') as f:
                    read = json.load(f)
                    self.Unique_ids = read.get("Card_ids", None)
                    return self.Unique_ids
            else:
                # file is empty then we need to create new file.
                with open(file,'w') as f:
                    json.dump(self.card_data)
                return None


    def retrieve_keep_card_data(self, file ='./data/KeepCards.json' ):
        """
        This function will be used to retrieve the card data if it exist.
        :return:
        """
        if os.path.isfile(file):
            if os.path.getsize(file) != 0:
                with open(file,'r') as f:
                    self.KeepCards_Data = json.load(f)
        else:
            print('Keep card Data file not found....')

        return self.KeepCards_Data['Cards'], self.KeepCards_Data['Card_ids']


    def initiate_keep_card_data_storage(self, file= './data/KeepCards.json'):
        """
        This function will be used to initiate KeepCard data if there is no card data present in the file.
        :return:
        """
        self.card_data = {"Cards": {},
                          "Card_ids": []}
        if not os.path.isfile(file):
            # if file is empty then we need to initiate the format of the card data.
            try:
                with open(file, 'w') as f:
                    json.dump(self.card_data,f, indent=2)
                    #print("Card data initiated...")
            except:
                    print("Unable to initiate the KeepCard data file.")
        else:
            if os.path.getsize(file) == 0:
                os.remove(file)
                return self.initiate_keep_card_data_storage()

    def save_keep_card_data(self,keepcarddata,keepcardids,update=0,**DataValues):
        """
        This class will be used to save the data of a card. Card data will be saved in two format, one is json and other is csv format.
        JSON: json format data will contain card attributes like date, time, title, marked, id etc.
        csv: csv format will hold id, title, and the card checks data.

        we will identify our card with the id of the card.
        :param keepcarddata: dict, a dictionary which holds all the cards information.
        :param keepcardids: list, a list which holds all the cards ids.
        :param update: bool, this will be used to update a card.
        :param **DataValues: keyword argument to be saved in local storage.
        """
        file = './data/KeepCards.json' # database file in which we will store all the data.

        #print("Need to save these data.")
        #print(DataValues)
        #print("keepcarddata: ",keepcarddata)
        #print("keepcardids: ",keepcardids)

        self.card_data = {"Cards": {},
                       "Card_ids": []}

        if update:
            # this section will be called when we are updating the card details.

            self.card_data["Cards"].update(keepcarddata)
            self.card_data["Card_ids"] = keepcardids
            try:
                with open(file, 'w') as f:
                    json.dump(self.card_data, f,indent=2)
            except:
                print(f"Unable to update the card details.")
        else:
            # This section will be called when we are creating a new card.

            card = {DataValues['title']:{'title':DataValues['title'],
                                         'Id':DataValues['Id'][0],
                                         'date':DataValues['date'],
                                         'time':DataValues['time'],
                                         'content':DataValues['content']}}
            #print("new card data: ", card)
            keepcarddata.update(card)
            keepcardids.append(DataValues['Id'][0])
            self.card_data["Cards"].update(keepcarddata)
            self.card_data["Card_ids"] = keepcardids

            #print("Card data saved: ",self.card_data)
            if os.path.isfile(file):
                with open(file,'w') as f:
                    json.dump(self.card_data,f, indent=2)


            return DataValues


    def load_keep_card_data(self):
        """
        This function will be help to load the keep card data form the local storage and this method will be called before
        Creating Keep Card.
        :return: tuple, this will return a keep card dat.
        """
        # first of all we will initiate our keep card data, this will be done one once
        # after creating a file this method wont create new file.
        self.initiate_keep_card_data_storage()

        # Now if we have initiated our file, now we need to retrieve all the available data on the local storage.
        self.KeepCards_Data, self.KeepCard_ids = self.retrieve_keep_card_data()

        return self.KeepCards_Data, self.KeepCard_ids
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
class tth_progress:
    """
    This class will be used to update tth progress bar on the Dashboard.
    """
    def __init__(self):
        self.daily_target_file = "./data/daily_target.csv"
        self.data_fields = None
        self.file_data = None
        self.today_data = None
        self.today_date = Time.get_current_date()
    def get_today_target(self):
        """
        This method will be used to get the today target record from the csv file which is stored on a local storage.
        This method will retrieve the data .
        :return: list, this will return a list of tuple which will hold the time range for today or recent day.
        """
        if os.path.isfile(self.daily_target_file):
            if os.path.getsize(self.daily_target_file) !=0:
                with open(self.daily_target_file,'r', newline='') as file:
                    reader = csv.DictReader(file)
                    self.data_fileds = next(reader)
                    for row in reader:
                        if row['Date'] == self.today_date:
                            self.today_data = row
                            break
            else:
                print("Daily target file has no data.")
                #messagebox.showwarning(title='Error',message='No data' )

        else:
            print("file not found.Creating a new file")
            file = open(self.daily_target_file,'w')
            file.close()

    def set_today_target(self,target):
        """
        This method will be used to set the today_target time
        :param target: list, target will be a list of tuples.
        :return:
        """
        temp = []
        today_present = False
        with open(self.daily_target_file, 'r') as read:

            Data = csv.DictReader(read)
            self.data_fileds = Data.fieldnames

            for row in Data:
                # checking for today date.
                if row["Date"] == Time.get_current_date():
                    row["l1l"] = target[0][0]
                    row['l1h'] = target[0][1]
                    row['l2l'] = target[1][0]
                    row['l2h'] = target[1][1]
                    row['l3l'] = target[2][0]
                    row['l3h'] = target[2][1]

                    today_present = True
                    break
            if not today_present:
                self.today_data = {"Date":Time.get_current_date(),
                                   "Time":Time.get_current_time(),
                                    "l1l" : target[0][0],
                                    'l1h' : target[0][1],
                                    'l2l' : target[1][0],
                                    'l2h' : target[1][1],
                                    'l3l' : target[2][0],
                                    'l3h' : target[2][1]
                }

class Activity_Classes:
    """
    This class will be used to define different type of classes in the application and it will manage which activity should
        place in which class.There are different kind of activity like Reading, Working, daily activity, Project, Subject,
        Playing

        ActivityClasses :{}
        TracksActivity:{}
        WatchActivity :{}
        NoWatchActivity :{}
    """
    def __init__(self):
        """
        This init method will initiate the activity record if there is no activity record with empty database. (self.init_activity_record())
        it will also retrieve activity record database and stroe them in self.Activity_Database attribute.

        methods in init:-
            self.init_activity_record()
            self.retrieve_activities()
        """
        self.COUNT_TIMER = [] # store all activities which need to watch.
        self.IDLE_TIME_COUNT = [] # store all activities which need to remain in idle and store their time in background

        self.misc = Misc()

        self.Activity_Database = None # store complete activity database.
        self.init_activity_record()  # init_activity_record will create a activity record file with not activity.
        self.retrieve_activities()

    def add_activity(self,Type, Name):
        """
        This method will be used to add new activity in the database.
        :param type: type of the activity.
        :param name: name of the activity.
        :return:
        """
        # first of all we will check that ActivityClasses is emtpy or not
        if self.misc.is_content(self.Activity_Database["ActivityClasses"]):
            content = self.Activity_Database["ActivityClasses"]
            # if it give us true then we will go through this and it means that there is some data in ActivityClasses.

            # Now we will check that content has something or not
            if self.misc.is_key_present(self.Activity_Database["ActivityClasses"], Type):
                if self.misc.is_content(content[Type]):
                    if isinstance(content[Type], list):
                        if Name not in content[Type]:
                            content[Type].append(Name)
                        else:
                            print("Activity already exists.")
                else:
                    # if content does not have something, then we will insert a list with one value.
                    content[Type] = [Name]
            else:
                content[Type] = [Name]
        else:
            # if it gives us false then it means the ActivityClasses are empty.
            self.Activity_Database["ActivityClasses"].update({Type:[Name]})

        # at last we will save our data.
        self.save_activities()
    def delete_activity(self):
        """
        This method will be used to delete an activity form the database.
        :return:
        """

    def save_activities(self, filepath = './data/activities.json'):
        """
        This method will be used to save all the activities in local storage database.
        :param Database: currently used database which holds all current saved activities.
        :param filepath: file path at which we will store the new things.
        :return:
        """
        with open(filepath,'w') as write:
            json.dump(self.Activity_Database,write, indent=1)


    def retrieve_activities(self, filepath = './data/activities.json'):
        """
        This method will be used to retrieve all the activities from the locally saved database.
        :param filepath: file path at which the database is stored.
        :return: dict
        """
        # self.Activity_Database =
        if os.path.isfile(filepath):
            if os.path.getsize(filepath) != 0:
                with open(filepath, 'r') as read:
                    self.Activity_Database = json.load(read)

        return self.Activity_Database

    def retrieve_Tracks_Actvity(self):
        """
        This method will be used to retrieve tracks data and add them in the TracksActivity list.
        :return:
        """

    def retrieve_Watch_Activities(self):
        """
        This method will be used to retrieve WatchActivities from the database.
        :return:
        """
        file = './data/activities.json'

        if os.path.isfile(file):
            if os.path.getsize(file) != 0:
                with open(file,'r') as read:
                    data = json.load(read)
        return data['WatchActivity']


    def init_activity_record(self):
        """
        This method will be used to initialize the activity record.
        :return:
         ActivityClasses :{}
        WatchActivity :{}
        NoWatchActivity :{}
        """
        print("initiating the activity record")
        file = './data/activities.json'
        Database = {"ActivityClasses":{},
                    "TracksActivity":{},
                    "WatchActivity":{"Project",'Subject'},
                    "NoWatchActivity":{}}

        if not os.path.isfile(file):  # if file is not present
            with open(file, 'w') as write:
                json.dump(Database, write, indent=2)
        else:
            if os.path.getsize(file) == 0: # if file is empty
                with open(file, 'w') as write:
                    json.dump(Database, write, indent=2)

class CheckFileStats:
    """
    This class will be used to check the stat_result of a file frequently.
    """
    def __init__(self,file):
        """
        In this init method we will initiate the file stat results.
        :param file: path, file or file path for which we want the stat result.
        """
        self.file = file # storing the file address for letter uses.
        self.stat_result = os.stat(file)  # initiating the stat_result
        self.file_size = self.stat_result.st_size # getting the file size
        self.file_access_time = self.stat_result.st_atime # getting the last access time
        self.file_modify_time = self.stat_result.st_mtime # getting the last modify time.
        self.file_creation_time = self.stat_result.st_ctime # getting the creating time.


    def checkupdate(self):
        """
        This method will be used to check the any recent modification on the file , if there is a modification in file then
        we will send a boolean value as True.
        :return: bool, True if file is modified else return False.
        """

        if self.file_modify_time != os.stat(self.file).st_mtime:
            # checking if our last modify time and new modify time are same or not.
            # if they are not same it means there is some modification in the file
            return True
        else: return False

    def modifytime(self):
        """
        This method will return the last modify time , use this to update the last modify time in your project of the
            CheckFileStats object.
        :return:
        """
        return os.stat(self.file).st_mtime


