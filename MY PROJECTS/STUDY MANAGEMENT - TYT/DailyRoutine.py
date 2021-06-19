import csv, Misc

import ExWid
import Widgets
import Apps_func as apps
from tkinter import (Tk, Frame, Label, Button, StringVar,
                     IntVar, Spinbox, Toplevel, Entry, Text,
                     Menu, Menubutton, messagebox, PhotoImage, LabelFrame)
from tkinter import ttk, font
misc = Misc.Misc()


class DailyRoutine(ttk.Frame):
    """
    This class will be used to define and manage of all classes and functionality of Daily Routine tab. it will be
    a Frame object which will be placed inside the tab.
    """

    def __init__(self, master=None):
        super().__init__(master)
        self.checkbutton_list = []  # list to store all check list
        self._taskcards_list_ = []  # this list will hold all tasklist card in it.
        self.style = ttk.Style()
        self.style.map("TaskList.TButton",
                       background=[('hover', '#e8f0ff'), ('pressed', '#598dff'), ('active', '#598dff')],
                       relief=[('hover', 'raised'), ('active', 'sunken'), ('pressed', 'sunken')],
                       )
        self.daily_app_func = apps.DailyRoutine()

    class CheckTask(ttk.Checkbutton):
        """
        This class will be used to inherit the ttk.Checkbutton class it will modify some functionlaity in it. this
        Checkbutton will be used to check our daily routine activity.

        init attribute:
            style : To set the style for Checkbutton and its member widgets.
            variable : control variable to control onvalue, offvalue of checkbutton.
            textvariable : control variable to set text for checkbutton label.
            normal_font : normal font style with specified font attributes for checkbutton's text label.
            striked_font : overstriked font style with specified font attributes for checkbutton's text label.
            notify : To show notification for some specific task.
            notify_time : notify time for notification.

        """

        def __init__(self, master=None):
            super().__init__(master)
            self.style = ttk.Style()
            self.TaskTitle = None
            self.checktaskid = None
            self.variable = IntVar()
            self.variable.set(0)  # setting 0 to variable to make checkbutton as deselected.
            self.textvariable = StringVar()
            self.normal_font = font.Font(family='Sarif', size=12)
            self.striked_font = font.Font(family='Sarif', size=12, overstrike=1)
            self.style.configure("Unchecked.TCheckbutton", font=self.normal_font)
            self.style.configure("checked.TCheckbutton", font=self.striked_font)
            self.alert_time = []  # this will contain the alert time at which we need to alert the user about this task.
            self.notify = False  # if this is True then only self.notify_time and self.alert_time will work.
            self.notify_time = None
            self.completed = False
            self.alert_start_time = None
            self.alert_end_time = None
            self.notify_day = None
            self.configure(style="Unchecked.TCheckbutton", variable=self.variable, textvariable=self.textvariable)
            self.edit_button = None  # this edit button will be used to edit the this task.
            self.notify_button = None
            self.bind("<Button-1>", self.oncheck)

        def edit_config(self):
            """
            This method will be config the edit button command after initializing of the checkbutton object.
            :return:
            """
            self.edit_button.config(command=self.onedit)

        def notify_config(self):
            """
            This method will be configure the notify button command after initializing of the checkbutton object.
            :param tasktitle: it is the title of the task.
            :return:
            """
            self.notify_button.config(command=self.onnotify)

        def oncheck(self, event):
            """
            This method is a handler method which will be used to handle the event of Button-1 click on the Checkbutton.
            This method will perform text overstrike operation on the selected check.
            :param event:
            :return:
            """
            print("checkbutton value: ", self.variable.get())
            # Now we will get the Checkbutton's on and off values by using the self.variable attribute
            # since on and off value will change after executing the event handler so we need to check variable value in reverse order.
            if not self.variable.get():
                # if these happens it means that checkbutton is selected.
                self.configure(style="checked.TCheckbutton")
                self.completed = True
            else:
                # if it happens it means that checkbutton is not selected.
                self.configure(style="Unchecked.TCheckbutton")
                self.completed = False

        def onedit(self):
            """
            This method will be invoked when the edit button is pressed.
            :return:
            """
            print("edit button is pressed inside the checkbutton object.")

        def onnotify(self):
            """
            This method will be invoked when notify button is pressed.
            :return:
            """
            print("print notify called")
            self.notifyroot = Toplevel()
            self.notifyroot.title("Set Task Notification")
            self.notifyroot.pack_propagate(False)
            self.notifyroot.geometry("400x400")
            self.notifyroot.protocol("WM_DELETE_WINDOW", self.modify_task_details)
            Notify = DailyRoutine.SetNotify(self.notifyroot, task=self)
            Notify.pack()

        def modify_task_details(self):
            """
            This method will be used to modify when the SetNotification window will be destroyed.
            :return:
            """
            print(self.checktaskid)
            # Now first of all we need to access the index of the task in tasklist
            index = self.master.master.tasklist.index(self)
            # Now we need to verify that we have selected right choice

            key = {"Task": self.textvariable.get(),
                   "TaskId": self.master.master.tasklist_id,
                   "CheckTaskid": self.checktaskid,
                   "TaskTitle": self.TaskTitle,
                   "Notify": self.notify,
                   "NotifyTime": self.notify_time,
                   "AlertTime": self.alert_time,
                   "StartTime": self.alert_start_time,
                   "EndTime": self.alert_end_time,
                   "NotifyDay": self.notify_day,
                   "TaskCompleted": self.completed}

            self.master.master.tasklists_data[index].update(key)
            self.notifyroot.destroy()

    class SetNotify(ttk.Frame):
        """
        This class will be used to Set notification for a particular task, this is a object will have ttk.Frame class
        attributes and function so we can use it like a ttk.Frame object with some additional method as functionality.
        """

        def __init__(self, master=None, task=None):
            super().__init__(master)
            self.Task = task
            self.master = master
            self.master.geometry("400x400")
            self.master.update_idletasks()
            self.notify = False
            self.notify_var = IntVar()
            self.alert_var = IntVar()
            self.alert_var.set(0)
            self.notify_time = None
            self.alert_time_wid = []
            self.alert_time_values = []
            self.notify_days = []
            self.start_time = "00:00:00 AM"
            self.end_time = "11:59:59 PM"
            self.wid = Widgets  # widgets class
            self.add_alert_count = 0
            self.set_time = False  # it will be true if we have any widget for settime
            self.day_choice = False  # it will be true if we have any widget for day choice.
            self.alert = True  # it will be true if we have any widget of alert time.
            # Now We need to set notification for every individual task.
            self.notify_label = ttk.Label(self, text='Task Notification Setting', font=("sarif", 15, 'bold'))
            self.notify_check = ttk.Checkbutton(self, text='Notify', variable=self.notify_var,
                                                command=self.notify_status)
            self.submit_notify = ttk.Button(self.master, text="Submit", command=self.get_notify_settings)
            self.notify_label.pack(pady=5)
            self.notify_check.pack(pady=5)
            self.submit_notify.place(x=320, y=10)

            self.Notifytimeframe = LabelFrame(self, text='Set Notify Time')
            self.SetNotifyTime = ExWid.SetTime(self.Notifytimeframe, 'Notify Time:')
            self.SetStartTime = ExWid.SetTime(self.Notifytimeframe, 'Start Time:')
            self.SetEndTime = ExWid.SetTime(self.Notifytimeframe, 'End Time:')
            self.AlertCheck = ttk.Checkbutton(self.Notifytimeframe, text='Alert Time:', variable=self.alert_var,
                                              command=self.alert_commad)
            self.SetNotifyTime.pack(pady=5, anchor='e')
            self.SetStartTime.pack(pady=5, anchor='e')
            self.SetEndTime.pack(pady=5, anchor='e')
            self.AlertCheck.pack()

            self.Alerttimeframe = LabelFrame(self, text='Set Alert Time')

            self.Notifydayframe = LabelFrame(self, text='Set Notify Days')
            self.DayChoice = ExWid.DayChoice(self.Notifydayframe)
            self.DayChoice.pack(pady=5)
            self.set_notify_setting()

        def notify_status(self):
            """
            This method will be used to set the notification status.
            :return:
            """
            if self.notify_var.get():
                # if we have selected to notify the task then we need to put the settime and daychoise frames also.
                self.Notifytimeframe.pack(pady=5)
                self.Alerttimeframe.pack(pady=5)
                self.Notifydayframe.pack(pady=5)
                self.set_time = True
                self.day_choice = True
                self.notify = True
            else:
                if self.set_time:
                    self.Notifytimeframe.pack_forget()
                if self.day_choice:
                    self.Notifydayframe.pack_forget()
                if self.alert:
                    self.Alerttimeframe.pack_forget()

        def alert_commad(self):
            """
            This method will be invoked when the alert checkbutton is selsected.
            :return:
            """
            if self.alert_var.get():
                if not bool(self.alert_time_wid):  # if self.alert_time is empty
                    self.add_alert_count = len(self.alert_time_wid) + 1
                    alerttime = ExWid.SetTime(self.Alerttimeframe, label=f"Alert Time {str(self.add_alert_count)}:")
                    alerttime.grid(row=0, column=0)
                    self.add_alert = ttk.Button(self.Alerttimeframe, text='add', command=self.add_new_alert)
                    self.add_alert.grid(row=0, column=1)
                    self.alert_time_wid.append(alerttime)
                else:
                    self.Alerttimeframe.pack_configure(before=self.Notifydayframe)
            else:
                self.Alerttimeframe.pack_forget()

        def set_notify_setting(self):
            """
            This method will be used to set saved setting for the current task notification setting.
            :return:
            """
            self.days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']
            # Now self.Task will hold all th available information to set the notification setting
            if self.Task.notify == 'True':
                self.notify = True
                self.notify_var.set(1)
                self.set_time = True
                # Now we need to pack Set time for notify time
                # Notify time setting.
                self.notify_time = misc._eval(self.Task.notify_time)
                self.start_time = misc._eval(self.Task.alert_start_time)
                self.end_time = misc._eval(self.Task.alert_end_time)

                self.SetNotifyTime.set_time_values(self.notify_time)
                self.SetStartTime.set_time_values(self.start_time)
                self.SetEndTime.set_time_values(self.end_time)
                self.Notifytimeframe.pack()

                # Alert Time setting
                self.alert_time_values = misc._eval(self.Task.alert_time)
                if self.alert_time_values:
                    self.alert = True
                    self.alert_var.set(1)

                    for index, atime in enumerate(self.alert_time_values):
                        self.add_alert_count = len(self.alert_time_wid) + 1
                        alerttime = ExWid.SetTime(self.Alerttimeframe, label=f"Alert Time {str(self.add_alert_count)}:")
                        alerttime.grid(row=index, column=0)
                        alerttime.set_time_values(atime)

                        self.add_alert = ttk.Button(self.Alerttimeframe, text='add', command=self.add_new_alert)
                        self.add_alert.grid_configure(row=index, column=1)
                        self.alert_time_wid.append(alerttime)
                self.Alerttimeframe.pack()

                # Day setting
                self.notify_days = misc._eval(self.Task.notify_day)
                if self.notify_days:
                    self.day_choice = True
                    self.Notifydayframe.pack()
                    self.DayChoice.set_days(self.notify_days)

        def add_new_alert(self):
            """
            This method will be invoked when the add alert time button will be pressed and this will be used to add a new
            SetTime object to set a new alert time.
            :param master:tk.Frame, parent in which it will be packed.
            :return:
            """
            self.add_alert_count = len(self.alert_time_wid) + 1
            alerttime = ExWid.SetTime(self.Alerttimeframe, label=f"Alert Time {str(self.add_alert_count)}:")
            alerttime.grid(row=self.add_alert_count - 1, column=0)
            self.add_alert.grid_configure(row=self.add_alert_count - 1, column=1)
            self.alert_time_wid.append(alerttime)

        def get_notify_settings(self):
            """
            This method will be used to get the settings of the notify which is set.
            :return:
            """
            # Now we need to set some value taskcheck
            self.Task.notify = self.notify
            if self.notify:
                self.Task.notify_time = tuple([int(i) for i in self.SetNotifyTime.get_time_values()])
                self.Task.alert_start_time = tuple([int(i) for i in self.SetStartTime.get_time_values()])
                self.Task.alert_end_time = tuple([int(i) for i in self.SetEndTime.get_time_values()])
                self.Task.notify_day = self.DayChoice.get_day()
                if self.alert_var.get():
                    self.Task.alert_time_wid = [tuple([int(value) for value in atime.get_time_values()]) for atime in self.alert_time_wid]
            # since alert time has many time values and all values are in string format so we have to convert them into integet.

            # key = {"Task": self.Task.textvariable.get(),
            #        "TaskId": None,
            #        "CheckTaskid": None,
            #        "TaskTitle": self.Task.TaskTitle,
            #        "Notify": self.notify,
            #        "NotifyTime": self.SetNotifyTime.get_time_values(),
            #        "AlertTime": [i.get_time_values() for i in self.alert_time],
            #        "StartTime": self.SetStartTime.get_time_values(),
            #        "EndTime": self.SetEndTime.get_time_values(),
            #        "NotifyDay": self.DayChoice.get_day(),
            #        "TaskCompleted": self.Task.completed}
            #
            # for key, value in key.items():
            #     print(f"{key}:\t{value}")


    class TaskList(ttk.Frame):
        """
        This class will be used to create a tasklist. it will be used to operate different functionality related to the TaskList
        like list of checkbutton , color configurations, style and other functionality.
        """

        def __init__(self, master=None):
            super().__init__(master)
            self.master = master
            self.tasklist = []
            self.tasklists_data = []
            self.tasklist_id = None
            self.tasklist_title = None
            self.next_task_row = 1
            self.edit_button_map = {}
            self.style = ttk.Style()
            self.style.configure("TaskList.TButton", highlightcolor='white', highlightthickness=5)
            self.init_date = apps.Time.get_current_date()
            self.content = self.Content(self)
            self.heading = self.Heading(self)

        # Note to use all inner class with outer class attributes we need to return a one object of each class by using
        # a method like below one.
        def _init_Heading_(self):
            """
            This method will be used to initialize the inner Heading class in which we will put all buttons and title of
            tasklist
            :return:
            """
            # in this we will return a Heading class object which is held by the TaskList class object.
            # it means that every TaskList object will have its own Heading object.
            # Now here self is the object of the TaskList class and TaskList have Heading class
            # Now we will return a Heading object and we will pass in it self object as master window of the object.
            return self.Heading(self)

        def _init_Content_(self):
            """
            This method will be used to initialize the inner Content class in which we will put all the tasks of tasklist.
            :return:
            """
            return self.Content(self)

        class Content(ttk.Frame):

            def __init__(self, master=None, ):
                super().__init__(master)
                self.master = master
                self.style = ttk.Style()
                self.contentbox_background = "#d6c1e8"
                self.style.configure("Content.TFrame", background=self.contentbox_background)
                self.configure(width=300, height=200, style='Content.TFrame')
                self.pack(side='bottom', anchor='s', fill='both', expand=1, pady=(10, 0))
                self.pack_propagate(False)

            def content(self, style=None):
                """
                This method will be used to create the content frame and this function will be used to change some configurations
                in later future.
                :param style:style, style object to set style configure for content frame.
                :return:
                """

        class Heading(ttk.Frame):
            """
            This heading class will be used to define the heading information and its attribute configuration, like heading label,
            style, and buttons.
            """

            def __init__(self, master=None):
                """
                This method will be used to initialize the constructor for Heading object it will also initiate the inherited
                    class __init__ method.
                :param master:
                :param parent:
                """
                super().__init__(master)
                self.style = ttk.Style()
                self.heading_master = master
                self.container = self.heading_master.content
                self.utility = apps.DailyRoutine()
                self.headbox_background = "#20627a"
                self.style.configure("Heading.TFrame", background=self.headbox_background)
                self.style.configure(width=300, height=50, style="Heading.TFrame")
                self.style.configure("Title.TLabel", font=("sarif", 12, 'bold'))
                self.style.map("Title.TLabel",
                               background=[('hover', 'white')])

                self.label_var = StringVar()
                if self.heading_master.tasklist_title:
                    self.label_var.set(self.heading_master.tasklist_title)
                else:
                    self.label_var.set("Untitled")
                self.heading_master.tasklist_title = self.label_var
                # Now we will make a label to show the title of the TaskList
                self.title_label = ttk.Label(self, textvariable=self.label_var, style="Title.TLabel")
                self.title_label.bind("<Button-1>", self.change_title)

                # Now we will make three buttons, save, delete and add a task button
                self.add_task_var = StringVar()
                self.add_task_var.set("add")
                self.add_task = ttk.Button(self, textvariable=self.add_task_var, style='TaskList.TButton',
                                           takefocus=False)

                # Now we will make a delete button
                self.delete_var = StringVar()
                self.delete_var.set("delete")
                self.delete_task = ttk.Button(self, textvariable=self.delete_var, style='TaskList.TButton',
                                              takefocus=False)

                # Now we will make a save button
                self.save_var = StringVar()
                self.save_var.set("save")
                self.save_task = ttk.Button(self, textvariable=self.save_var, style='TaskList.TButton', takefocus=False,
                                            command = self.save_command)

                # ===========================================================================================#
                self.pack_widgets()  # packing all widgets at once.
                self.add_task.config(command=self.add_command)
                self.pack(side='top', anchor='n', fill='x')

            def pack_widgets(self):
                """
                This method will be used to pack all widgets of Heading Frame at once.
                :return:
                """
                self.title_label.pack(side='left', anchor='w')
                self.add_task.pack(side='right', anchor='e')
                self.delete_task.pack(side='right', anchor='e')
                self.save_task.pack(side='right', anchor='e')

            def add_command(self):
                """
                This command will be used to add new task in the tasklist which is held by  container.
                :param container:ttk.Frame, a Frame container in which we will put all the tasks.
                :return:
                """
                self.pack_propagate(False)
                # Now here we need to make a Dailyroutine.Checkbutton object to create a object
                self.Entery_var = StringVar()
                self.Entery = Entry(self.master, textvariable=self.Entery_var, width=35, font=('sarif', 12))
                self.Entery.focus_set()
                self.Entery.pack(side='left', anchor='w', )
                self.Entery.pack_propagate(False)

                self.task_check = DailyRoutine.CheckTask(self.container)
                self.task_check.TaskTitle = self.label_var.get()  # passing the Title to the TaskCheck object.
                self.container.grid_columnconfigure(0, minsize=250)
                self.container.grid_columnconfigure(1, minsize=50)
                self.task_check.grid(row=self.master.next_task_row, column=0, sticky='w')

                # Now we need to pack a edit button to edit the task_check
                self.edit_check = ttk.Button(self.container, text='edit', style='TaskList.TButton', takefocus=False)
                self.edit_check.grid(row=self.master.next_task_row, column=1, sticky='e')
                self.task_check.edit_button = self.edit_check  # setting the edit button into checkbutton
                self.task_check.edit_config()  # configuring the edit command.

                # Now we will make a notification
                self.notify_check = ttk.Button(self.container, text='notify', style='TaskList.TButton', takefocus=False)
                self.notify_check.grid(row=self.master.next_task_row, column=2, sticky='e')
                self.task_check.notify_button = self.notify_check  # setting the notify button into checkbutton
                self.task_check.notify_config()  # configuring the notify command

                self.master.tasklist.append(self.task_check)
                self.master.edit_button_map[self.edit_check] = self.task_check
                self.master.next_task_row += 1
                self.Entery.bind("<Return>", self.get_entrytext)

            def insert_task(self, task_object):
                """
                This method will be used when we will retrieve our data from the local storage
                :return:
                """

                # Now here we need to make a Dailyroutine.Checkbutton object to create a object
                self.task_check = task_object
                self.task_check.TaskTitle = self.label_var.get()  # passing the Title to the TaskCheck object.
                self.container.grid_columnconfigure(0, minsize=250)
                self.container.grid_columnconfigure(1, minsize=50)
                self.task_check.grid(row=self.master.next_task_row, column=0, sticky='w')
                self.task_check.checktaskid = self.master.next_task_row


                # Now we need to pack a edit button to edit the task_check
                self.edit_check = ttk.Button(self.container, text='edit', style='TaskList.TButton', takefocus=False)
                self.edit_check.grid(row=self.master.next_task_row, column=1, sticky='e')
                self.task_check.edit_button = self.edit_check  # setting the edit button into checkbutton
                self.task_check.edit_config()  # configuring the edit command.

                # Now we will make a notification
                self.notify_check = ttk.Button(self.container, text='notify', style='TaskList.TButton', takefocus=False)
                self.notify_check.grid(row=self.master.next_task_row, column=2, sticky='e')
                self.task_check.notify_button = self.notify_check  # setting the notify button into checkbutton
                self.task_check.notify_config()  # configuring the notify command

                self.master.tasklist.append(self.task_check)
                self.master.edit_button_map[self.edit_check] = self.task_check
                self.master.next_task_row += 1

            def get_entrytext(self, event):
                """
                This method will be bound to the Entry box of the Tasklist and it will be executed when Return key is pressed.
                :return: 
                """
                data = {"Task": self.Entery_var.get(),
                        "TaskId": self.heading_master.tasklist_id,
                        "TaskTitle": self.label_var.get()}
                self.task_check.textvariable.set(self.Entery_var.get())

                self.utility.save_dailyroutine(data)
                self.utility.CSV_DATABASE.append(data)
                self.Entery.destroy()

            def change_title(self, event):
                """
                This method will be used to change the title of the tasklist. this method will be bind to the table variable.
                :return:
                """
                print("change title function is called.")
                self.title_label.pack_forget()

                Entry = ttk.Entry(self, textvariable=self.label_var, font=('sarif', 12, 'bold'))
                Entry.pack(side='left', anchor='w')

                def set_title(event2):
                    # this method will be executed when the enter will be hit.
                    Entry.destroy()
                    self.title_label.pack(side='left', anchor='w')
                    self.utility.JSON_DATABASE[self.heading_master.tasklist_id]['Title'] = self.label_var.get()

                Entry.bind("<Return>", set_title)

            def save_command(self):
                """
                This method will be used to save a tasklist's task data and notify values also.
                :return:
                """
                with open("./data/dailyroutine.csv", 'w', newline='') as file:
                    writer = csv.DictWriter(file, fieldnames=self.utility.tasklist_fields)
                    writer.writeheader()
                    writer.writerows(self.utility.CSV_DATABASE)