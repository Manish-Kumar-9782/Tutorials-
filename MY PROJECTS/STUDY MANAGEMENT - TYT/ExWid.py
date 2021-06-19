"""
This module contains some extra widgets class which is used to combine many widgets in one class and to create a single
object which contain all of their attributes.
"""
import tkinter as tk
from tkinter import ttk, font


class ScrollFrame(tk.Frame):
    """
    This class will be used to define and set a scrollbar on a frame widgets and it unable us to scroll through a frame.
    widgets.
    """

    def __init__(self, master=None, cfg=None, **kw):
        """
        init constructor will initialize all the feature of the frame in which will put our scrollbar and a canvas which
        will help us to scroll through the whole region.
        :param master:master, a master window in which we will put our our ScrollFrame window.
        :param mainframe:widget, it is the main frame in which we will put all of our other content or widgets of the application.
        """
        super().__init__(master, cnf=cfg, **kw)
        # Now first of all we need to create a ttk.scrollbar widget and put it into the ScrollFrame object
        self.scroll = ttk.Scrollbar(self, orient='vertical')
        self.scroll.pack(side='right', anchor='e', fill='y')

        # Now we need to make a canvas which will hold our main frame in which we will put our mainframe
        self.canvas = tk.Canvas(self, background='green')
        self.canvas.pack(side='left', anchor='w', fill='both', expand=1)

        # Now we need to configure the scrollbar and canvas also.
        self.scroll.config(command=self.canvas.yview)
        self.canvas.config(yscrollcommand=self.scroll.set, confine=True)
        self.canvas.bind("<Configure>", lambda e: self.canvas.configure(scrollregion=self.canvas.bbox('all')))

        # Now we need to put our mainframe inside the canvas.
        self.ContentFrame = tk.Frame(self.canvas, height=800)

        self.canvas.create_window(0, 0, anchor='nw', window=self.ContentFrame, tags='contentframe')
        self.canvas.itemconfigure('contentframe', width=self.canvas.winfo_width())
        self.bind("<Configure>", self._configure_content_frame)
        self.ContentFrame.bind("<Enter>", self._bound_to_mousewheel)
        self.ContentFrame.bind("<Leave>", self._unbound_to_mousewheel)
        self.update_idletasks()

    def _bound_to_mousewheel(self, event):
        self.bind_all("<MouseWheel>", self._on_mousewheel)

    def _unbound_to_mousewheel(self, event):
        self.unbind_all("<MouseWheel>")

    def _on_mousewheel(self, event):
        self.canvas.yview_scroll(int(-1 * (event.delta / 120)), "units")
        # here delta is used for mouse , delta is a integer value which is eaual to 120
        # if we dont devide event.delta by 120 then our frame will move very fast.

    def _configure_content_frame(self, event):
        # this method will be used to update the size of the content frame as it updates.
        self.update_idletasks()
        size = (self.canvas.winfo_height(), self.canvas.winfo_width())
        if self.canvas.winfo_height() != self.ContentFrame.winfo_height():
            self.canvas.config(height=self.ContentFrame.winfo_height())

        if self.canvas.winfo_width() != self.ContentFrame.winfo_width():
            self.canvas.itemconfigure('contentframe', width=self.canvas.winfo_width())

        self.update_idletasks()



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
        self._hour_ = 0
        self._minute_ = 0
        self._sec_ = 0
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

    def set_time_values(self,value):
        """
        This method will be used to set the time value from the local storage if there are any.
        :param value:tuple, tuple or iterable like object containing hour, min, and seconds value.
        """
        _hr, _min, _sec = value
        self.hour.set(_hr)
        self.minute.set(_min)
        self.seconds.set(_sec)
        
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

    def set_days(self, days):
        """
        This method will be used to set selected days while opening the notify setting.
        :return:
        """
        if len(days) == 7:
            self.Notify_Daily.invoke()
        else:
            self.allday = False
            self.Notify_Choice.invoke()
            col = 0
            row = 1
            for index, day in enumerate(self.days):
                selected_choice = tk.IntVar()
                if day in days:
                    selected_choice.set(1)
                choice = ttk.Checkbutton(self, text=day, variable=selected_choice)
                choice.grid(row=row, column=col, sticky='w')
                # self.day_choice_map.append((selected_choice, day))
                choice.config(command=lambda x=selected_choice,
                                             y=day: self.add_day(x, y))
                self.day_widgets.append(choice)
                if index % 3 == 0 and index != 0:
                    col = 0
                    row += 1
                else:
                    col += 1

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