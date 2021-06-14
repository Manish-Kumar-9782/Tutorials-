"""
This module contains some extra widgets class which is used to combine many widgets in one class and to create a single
object which contain all of their attributes.
"""
import tkinter as tk
from tkinter import ttk, font


class SetTime(ttk.Frame):
    """
    This class will be used to set the time for a task it will contain three Spinbox to set the hour, minute and second
        for any kind of task.
    """
    def __init__(self, master=None, label=None):
        super().__init__(master)
        self.style = ttk.Style()
        self.master = master
        self.hour = tk.StringVar()
        self.minute = tk.StringVar()
        self.seconds = tk.StringVar()
        self.label_var = tk.StringVar()
        self.s_epadx= 5

        self.spin_config = {'width':2, 'font':('sarif',15,'bold'), 'bg':'white',
                       'buttonbackground':self.master.cget('bg'), 'buttondownrelief':'flat',
                       'relief':'flat', 'buttonup':'flat', 'from_':00, 'format':'%02.0f'}

        self.label = ttk.Label(self, textvariable=self.label_var)
        self.hour_spin = tk.Spinbox(self, cnf=self.spin_config, to=24, textvariable=self.hour, command=self.update_values)
        self.min_spin = tk.Spinbox(self, cnf=self.spin_config, to=60, textvariable=self.minute, command=self.update_values)
        self.sec_spin = tk.Spinbox(self, cnf=self.spin_config, to=60, textvariable=self.seconds, command=self.update_values)

        if label:
            self.label_var.set(label)
            self.label.pack(side='left', anchor='w', padx=10)
        self.hour_spin.pack(side='left', anchor='w', padx=self.s_epadx)
        self.min_spin.pack(side='left', anchor='w', padx=self.s_epadx)

        self.sec_spin.pack(side='left', anchor='w', padx=self.s_epadx)


    def update_values(self):
        """
        This method will be used to define values of the spinbox control variables. it means that it will update or return
        hour, min, sec value
        :return:
        """
        self._hour_ = self.hour.get()
        self._minute_ = self.minute.get()
        self._sec_ = self.seconds.get()

    def get_time_values(self):
        """
        This method will be used to get the time values after setting the time.
        :return:tuple, hour, min, sec.
        """
        return self._hour_, self._minute_, self._sec_

        # Now we need to create some Spinbox which will help us to set some valus.

    def pack_settime(self, cfg=None, **kw):
        self.pack(cnf=cfg, **kw)

    def destroy_settime(self):
        self.destroy()


class DayChoice(ttk.Frame):
    """
    This class will be used to create a day choicer object which will be put in a class attributes which will be used
    by another class object.
    """
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.allday = False
        self.days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']
        self.selected_days = []
        self.choice_daily = 'daily'
        self.choice_select = 'select'
        self.day_widgets = []
        # Now we need to add some other widgets in this like Radiobutton, checkbutton, Label etc.
        self.label = ttk.Label(self, text="Notify Me:")
        self.Notify_Daily = ttk.Radiobutton(self, text="Daily", value=self.choice_daily,
                                            command=lambda x=self.choice_daily:self.choice_command(x))
        self.Notify_Choice = ttk.Radiobutton(self, text='Select', value=self.choice_select,
                                             command=lambda x=self.choice_select: self.choice_command(x))

        self.label.grid(row=0, column=0, sticky='w')
        self.Notify_Daily.grid(row=0, column=1, sticky='w')
        self.Notify_Choice.grid(row=0, column=2, sticky='w')


    def choice_command(self, selection):
        """
        This method will be invoked when the any of the Radiobutton is selected.
        :return:
        """

        print("selected button: ", selection)
        if selection == 'select':
            self.allday = False
            col = 0
            row = 1
            for index, day in enumerate(self.days):
                selected_choice = tk.IntVar()
                selected_choice.set(0)
                choice = ttk.Checkbutton(self, text=day, variable=selected_choice)
                choice.grid(row=row, column=col, sticky='w')
                # self.day_choice_map.append((selected_choice, day))
                choice.config(command=lambda x=selected_choice,
                                            y=day: self.add_day(x, y))
                self.day_widgets.append(choice)
                if index % 3 == 0 and index != 0:
                    col = 0
                    row += 1
                else: col += 1

        elif selection == 'daily':
            """
            If daily is chosen then first of all we need to delete all the day if they exist.
            """
            self.allday = True
            if self.day_widgets:
                for day in self.day_widgets:
                    day.destroy()




    def add_day(self, var, day):
        """
        This method will be used to call when any of the day is selected.
        :param var: control variable for selected focused and active choices.
        :param day: selected day through checkbutton.
        :return:
        """
        if var.get():
            self.selected_days.append(day)
        else:
            if day in self.selected_days:
                self.selected_days.remove(day)

    def pack_day(self, cfg=None, **kw):
        self.pack(cnf=cfg, **kw)

    def destroy_day(self):
        self.destroy()

    def get_day(self):
        """
        This method will be used to get the selected day.
        :return:
        """
        if self.allday:
            return self.days
        else:
            return self.selected_days