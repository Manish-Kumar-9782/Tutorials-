
# in this section we will make the small app ow by using the widgets and app_func modules.
# In this section we will use the Tkinter module to make the GUI application or the top level or frame level app.

from tkinter import (Frame, Label , Button ,Spinbox , Toplevel, Tk ,
                     Entry, OptionMenu , StringVar, IntVar,Menubutton,
                     Menu)
from tkinter import GROOVE, RAISED, SUNKEN, FLAT
from tkinter import TOP, LEFT, RIGHT, BOTTOM, W,S,SW, SE, E, EW , X, Y , BOTH
from tkinter import ttk
import Apps_func as apps
import time as ttime
from tkinter import messagebox
import Widgets


class Timer():

    def __init__(self):
        pass


    class Countdown(Frame):
        # this class will inherit the tkinter Frame attribute so we can perform all the operation which is available in the
        # on Frame object, but also we need to initiate the master but for that we need use the init method of the super class
        # by using the super method

        # form here our work starts
        # initiating the constructor
        def __init__(self, master=None, **kw):

            # initiating the Frame class __init__ method.
            if master != None:

                super().__init__(master, **kw)
                self.master = master
                self.master.geometry("100x100")
                self.master.title("Countdown Timer")
                self.master.update_idletasks()

        # Now first of all we need to make a frame for the count down
        # we need to set the position of the timer for that we will make different method in more flexible way
            # global attributes
            self.bg_color = '#1f2421'
            self.fg_color = 'white'
        # initiating the timer
            #self.Timer_Frame(self.master)
            self.Countdown_Status = False
            #self.Display_Start(self.master)
            #self.Ask_Countdown_Time(self.master)
            #self.Countdown_timer(self.master)


            # Countdown time
            self.Countdown_Timer_Status = None # This status will be set by the three button of the Countdown_timer body.
            # There are three timer status ----> running, paused, stopped.
            self.Stopwatch = None # this stopwatch will be set after completion of the countdown timer
            self.timer_id = None
            self.Countdown_Time = None # this is the time which is set by Ask_Countdown_timer() method.
            self.ad_time = None # This is the Extra time after CTime.

            # after initiating all the attirbute or properties of the master window we need to use the .updateidle_task() method().
            self.Timer_record_data = None
            self.Timer_data_file = "./data/Timer_Data.csv" # in this file we will

            Widgets.Widgets.Track_Card.Set_Countdown_Timer = Timer()


        def Timer_Attribute(self , t_frame):
            t_frame.config(bg = 'black')

        def make_borderless(self):
            self.master.withdraw()

        @staticmethod
        # here we will start our timer when the start button is pressed.
        # This timer_app function have a method of stopwatch which will start the timer and will return the timer
        def Start_Stopwatch():
            return apps.Time.StopWatch()  # to initiate the timer.
        @staticmethod
        def Start_countdown():
            return apps.Time.Countdown()

        def continue_timer(self ,frame_handler, label_handler):
            """
            This function will update the timer (stopwatch) by using the after loop of the widget.
            :param frame_handler:
            :param label_handler:
            :return:
            """
            init_timer = self.Start_Stopwatch()
            # now we have initiate the timer , so we need to update it, to update the timer we need make another
            # function which will run in while loop
            def update_timer():
                # here we need to  update the timer by updating the label
                # in this we will update the timer by using the after loop.
                timer_time = init_timer.stopwatch() # get updated time to set it on the Label.
                label_handler.config(text = timer_time ) # Setting the updated time on the Label.
                label_handler.after(1, update_timer)

            update_timer()

