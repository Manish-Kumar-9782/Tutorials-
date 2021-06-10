# in this section we will make a small widget object which will be used in our application.
import csv
import os
from tkinter import (Tk, Frame, Label, Button, StringVar,
                     IntVar, Spinbox, Toplevel, Entry, Text,
                     Menu, Menubutton, messagebox)
from tkinter import ttk
from random import randint
import time, json
import Apps_func as apps
import calendar
import datetime

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
        # print("length of KCL: ", len(KCL))
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

    def get_children(self, parent=None):
        """
        This method will help us to retrieve all children present in a parent window. it will yield all child including nested child also.
        :param parent: window/Widget/Frame , it is the very first parent for which we want ot get children.
        :return: generator...
        """
        # this method will help us to get all the child present in the parent window
        for child in parent.winfo_children():
            yield child
            yield from self.get_children(child)


misc = Misc()


class Widgets:
    APP_TRACKS = None

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

    # ======================================================================================================================#
    # ======================================================================================================================#
    class Create_ProgressBar(Frame):

        def __init__(self, master=None):

            super().__init__(master)
            self.style = ttk.Style()
            self.Time = apps.Time()
            self.App_Track = apps.Tracks_Cards()
            # Now here we need to define the master window property if needed.
            # and also here we will initiate some progressbar property.
            self.progress_after_id = None
            self.Progress = None
            self.Progress_Update_delay = 60000 * 30  # update delay for 30 minutes.
            self.Progress_bar_name = None
            self.Progress_Current_Countdown_Time = 0
            self.Progress_Timer_Status = False
            self.Progress_Target_Hour = None
            self.Progress_Completed_Hour = None

        def progressbar(self, master, bar_progress, progress_func=None, suffix='Progress', prefix='Completed',
                        length=150, theme=None):
            """
            This method will be used to create a progress bar for a task .
            :param master: master parent window/frame/toplevel window in which we will put the progressbar.
            :param bar_progress: int, range(0,100) it the progress bar value which will be used to set the progress bar value during the
                                initiation of the progressbar.
            :param progress_func: func, This is the progress bar function which should contain the data/logic statements which is need to
                                    update in a time interval.
            :param suffix: str, string to show before the progress bar.
            :param prefix: str, string to show after the progress bar.
            :param length:
            :param theme:
            :return:
            """
            self.style.configure("Track.Horizontal.TProgressbar", troughcolor='red', background='white',
                                 bordercolor='black')
            # now here we need to define the Frame , Label and a Progressbar.
            self.Progress = bar_progress
            self.Progress_Frame = Frame(master, height=5, width=250)
            # Progress_Frame.pack(side = 'right', anchor='e', padx = 10)

            # now in this frame we need to put some Label and a Progress bar
            # Note that we need to put the label and progress bar in order
            suffix_label = Label(self.Progress_Frame, text=suffix)
            Progress_Bar = ttk.Progressbar(self.Progress_Frame, length=length, style="Track.Horizontal.TProgressbar")
            prefix_label = Label(self.Progress_Frame)

            suffix_label.pack(side='left', anchor='n')
            Progress_Bar.pack(side='left', anchor='n')
            prefix_label.pack(side='left', anchor='n')

            # Now we need to make a function to update the progress bar
            def update_progress():
                # this function will be run by a .after function.
                # Now here we need to add some increment value in the Progress_Bar['value']

                if self.Progress_Timer_Status:  # if timer status is True
                    # print(f"Progressbar timer is on {self.Progress_bar_name}")
                    self.Progress_Update_delay = 1000
                    self.update_progress_time()

                else:
                    # print(f"Progressbar timer is off {self.Progress_bar_name}\t",end='')
                    self.Progress = progress_func()
                    self.Progress_Update_delay = 1000  # if Progress_Timer is False then we will update the timer from local storage
                    # print("Progress bar delay: ",self.Progress_Update_delay)
                    # in a time interval.

                # print("Progress value for: ",self.Progress_bar_name,"\t",self.Progress)
                Progress_Bar['value'] = self.Progress
                a = Progress_Bar['value']

                # Now we need to show this increment in the prefix label
                prefix_label.config(
                    text=f"{a:.2f} " + prefix)  # this formatting is to show two digits after decimal point.
                # now we need to make a .after() loop to update the progress bar in a time interval

                if a >= 100:
                    # then it means we have reached to 100% Now we need to stop the .after() loop
                    if self.progress_after_id:
                        prefix_label.after_cancel(self.progress_after_id)

                else:
                    # Note: to track the .after() id we need to make a class instace.
                    self.progress_after_id = prefix_label.after(self.Progress_Update_delay, update_progress)
                    # Now this will update the progress bar in every seconds.

            update_progress()

            return self.Progress_Frame

        def update_progress_time(self):
            # to update the progress bar time first we need to convert the time in seconds
            completed_seconds = self.Time.time_to_seconds(self.Progress_Completed_Hour)
            total_targeted_seconds = self.Time.time_to_seconds(self.Progress_Target_Hour)
            updated_seconds = completed_seconds + self.Progress_Current_Countdown_Time

            # Now we need to get the total percent of completed bar.
            if total_targeted_seconds != 0:
                self.Progress = (100 / total_targeted_seconds) * updated_seconds
            else:
                self.Progress = 0

        def save_bar_progress(self):
            """
            This method will be used to save the bar progress in local storage.
            :return:
            """
            file = './data/temp'
            temp = self.Progress_bar_name.split('.')
            cardName = temp[-1]
            cardParent = '.'.join(temp[:-1])
            card = self.App_Track.Get_Card(cardParent, cardName, Widgets.Track_Card.Tracks_Cards_Database)
            updated_time = self.Progress_Current_Countdown_Time + self.Time.time_to_seconds(
                self.Progress_Completed_Hour)
            card["Completed Hour"] = self.Time.sec_to_time(updated_time, rt_str=True)

            card["Progress"] = (100 / self.Time.time_to_seconds(self.Progress_Target_Hour)) * updated_time

            updated_Database = self.App_Track.update_card(cardName, cardParent, card,
                                                          Widgets.Track_Card.Tracks_Cards_Database)

            with open(file, 'w') as write:
                json.dump(updated_Database, write, indent=2)

    # ======================================================================================================================#
    # ======================================================================================================================#
    class TTH_ProgressBar(Frame):
        """
        This frame will be used to create a three level progressbar to show the completion of working hour of the day.
        these progressbar will run in order, third after second, second after first one.
        """
        COUNTDOWN_STATUS = None  # To check that any timer is running or not.
        COUNTDOWN_TIME = 0  # This is the time which will be retrieved from the local storage.
        CURRENT_COUNTDOWN_TIME_ELAPSED = 0  # current countdown timer
        WATCH_TYPE = None
        TODAY_COUNTDOWN_TIME = None
        SAVE_UPDATES = False

        def __init__(self, master=None, time=None):
            """
            This is init method of the TTH_Progressbar widget.
            :param master: master frame in which we will put the all progressbar.
            :param time: tuple, t1,t2,t3 time in tuple format.
            """
            super().__init__(master)
            # to initiate the main frame will hold the other three progress bars.
            self.db_file = "./data/daily_target.csv"
            self.Time = apps.Time()
            self.style = ttk.Style()
            self.Today_Total_Elapsed_Time = 0
            self.current_date = self.Time.get_current_date()
            if not time:
                # self.today_target = [(1,3),(3,6),(6,8)]
                self.retrieve_today_target()
            else:
                self.today_target = time
            self.WatchList = apps.Activity_Classes.retrieve_Watch_Activities(apps.Activity_Classes)
            self.Today_after_id = None
            self.Delay_Minutes = 0.5  # minute in whihc we will update the TTH_Progressbar.
            self.Today_Time_Update_Delay = int(1000 * 60 * self.Delay_Minutes)  # in miliseconds 1000ms = 1sec.
            self.t1 = self.today_target[0]  # level one time (l1l, l1h)
            self.t2 = self.today_target[1]  # level two time (l2l, l2h)
            self.t3 = self.today_target[2]  # level three time (l3l, l3h)
            self.db_update = apps.CheckFileStats(self.db_file)
            self.today_date = datetime.date(*self.Time.get_present_date_values())  # getting today values in tuple

            # creating the TTH_Progress bar.
            self.new_date = self.today_date
            self.Create_TTH_Progress_bar()
            self.update_tth_progressbar()

        def Create_TTH_Progress_bar(self):
            """
            This method will be used to create all three level progress bars, and all progress bars will be put in
            self master frame. width of the
            :return:
            """
            # We need style configuration for every level bar
            # Horizontal.TProgressbar
            self.style.configure("level1.Horizontal.TProgressbar", background='#30b043', troughcolor='white')
            self.style.configure("level2.Horizontal.TProgressbar", background='#acb030', troughcolor='white')
            self.style.configure("level3.Horizontal.TProgressbar", background='#b07030', troughcolor='white')

            # Now we will make to container frame.
            # one will contain time_range labels and other frame will contain progress bar.
            self.Label_Container = Frame(self, height=22)
            self.Label_Container.pack()

            self.Bar_Container = Frame(self)
            self.Bar_Container.pack()

            level1_width = self.t1[1] - self.t1[0]  #
            level2_width = self.t2[1] - self.t2[0]  # They are also used as the time hour for each level tth bar.
            level3_width = self.t3[1] - self.t3[0]  #
            fac = 0.4
            width1 = int(level1_width * 100 * fac)
            width2 = int(level2_width * 100 * fac)
            width3 = int(level3_width * 100 * fac)

            twidth = width1 + width2 + width3
            self.Label_Container.config(width=int(twidth))
            # print("level width:", level1_width, level2_width, level3_width)
            # control variable for to control the values of the progress bar.

            self.level1_seconds = 3600 * level1_width
            self.level2_seconds = 3600 * level2_width
            self.level3_seconds = 3600 * level3_width

            # print(f"level 1 seconds: {self.level1_seconds}")
            # print(f"level 2 seconds: {self.level2_seconds}")
            # print(f"level 3 seconds: {self.level3_seconds}")

            self.t1_var = IntVar()
            self.t2_var = IntVar()
            self.t3_var = IntVar()

            self.level1_ProgressBar = ttk.Progressbar(self.Bar_Container, length=width1, variable=self.t1_var,
                                                      style='level1.Horizontal.TProgressbar')
            self.level2_ProgressBar = ttk.Progressbar(self.Bar_Container, length=width2, variable=self.t2_var,
                                                      style='level2.Horizontal.TProgressbar'
                                                      )
            self.level3_ProgressBar = ttk.Progressbar(self.Bar_Container, length=width3, variable=self.t3_var,
                                                      style='level3.Horizontal.TProgressbar'
                                                      )
            # Now before packing all the Progressbar we will put some time range Label on the self Frame.
            self.t1_range_label = Label(self.Label_Container, text=f'{self.t1[0]} - {self.t1[1]}',
                                        font=('sarif', 8, 'bold'))
            self.t2_range_label = Label(self.Label_Container, text=f'{self.t2[0]} - {self.t2[1]}',
                                        font=('sarif', 8, 'bold'))
            self.t3_range_label = Label(self.Label_Container, text=f'{self.t3[0]} - {self.t3[1]}',
                                        font=('sarif', 8, 'bold'))

            # Now we need to get every label position to put them on the frame.
            l1_posx = width1 // 2 - 10
            l2_posx = int(width1 + width2 // 2) - 10
            l3_posx = int(width1 + width2 + width3 // 2) - 10
            self.t1_range_label.place(x=l1_posx)
            self.t2_range_label.place(x=l2_posx)
            self.t3_range_label.place(x=l3_posx)

            # print("Labels Positions: ", l1_posx, l2_posx, l3_posx)

            self.level1_ProgressBar.pack(side='left', anchor='e', )
            self.level2_ProgressBar.pack(side='left', anchor='e', )
            self.level3_ProgressBar.pack(side='left', anchor='e', )

        def tth_theme_configure(self, head_bg_color=None, head_text_color=None, bar1='#30b043', bar2='#acb030',
                                bar3='#b07030'):
            """
            This method will set the color of the labels which is placed inside the Label container.
            :param head_bg_color: background of the head container.
            :param head_text_color: text color of text placed in head container child widgets.
            :return: None
            """
            # Setting Label container
            self.Label_Container.config(bg=head_bg_color)

            # Setting time_range_label
            for child in self.Label_Container.winfo_children():
                child.config(bg=head_bg_color, fg=head_text_color)

            # setting Bar confgure
            self.style.configure("level1.Horizontal.TProgressbar", background=bar1, troughcolor='white')
            self.style.configure("level2.Horizontal.TProgressbar", background=bar2, troughcolor='white')
            self.style.configure("level3.Horizontal.TProgressbar", background=bar3, troughcolor='white')

            self.level1_ProgressBar.configure(style="level1.Horizontal.TProgressbar")
            self.level2_ProgressBar.configure(style="level2.Horizontal.TProgressbar")
            self.level3_ProgressBar.configure(style="level3.Horizontal.TProgressbar")

        def update_tth_progressbar(self):
            """
            This method will update the tth progress bar according to the given date and time range. by this method we
                will retrieve the saved time from the Countdown timer data and we will
            :return:
            """
            # self.new_date = datetime.date(*self.Time.get_present_date_values())
            if self.CURRENT_COUNTDOWN_TIME_ELAPSED > 60 * 5:
                self.new_date = datetime.date(2021, 6, 10)

            if self.new_date > self.today_date:
                print("Day changed resetting TTH Progressbar.")
                # it means that day has been changed
                self.save_today_target(self.today_target, self.TODAY_COUNTDOWN_TIME,
                                       day_date=self.current_date)  # Saving the yesterday details
                self.COUNTDOWN_TIME = 0  # making all Countdown time to 0 for new day.
                self.CURRENT_COUNTDOWN_TIME_ELAPSED = 0
                self.set_bar_values(0)  # setting bar to 0
                self.current_date = '10-Jun-2021'
                self.retrieve_today_target()  # retrieving new day data.

            if Widgets.TTH_ProgressBar.COUNTDOWN_STATUS == True:
                # if this condition is true then it means that countdown is running
                # if we are running the timer then we will update the timer in every 5 minutes.
                # self.Delay_Minutes = 1
                # Now we will Countdown timer class variable in TTH_Progress class variable.

                if self.WATCH_TYPE in self.WatchList:
                    self.TODAY_COUNTDOWN_TIME = self.CURRENT_COUNTDOWN_TIME_ELAPSED + self.COUNTDOWN_TIME

                    self.set_bar_values(self.TODAY_COUNTDOWN_TIME)
                    print("TTH Timer Running, Total Elapsed Time", self.Today_Total_Elapsed_Time)
                    print("TTH Timer Running, TODAY_COUNTDOWN_TIME", self.TODAY_COUNTDOWN_TIME)
                    print("TTH Timer Running, COUNTDOWN_TIME", self.COUNTDOWN_TIME)
                    # print("Watch Type: ",self.WATCH_TYPE)
                    print()
                else:
                    print("Record Type not in WatchList: ", self.WATCH_TYPE)
                    pass

            else:
                # if this condition is true then it means that we need to retrieve data from local storage.
                # self.Delay_Minutes = 30 # if are not running any timer then we will update the progress bar in every 30 min
                if self.WATCH_TYPE in self.WatchList:  # if our running time activity is in the watchlist then we will update the data
                    if Widgets.TTH_ProgressBar.SAVE_UPDATES:
                        self.Today_Total_Elapsed_Time = self.TODAY_COUNTDOWN_TIME
                        print("tth database is updated.")
                        self.save_today_target(self.today_target, self.Today_Total_Elapsed_Time)
                        Widgets.TTH_ProgressBar.SAVE_UPDATES = False

                update_result = self.db_update.checkupdate()
                if update_result:
                    self.COUNTDOWN_TIME = self.get_today_working_time2()
                    self.set_bar_values(self.COUNTDOWN_TIME)
                    self.db_update.file_modify_time = self.db_update.modifytime()
                    print("tth database is modified.")
                else:
                    self.set_bar_values(self.Today_Total_Elapsed_Time)
                print("TTH Timer Not Running getting data from local: ", update_result)

            # Now we will make an after loop and we will store its id in a self object's attribute.
            self.Today_after_id = self.after(self.Today_Time_Update_Delay, self.update_tth_progressbar)
            print(
                f"COUNTDOWN STATUS {Widgets.TTH_ProgressBar.COUNTDOWN_STATUS}: \t\t COUNTDOWN_TIME: {self.COUNTDOWN_TIME} ")
            print(f"Today_Elepsed_Time: ", self.Today_Total_Elapsed_Time)
            # print(f"Today countdown time: ")

        def retrieve_today_target(self, file="./data/daily_target.csv"):
            """
            This method will be used to retrieve today target value to put in the tth progressbar. in this we will read the
            today target file. if there is any entry of today then we will set tth_progress by using retrieving data else we
            will use a default set to time.
            :return:
            """
            print(f"today date: {apps.Time.get_current_date()} ")

            with open(file, 'r', newline='') as read:

                reader = csv.DictReader(read)
                # fields = reader.fieldnames  '09-Jun-2021'
                today_present = False
                for row in reader:
                    if row['Date'] == self.current_date:
                        print(row)
                        self.today_target = [(int(row['l1l']), int(row['l1h'])),
                                             (int(row['l2l']), int(row['l2h'])),
                                             (int(row['l3l']), int(row['l3h']))]
                        self.Today_Total_Elapsed_Time = int(row["Total Time"])
                        self.COUNTDOWN_TIME = self.Today_Total_Elapsed_Time
                        today_present = True
                        break

                if not today_present:
                    # if there is no target present for today then we will write a default target.
                    self.today_target = [(0, 2), (2, 4), (4, 6)]
                    # and also we will save our default target on local storage.
                    self.save_today_target(self.today_target, total_time=0, day_date=self.current_date)

        def get_today_working_time(self, file="./data/Timer_Data.csv"):
            """
            This method will retrieve the total time which is saved locally. by this method we will only retrieve today data.
            :param file:str, this is the file from which we will retrieve the tth data.
            :return:
            """
            print("Getting today working time:======================>", apps.Time.get_current_date())
            today_time = []
            with open(file, 'r', newline='') as read:
                reader = csv.DictReader(read)
                for row in reader:
                    if row['Date'] == apps.Time.get_current_date():
                        # if we get any data of current day then we need to calculate the total time of the day.
                        # print("Total Time values: ", row["Total Time"], type(row['Total Time']))
                        if row[
                            'Record Type'] in self.WatchList:  # our row belongs to in watch list then we will count it.
                            today_time.append(int(row["Total Time"]))
            # and at last we need to sum all the times.
            # [int(i) for i in today_time]
            return sum(today_time)

        def get_today_working_time2(self, file="./data/daily_target.csv"):
            """
            This method will be used to get the total_today_working_time from daily_target.csv file.
            :param file:str, filepath
            :return:int, return seconds.
            """

            with open(file, 'r', newline='') as read:
                reader = csv.DictReader(read)
                for row in reader:
                    if row["Date"] == self.Time.get_current_date():
                        return int(row["Total Time"])

        def save_today_target(self, target, total_time=None, day_date=None):
            """
            This method will be used to save  today_target time
            :param target: list, target will be a list of tuples.
            :return:
            """
            temp = []
            today_present = False
            with open(self.db_file, 'r', newline='') as read:

                Data = csv.DictReader(read)
                self.data_fileds = Data.fieldnames

                if not day_date:
                    day_date = self.Time.get_current_date()

                for row in Data:
                    # checking for today date.
                    if row["Date"] == day_date:
                        row["l1l"] = target[0][0]
                        row['l1h'] = target[0][1]
                        row['l2l'] = target[1][0]
                        row['l2h'] = target[1][1]
                        row['l3l'] = target[2][0]
                        row['l3h'] = target[2][1]
                        row['Total Time'] = total_time
                        today_present = True

                    temp.append(row)

                if not today_present:
                    self.today_data = {"Date": day_date,
                                       "Time": self.Time.get_current_time(),
                                       "l1l": target[0][0],
                                       'l1h': target[0][1],
                                       'l2l': target[1][0],
                                       'l2h': target[1][1],
                                       'l3l': target[2][0],
                                       'l3h': target[2][1],
                                       'Total Time': total_time
                                       }

            with open(self.db_file, 'w', newline="") as write:

                writer = csv.DictWriter(write, fieldnames=self.data_fileds)
                writer.writeheader()
                for row in temp:
                    writer.writerow(row)

                if not today_present:
                    # Now we need to save today data.
                    writer.writerow(self.today_data)

                del temp  # deleting the temporary data from memory.

        def set_bar_values(self, seconds):
            """
            This method will be used to set the bar values according to the time , this will set every bar after one by one.
            :return:
            """
            level1 = self.level1_seconds
            level2 = self.level1_seconds + self.level2_seconds
            level3 = self.level1_seconds + self.level2_seconds + self.level3_seconds

            # print("bar seconds levels:")
            # print("level1: \t", level1)
            # print("level2: \t", level2)
            # print("level3: \t", level3)

            if seconds <= self.level1_seconds:
                # if this happens then we need to update only level1 progress bar.
                # self.level1_seconds = Widgets.TTH_ProgressBar.COUNTDOWN_TIME
                # print("bar 1 set value: ", (100 / self.level1_seconds) * seconds)
                self.t1_var.set((100 / self.level1_seconds) * seconds)

            elif seconds > level1 and seconds <= level2:
                # if this happens then we need to set level 1 bar full and level2 bar with self.level2_seconds.
                # self.level2_seconds = level1 - Widgets.TTH_ProgressBar.COUNTDOWN_TIME
                self.t1_var.set((100 / self.level1_seconds) * level1)
                self.t2_var.set((100 / self.level2_seconds) * (seconds - level1))

            elif seconds > level2 and seconds <= level3:
                # if this happens then we need to se the level1, and level2 bar as full
                # and set level3 bar with self.level3_seconds
                # self.level3_seconds = level2 - Widgets.TTH_ProgressBar.COUNTDOWN_TIME
                self.t1_var.set((100 / self.level1_seconds) * level1)
                self.t2_var.set((100 / self.level2_seconds) * level2)
                self.t3_var.set((100 / self.level3_seconds) * (seconds - level2))
            else:
                print("Target completed")

    # ======================================================================================================================#
    # ======================================================================================================================#
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

            style.theme_create("NewNotebook", parent="clam", settings={
                "TNotebook": {"configure": {"tabmargins": [2, 5, 2, 0], 'tabposition': 'wn', 'background': '#3e4c63'}},

                "TNotebook.Tab": {
                    "configure": {"padding": [15, 15], "background": mygreen, 'font': ('sarif', 10, 'bold'),
                                  'foreground': 'blue'},
                    "map": {"background": [("selected", '#7d7f82')],
                            "expand": [("selected", [2, 1, 1, 0])]}},

                "TCheckbutton": {
                    "configure": {'background': '#bbc9c5', 'indicatorbackground': '#5f8278',
                                  'indicatorcolor': '#7a3ca6',
                                  "indicatormargin": 0, 'padding': 6, 'indicatorrelief': 'flat'},
                    "map": {"background": [("selected", '#7a3ca6')]}},

                "TProgressbar": {
                    "configure": {'background': 'white', 'troughcolor': 'green', 'bordercolor': 'black',
                                  'darkcolor': 'red', 'lightcolor': 'white'},
                    "map": {"background": [("selected", '#4fbd9d')]}},

                "TCombobox": {
                    "configure": {'background': 'black', 'foreground': 'black', 'bordercolor': 'black',
                                  'darkcolor': 'red', 'lightcolor': 'yellow', 'fieldbackground': 'red'},
                    "map": {"background": [("selected", '#4fbd9d')]}}

            })

            style.theme_use("NewNotebook")

            # style = ttk.Style()

            # style.configure('Tracks.TNotebook', tabposition = tabposition, background='#3e4c63', tabmargins = (20,20,20,0))
            self.notebook = ttk.Notebook(master, height=height, width=width, takefocus=False)
            self.notebook.pack(fill='both', expand=True)
            # print("Note book before returning. ", self.notebook)
            return self.notebook

        def Add_Tab(self, addInstance=None, tabName='tab'):
            """
            This method will be used to add new tabs in the
            :param sep:
            :return:
            """
            self.notebook.add(child=addInstance, text=tabName)

    # ======================================================================================================================#
    # ======================================================================================================================#
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

    # ======================================================================================================================#
    # ======================================================================================================================#
    class Track_Card(Frame):

        """
        This class will be used to Root Track Card and SubTrack Cards widgets/Frames and those widgets/Frames can be put
            in any application.
        """
        Tracks_Cards_DbUpdate = apps.CheckFileStats(file="./Data/temp")
        Tracks_Cards_Reload_after_id = None
        Tracks_Cards_Database = None
        Tracks_Cards_AddButton_Mapping = {}
        Tracks_Cards_DelButton_Mapping = {}
        Tracks_Cards_Progress_Bars = {}
        Set_Countdown_Timer = None  # this is a class varibable which will be linked to the Ask_Countdown_Timer method from Apps module.

        TCD = apps.Tracks_Cards()
        Database_File = "./Data/temp"

        def __init__(self, master=None):
            Widgets.Track_Card.Tracks_Cards_Database = Widgets.Track_Card.TCD.Read_Cards_Database(
                Widgets.Track_Card.Database_File)
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
            self.Time = apps.Time()

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
            # print("Inside the Create Track Record.")
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
            self.Root_Card_Frame.pack(fill='x', expand=1, anchor='n', padx=50, pady=10)
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
            bar.Progress_bar_name = Data['FullPath']
            bar.Progress_Target_Hour = Data['Target Hour']
            bar.Progress_Completed_Hour = Data['Completed Hour']
            self.Tracks_Cards_Progress_Bars[Data['FullPath']] = bar
            CompletedBar = bar.progressbar(self.head_frame, bar_progress=Data["Progress"],
                                           progress_func=lambda x=Data["Name"],
                                                                y=Data["Parent"]: self.Card_Progress_Bar(x, y),
                                           suffix="", prefix="")

            Thour_label = Label(self.head_frame, text=Data['Target Hour'])
            EndDate_label = Label(self.head_frame, text=Data['EndDate'])
            AddButton = Button(self.head_frame, text='+', font=('sarif', 10, 'bold'))
            DeleteButton = Button(self.head_frame, text='x', font=('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.

            DeleteButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(5, 0))
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))
            # Now here we will add a timer button which will start timer for that card.
            self.Insert_Timer(self.head_frame, Data, Track_card_bar=bar,
                              pack={'side': 'right', 'anchor': 'ne', 'padx': (5, 0)})
            # Now here we need to map the Parent name with the button Tracks_Card_Mapping
            self.Tracks_Cards_AddButton_Mapping[AddButton] = "Root." + CardName
            Widgets.Track_Card.Tracks_Cards_DelButton_Mapping = self.Root_Card_Frame  # mapping Card Frame container

            self.Tracks_Cards_Frames.update({Data['FullPath']: self.content_frame})

            # Now we need to configure the AddButton
            def add_subcard(button):
                # print("add record button pressed")
                # Ok so when we press the button then we need to ask for new record data.
                # New record or sub record also need a Parent Name, its own Name (card name)
                root = Toplevel()

                # When we press the Add SubCard button then it wil make a top level window
                # and it will call the self.Add_SubRecord
                self.Add_SubRecord(root, Parent=self.Tracks_Cards_AddButton_Mapping[button])
                self.Root_Card_Frame.wait_window(root)
                # print(button)

                # Data.update(self.SubDictData) # This self.SubDictData Contains the SubCard information.
                # print("Subcard Detail using self.SubDictData: ", self.SubDictData, )
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
            DeleteButton.config(command=lambda x=Data["Name"],
                                               y=Data['Parent'],
                                               z=Widgets.Track_Card.Tracks_Cards_Database,
                                               card=self.Root_Card_Frame: self.delete_card(x, y, z, card))
            # setting the theme for root card.
            self.root_card_theme_configure(mainbody='#daffb5', head_bg_color='#3b4352', head_text_color='#73fffd',
                                           content_bg_color='#4b73c9', content_text_color='white')

            # Now we need to add the bar object in the Tracks_Cards_Progress_Bars dict

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
            bar.Progress_bar_name = Data['FullPath']  # setting the name of the progress bar.
            bar.Progress_Target_Hour = Data['Target Hour']
            bar.Progress_Completed_Hour = Data['Completed Hour']
            self.Tracks_Cards_Progress_Bars[Data['FullPath']] = bar
            CompletedBar = bar.progressbar(SubHead, bar_progress=Data["Progress"],
                                           progress_func=lambda x=Data["Name"],
                                                                y=Data["Parent"]: self.Card_Progress_Bar(x, y),
                                           suffix="", prefix="")

            Thour_label = Label(SubHead, text=Data['Target Hour'])
            EndDate_label = Label(SubHead, text=Data['EndDate'])
            AddButton = Button(SubHead, text='+', font=('sarif', 10, 'bold'))
            DeleteButton = Button(SubHead, text='x', font=('sarif', 10, 'bold'))

            # Now its time to pack all the widgets.
            DeleteButton.pack(side='right', anchor='ne', padx=(50, 0))
            EndDate_label.pack(side='right', anchor='ne', padx=(50, 0))
            Thour_label.pack(side='right', anchor='ne', padx=(50, 0))
            CompletedBar.pack(side='right', anchor='ne', padx=(5, 0))
            AddButton.pack(side='right', anchor='ne', padx=(50, 0))

            self.Insert_Timer(SubHead, Data, Track_card_bar=bar,
                              pack={'side': 'right', 'anchor': 'ne', 'padx': (5, 0)})
            # Now here we need to add the SubCard Full Name in the global Tracks_Card_Mapping dictionary
            self.Tracks_Cards_AddButton_Mapping[AddButton] = FullName
            self.Tracks_Cards_Frames.update({Data['FullPath']: SubContent})

            def add_subcard(button):
                # This method will be called from a subcard button
                # print("add record button pressed")
                one_card_height = 80
                sub_current_height = Subcard.cget('height')  # height of the sub card
                root_current_height = self.Root_Card_Frame.cget('height')  # height of Root card

                SubContent.config(height=sub_current_height + one_card_height)

                self.Root_Card_Frame.config(height=root_current_height + 70)

                # Now here after increasing the height of the subcard we need to call Add_SubCard function
                # This Add_SubCard metod need a top level window
                root = Toplevel()
                self.Add_SubRecord(root, self.Tracks_Cards_AddButton_Mapping[button])
                # Parent = self.Tracks_Cards_AddButton_Mapping[button]
                # Tracks_Cards_AddButton_Mapping stores all the Card full name and map them to the button id.
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
                                     Database=Widgets.Track_Card.Tracks_Cards_Database, Subcard=self.SubDictData,
                                     FullName=self.SubCard_FullName)

            # Now we need to track every new sub card with the help of the button.
            AddButton.config(command=lambda x=AddButton: add_subcard(x))
            DeleteButton.config(command=lambda x=Data["Name"],
                                               y=Data['Parent'],
                                               z=Widgets.Track_Card.Tracks_Cards_Database,
                                               card=Subcard: self.delete_card(x, y, z, card))

            # This button will be placed on the Subcard.
            def sub_card_theme_configure(mainbody='#8cb4fa', head_bg_color=None, head_text_color=None,
                                         content_bg_color=None, content_text_color=None, **theme_keys):
                """
               This is the theme configuration method which will config the basic color property and effect of the tk and ttk widgets.
               :param mainbody: The Main container of the other widget.
               :param head_bg_color: head of the content inside the mainbody container.
               :param head_text_color: text color of content inside the head container.
               :param content_bg_color: content body background color.
               :param content_text_color: content text color.
               :param theme_keys:
               :return:
                """
                style = ttk.Style()  # a separate style for progressbar
                style.configure("SubCard.Horizontal.TProgressbar", background='#07db5f', bordercolor='black',
                                troughcolor='white', lightcolor='#05ffb0', darkcolor='#b8ffcb', relief='flat')

                # subcard main frame:
                Subcard.config(bg=head_bg_color)

                # Now we will set the head color
                SubHead.config(bg=head_bg_color)
                # Now we need to set all the child widget color config.
                for child in misc.get_children(SubHead):
                    # print(f"theme setting for: ", child)
                    if isinstance(child, Frame):
                        # if child is a frame then set only background
                        child.config(bg=head_bg_color)
                    elif isinstance(child, Button):
                        # if button then set fg, bg, relief , active-bg and active-fg
                        child.config(bg=head_bg_color, fg=head_text_color, activebackground=head_bg_color,
                                     activeforeground=head_text_color, relief='flat', overrelief='flat')
                    elif isinstance(child, Label):
                        # if it is a label then we will set fg, bg
                        child.config(bg=head_bg_color, fg=head_text_color)

                    elif isinstance(child, ttk.Progressbar):
                        child.configure(style='SubCard.Horizontal.TProgressbar')

                # NOw we need to set the Content section config.
                SubContent.config(bg=content_bg_color)

            sub_card_theme_configure(mainbody='#2f3861', head_bg_color='#2f3861', head_text_color='white',
                                     content_bg_color='#8a9fff', content_text_color='black')

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
                            # print('Root card parent name:', parent)
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
                # print(h, w)
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
                # print(f"{'_' * 30}")
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
                                                     'Completed Hour': 0,
                                                     'EndDate': wid2.Date,  # here we need to pass a end date of the
                                                     'Progress': 0,
                                                     'Parent': Parent,
                                                     'FullPath': '.'.join([Parent, SubCard_entry.get()]),
                                                     'Childs': 0}}

                # data_dict['FullName'] = ".".join([Parent,data_dict['Topic']])
                # defining the Subcard detail
                self.SubCard_Parent = Parent
                # print("Sub card Parent in widgets.Create_Tracks.Add_SubCard: ", self.SubCard_Parent)
                self.SubCard_Name = SubCard_entry.get()
                self.SubCard_FullName = '.'.join([Parent, SubCard_entry.get()])

                self.NextParentTopic = SubCardData[self.SubCard_Name]
                self.SubDictData = SubCardData
                # print("self.SubDictData =>", self.SubDictData)
                # Now after Sucessfully save and create a new NTR Card we need to close this root window
                # Now after saving the data we need to retrieve the data
                save = apps.Tracks_Cards()
                save.SaveCard(CardName=self.SubCard_Name, Parent=Parent,
                              Database=Widgets.Track_Card.Tracks_Cards_Database,
                              Subcard=SubCardData, FullName=self.SubCard_FullName)
                master.destroy()
                # print(".".join([parent_topic,data_dict['Topic']]))
                # print(f"{'_' * 30}")

            Set_button.config(command=lambda x=Set_button: save_data(x))

        def root_card_theme_configure(self, mainbody='#8cb4fa', head_bg_color=None, head_text_color=None,
                                      content_bg_color=None, content_text_color=None, **theme_keys):
            """
            This is the theme configuration method which will config the basic color property and effect of the tk and ttk widgets.
            :param mainbody: The Main container of the other widget.
            :param head_bg_color: head of the content inside the mainbody container.
            :param head_text_color: text color of content inside the head container.
            :param content_bg_color: content body background color.
            :param content_text_color: content text color.
            :param theme_keys:
            :return:
            """
            style = ttk.Style()  # a separate style for progressbar
            style.configure("Root.Horizontal.TProgressbar", background='#07db5f', bordercolor='black',
                            troughcolor='white', lightcolor='#05ffb0', darkcolor='#b8ffcb')

            ##Main body
            self.Root_Card_Frame.config(bg=mainbody)

            ### Head section
            # head section is placed inside the mainbody on top side.
            self.head_frame.config(bg=head_bg_color)
            # now we need to set the child widgets colors.
            for child in misc.get_children(self.head_frame):
                # print(f"theme setting for: ",child)
                if isinstance(child, Frame):
                    # if child is a frame then set only background
                    child.config(bg=head_bg_color)
                elif isinstance(child, Button):
                    # if button then set fg, bg, relief , active-bg and active-fg
                    child.config(bg=head_bg_color, fg=head_text_color, activebackground=head_bg_color,
                                 activeforeground=head_text_color, relief='flat', overrelief='flat')
                elif isinstance(child, Label):
                    # if it is a label then we will set fg, bg
                    child.config(bg=head_bg_color, fg=head_text_color)

                elif isinstance(child, ttk.Progressbar):
                    child.configure(style='Root.Horizontal.TProgressbar')

            # Now here is the last part of the Root card is content Frame in which other subcards are placed.
            self.content_frame.config(bg='#daffb5')

        def Insert_Timer(self, master, carddata=None, Track_card_bar=None, pack=None):
            """
            This method will be used to run a timer which will be linked to a Countdown timer and tth_Progress and also its own bar.
            :param master: This is the master window/container in which we will contain/put this Timer.
            :param carddata: dict, contain card type and name details.
            :param Track_card_bar: !create_progressbar object, this is the card bar which contain the progress details
            :param pack: pack layout management argument (optional)
            :return:
            """

            def start_timer():
                card_type = self.App_Cards.Get_Card_Type(Widgets.Track_Card.Tracks_Cards_Database, carddata['Parent'],
                                                         carddata['Name'])
                print("Print Card", card_type)
                # for key,value in carddata.items():
                #     print(f"{key}:\t{value}")

                data = {'Record Type': card_type,
                        'Record Name': carddata["Parent"],
                        'Record Topic': carddata['Name'],
                        'Record SubTopic': None}

                root = Toplevel()
                countdown = self.Set_Countdown_Timer.Countdown(root)
                countdown.Ask_Countdown_Time(root, data, Track_card_bar=Track_card_bar)
                root.mainloop()

            Timer_Button = Button(master, text='Timer', command=start_timer)

            if pack:
                Timer_Button.pack(**pack)
            else:
                Timer_Button.pack()

        @classmethod
        def update_database(cls, Database):
            """
            This is a class method which we will be used to update the Tracks_Card_Database
            :param Database:dict or json object,  updated database.
            :return:
            """
            cls.Tracks_Cards_Database = Database

        def Card_Progress_Bar(self, cardName, cardParent):
            """
            This method will be used update the progress bar, this will use the self.Tracks_Cards_Database to get the progress
                of all cards.
            :param cardName: This is the name if the card.
            :param cardParent: card parent to which will be used to get the right card.
            :return:
            """
            # we are using the self.Tracks_Cards_Database.
            data = Widgets.Track_Card.Tracks_Cards_Database
            parents = cardParent.split('.')

            for parent in parents:
                if cardParent != 'Root' and parent != 'Root':
                    data = data[parent]['Topic']
                else:
                    data = data[parent]

            return data[cardName]["Progress"]

        def save_card_progress(self, cardName, cardParent):  # this is done in Progressbar classs
            """
            This method will be used to save card progress while running the timer and after timer.
            :param cardName: str, Card name for which we want ot save the card progress
            :param cardParent: str,Card parent name.
            :return: None.
            """
            # first of all we need to get the card local data
            card = self.App_Cards.Get_Card(cardParent, cardName, Widgets.Track_Card.Tracks_Cards_Database)
            # Now we need to get two things, first we need to get the total target hour values
            # and second we need to get existing progress values.
            card_target_hour = card['Target Hour']
            card_progress = card['Progress']
            card_completed_hour = card['Completed Hour']

            # Now we have got the total target seconds and we need to get current total elapsed seconds for this card.
            # Now we need to convert the time into seconds.
            target_seconds = self.Time.time_to_seconds(card_target_hour)
            completed_seconds = self.Time.time_to_seconds(card_completed_hour)

            # total completed percent value for card progress bar.
            percent_completed = (100 / target_seconds) * completed_seconds
            # until now we have get the saved data now we need to update the completed_seconds.
            # to update this we need to call this method inside the insert_Timer method
            # Now we need to update the card progress

        def delete_card(self, cardName, cardParent, Database, cardwidget):
            """
            This method will be used to delete a card from a Track Card database.
            :param cardName: str, This is the name of the card which is to be deleted.
            :param cardParent: str, card parent to which will be used to get the right card.
            :param Database: dict or json object, Database in from which we need to delete the card.
            :param cardwidget: frame, card fram object.
            :return:
            """
            file = './data/temp'
            data = Database
            parents = cardParent.split('.')

            # Now first we need to delete the card widget
            cardwidget.destroy()

            for parent in parents:
                if cardParent != 'Root' and parent != 'Root':
                    data = data[parent]['Topic']
                else:
                    data = data[parent]

            del data[cardName]  # deleting the card from the database.

            # Now after deleting the deleting the card we need to update the cls.Tracks_Cards_Database
            Widgets.Track_Card.update_database(Database)

            # Now after updating the database we need to save it.
            with open(file, 'w') as write:
                json.dump(Widgets.Track_Card.Tracks_Cards_Database, write, indent=2)

            self.update_idletasks()

        @classmethod
        def reload_Database(cls):
            """
            This is a class method and it will be used to update the Tracks Card database if there is any modification in
                the database.
            :param database_file:filepath,  this is the database file or path of the file.
            :return: None
            """
            result = cls.Tracks_Cards_DbUpdate.checkupdate()

            if result:
                # if result is True then file is update so we need update the database.
                cls.Tracks_Cards_Database = cls.TCD.Read_Cards_Database(cls.Database_File)
                # Now we need to update the modify time also of the object.
                cls.Tracks_Cards_DbUpdate.file_modify_time = cls.Tracks_Cards_DbUpdate.modifytime()
                # Now database is update

    class Activities(Frame):
        """
        This class will be used to manage activities and their functions, it will be also used to manage all the activities
        ActivityClasses :{}
        TracksActivity:{}
        WatchActivity :{}
        NoWatchActivity :{}
        """
        ACTIVITY_FRAME = None
        ACTIVITY_DATABASE = None  # this class method will be used to hold activity database.
        ACTIVITY_CLASS_MENU_MAP = {}

        def __init__(self, master=None, timer_class=None, cnf=None, **kw):
            """
            This will initiate the Activities class object which will be used to manage all the activities related functionality.
            :param master:tk.widget, a master window/widget/toplevel window to hold the Activities Frame.
            :param timer_class: this is a special argument which is added in a problematic condition , this will hold the Timer class from the
                    Apps module, since we cant import directly App module in Widgets module so we need to pass this class as an argument.
            :param cnf:options, Frame configuration options.
            :param kw: keyword arguments.

            Database keys:
                ActivityClasses :{}
                TracksActivity:{}
                WatchActivity :{}
                NoWatchActivity :{}

            """
            super().__init__(master, cfg=cnf, **kw)  # initiating the activities bar.
            self.Top_Frame = None  # this is the top frame from the frame_section
            self.activity_func = apps.Activity_Classes()  # initiating the activity record and loading into memory.
            self.tracks_func = apps.Tracks_Cards()
            self.Apps_Timer = timer_class

            self.Activity_Database = self.activity_func.Activity_Database
            self.WatchList = self.Activity_Database["WatchActivity"]  # activities to watch for countdown timer.
            self.TracksActivities = None  # activity list for Tracks Activities.
            self.DailyActivities = None  # Daily activity
            self.OtherActivities = None  # Other Activities.
            self.ActivityClasses = self.Activity_Database[
                "ActivityClasses"]  # To hold all the activity classes in which we can hold all the activities.
            self.New_activity = None
            self.New_watchlist_item = None
            # self.New_activity_class_item = None
            self.ActivityClasses_MenuMap = {}
            self.TracksActivities_MenuMap = {}

            # initiating the activity bar .
            self.activity_classes()  # init activity classes menu
            self.tracks_activities()  # init activity tracks menu
            # self.watchlist_menu()
            # self.new_activity() # init start a new activity.

        @classmethod
        def Get_Database(cls):
            act = apps.Activity_Classes()
            cls.ACTIVITY_DATABASE = act.Activity_Database

        def activity_classes(self):
            """
            This method will be used to set activity bar on its parent widget/window.
            :param timer_class: This will be the timer class which should be used to create a time
            :return:

            pack: ActivityMainMenuButton
            """
            actmap = Widgets.Activities.ACTIVITY_CLASS_MENU_MAP  # referencing with another name.
            filter_class = ["Activities", "TracksActivity", "NoWatchActivity", "ActivityClasses"]
            # first of all we will make a menu to hold all the activity except Tracks card activities.
            # we will make separate menu for the TracksActivities.

            self.ActivityMainMenuButton = Menubutton(self, text='Activities')

            # Now in this activity menu we need to make a
            self.ActivityMainMenu = Menu(self.ActivityMainMenuButton, tearoff=0)
            # Now need to config the Menubutton for this menu.
            self.ActivityMainMenuButton.config(menu=self.ActivityMainMenu)
            # Now in this we need to get all the activity classes and put them in their own separate menu.
            # getting the Activity database form local storage.
            for key, activity in self.activity_func.retrieve_ActivityClasses(self.ActivityClasses):
                # Now we need to bind every menu with actmap dict.
                if key not in filter_class:
                    classMenu = Menu(self.ActivityMainMenuButton, tearoff=0)
                    classMenu.add_command(label=key,
                                          command=lambda
                                              x="ActivityClasses",
                                              y=activity["Parent"],
                                              other={"Record Topic": activity["Name"]}
                                          : self.activity_command(x, y, other))

                    classMenu.add_separator()
                    classMenu.add_separator()
                    # adding command to add new activity.
                    classMenu.add_command(label="Add New",
                                          command=lambda
                                              db=self.Activity_Database,
                                              x='ActivityClasses',
                                              y=key,
                                              z='.'.join([activity["Parent"], key])
                                          : self.add_activity(db, x, y, z))
                    # Now we need to put it into actmap
                    fullname = '.'.join([activity["Parent"], activity["Name"]])
                    actmap[fullname] = classMenu

            # Now after adding all the menus actmap dict we need to bind them with their parent menu
            for key, activity in self.activity_func.retrieve_ActivityClasses(self.ActivityClasses):
                # Now we need to bind every menu with actmap dict.

                if key not in filter_class:
                    fullname = '.'.join([activity["Parent"], activity["Name"]])
                    if activity["Parent"] == "ActivityClasses":
                        # if this happens then we need to add menu into Root menu
                        self.ActivityMainMenu.add_cascade(label=key, menu=actmap[fullname])
                    else:
                        parentMenu = actmap[activity["Parent"]]
                        childMenu = actmap[fullname]
                        pos = parentMenu.index('end') - 1
                        parentMenu.insert_cascade(pos, label=key, menu=childMenu)

            # we will call here self.watchlist_menu() to add all the Watchlist item before the Add New command
            self.watchlist_menu()
            self.ActivityMainMenu.add_separator()
            self.ActivityMainMenu.add_command(label="Add New",
                                              command=lambda
                                                  x=Widgets.Activities.ACTIVITY_FRAME: self.add_activity_class(x))
            self.ActivityMainMenuButton.pack()

        def tracks_activities(self):
            """
            This method will be used to put all the Track Cards on the activity card bar.
            :return:

            pack: TracksActivities_MbButton
            """
            ## Now very first we need to make a root Menu and its holding button.
            self.TracksActivities_MbButton = Menubutton(self, text='TrackCards')
            self.TracksActivities_MbButton.pack()

            # Now create a root menu for it
            self.TracksActivities_RootMenu = Menu(self.TracksActivities_MbButton, tearoff=0)
            self.TracksActivities_MbButton.config(
                menu=self.TracksActivities_RootMenu)  # configuring the root menu in the menu button.

            # 1. In this first we will retrieve all card recursively.
            # 2. Each card will have its Parent and FullPath we will use it to map each card
            db_file = './data/temp'

            with open(db_file, 'r') as read:
                database = json.load(read)

                # Now we need to use this database to retrieve all cards/
                for key, card in self.tracks_func.Retrieve_Cards(database):
                    if key != "Root":
                        if key != "Topic":
                            # Now we can access each card individually
                            # Now we need to get card Parent and FullPath.
                            # for FullPath we need to make its own menu and put its menu in its parent menu.
                            # To map the ParnetMenu and CardMenu we will use self.TracksActivities_MenuMap dictionay.
                            cardMenu = Menu(self.TracksActivities_MbButton, tearoff=0)
                            cardMenu.add_command(label=key,
                                                 command=lambda x="Tracks",
                                                                y=card["Parent"],
                                                                other={"Record Topic": card["FullPath"]}
                                                 : self.activity_command(x, y, other))
                            # Now we need to add a separator to separate child keys.
                            cardMenu.add_separator()
                            # cardMenu.add_separator()
                            # cardMenu.add_command(label="Add New", command=None)
                            self.TracksActivities_MenuMap[card['FullPath']] = cardMenu

                # Now we have created Menus for each card we need to map each card with its parent cardMenu.
                for key, card in self.tracks_func.Retrieve_Cards(database):
                    if key != "Root":
                        if key != 'Topic':
                            if card["Parent"] == "Root":
                                cardMenu = self.TracksActivities_MenuMap[card["FullPath"]]  # retrieving the cardMenu
                                self.TracksActivities_RootMenu.add_cascade(label=card["Name"], menu=cardMenu)
                                # if card is Root then we need to put this card into RootMenu
                            else:
                                # if card is not Rott then it is a child os we need to its Menu into its card.
                                parentMenu = self.TracksActivities_MenuMap[card["Parent"]]
                                cardMenu = self.TracksActivities_MenuMap[card["FullPath"]]
                                # Now need to put cardMenu in its Parent Menu.
                                # pos = parentMenu.index('end')-1
                                # parentMenu.insert_cascade(pos,label = card["Name"] , menu = cardMenu)
                                parentMenu.add_cascade(label=card["Name"], menu=cardMenu)

                # at the final we need to make cascade menu by using the very top menus.

        # in new_activity method we need to resolve some execution problem.
        def new_activity(self, tracks_object):
            """
            This method will be used to initiate a new activity which is not in the Database.
            :param tracks_object: This is a class object which is defined in the Apps module.
            :return:

            Note: Since we need to start a new activity so we need to set some parameters which can be set by a toplevel
                application which is already defined in Apps Module. So Now if we want to call that method we need to take
                a function as an argument and then call that function with a toplevel object.
            """
            self.NewActivityButton = Button(self, text='New', relief='flat')
            self.NewActivityButton.pack()

            def new_activity_command():
                # This method will be used to invoke when the NewActivity button is pressed.
                root = Toplevel()
                # Now we need  class object.
                track = tracks_object(root)
                track.Add_Time_Record(master=root)
                self.wait_window(root)
                root.mainloop()

            self.NewActivityButton.config(command=new_activity_command)

        def add_activity(self, Database, Key, Name, Parent=None):
            """
            This method will be used to add activities in ActivityClasses, Tracks Activity and it will also will be used to add
                into WatchList activities.

            :param Key: str, Key of the activity in which we want to add activity.
                        a Key can any of them  ActivityClasses :{} TracksActivity:{} WatchActivity :{}

            Note: Tracks activity will be added automatically in the list when a new Track card will be added.
                    So we don't need to make another function or logic for this section.

            :param Name: str, Name of the activity.
            :param Parent: str, Parent full name of the activity if there is any parent.
            :return: None
            """

            # Now first of all we need to make
            # print("new activity info: ")
            # print("Database:\t",Database)
            # print("Key:\t",Key)
            # print("Name:\t",Name)
            # print("Parent:\t",Parent)

            # Now here we need to make toplevel window to ask name of the activity.
            root = Toplevel()
            root.geometry("400x400")
            self.add_activity_toplevel(root, Parent)
            self.wait_window(root)
            # print("New activity Name: ",self.New_activity)
            # root.mainloop()

            if Key == "ActivityClasses" and self.New_activity is not None:
                # print("Creating a new activity: ")
                self.activity_func.add_to_activityclasses(Database=Database, Name=self.New_activity, Parent=Parent)
                # Now after creating a new activity we need to reload the Database.
                # print("New activity created.")
                parent_menu = self.ACTIVITY_CLASS_MENU_MAP[Parent]
                self.insert_menu(menu=parent_menu, Activity=self.New_activity, Activity_parent=Parent,
                                 use="Child")  # self.New_activity used to get the name of the activity.

            elif Key == "WatchActivity":
                self.activity_func.add_to_watchlist(Database, Name)
            else:
                print("KeyError: invalid Key please pass ActivityClasses or WatchActivity ")

        def activity_command(self, type=None, name=None, other=None):
            # Record Type,Record Name,Record Topic,Record SubTopic
            data = {"Record Type": type,
                    "Record Name": name,
                    "Record Topic": None,
                    "Record SubTopic": None}
            if other:
                data["Record Topic"] = other.get('Record Topic', None)
                data["Record SubTopic"] = other.get("Record SubTopic", None)

            print("Activity Data for timer: ", data)

            root = Toplevel()  # Since Ask Count down timer need a Toplevel window.
            # So we will give it a top level window.
            countdown = self.Apps_Timer.Countdown(root)
            countdown.Ask_Countdown_Time(root, data)
            self.wait_window(root)
            root.mainloop()

        # add_activity_toplevel method name does not match to its
        def add_activity_toplevel(self, frame, parent):
            """
            This method will be used to execute after selecting one of the parent to add new activity in database.
            :param frame:tk.Frame, frame object in which we will put our widgets.
            :return:
            """
            self.parent_label = Label(frame, text='Activity Parent:')
            self.parent_label2 = Label(frame, text=parent)

            self.activity_var = StringVar()
            self.Name_label = Label(frame, text='Activity Name:')
            self.Name_entry = Entry(frame, textvariable=self.activity_var)

            self.submit_button = Button(frame, text="Submit")

            self.parent_label.grid(row=0, column=0, )
            self.parent_label2.grid(row=0, column=1)

            self.Name_label.grid(row=1, column=0)
            self.Name_entry.grid(row=1, column=1)

            self.submit_button.place(x=50, y=50)

            def submit():
                self.New_activity = self.activity_var.get()
                frame.destroy()

            self.submit_button.config(command=submit)

        def watchlist_menu(self):
            """
            This method will be used to show the watchlist menu from the database.
            :return: None
            """
            # To put the watchlist in the activity bar we need the RootMenu
            # self.ActivityMainMenu is our root main menu
            self.WatchList_Menu = Menu(self.ActivityMainMenuButton, tearoff=0)
            # Now we need to  put this menu inside the Root menu
            self.ActivityMainMenu.add_cascade(label='WatchList', menu=self.WatchList_Menu)

            for item in self.WatchList:
                self.WatchList_Menu.add_command(label=item,
                                                command=lambda x=item: self.watchList_command(x))

            self.WatchList_Menu.add_separator()
            self.WatchList_Menu.add_command(label="Add New",
                                            command=lambda
                                                x=Widgets.Activities.ACTIVITY_FRAME: self.add_activity_to_watchlist(x))

            # we will define it later.

        def add_activity_to_watchlist(self, frame):
            """
            This method will be used to add a new activity item inside the watchlist this will also update the activity list.
            :return:

            Note: This method will use the self.ActivityClasses and self.WatchList instance to use the data of Database.

            This will use a toplevel window to add a new activity.
            """

            self.cbox_var = StringVar()
            self.New_WatchList_Entry_Frame = Frame(frame, highlightbackground='black',
                                                   highlightcolor='black', highlightthickness=2)
            # Now we need to put a combobox and a submit button.
            self.cbox = ttk.Combobox(self.New_WatchList_Entry_Frame, textvariable=self.cbox_var,
                                     values=list(self.ActivityClasses.keys()))
            self.submit_button = Button(self.New_WatchList_Entry_Frame, text='Submit')

            self.cbox.pack(side='left', anchor='w')
            self.submit_button.pack(side='left', anchor='w')
            self.New_WatchList_Entry_Frame.pack(side='left', anchor='nw')

            def submit_action():
                # this method will be used to invoke below statement when the submit button is pressed.
                # 1. add item in the Watchlist menu
                # 2. add item in the Watchlist
                # 3. add item in the database.
                self.New_watchlist_item = self.cbox_var.get()
                if self.New_watchlist_item not in self.WatchList and not None:
                    # if our new item not in the Watch list then add it else go in else condition.
                    pos = self.WatchList_Menu.index('end') - 1
                    self.WatchList_Menu.insert_command(pos, label=self.New_watchlist_item)
                    self.WatchList.append(self.New_watchlist_item)
                    self.activity_func.add_to_watchlist(self.Activity_Database, self.New_watchlist_item)

                    # Now we need to destroy the Frame after doing all the above statement.
                    self.New_WatchList_Entry_Frame.destroy()
                else:
                    # if our item is already present in the watchlist then show a warning.
                    result = messagebox.askretrycancel(title="Key Error",
                                                       message='Selected key is already present in Watchlist \ntry to add different key.')
                    if not result:
                        # if we cancel the choice then we need to destroy the  self.New_WatchList_Entry_Frame
                        self.New_WatchList_Entry_Frame.destroy()

            self.submit_button.config(command=submit_action)

        def add_activity_class(self, frame):
            """
            This method will be used to add a new activity class in ActivityClasees dict. This will add a Root class not a child
                class.
            :param frame:tk.Frame object,
            :return:
            """
            self.Entry_box_var = StringVar()
            self.Class_Frame = Frame(frame, highlightbackground='black', highlightcolor='black', highlightthickness=2)

            self.Entry_box = Entry(self.Class_Frame, textvariable=self.Entry_box_var)
            self.Submit_class = Button(self.Class_Frame, text='submit')

            self.Entry_box.pack(side='left', anchor='w')
            self.Submit_class.pack(side='left', anchor='w')
            self.Class_Frame.pack(side='left', anchor='nw')

            def submit():
                # This method will be executed when the submit button is pressed.
                # first of all we will get the new class value.
                if self.Entry_box_var.get() not in self.ActivityClasses.keys() and self.Entry_box_var.get() != '' and not None:
                    # here we need to add new item in the activityclasses
                    self.activity_func.add_activity_class(self.Activity_Database, self.Entry_box_var.get())
                    # Need to add a cascade menu here for new class activity.
                    self.insert_menu(self.ActivityMainMenu, self.Entry_box_var.get(), use='Root')
                    # Now after completing all work we need to destroy the Class_Frame so we can free the space.
                    self.Class_Frame.destroy()
                else:
                    if self.Entry_box_var.get() is None:
                        messagebox.showerror(title='Key Error', message="Invalid key input.")
                        self.Class_Frame.destroy()
                    elif self.Entry_box_var.get() == '':
                        result = messagebox.askretrycancel(title='Key Error',
                                                           message="Class name required got no name for class.")
                        if not result:
                            self.Class_Frame.destroy()
                    elif self.Entry_box_var.get() in self.ActivityClasses.keys():
                        message = f"""{self.Entry_box_var.get()} key already exist in the ActivityClasses
    Please try again."""
                        result = messagebox.askretrycancel(title='Key Error', message=message)
                        if not result:
                            self.Class_Frame.destroy()
                    else:
                        messagebox.showerror(title='Key Error', message="Invalid key input.")
                        self.Class_Frame.destroy()

            # configuring the Submit_class button for doing desired action which is defined above
            self.Submit_class.config(command=submit)

        # In insert_menu: make this method short as much as possible and remove the add_new_activity_menu method
        def insert_menu(self, menu, Activity, Activity_parent=None, use='Root'):

            """
            This method will be used to created a default cascade menu with four additional item. it will have two command and two separator,
            b/w separator we will have our separators.
            :param menu:tk.Menu, it will be the parent menu in which we will add these four items.
            :param Activity:str, it will be the label to show the name of the command item selection.
            :param Activity_parent:str, it is the parent of the activity if it has any parent, pass this if we are adding a child activity.
            :param use:str, this will define the use of this function either for Root ActivityClasses or for child activity.
            :return:

            use: 'Root'  to use this function for ActivityClasses class,
                 'Child' to use this function for child activity classes.

            itemfunc:func, it is the command function for its own selection.
            addfunc:func, it is the command function to add new item in current selected category.
            """
            childmenu = Menu(self.ActivityMainMenuButton, tearoff=0)
            activity_fullname = None
            add_func = None  # initiating the reference for the add_func
            item_func = None  # initiating the reference for the item_func
            if use == "Root":

                activity_fullname = '.'.join(["ActivityClasses", Activity])

                def item_func():
                    self.activity_command("ActivityClasses", Activity)

                def add_func():
                    self.add_activity(self.Activity_Database, "ActivityClasses", Activity, activity_fullname)

            elif use == "Child":

                activity_fullname = '.'.join([Activity_parent, Activity])

                def item_func():
                    self.activity_command("ActivityClasses", Activity_parent, {"Record Topic": self.New_activity})

                def add_func():
                    self.add_activity(self.Activity_Database, "ActivityClasses", Activity, activity_fullname)

                # db = self.Activity_Database,
                # x = 'ActivityClasses',
                # y = self.New_activity,
                # z = new_activity_fullname
            childmenu.add_command(label=Activity, command=item_func)
            childmenu.add_separator()  #
            childmenu.add_separator()
            childmenu.add_command(label='Add New', command=add_func)
            self.ACTIVITY_CLASS_MENU_MAP[activity_fullname] = childmenu
            pos = menu.index('end') - 1
            menu.insert_cascade(pos, label=Activity, menu=childmenu)

        def theme_configure(self, bar_bg_color=None, bar_item_bg=None, bar_item_fg=None):
            """
            This method will be used to change the color of the Activity bar these all configuration will be applied on the
                child of master window.
            :param bar_bg_color: background for frame child.
            :param bar_item_bg: background for item.
            :param bar_item_fg: foreground for item.
            :return:
            """
            for child in self.winfo_children():
                if isinstance(child, Frame):
                    child.config(bg=bar_bg_color)
                else:
                    child.config(bg=bar_item_bg, fg=bar_item_fg)

    # ======================================================================================================================#
    # ======================================================================================================================#
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
        KEEP_NEW_CHECK_TEXTBOX = None
        KEEP_CARD_TITLE_BAR = None

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
                self.Next_AddButton_Position = (1, 1)
                self.CheckList = []
                self.CheckContent = []
                self.add_button_holder = None  # this attribute will be used to identify pressed button holder
                # self.init_check = None

                self.Create_Keep_Card(self.master, self.title)
                # Create the Keep card when the object is created.
                # print("keep init method called")

            def Create_Keep_Card(self, master, title=None, data=None, cfg={}, **kw):
                """
                This method will be used to Create a new card with some extra additional ability.
                this method will allow us to add new to-do list records.
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
                self.AddCheckbutton.config(command=lambda x=self.CardContentFrame,
                                                          y=self.AddCheckbutton,
                                                          z=None
                : self.Add_Keep_Check(master=x, bt=y))

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
                self.Next_AddButton_Position = (0, 1)
                for check_text, check_mark in self.checklist:
                    Textbox = Widgets.Keeps_Card.KeepCardCheck(self.CardContentFrame2)
                    Textbox.text.insert(1.0, check_text)
                    Textbox.check_var.set(check_mark)
                    Textbox.set_check_status(check_text)
                    # after creating the checkbox inside the Keep Card we need to store the Textbox in the self.CheckList
                    # and also we need to store the text content and check mark in the self.CheckContent list.
                    self.CheckList.append(Textbox)
                    self.CheckContent.append((check_text, check_mark))

                    Textbox.grid(row=self.Next_Check_Position[0], column=self.Next_Check_Position[1])

                    # now we will add a button to add new check label

                    self.AddCheckbutton2.grid_configure(row=self.Next_AddButton_Position[0],
                                                        column=self.Next_AddButton_Position[1])

                    # now increase the position of the Check and button
                    self.Next_Check_Position = (self.Next_Check_Position[0] + 1, 0)
                    self.Next_AddButton_Position = (self.Next_AddButton_Position[0] + 1, 1)
                r, c = position
                # print("Keep Card position: ", position)
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
                    # print("retrieved card detail: ", card_detail)
                    Widgets.Keeps_Card.Keep_Cards_List.append(card)
                    self.Create_Keep_Card2(master, pos, card_detail)
                # Now we need to iterate through all the cards.

            def Delete_Keep_Card(self, card_id):
                # print("delete keep card called.")
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

            def theme_configure(self, head_bg_color='#4f485e', content_bg_color='#488231',
                                head_text_color='white', content_text_color='white'):
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
                self.CardMainFrame2.config(highlightbackground=None, highlightcolor=None, highlightthickness=0)

                # common
                hc_cfg = {'bg': head_bg_color, 'font': ('snas-sarif', 15, 'bold'), 'fg': head_text_color,
                          'relief': 'flat', 'takefocus': 0}
                hb_cfg = {}

                # first of all we will configure the HeadFrame of the Keep_Card.
                self.HeadFrame2.config(bg=head_bg_color)
                for child in self.HeadFrame2.winfo_children():
                    child.config(cnf=hc_cfg)

                # Now we will work on the CardContentFrame
                self.CardContentFrame2.config(bg=content_bg_color)
                for child in self.CardContentFrame2.winfo_children():
                    if isinstance(child, Button):
                        child.config(bg=content_bg_color, takefocus=0, relief='flat', fg=content_text_color,
                                     font=('sarif', 11, 'bold'))
                    else:
                        child.config(bg=content_bg_color, takefocus=0, relief='flat')

                # Now we need to config every checkbox, for that we need to config Textbox.
                style = ttk.Style()
                style.configure('KeepCard.TCheckbutton', background=content_bg_color,
                                indicatorbackground=content_bg_color,
                                indicatorcolor=content_bg_color)
                for Textbox in self.CheckList:
                    Textbox.text.config(bg=content_bg_color, fg=content_text_color, takefocus=0, relief='flat',
                                        state='disabled', font=('MS Sans Serif', 12), pady=5)
                    Textbox.check.config(style='KeepCard.TCheckbutton', takefocus=0)

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

            def Add_Keep_Check(self, master, bt=None, _class=None, row=None, column=None):
                # print("Add keep check called")
                """
                This method will be used to create a new Text box inside the Keep card.
                :param master:tk.Frame, parent window frame in which this new keep check will be placed.
                :param bt: tk.Button, a common button for each CreateKeepCard object
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
                Brow, Bcol = self.Next_AddButton_Position
                # here we need to put the Frame according to need
                Textbox = Widgets.Keeps_Card.KeepCardCheck(master)
                Textbox.grid(row=Trow, column=Tcol)
                Textbox.focus_set()

                if self.add_button_holder == "KeepCardBar":  # this condition is used to use different theme for new check
                    Textbox.title_theme_configure(Widgets.Keeps_Card.KEEP_CARD_TITLE_BAR.Content,
                                                  content_bg_color='#1b4875',
                                                  content_text_color='#a28cff',
                                                  outmouse_bg='#1b4875', outmouse_fg='white',
                                                  infocus_bg='#1b4875', infocus_fg='white',
                                                  outfocus_bg='#1b4875', outfocus_fg='white')
                else:
                    Textbox.theme_configure()

                bt.grid_configure(row=Brow, column=Bcol)
                # Now we need to update the next Position for the Textbox and Add button.
                self.Next_Check_Position = (self.Next_Check_Position[0] + 1, 0)
                self.Next_AddButton_Position = (self.Next_AddButton_Position[0] + 1, 1)

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
                # print("keep initiated")

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

            def set_check_status(self, check_status):
                """
                This method will set the status of the check, if the check is marked then it will make overstrike on the text,
                if the check is not marked then it will leave the text.
                :param check_status: bool, it is a boolean value, set it 0 or False for False, or 1 or True for True.
                :return:
                """
                if check_status:
                    # if check_status is true it means we have to make overstrike on the text.
                    self.update_checkbutton_states()

            def bind_Return(self, event):
                # print(event)
                """
                This method will be execute when the Return button is pressed.
                :return:
                """
                self.text.config(state='disabled', relief='flat', bg=self.MainFrame.cget('bg'), takefocus=0)
                self.keep_data = (self.text.get(1.0, 'end'), self.check_var.get())
                self.MainFrame.focus_set()

            def InFocus(self, event, background=None, foreground=None):
                """
                This is a event method which will be invoked when focus is set to the widget.
                :param event:
                :param background: color, background color when widget is in focus.
                :param foreground: color, foreground color when widget is not in focus.
                :return:
                """
                if not background:
                    background = Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR

                if not foreground:
                    foreground = Widgets.Keeps_Card.KEEP_CARD_CONTENT_TEXT_COLOR

                self.text.config(state='normal', relief='sunken', bg=background, fg=foreground, takefocus=0)

            def OutFocus(self, event, background=None, foreground=None):
                """
                This is an event method which will be invoked when focus out from the widget.
                :param event:
                :param background: color, background color when widget is in focus.
                :param foreground: color, foreground color when widget is not in focus.
                :return:
                """
                if not background:
                    background = Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR

                if not foreground:
                    foreground = Widgets.Keeps_Card.KEEP_CARD_CONTENT_TEXT_COLOR
                self.text.config(state='disabled', relief='flat', bg=background, fg=foreground, takefocus=0)

            def MouseEnter(self, event, background=None, foreground=None):
                """
                This is a event method which will be invoked when a mouse is Enters over the widget.
                :param event:
                :param background: color, background color when widget is in focus.
                :param foreground: color, foreground color when widget is not in focus.
                :return:
                """
                # default state color:  Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR
                # Mouse enter background color: #d8dbe8
                # Mouse enter foreground color: #1b2e85
                if not background:
                    background = '#d8dbe8'

                if not foreground:
                    foreground = '#1b2e85'

                self.text.config(state='disabled', relief='ridge', bg=background, fg=foreground, takefocus=0)

            def MouseLeave(self, event, background=None, foreground=None):
                """
                This is a event method when the mouse leave the widget.
                :param event:
                :param background: color, background color when widget is in focus.
                :param foreground: color, foreground color when widget is not in focus.
                :return:
                """
                if not background:
                    background = Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR

                if not foreground:
                    foreground = Widgets.Keeps_Card.KEEP_CARD_CONTENT_TEXT_COLOR

                self.text.config(state='disabled', relief='flat', bg=background, fg=foreground, takefocus=0)

            def bind_bt_1(self, event, background=None, foreground=None):
                """
                This method will be used to bind the event to the mouse button-1
                :param foreground:
                :param background:
                :param event:
                :return:
                """
                if not background:
                    background = Widgets.Keeps_Card.KEEP_CARD_CONTENT_COLOR

                if not foreground:
                    foreground = Widgets.Keeps_Card.KEEP_CARD_CONTENT_TEXT_COLOR

                self.text.config(state='normal', relief='sunken', bg=background, fg=foreground)

            def event_binding(self):
                """
                This function will have all the event binding.
                :return:
                """
                self.text.bind("<Return>", self.bind_Return)
                self.text.bind("<Button-1>", self.bind_bt_1)
                self.text.bind("<KeyPress>", self.update_textheight)
                self.text.bind("<FocusIn>", self.InFocus)
                self.text.bind("<FocusOut>", self.OutFocus)
                self.text.bind("<Enter>", self.MouseEnter)
                self.text.bind("<Leave>", self.MouseLeave)

            def theme_configure(self, content_bg_color='#a267c7',
                                content_text_color='#a28cff', **colors):
                """
                This method will be used to set the theme color for the Textbox class widgets.
                :param head_bg_color: Heading widgets color.
                :param head_text_color:  Heading widgets text color
                :param content_bg_color:  content widgets background color.
                :param content_text_color: content widgets text color.
                :return:

                colors: this is wid keyword argument which will give us some more color keys:

                        check_hover_effect  = 'defalut'

                """
                self.check_bg_color = None
                self.text_bg_color = content_bg_color
                self.text_fg_color = content_text_color

                if colors:
                    self.check_hover_effect = colors['check_hover_effect']

                # Textbox container frame
                self.MainFrame.config(bg=content_bg_color)

                # Textbox text color
                self.text.config(bg=content_bg_color, fg=content_text_color)

                # Textbox check color
                style = ttk.Style()
                style.configure('KeepCheck.TCheckbutton', background=content_bg_color,
                                indicatorbackground=content_bg_color,
                                indicatorcolor=content_bg_color)
                self.check.configure(style='KeepCheck.TCheckbutton')

            def title_theme_configure(self, container, content_bg_color='#a267c7',
                                      content_text_color='#a28cff', **colors):
                """
                This method will be used to set the theme color for the Textbox class widgets for KeepCheckbar.
                :param container: This container will hold the all the widgets of KeepCard.
                :param head_bg_color: Heading widgets color.
                :param head_text_color:  Heading widgets text color
                :param content_bg_color:  content widgets background color.
                :param content_text_color: content widgets text color.
                :return:

                colors: this is wid keyword argument which will give us some more color keys:

                        {'inmouse_bg': color,
                          'inmouse_fg': color,
                          'outmouse_bg': color,
                          'outmouse_fg': color,
                          'infocus_bg': color,
                          'infocus_fg': color,
                          'outfocus_bg': color,
                          'outfocus_fg': color}
                """
                self.check_bg_color = None
                self.text_bg_color = content_bg_color
                self.text_fg_color = content_text_color

                color_options = ["inmouse_bg", "inmouse_fg", "outmouse_bg", "outmouse_fg",
                                 "infocus_bg", "infocus_fg", "outfocus_bg", "outfocus_fg"]

                color_dict = {'inmouse_bg': None,
                              'inmouse_fg': None,
                              'outmouse_bg': None,
                              'outmouse_fg': None,
                              'infocus_bg': None,
                              'infocus_fg': None,
                              'outfocus_bg': None,
                              'outfocus_fg': None}

                if colors:
                    for key, value in colors.items():
                        if key not in color_options:
                            raise KeyError(f"BadKey: {key} key should be {color_options}")
                        else:
                            color_dict[key] = value

                self.text.bind("<FocusIn>", lambda event: self.InFocus(event, background=color_dict['infocus_bg'],
                                                                       foreground=color_dict['infocus_fg']))
                self.text.bind("<FocusOut>", lambda event: self.OutFocus(event, background=color_dict['outfocus_bg'],
                                                                         foreground=color_dict['outfocus_fg']))
                self.text.bind("<Enter>", lambda event: self.MouseEnter(event, background=color_dict['inmouse_bg'],
                                                                        foreground=color_dict['inmouse_fg']))
                self.text.bind("<Leave>", lambda event: self.MouseLeave(event, background=color_dict['outmouse_bg'],
                                                                        foreground=color_dict['outmouse_fg']))
                self.text.bind("<Button-1>", lambda event: self.bind_bt_1(event, background=color_dict['infocus_bg'],
                                                                       foreground=color_dict['infocus_fg']))

                # Now we need to set the container's theme configuration.
                for child in misc.get_children(container.CardMainFrame):
                    # getting all children from CardMainFrame.
                    if isinstance(child, Frame):
                        child.config(bg=content_bg_color)
                    elif isinstance(child, Button):
                        child.config(bg=content_bg_color, fg=content_text_color, font=('MS Serif', 12,'bold'))

                # Textbox container frame
                self.MainFrame.config(bg=content_bg_color)

                # Textbox text color
                self.text.config(bg=content_bg_color, fg=content_text_color, font=('MS Serif', 12))

                # Textbox check color
                style = ttk.Style()
                style.configure('TitleCheck.TCheckbutton', background=content_bg_color,
                                indicatorbackground=content_bg_color,
                                indicatorcolor='white', padding=3, indicatormargin=5)
                self.check.configure(style='TitleCheck.TCheckbutton')

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
                # print("Focused widget: ", self.MainFrame.focus_get())

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
                                   fg="#e08e46", takefocus=0, )
                self.Entry.pack(fill='y', anchor='nw')

                self.ChecksFrame = Frame(self.MainFrame, bg='red')
                self.ChecksFrame.pack(fill='y', anchor='nw')

                self.BottomFrame = Frame(self.MainFrame, bg='green')
                self.BottomFrame.pack(fill='y', anchor='se', side='bottom')

                self.theme_configure(Mainbody_color="#1b4875", head_bg_color='#1b4875',
                                     head_text_color='#827c91', content_bg_color='#1b4875',
                                     content_text_color='#a28cff')

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
                # print("Entry event responded")
                # print("Focused widget: ", self.MainFrame.focus_get())
                if self.Entry.focus_get() != self.Entry and self.BarActive == False:
                    # Now since Bar has been activated so we need to make self.BarActive == True
                    self.BarActive = True
                    # Now if self.BarActive is True then it will be not recreated when we press again.

                    self.Title_var.set("")
                    self.Entry.config(fg='black')
                    self.Entry.pack_configure(fill='x', pady=10, padx=10)
                    self.MainFrame.pack_configure(pady=10)
                    # Now we need to initiate a Keep check
                    self.Content = Widgets.Keeps_Card.CreateKeepsCard(self.ChecksFrame, title=None)
                    self.Content.add_button_holder = "KeepCardBar"
                    self.Content.CardMainFrame.config(highlightbackground=None, highlightcolor=None,
                                                      highlightthickness=0)
                    self.Content.pack(pady=10)
                    self.Content.CheckList.append(self.Content.Textbox)
                    # Now we need to put two button one for save the card and another for cancel the save of card
                    # delete all the card data.

                    self.save_button = Button(self.BottomFrame, text='Save')
                    self.save_button.pack(side='right', anchor='ne')

                    self.cancel_button = Button(self.BottomFrame, text='Cancel')
                    self.cancel_button.pack(side='right', anchor='ne')

                    self.cancel_button.config(command=self.reset_card_bar)
                    self.save_button.config(command=self.save_card)

                    # Here after all packing we need to configure theme of the title bar.

                    self.theme_configure(Mainbody_color="#1b4875", head_bg_color='#1b4875',
                                         head_text_color='#827c91', content_bg_color='#1b4875',
                                         content_text_color='#a28cff')

                    self.Content.Textbox.title_theme_configure(self.Content, content_bg_color='#1b4875',
                                                               content_text_color='#a28cff',
                                                               outmouse_bg='#1b4875', outmouse_fg='white',
                                                               infocus_bg='#1b4875', infocus_fg='white',
                                                               outfocus_bg='#1b4875', outfocus_fg='white')
                    self.Content.AddCheckbutton.config(bg='#1b4875', fg='white', relief='flat',
                                                       activebackground='#1b4875', activeforeground='white',
                                                       font=('MS Serif', 12,'bold'))

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
                # print("In KeepCardBar: ")
                # print("\t\t ", Widgets.Keeps_Card.Keep_Cards_List)

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
                # print("length of KCL: ", len(KCL))
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

            def theme_configure(self, Mainbody_color=None, head_bg_color=None, head_text_color=None,
                                content_bg_color=None, content_text_color=None):
                """
                This is a color configuration of the Creating new card title bar, in which title bar section will act as a
                    head of the Frame and below part will act as a content section of the Frame.
                :param head_bg_color: background color of the title bar.
                :param head_text_color: text color of the title bar.
                :param content_bg_color: background color of the content section.
                :param content_text_color: text color of the content section.
                :return:
                """

                # NOw first we need configure Main body which is also a container of the title bar.
                self.MainFrame.config(bg=Mainbody_color)

                # Now we will configure the title bar.
                self.Entry.config(bg=head_bg_color, fg=head_text_color)

                # Now we need to configure the Text box color
                self.ChecksFrame.config(bg=content_bg_color)
                # Now we will configure the CheckFrame child color (text, checkbutton)
                style = ttk.Style()
                style.configure('Check.TCheckbutton', background=content_bg_color, indicatorbackground=content_bg_color,
                                indicatorcolor=content_bg_color)
                for child in self.ChecksFrame.winfo_children():

                    if isinstance(child, Button):
                        child.config(bg=content_bg_color, fg=content_text_color, relief='flat',
                                     activebackground=content_bg_color, activeforeground=content_text_color)
                    elif isinstance(child, ttk.Checkbutton):
                        child.configure(style='Check.TCheckbutton')
                    elif isinstance(child, Text):
                        child.config(bg=content_bg_color, fg=content_text_color)

                    elif isinstance(child, Frame):
                        child.config(bg=content_bg_color)

                # Now we will config the bottom section in which buttons are placed.
                self.BottomFrame.config(bg=content_bg_color)

                # Now we will set buttons config.
                for child in self.BottomFrame.winfo_children():
                    if isinstance(child, Button):
                        child.config(bg=content_bg_color, fg=content_text_color, relief='flat',
                                     activebackground=content_bg_color, activeforeground=content_text_color)
