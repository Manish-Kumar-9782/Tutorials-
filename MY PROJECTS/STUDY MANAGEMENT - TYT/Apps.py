
# in this section we will make the small app ow by using the widgets and app_func modules.
# In this section we will use the Tkinter module to make the GUI application or the top level or frame level app.
from tkinter import Frame, Label , Button ,Spinbox , Toplevel, Tk
from tkinter import GROOVE, RAISED, SUNKEN, FLAT
from tkinter import TOP, LEFT, RIGHT, BOTTOM, W,S,SW, SE, E, EW , X, Y , BOTH
import Apps_func as apps
import time as ttime



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

            # initiating the super __init__ .
            super().__init__(master, **kw)
            self.master = master
            self.master.geometry("100x100")
            self.master.title("Countdown Timer")
            self.bg_color = '#1f2421'
            self.fg_color = 'white'
            self.master.update_idletasks()

        # Now first of all we need to make a frame for the count down
        # we need to set the position of the timer for that we will make different method in more flexible way
            
        # initiating the timer
            #self.Timer_Frame(self.master)
            self.Countdown_Status = False
            self.Display_Start(self.master)
            #self.Ask_Countdown_Time(self.master)
            #self.Countdown_timer(self.master)


            # Countdown time
            self.Countdown_Timer_Status = None # This status will be set by the three button of the Countdown_timer body.
            # There are three timer status ----> running, paused, stopped.
            self.Stopwatch = None # this stopwatch will be set after completion of the countdown timer
            self.timer_id = None
            self.Countdown_Time = None # this is the time which is set by Ask_Countdown_timer() method.
            self.ad_time = None

            # after initiating all the attirbute or properties of the master window we need to use the .updateidle_task() method().



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
            This function will update the timer (stopwatch)
            :param frame_handler:
            :param label_handler:
            :return:
            """
            init_timer = self.Start_Stopwatch()

            # now we have initiate the timer , so we need to update it, to update the timer we need make another
            # function which will run in while loop
            def update_timer():
                # here we need to  update the timer by updating the label
                timer_time = init_timer.stopwatch()
                label_handler.config(text = timer_time )
                label_handler.after(1, update_timer)

            update_timer()

##----------------------------------------------------------------------------------------------------------------------
        def Countdown_timer(self, master , time): # Toplevel app

            """
            This method will be used to start the countdown timer.
            :param master: this is the root window on which we will put this.
            :return: This will return nothing.
            """
            self.Restart_count = 0
            self.save_timer = apps.SaveTime()
            data_dict = {
                "Date":ttime.strftime("%d-%b-%Y"),
                "Countdown time":time,
                "Countdown completion time": None,
            }


            # timer id which will be set by calling the .after() method,
            self.timer_id = None
            # this id will be used to stop the timer (Countdown timer.)

            # As soon as the Countdown_timer is called we will set the Countdown_timer_status as "Running"
            self.Countdown_Timer_Status = "Running"
            # here we need to convert the time into seconds.
            ts = apps.Time()
            Pos  = apps.widget()

            # Note: in this section we will have two frame, time_frame and button frame.
            # timer_frame: to show the time.
            # button_frame: to show the button (start, pause, stop)

            # to start the timer first of all we need the Countdown object.
            seconds = ts.time_to_seconds(time)
            self.Countdown_Time = time
            #print("Countdown Time: ",self.Countdown_Time)
            count_time = apps.Time.Countdown(seconds)

            # after that we will display the countdown time.
            master.overrideredirect(True)
            master.geometry("200x60")
            master.update_idletasks()
            
            # setting the position of the Contdown timer.
            ww, wh, x, y = Pos.Position_Timer(master, "BottomRight")
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
                updated_time = count_time.timer()
                New_sec = apps.Time()

                # now here after reaching to zero seconds we need to start the stopwatch.
                if New_sec.time_to_seconds(list(updated_time)) >= 0:
                    hr, mins, sec = updated_time
                    time_label.config(text = f"{hr:02d}:{mins:02d}:{sec:02d}")

                    # here we can apply the pause and start button logic.
                    # if we press the pause button then we will not add or subtract any seconds.
                    # if we press the start button then again we will start to
                    if self.Countdown_Timer_Status == "Running":
                        #print("Timer is Running.")
                        count_time.seconds -=1
                        delay = 1000

                    elif self.Countdown_Timer_Status == "Paused":
                        delay = 1
                        count_time.seconds -= 0

                    else:
                        print("Wrong status",self.Countdown_Timer_Status)

                else:
                    delay = 1
                    if self.Stopwatch == None:
                        # initiate the stopwatch
                        self.Stopwatch = self.Start_Stopwatch()
                        # here self.Stopwatch is just an instance which holds the Start_Stopwatch object
                        # now self.Stopwatch is not None so we can Add the timer.
                    else:
                        additional_time = self.Stopwatch.stopwatch()
                        time_label.config(text = "+"+additional_time)
                        self.ad_time = additional_time

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

                elif button.cget('text') == "Stop":
                    # if start button is pressed then we will set Stopped.
                    self.Countdown_Timer_Status = "Stopped"
                    start_button.config(text="Restart")
                    pause_button.config(text='--')
                    time_label.after_cancel(self.timer_id)

                    # Now when we press stop button we need to set the values of data_dict
                    _time_elapsed = ts.time_to_seconds(self.Countdown_Time) - count_time.seconds - 1
                    _time_elapsed = ts.sec_to_time(_time_elapsed,rt_str=True)
                    if self.Restart_count == 0:
                        data_dict["Countdown completion time"] = _time_elapsed
                    else:
                        data_dict[f"Restart{self.Restart_count} Completion"] = _time_elapsed


                    if data_dict["Countdown time"] == data_dict["Countdown completion time"]:
                        data_dict[f"Additional time {self.Restart_count}"]= self.ad_time

                    print("time elapsed: ", data_dict)
                    # now at the end we need to make self.Stopwatch as NOne.
                    self.Stopwatch = None

                    # Now here we need to save the data by using the SaveTime class from Apps_func.
                    self.save_timer.save_countdown_time("./data/temp.csv", data_dict)



                elif button.cget('text') == "Restart":
                    # if we pressed the restart then it should restart the time.
                    self.Countdown_Timer_Status = "Restart"
                    button.config(text='Start')
                    self.Restart_count += 1
                    print("Restart count: ",self.Restart_count)


                else:
                    print("Wrong status..", button.cget('text'))
                    time_label.after_cancel(self.timer_id)

            start_button.config(command=lambda x=start_button: set_status(x))
            pause_button.config(command=lambda x=pause_button: set_status(x))
            stop_button.config(command=lambda x=stop_button: set_status(x))




##----------------------------------------------------------------------------------------------------------------------
        def Ask_Countdown_Time(self , master):   # Top level app
            """
            This Function will create another top level window to ask the time for countdown.
            :param Master: This is the root window for the For this frame on which we are asking the time.
            :return: -----> str this will return the time in form of string.
            """
            # first of all we need to make a frame for the entries.
            Pos = apps.widget()

            # removing the border
            master.overrideredirect(True)
            master.geometry("400x200")
            master.attributes('-topmost', True)  # this will set the attribute for the master window.
            master.update()  # after setting the attribute we need to use the update so we can update the master window.

            ww, wh, x, y = Pos.Position_Timer(master)
            print("New position")
            print(f"{ww}x{wh}+{x}+{y + 30}")
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

            #Label(time_frame,text=" ",  bg= self.bg_color, fg = self.fg_color).grid(row = 0, column = 1)

            min_label = Label(time_frame,text = "Min", font = ("sarif", 40, 'bold'), bg= self.bg_color, fg = self.fg_color)

            #Label(time_frame, text=" ", bg=self.bg_color, fg=self.fg_color).grid(row = 0, column = 3)

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
                print(time)
                root = Tk()
                # Now after getting the time we need to pass this time into Countdown timer method.
                master.destroy()
                self.Countdown_timer(root , time)
                root.mainloop()
            # now configuring the start button
            start_timer_button.config(command=set_timer)



##----------------------------------------------------------------------------------------------------------------------

        # This timer frame will be used to create a new countdown frame. This can be used any where in the application
        def Timer_Frame(self, Master):
            # Now we need to define the timer frame
            # in this we need to define the frame properties like , size, color , and also need to construct a new frame for the timer
            timer_frame = Frame(Master, width = 500, height = 100, bg=self.bg_color , relief = GROOVE)
            # Now in this time Frame we need to put a label which will be used to display the time in the application.
            timer_frame.pack(padx = 20)
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

            Note: we should not tht this display section will appear if and only if we are idle.
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


#-----------------------------------------------------------------------------------------------------------------------