##----------------------------------------------------------------------------------------------------------------------
        def Countdown_timer(self, master , time,Track_card_bar=None): # Toplevel app
            """
            This method will be used to start the countdown timer.
            :param time: time of the Countdown timer set by the Ask_Countdown_Time method.
            :param master: this is the root window on which we will put this.
            :return: This will return nothing.
            """
            self.Restart_count = 0
            self.Countdown_Time_Elapsed = 0
            self.save_timer = apps.SaveTime()
            data_dict = {
                "Date":ttime.strftime("%d-%b-%Y"), # initiate date of the timer
                "Start Time":ttime.strftime("%I:%M:%S %p"), # Intiate time of the timer
                "TTime":time, # Countdown time for timer.
                "CTime": None, # Completion time of countdown before stopping or restarting the timer.
            }
            self.total_time = None # this will be added at the end of the dictionary (data_dict)
            # timer id which will be set by calling the .after() method,
            self.timer_id = None
            # this id will be used to stop the timer (Countdown timer.)

            # As soon as the Countdown_timer is called we will set the Countdown_timer_status as "Running"
            self.Countdown_Timer_Status = "Running"
            # here we need to convert the time into seconds.
            ts = apps.Time()  # ts object using Apps_func module.
            Pos  = apps.widget() # This will help us to set the position of the Countdown timer toplevel window.
            # Note: in this section we will have two frame, time_frame and button frame.
            # timer_frame: to show the time.
            # button_frame: to show the button (start, pause, stop)

            # to start the timer first of all we need the Countdown object.
            seconds = ts.time_to_seconds(time)
            self.Countdown_Time = time  # this is the Countdown time which will be set to TTime.
            #print("Countdown Time: ",self.Countdown_Time)
            count_time = apps.Time.Countdown(seconds) # initiating the countdown timer object.
            # this object will hold the all countdown timer functionallity.

            # after that we will display the countdown time.
            master.overrideredirect(True)
            master.geometry("200x60")
            master.update_idletasks()
            master.attributes("-topmost",True)
            master.update()
            
            # setting the position of the Contdown timer.
            ww, wh, x, y = Pos.Position_Timer(master, "BottomRight")  # getting the x,y coordinate of the main screen to set the Countdown timer.
            print(f"{ww}x{wh}+{x}+{y + 30}")
            master.geometry(f"{ww}x{wh}+{x}+{y + 30}")

            l_cfg = {"bg":self.bg_color,
                   "fg":self.fg_color,
                   'font':('sarif',25,'bold')}

            b_cfg = {"bg":self.bg_color,
                   "fg":self.fg_color,
                   'font':('sarif',10,'bold'),
                     'relief':FLAT,
                     'bd':0,'activebackground':self.bg_color, 'activeforeground':self.fg_color
                     }

            Time_Frame = Frame(master, bg= self.bg_color , width = 400, height = 40)
            Time_Frame.pack()
            Time_Frame.pack_propagate(False)
            
            Button_Frame = Frame(master, bg= self.bg_color ,  width = 400, height = 20)
            Button_Frame.pack()
            Button_Frame.pack_propagate(False)

            # Now we need to put the time and buttons
            time_label = Label(Time_Frame, text = "00:00:00", cnf = l_cfg)
            time_label.pack()

            # now we will put the buttons
            start_button = Button(Button_Frame, text = 'Start', cnf = b_cfg)
            start_button.pack(side = LEFT, padx = 10)

            pause_button = Button(Button_Frame, text = 'Pause', cnf = b_cfg)
            pause_button.pack(side = LEFT, padx = 10)

            stop_button = Button(Button_Frame, text = 'Stop' , cnf = b_cfg)
            stop_button.pack(side = LEFT, padx = 00)

            close_button = Button(Button_Frame, text ='x', cnf = b_cfg , command = master.destroy)
            close_button.pack(side=RIGHT, anchor='se')

            # now of the above widget we need to do the actual work here
            # here we need to make use the Countdown object.
            delay = 1000


            def update_countdown_timer():
                # This update_countdown_timer will update the time on the time_label.
                updated_time = count_time.timer() # this will give us the update time of the Countdown timer.
                # countdown timer is running in timer() method.
                New_sec = apps.Time()
                # if Track_card_bar:
                #     print("Timer Running from card bar: ",Track_card_bar.Progress_bar_name)

                # now here after reaching to zero seconds we need to start the stopwatch.
                if New_sec.time_to_seconds(list(updated_time)) >= 0:
                    hr, mins, sec = updated_time
                    time_label.config(text = f"{hr:02d}:{mins:02d}:{sec:02d}")

                    # here we can apply the pause and start button logic.
                    # if we press the pause button then we will not add or subtract any seconds.
                    # if we press the start button then again we will start to
                    if self.Countdown_Timer_Status == "Running":
                        #print("Timer is Running.")
                        count_time.seconds -=1 # if countdown is running the we will minus one second.
                        delay = 1000 # updating a new time in one second.
                        self.Countdown_Time_Elapsed += 1
                        # print("self.Countdown_Time_Elapsed: ", self.Countdown_Time_Elapsed)
                        Widgets.Widgets.TTH_ProgressBar.CURRENT_COUNTDOWN_TIME_ELAPSED = self.Countdown_Time_Elapsed
                        Widgets.Widgets.TTH_ProgressBar.COUNTDOWN_STATUS = True
                        Widgets.Widgets.TTH_ProgressBar.WATCH_TYPE = self.Timer_record_data['Record Type']

                        if Track_card_bar:
                            # we are setting timer from a card bar then we will get a progress bar object which will be updated
                            Track_card_bar.Progress_Current_Countdown_Time +=1
                            Track_card_bar.Progress_Timer_Status = True

                    elif self.Countdown_Timer_Status == "Paused":
                        delay = 1
                        count_time.seconds -= 0

                    else:
                        print("Wrong status",self.Countdown_Timer_Status)

                else:
                    # This section will run if we have completed our countdown time,
                    # This run after CTime and gives us ETime.
                    delay = 1000
                    if self.Stopwatch == None:
                        # initiate the stopwatch
                        self.Stopwatch = self.Start_Stopwatch()
                        # here self.Stopwatch is just an instance which holds the Start_Stopwatch object
                        # now self.Stopwatch is not None so we can Add the timer.
                    else:
                        additional_time = self.Stopwatch.stopwatch() # getting the Extra time.
                        time_label.config(text = "+"+additional_time) # updating the Extra time on the Countdown timer label.
                        self.ad_time = additional_time
                        self.Countdown_Time_Elapsed += 1
                        Widgets.Widgets.TTH_ProgressBar.CURRENT_COUNTDOWN_TIME_ELAPSED = self.Countdown_Time_Elapsed
                        Widgets.Widgets.TTH_ProgressBar.COUNTDOWN_STATUS = True

                        if Track_card_bar: # To update the card bar separately
                            Track_card_bar.Progress_Current_Countdown_Time += 1
                            Track_card_bar.Progress_Timer_Status = True
                        # print("self.Countdown_Time_Elapsed: ", self.Countdown_Time_Elapsed)

                #time_label.config(text=f"{hr:02d}:{mins:02d}:{sec:02d}")
                self.timer_id = time_label.after(delay, update_countdown_timer)

            update_countdown_timer()
            # Since we have three button to control the Countdown_timer_buttons, but to control them timer we need timer status
            # here we will configure the these three button with the status
            # start button: For start button we will set running.
            # pause button: For pause button we will set paused status.
            # stop button: For stop button we will set the stopped.

            def set_status(button):
                # in this we will set the Countdown_timer_status.
                # in this method we will bind our three buttons Start,  Pause and Stop buttons.
                print("Button is pressed: ",button.cget('text'))

                if button.cget('text') == "Start":
                    # if start button is pressed then we will set Running.
                    self.Countdown_Timer_Status = "Running"

                    if pause_button.cget('text') == "--":
                        pause_button.config(text="Pause")
                        seconds = ts.time_to_seconds(self.Countdown_Time)
                        count_time.seconds = seconds
                        time_label.after(1, update_countdown_timer)

                elif button.cget('text') == "Pause":
                    # if start button is pressed then we will set Paused.
                    self.Countdown_Timer_Status = "Paused"
                    Widgets.Widgets.TTH_ProgressBar.COUNTDOWN_STATUS = False
                    if Track_card_bar:
                        Track_card_bar.Progress_Timer_Status = False

                elif button.cget('text') == "Stop":
                    # if start button is pressed then we will set Stopped.
                    self.Countdown_Timer_Status = "Stopped"
                    start_button.config(text="Restart")
                    pause_button.config(text='--')
                    time_label.after_cancel(self.timer_id)
                    Widgets.Widgets.TTH_ProgressBar.COUNTDOWN_STATUS = False
                    if Track_card_bar:
                        Track_card_bar.Progress_Timer_Status = False

                    # Now when we press stop button we need to set the values of data_dict
                    _time_elapsed_sec = ts.time_to_seconds(self.Countdown_Time) - count_time.seconds - 1
                    _time_elapsed = ts.sec_to_time(_time_elapsed_sec,rt_str=True)
                    if self.Restart_count == 0:
                        # if we no restart then it is our first countdown so we need to store CTime
                        data_dict["CTime"] = _time_elapsed
                        data_dict["End Time"] = ttime.strftime("%I:%M:%S %p")
                    else:
                        data_dict[f"R{self.Restart_count}-CTime"] = _time_elapsed
                        data_dict[f"R{self.Restart_count}-End Time"] = ttime.strftime("%I:%M:%S %p")


                    if data_dict["TTime"] == data_dict["CTime"]:
                        # if we have completed the countdown timer time then we need to add Extra time.
                        if self.Restart_count == 0:
                            data_dict[f"ETime"]= self.ad_time
                            data_dict["End Time"] = ttime.strftime("%I:%M:%S %p")
                        else:
                            data_dict[f"R{self.Restart_count}-ETime"] = self.ad_time
                            data_dict[f"R{self.Restart_count}-End Time"] = ttime.strftime("%I:%M:%S %p")

                    print("time elapsed: ", data_dict)
                    # now at the end we need to make self.Stopwatch as None to reset the stopwatch time so we can
                    # start it again from zero on next restart.
                    self.Stopwatch = None



                elif button.cget('text') == "Restart":
                    # if we pressed the restart then it should restart the time.
                    self.Countdown_Timer_Status = "Restart"
                    button.config(text='Start')
                    self.Restart_count += 1
                    data_dict[f"Restart-{self.Restart_count}"] = data_dict["TTime"]
                    data_dict[f"R{self.Restart_count}-Start Time"] = ttime.strftime("%I:%M:%S %p")
                    print("Restart count: ",self.Restart_count)


                else:
                    print("Wrong status..", button.cget('text'))
                    time_label.after_cancel(self.timer_id)

            def save_data():
                # Now here we need to save the data by using the SaveTime class from Apps_func.
                """
                This method will be used to save the data of Countdown timer.
                :return:
                """
                Widgets.Widgets.TTH_ProgressBar.SAVE_UPDATES = True
                total_time = {"Total Time":self.Countdown_Time_Elapsed}

                if Track_card_bar:
                    Track_card_bar.save_bar_progress()

                if self.Timer_record_data:
                    self.Timer_record_data.update(data_dict)
                    self.Timer_record_data.update(total_time)
                else:
                    data_dict.update(total_time)
                    self.Timer_record_data = data_dict
                self.save_timer.save_countdown_time("./data/Timer_Data.csv", self.Timer_record_data)
                master.destroy()


            start_button.config(command=lambda x=start_button: set_status(x))
            pause_button.config(command=lambda x=pause_button: set_status(x))
            stop_button.config(command=lambda x=stop_button: set_status(x))
            close_button.config(command = save_data) # we will save our countdown timer after closing the timer.

##---------------------------------------------------------------------------------------------------------------------##
        def Ask_Countdown_Time(self , master, data = None,Track_card_bar=None):   # Top level app
            """
            This Function will create another top level window to ask the time for countdown timer.
            :param data: addition data which will be given by Tracks,Keeps,Planning,calender etc sections.
            :param master: This is the root window for the For this frame on which we are asking the time.
            :return: -----> str this will return the time in form of string.
            """
            if data:
                self.Timer_record_data = data
                print("got record data: ", self.Timer_record_data)
            # first of all we need to make a frame for the entries.
            Pos = apps.widget()

            # removing the border
            master.overrideredirect(True)
            master.geometry("400x200")
            master.attributes('-topmost', True)  # this will set the attribute for the master window.
            master.update()  # after setting the attribute we need to use the update so we can update the master window.

            ww, wh, x, y = Pos.Position_Timer(master)
            # print("New position")
            # print(f"{ww}x{wh}+{x}+{y + 30}")
            master.geometry(f"{ww}x{wh}+{x}+{y + 30}")

            main_frame = Frame(master, width = 400, height = 400 , bg= self.bg_color)
            main_frame.pack()
            main_frame.pack_propagate(False)

            # Now in this we need to put entries. We wll put the entries for hour, min, sec.
            time_frame = Frame(main_frame, width = 300, height = 100, bg = self.bg_color )
            time_frame.pack(side = TOP)

            # now we will put the Hour, min, sec labels and spinbox entries in the rows.
            # now we will define the columns for the time_frame.
            hour_label = Label(time_frame,text = "Hour", font = ("sarif", 40, 'bold'), bg= self.bg_color, fg = self.fg_color)
            min_label = Label(time_frame,text = "Min", font = ("sarif", 40, 'bold'), bg= self.bg_color, fg = self.fg_color)
            sec_label = Label(time_frame,text = "Sec", font = ("sarif", 40, 'bold'), bg= self.bg_color, fg = self.fg_color)

            hour_label.grid(row = 0, column = 0)
            min_label.grid(row = 0, column = 2)
            sec_label.grid(row = 0, column = 4)

            # now we need to put entries in this time_frame.
            hour_entry = Spinbox(time_frame, width = 2, font = ("sarif", 40, 'bold') , bg= self.fg_color, fg = self.bg_color,
                                 buttonbackground =self.fg_color, buttondownrelief = FLAT, relief = FLAT, buttonup = FLAT,
                                 from_ = 00,to=24, format = '%02.0f')
            hour_entry.grid(row = 1, column = 0)

            # putting colon
            Label(time_frame, text = ":", font = ("sarif",40,'bold') , bg= self.bg_color, fg = self.fg_color).grid(row = 1, column = 1)

            min_entry = Spinbox(time_frame, width = 2, font = ("sarif", 40, 'bold') , bg= self.fg_color, fg = self.bg_color,
                                buttonbackground = self.fg_color, buttondownrelief = FLAT, relief = FLAT, buttonup = FLAT, bd= 0,
                                from_ = 00,to=60, format = '%02.0f')
            min_entry.grid(row = 1, column = 2)

            # putting colon
            Label(time_frame, text=":", font=("sarif", 40, 'bold') , bg= self.bg_color, fg = self.fg_color).grid(row = 1, column = 3)

            sec_entry = Spinbox(time_frame, width = 2, font = ("sarif", 40, 'bold'), bg= self.fg_color, fg = self.bg_color,
                                buttonbackground = self.fg_color, buttondownrelief = FLAT, relief = FLAT, buttonup = FLAT,
                                from_ = 00,to=60, format = '%02.0f')
            # to Display the double zeros on the Spinbox we need to put this in format '%02.0f'

            sec_entry.grid(row = 1, column = 4)

            start_timer_button = Button(time_frame, text = 'Start' ,font = ("sarif", 15, 'bold'), bg= self.bg_color, fg = self.fg_color
                                        , relief = FLAT, activebackground = self.bg_color, activeforeground = self.fg_color, bd = 0)
            start_timer_button.grid(row=2, column = 1, columnspan=3, pady = 10)
            
            close_button = Button(time_frame, text = 'x' ,font = ("sarif", 8, 'bold'), bg= self.bg_color, fg = self.fg_color
                                        , relief = FLAT, activebackground = self.bg_color, activeforeground = self.fg_color, bd = 0)
            close_button.grid(row=2, column = 4, sticky='se')


            # configuring the closing button
            close_button.config(command = master.destroy)
            # Now to configure the start button we need to make a function which will set the timer.

            def set_timer():
                # in this we need to get the value from the Spinbox and and set the timer.
                time = f"{hour_entry.get()}:{min_entry.get()}:{sec_entry.get()}"
                print("Timer set to:", time)
                root = Tk()
                # Now after getting the time we need to pass this time into Countdown timer method.
                master.destroy()
                self.Countdown_timer(root , time , Track_card_bar=Track_card_bar) # Here Now we will start the Countdown timer.
                root.mainloop()
            # now configuring the start button
            start_timer_button.config(command=set_timer)


##----------------------------------------------------------------------------------------------------------------------

        # This timer frame will be used to create a new countdown frame. This can be used any where in the application
        def init_Timer(self, Master):
            """
            This method will be used to initiate the timer, in this it will start the timer from 0 seconds., it will have
            a start button to initiate the Timer.
            :param Master: This is the master window/Frame/Container in which we will place our timer Frame.
            :return:
            """


            Outer_Container_Frame = Frame(Master, highlightbackground = 'green',
                                                    highlightcolor = 'green',
                                                    highlightthickness = 2)
            Outer_Container_Frame.pack()

            Activities = Widgets.Widgets.Activities(Outer_Container_Frame,timer_class=Timer ,width = 500, bg=self.bg_color)
            Activities.ActivityMainMenuButton.pack_configure(side='left', anchor = 'w', padx= (0,2))
            Activities.TracksActivities_MbButton.pack_configure(side = 'left', anchor = 'w', padx=(0,2))
            Activities.new_activity(Tracks)
            Activities.NewActivityButton.pack_configure(side = 'left', anchor = 'w', padx=(0,2))
            # Activities.pack_propagate(False)
            Activities.pack(fill= 'x')


            # at the top we need to put the Activity Bar Frame.
            # Activity_Frame = Frame(Activities, width = 290, height = 50, bg= self.bg_color)
            # Activity_Frame.pack()

            # Now in this Frame we need to pack our activity Menus

            # Now we need to define the timer frame
            # in this we need to define the frame properties like , size, color , and also need to construct a new frame for the timer
            timer_frame = Frame(Outer_Container_Frame, width = 500, height = 100, bg=self.bg_color , relief = GROOVE)
            # Now in this time Frame we need to put a label which will be used to display the time in the application.
            timer_frame.pack(fill='x')
            # to disable the self adjustment of the timer_frame
            #timer_frame.pack_propagate(False)

            timer_label = Label(timer_frame, text = "Start Timer" , font = ("sarif", 40, 'bold'), bg= self.bg_color, fg= self.fg_color)
            timer_label.pack()

            # now we need to put an start timer button on the
            start_timer_button = Button(timer_frame, text='start', bg=self.bg_color, fg=self.fg_color,
                                        highlightbackground = 'white', highlightcolor = 'white', highlightthickness=1,
                                        relief = GROOVE , width=5 , command = lambda x = timer_frame,y = timer_label: self.continue_timer(x,y))

            # Now when i press the start_timer_button then a new top level window should appear.
            start_timer_button.pack()

#-----------------------------------------------------------------------------------------------------------------------
        def Display_Start(self, master ):  # Top level app
            """
            This will be used to display the start timer label and start the count down when we are idle.
            if Countdown_Status = False then it means we are idle,
            if Countdown_Status = Ture then it means we are not idle.
            :return: Nothing

            Note: we should not that this display section will appear if and only if we are idle.
            """
            Pos = apps.widget()

            #removing the border
            master.overrideredirect(True)
            master.geometry("160x65")
            master.attributes('-topmost', True) # this will set the attribute for the master window.
            master.update() # after setting the attribute we need to use the update so we can update the master window.


            ww, wh, x, y = Pos.Position_Timer(master, "Bottom")
            print("New position")
            print(f"{ww}x{wh}+{x}+{y+30}")
            master.geometry(f"{ww}x{wh}+{x}+{y+30}")


            # now if our Countdown_Status is idle then we need to start the countdown.
            # some basic config.
            # no Border, bg and fg color will be same as the parent.
            # it will be put on the button of the screen and just above the task bar , inline to the center.

            # now first we need to set the position. (Later ....) # Position setting will be done on the master.

            # now we need to put the frame.
            Start_Frame = Frame(master, height = 80, bg = self.bg_color)
            Start_Frame.pack()

            # now we will make a button configuration function



            close_display_button = Button(Start_Frame, text='X', relief=FLAT, bg=self.bg_color, fg=self.fg_color ,
                                          activebackground = self.bg_color, bd = 0 )
            close_display_button.pack(side=RIGHT, anchor = 'ne')


            # now we need to put a label
            Start_label = Label(Start_Frame,width = 20 ,bg = self.bg_color, fg= self.fg_color, text = 'Start To Track',
                                font = ("Newsreader", 10, "bold"), highlightbackground = self.bg_color,
                                highlightcolor = 'white', highlightthickness=1,)
            Start_label.pack(side=TOP, anchor = 'n')

            # Now adding a start button on the Start Frame
            Start_countdown_timer_button = Button(Start_Frame,text = 'Start', relief = GROOVE,bg = self.bg_color,fg = self.fg_color,
                                                  highlightbackground = self.bg_color, highlightcolor = 'white', highlightthickness=1, bd=1,
                                                  activebackground = self.bg_color)
            Start_countdown_timer_button.pack(pady  = (10,10) , anchor = 'center')

            close_display_button.config(command  = master.destroy)

            def set_timer():
                # now here we need to open the Ask_Countdown_App
                root = Tk()
                self.Ask_Countdown_Time(root)
                master.destroy()
                root.mainloop()


            Start_countdown_timer_button.config(command = set_timer)

        def Display_Idle_Timer(self ,master):
            """
            This function will be used to display the idle timer on the Dashboard about section.
            :param master: this is the master window where we will display our idle timer.
            :return: None
            """
            '''
            This will contain the idle time and it will be paused while the countdown timer is running.
            '''
            pass

##---------------------------------------------------------------------------------------------------------------------##
##---------------------------------------------------------------------------------------------------------------------##
##---------------------------------------------------------------------------------------------------------------------##

class Keeps:
    """
    This class will hold all of the Keeps objects.
    """

class Tracks(Frame):

    """
    This class will be used to operates the tracks and their data.
    """
    def __init__(self, master = None):
        super().__init__(master=master)
        self.TimerApp = Timer.Countdown()
        self.target_id = None
        self.target_datadict = None
        self.Add_Record_Data = None  # This is the New Root Card Data in Which we can add more subcard
        self.Add_Record_Card_Name = None  # This will be the Name of the RootCard.
        self.App_Cards = apps
        if master:
            if master.winfo_class() == 'Tk' or master.winfo_class() == 'Toplevel' :
                self.master.title("Tracks")
                # for now we will set this master geometry.
                self.master.geometry("700x600")

        self.Add_Time_Record_master = None
        self.BottomSection_master = None

    def Set_Today_target(self,master = None):
        """
        This will create a top level window which will allow us to make the today working hour target.
        :param master: This will be the
        :return: this will return tuple of three value, these values contains the range of hour.
                The range of hour will be defined in the level entries.
        """
        self.set_today_target_hour = None # class instance to store the today_target_hour.
        spin_config = {'width':2, 'font': ('sarif', 15, 'bold')  }

        target_frame = Frame(master, height = 200, width = 100)
        target_frame.pack(fill = BOTH, expand = 1)
        master.geometry('250x250')

        # now we need to add some level in this target_frame
        level1_lvar , level1_hvar= IntVar() , IntVar()
        level2_lvar , level2_hvar= IntVar() , IntVar()
        level3_lvar , level3_hvar= IntVar() , IntVar()


        # now we will create three row for each level
        level1_label = Label(target_frame, text = 'Level 1 Hours')
        level2_label = Label(target_frame, text = 'Level 2 Hours')
        level3_label = Label(target_frame, text = 'Level 3 Hours')

        # Now we need to create spin box for lower and upper values.
        level_1_low = Spinbox(target_frame , cnf = spin_config , textvariable = level1_lvar , from_ = 0 , to= 24)
        level_1_high = Spinbox(target_frame, cnf=spin_config , textvariable = level1_hvar, from_ = 0 , to= 24)

        level_2_low = Spinbox(target_frame, cnf=spin_config , textvariable = level2_lvar, from_ = 0 , to= 24)
        level_2_high = Spinbox(target_frame, cnf=spin_config , textvariable= level2_hvar, from_ = 0 , to= 24)

        level_3_low = Spinbox(target_frame, cnf=spin_config , textvariable = level3_lvar, from_ = 0 , to= 24)
        level_3_high = Spinbox(target_frame, cnf=spin_config , textvariable = level3_hvar, from_ = 0 , to= 24)

        # now we need to put all the thing using a grid layout.
        padding_x = 15
        padding_y = 20
        # first row
        level1_label.grid(row = 0 , column = 0 ,pady = padding_y+10 , padx = padding_x)
        level_1_low.grid(row = 0 , column = 1, pady = padding_y ,padx = padding_x)
        level_1_high.grid(row = 0 , column = 2, pady = padding_y , padx = padding_x)

        # second row
        level2_label.grid(row = 1 , column = 0, pady = padding_y, padx = padding_x)
        level_2_low.grid(row = 1, column = 1, pady = padding_y ,padx = padding_x)
        level_2_high.grid(row = 1 , column = 2, pady = padding_y, padx = padding_x)

        # Third row
        level3_label.grid(row = 2 , column = 0, pady = padding_y, padx = padding_x)
        level_3_low.grid(row = 2 , column = 1, pady = padding_y, padx = padding_x)
        level_3_high.grid(row = 2 , column = 2, pady = padding_y, padx = padding_x)


        def check_values():
            # this function will check the level values if they are not in order then we will show an error.

            l1l, l1h = int(level_1_low.get()) , int(level_1_high.get())
            l2l, l2h = int(level_2_low.get()) , int(level_2_high.get())
            l3l, l3h = int(level_3_low.get()) ,int( level_3_high.get())

            errormessage = """Time Bound Error, Please set the time in continuous order,
            like: 1-4, 4-6, 6-8"""

            if l1l >= 0 and l1l < l1h:
                if l2l == l1h and l2h > l2l:
                    if l2h == l3l and l3h > l3l:
                        # Now all the level are inserted correctly then we will save our data.
                        self.target_datadict = {"Date":ttime.strftime("%d-%b-%Y"),
                                    "Time":ttime.strftime("%I:%M:%S %p"),
                                    "l1l":l1l, "l1h":l1h,
                                    "l2l":l2l, "l2h":l2h,
                                    "l3l":l3l, "l3h":l3h,
                                    "Total Time":0}

                        save = apps.SaveTime()
                        save.save_today_target_time(self.target_datadict)
                        self.set_today_target_hour = ((l1l,l1h),(l2l,l2h),(l3l,l3h))
                        master.destroy()
                    else:
                        messagebox.showerror(title = "Time Error", message = errormessage)
                else:
                    messagebox.showerror(title = "Time Error", message = errormessage)
            else:
                messagebox.showerror(title = "Time Error", message = errormessage)

        set_button = Button(target_frame, text = 'set', command = check_values , width = 5)
        set_button.place(x = 100, y = 215)


        # Now if we dont have any root for this then we will make a new toplevel window.

    def Add_Time_Record(self, master = None):
        """
        This will be used to add a new time record for the day. We will use this application to set a new time record for an existing
            or new Time_Record.
        :param master: this is the master window in which it will be placed, for simplicity make it a toplevel window.
        :return: Nothing.
        """
        options  = ['Subject','Project','Activity']
        option_menu_var = StringVar()
        option_menu_var.set('Select Record Section')

        record_name_var = StringVar()
        record_topic_var = StringVar()
        record_subtopic_var = StringVar()

        # since it will be placed in a new top level window so now we need to set some property for the new top level window.
        if master.winfo_class() == 'Tk' or master.winfo_class() == 'Toplevel':
            master.title("Add Time Record")
            master.geometry("400x400")
            master.update_idletasks()
            #master.config(bg = 'white')

        # now we need to make some label and some entry
        l_cfg = {'bg':'white', 'fg':'blue'}
        e_efg = {'bg':"white", 'fg':'blue', 'highlightbackground':'black', 'highlightcolor':'black', 'highlightthickness':2 , 'relief':FLAT}



        options_menu = OptionMenu(master, option_menu_var, *options)
        options_menu.grid(row = 0, column = 1, pady= (10,5))

        time_record_name_label = Label(master, text = 'Record Name',cnf = l_cfg)
        time_record_name_label.grid(row = 1, column = 0, pady = 10)

        time_record_name_entry = Entry(master, cnf = e_efg , textvariable = record_name_var)
        time_record_name_entry.grid(row = 1, column = 1, pady = 10)

        time_topic_label = Label(master,text = 'Topic' ,cnf = l_cfg)
        time_topic_label.grid(row = 2, column = 0)

        time_topic_entry = Entry(master, cnf = e_efg , textvariable = record_topic_var)
        time_topic_entry.grid(row = 2, column = 1, pady = 10)

        time_record_subtopic_label = Label(master,text = 'Sub Topic',  cnf = l_cfg)
        time_record_subtopic_label.grid(row = 3, column = 0, pady = 10)

        time_record_subtopic_entry = Entry(master, cnf= e_efg , textvariable = record_subtopic_var)
        time_record_subtopic_entry.grid(row = 3, column = 1, pady = 10)

        start_time_record_button = Button(master, text = 'Start')
        start_time_record_button.grid(row = 4, column = 1,pady = (20,0 ))

        # now we need to set all the record data in a dict to send the data for ask_countdown method.

        # here we need to initiate the Ask_Countdown_Timer

        def init_countdown_timer():
            # here we need to make a new toplevel window.
            # this will start the ask countdown application to ask the time for the countdown.
            # and here also we will set the data for the record when the time is asked.
            record_data = {"Record Type": option_menu_var.get(),
                           "Record Name": record_name_var.get(),
                           "Record Topic": record_topic_var.get(),
                           "Record SubTopic": record_subtopic_var.get()}
            root =  Tk()
            self.Add_Time_Record_master.destroy()
            self.TimerApp.Ask_Countdown_Time(root , record_data)
            root.mainloop()

        start_time_record_button.config(command = init_countdown_timer)



    def Add_Record(self,master):
        """
        This will be small top level application which will be used to add a new record which will be displayed on the Track Section.
        :param master: This will be the master/root window on which this application will be placed.
        :return: None
        """
        ts = apps.Time()
        wid = Widgets.Widgets()

        DateFrame = wid.Date_Frame()
        Style = ttk.Style() # this style is for combobox



        Date = ts.get_current_date()  # This wiil be use to set the current date on which the card is created.
        Time = ts.get_current_time()  # This will be use to set the current time at which the card is created.
        l_cfg = {'bg': 'green', 'fg': 'white', 'font':('sarif',10,'bold')}
        e_cfg = {'bg': "white", 'fg': 'blue', 'highlightbackground': 'black', 'highlightcolor': 'black',
                 'highlightthickness': 2, 'relief': FLAT , 'width': 30}

        # Now we need to make the applicaton layout.
        Main_Frame = Frame(master, width = 350 , height = 300, bg = 'green')
        Main_Frame.pack()
        Main_Frame.pack_propagate(False)
        Main_Frame.grid_propagate(False)
        Main_Frame.update_idletasks()
        l_cfg['bg'] = Main_Frame.cget('bg')
        if master.winfo_class() == 'Tk' or master.winfo_class == 'Toplevel':
            # here if we get master as a toplevel or root window then we will set the size of the window.
            h= Main_Frame.cget('height')
            w =Main_Frame.cget('width')
            print(h,w)
            master.geometry(f"{w}x{h}")
            master.update_idletasks()

        Style.configure("Add_Record.TCombobox", background= 'white')

        # Now we need to make the Entries and labels.
        Type_option_List = ["Project","Subject","Activity"]
        Type_option_var = StringVar()
        Type_option_var.set("Select Type")

        Type_Label = Label(Main_Frame, text = "Name of Type", cnf =l_cfg)
        Type_Option = OptionMenu(Main_Frame,Type_option_var, *Type_option_List )
        Type_Option.config(width = 24 , relief = 'flat', bg='white',
                           highlightbackground ='black', highlightcolor = 'black',highlightthickness = 2)

        # Now we need to do put other things.
        # Name of selected type
        Name_label = Label(Main_Frame, text = 'Name', cnf = l_cfg)
        Name_entry = Entry(Main_Frame , cnf = e_cfg)

        # Topic
        # Topic_label = Label(Main_Frame, text = 'Topic Name', cnf = l_cfg)
        # Topic_entry = Entry(Main_Frame, cnf = e_cfg)

        # SubTopic
        # SubTopic_label = Label(Main_Frame, text = 'Sub Topic Name', cnf = l_cfg)
        # SubTopic_entry = Entry(Main_Frame, cnf = e_cfg)

        # Target houre
        # Now we need a frame to put three spinbox for time
        s_cfg = {'font':('sarif',15,'bold')
                 }
        sp_cfg = {'padx':6}
        f_cfg = {'bg':Main_Frame.cget('bg')}

        TargetHour_Frame_entry = wid.Time_Frame(Main_Frame , s_cfg=s_cfg , sp_cfg=sp_cfg , f_cfg=f_cfg)
        TargetHour_Frame_label = Label(Main_Frame, text ='Target Hour', cnf=l_cfg)


        EndDate_Frame_Label = Label(Main_Frame, text = 'EndDate', cnf=l_cfg)
        EndDate_Frame_Entry = DateFrame.Date_Frame(Main_Frame , Style="Add_Record.TCombobox")
        EndDate_Frame_Entry.config(bg = Main_Frame.cget('bg'))



        c_pady = 10
        c_padx = 10
        # Now we need to put all thing using the grid system layout.
        Type_Label.grid(row=0, column=0  , pady= (20,0) , sticky = 'e')
        Type_Option.grid(row=0, column=1, pady = (20,0))

        Name_label.grid(row=1, column=0 , pady = c_pady, padx =c_padx, sticky = 'e')
        Name_entry.grid(row=1, column=1, pady = c_pady, padx =c_padx)

        # Topic_label.grid(row=2, column=0, pady = c_pady, padx =c_padx, sticky = 'e')
        # Topic_entry.grid(row=2, column=1, pady = c_pady, padx =c_padx)

        # SubTopic_label.grid(row=3, column=0, pady = c_pady, padx =c_padx, sticky = 'e')
        # SubTopic_entry.grid(row=3, column=1, pady = c_pady, padx =c_padx)


        TargetHour_Frame_label.grid(row=4, column=0, pady = c_pady, padx =c_padx, sticky = 'e')
        TargetHour_Frame_entry.grid(row=4, column=1, pady = c_pady, padx =c_padx)

        EndDate_Frame_Label.grid(row=5, column=0, pady = c_pady, padx =c_padx, sticky = 'e')
        EndDate_Frame_Entry.grid(row=5, column=1, pady = c_pady, padx =c_padx)
        # Now finally we need to make a button ti submit the and save the data.
        Set_button = Button(Main_Frame, text ='Set', width = 10)
        Set_button.place(x=130, y = 250 )

        # Now we will set a function for this set_button in this we will save our data in a file.
        def save_data():
            # Note that subtopic can be manipulated by a Subtopic_frame object.
            # subtopic_frame object will contain the subtopics
            Hr_var, Min_var, Sec_var = wid.Hr_var.get(), wid.Min_var.get(), wid.Sec_var.get()
            endDate = DateFrame.Date
            EndDate_Frame_Entry.after_cancel(DateFrame.Date_update_id)
            # Now here we need to use the Tracks_Cards class from Apps_func module, class will help us to save all the cards
            # with their parents in nested way.
            # For this card we need the CardName
            Root = {"Root":{}}
            RootCard = {Name_entry.get(): {'Type':Type_option_var.get(),
                                   'Name': Name_entry.get(),
                                   'Date': ttime.strftime("%d-%b-%Y"),
                                   'Time': ttime.strftime("%I:%M:%S %p"),
                                   'Topic': {},
                                   'Target Hour':f"{Hr_var}:{Min_var}:{Sec_var}",
                                   'Completed Hour':0,
                                   'EndDate':endDate, # here we need to pass a end date of the
                                   'Progress': 0,
                                   'Parent': "Root",
                                   'FullPath':f"Root.{Name_entry.get()}",
                                   'Childs': 0}}


            self.Add_Record_Card_Name = Name_entry.get()
            card = wid.Track_Card()

            #Root['Root'].update(RootCard)# updating the Root section of the card database
            card.Tracks_Cards_Database['Root'].update(RootCard) # updating our old database.
            print('Database after updating: ',card.Tracks_Cards_Database)
            #print("Tracks_Cards_Database", card.Tracks_Cards_Database)
            self.Add_Record_Data = card.Tracks_Cards_Database
            # Now after Successfully save and create a new NTR Card we need to close this root window
            # Now after saving the data we need to retrieve the data
            save = apps.Tracks_Cards()
            save.SaveCard(CardName=Name_entry.get(), Parent="Root", Database=card.Tracks_Cards_Database)
            master.destroy()
            print("self.Add_Record_Data: ",self.Add_Record_Data)

        Set_button.config(command = save_data)


    def Add_SubRecord(self, master):

        """
        This will be small top level application which will be used to add a new sub record which will be displayed on the Track Section.
        :param master: This will be the master/root window on which this application will be placed.
        :return: None
        """
        ts = apps.Time()
        wid = Widgets.Widgets()
        Date = ts.get_current_date()
        Time = ts.get_current_time()
        l_cfg = {'bg': 'green', 'fg': 'white', 'font': ('sarif', 10, 'bold')}
        e_cfg = {'bg': "white", 'fg': 'blue', 'highlightbackground': 'black', 'highlightcolor': 'black',
                 'highlightthickness': 2, 'relief': FLAT, 'width': 30}

        # Now we need to make the applicaton layout.
        Main_Frame = Frame(master, width=350, height=300, bg='green')
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
        Type_option_List = ["Project", "Subject", "Activity"]
        Type_option_var = StringVar()
        Type_option_var.set("Select Type")

        Type_Label = Label(Main_Frame, text="Name of Type", cnf=l_cfg)
        Type_Option = OptionMenu(Main_Frame, Type_option_var, *Type_option_List)
        Type_Option.config(width=24, relief='flat', bg='white',
                           highlightbackground='black', highlightcolor='black', highlightthickness=2)

        # Now we need to do put other things.
        # Name of selected type
        Name_label = Label(Main_Frame, text='Name', cnf=l_cfg)
        Name_entry = Entry(Main_Frame, cnf=e_cfg)

        # Topic
        Topic_label = Label(Main_Frame, text='Topic Name', cnf=l_cfg)
        Topic_entry = Entry(Main_Frame, cnf=e_cfg)

        # SubTopic
        SubTopic_label = Label(Main_Frame, text='Sub Topic Name', cnf=l_cfg)
        SubTopic_entry = Entry(Main_Frame, cnf=e_cfg)

        # Target houre
        # Now we need a frame to put three spinbox for time
        s_cfg = {'font': ('sarif', 15, 'bold')
                 }
        sp_cfg = {'padx': 6}
        f_cfg = {'bg': Main_Frame.cget('bg')}

        TargetHour_Frame_entry = wid.Time_Frame(Main_Frame, s_cfg=s_cfg, sp_cfg=sp_cfg, f_cfg=f_cfg)
        TargetHour_Frame_label = Label(Main_Frame, text='Target Hour', cnf=l_cfg)

        c_pady = 10
        c_padx = 10
        # Now we need to put all thing using the grid system layout.
        Type_Label.grid(row=0, column=0, pady=(20, 0), sticky='e')
        Type_Option.grid(row=0, column=1, pady=(20, 0))

        Name_label.grid(row=1, column=0, pady=c_pady, padx=c_padx, sticky='e')
        Name_entry.grid(row=1, column=1, pady=c_pady, padx=c_padx)

        Topic_label.grid(row=2, column=0, pady=c_pady, padx=c_padx, sticky='e')
        Topic_entry.grid(row=2, column=1, pady=c_pady, padx=c_padx)

        SubTopic_label.grid(row=3, column=0, pady=c_pady, padx=c_padx, sticky='e')
        SubTopic_entry.grid(row=3, column=1, pady=c_pady, padx=c_padx)

        TargetHour_Frame_label.grid(row=4, column=0, pady=c_pady, padx=c_padx, sticky='e')
        TargetHour_Frame_entry.grid(row=4, column=1, pady=c_pady, padx=c_padx)

        # Now finally we need to make a button ti submit the and save the data.
        Set_button = Button(Main_Frame, text='Set', width=10)
        Set_button.place(x=130, y=250)

        # Now we will set a function for this set_button in this we will save our data in a file.
        def save_data():
            # Note that subtopic can be manipulated by a Subtopic_frame object.
            # subtopic_frame object will contain the subtopics
            Hr_var, Min_var, Sec_var = wid.Hr_var.get(), wid.Min_var.get(), wid.Sec_var.get()

            data_dict = {'Date': Date, 'Time': Time,
                         'Type': Type_option_var.get(),
                         'Name': Name_entry.get(),
                         'Topic': Topic_entry.get(),
                         'SubTopic': SubTopic_entry.get(),
                         # This should be subtopic id , since we will create subtopic and
                         # we will save them it in differrent file.
                         'Completed': None,  # This completed will be set in another CompletionBar section.
                         'Target Hour': f"{Hr_var}:{Min_var}:{Sec_var}"}

            # Now after Sucessfully save and create a new NTR Card we need to close this root window
            # Now after saving the data we need to retrieve the data
            master.destroy()
            print(data_dict)

        Set_button.config(command=save_data)


class Activities_Apps(Frame):
    """
    This method will be used to create all the small toplevel application which will be need to perform some task of
    Activities classes.

    ActivityClasses :{}
    TracksActivity:{}
    WatchActivity :{}
    NoWatchActivity :{}

    """
    def __init__(self,master=None, cfg=None, **kw):
        super().__init__(master, cnf=cfg, **kw)
        self.activity_func = apps.Activity_Classes()
        self.master = master
        # some predefined activity class:
        self.Activities_List = ['Project','Reading','Study','Workout','Entertainment','Daily Activity','Market']

    def add_activity(self):
        """
        This method will be used to create a top level window in which we will add a new activity.
        In this we will insert the type of the activity and name of the activity.
        :return:
        """
        # resizing the master window according to the apps
        self.master.geometry("300x200")
        self.master.update_idletasks()
        self.config(bg='green', height = 200, width = 200)
        self.pack_propagate(False)
        self.propagate(False)

        self.Type_Entry_var = StringVar()
        self.Name_Entry_var = StringVar()
        self.Type_Entry_var.set("Project")

        self.Type_Label = ttk.Label(self, text='Type of Activity: ')
        self.Name_Label = ttk.Label(self, text='Name of Activity: ')

        self.Type_Entry = ttk.Combobox(self, textvariable = self.Type_Entry_var, values = self.Activities_List, width = 15)
        self.Name_Entry = ttk.Entry(self, textvariable = self.Name_Entry_var, width = 18)

        # adding a button to add new activity
        self.Add_Button = ttk.Button(self, text='Add')

        # Now we will pack all the the widgets using the grid layout management.
        self.Type_Label.grid(row=0, column=0, pady = 10, sticky = 'e', padx = 5)
        self.Type_Entry.grid(row=0, column=1 , pady = 10, sticky = 'e', padx = 10)
        self.Name_Label.grid(row=1, column=0, pady = (0,50), sticky ='e', padx = 5)
        self.Name_Entry.grid(row=1, column=1, pady = (0,50), sticky = 'e', padx = 10)
        self.Add_Button.place(x=80, y=80)

        def submit_addition():
            """
            This method wiil be invoke when Add Button will be pressed.
            :return:
            """
            type = self.Type_Entry_var.get()
            name = self.Name_Entry_var.get()
            self.activity_func.add_activity(type, name)
            self.master.destroy()


        # Configuring the Add button
        self.Add_Button.config(command = submit_addition)


    def Activity_list_bar(self):
        """
        This method is used to create a bar at which we can access the list which is created by the add_activity method.
        :return:
        Note: don,t use this method on the same object at which we have used add_activity method.
        """
        self.Activity_Menu_Button = Menubutton(self, text='Activities ^')

        # Now we need to create a menu
        self.Root_Menu = Menu(self.Activity_Menu_Button, tearoff = 0)
        self.Activity_Menu_Button.config(menu = self.Root_Menu)

        # Now here we need to make a cascade item in the Menu.
        self.Activity_Database = self.activity_func.Activity_Database # getting the Activity database form local storage.

        for Class,Activities in self.Activity_Database['ActivityClasses'].items():
            # we need to make a menu for each
            class_menu = Menu(self.Activity_Menu_Button, tearoff = 0)

            # Now in each Activity Class there will be more activities so we need to add command for each activity.
            for activity in Activities:
                class_menu.add_command(label = activity, command=lambda x=activity:self.activity_command(x))

            # finally we need to add our class_menu in its parent menu which is Class.
            self.Root_Menu.add_cascade(label=Class, menu=class_menu)


        # and at last we need to pack the self.Activity_Menu_Button
        self.Activity_Menu_Button.pack()

    def activity_command(self,activity):
        print("Activity is callled: ",activity)