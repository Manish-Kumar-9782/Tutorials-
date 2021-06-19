# Now in this we will test of run our program
import tkinter as tk
import Dashboard as Dash
from Apps import Tracks, Timer
from Apps_func import DailyRoutine as daily
import Widgets
root = tk.Tk()
root.geometry('1000x600')

wtimer = tk.Toplevel()
wtimer.geometry("500x200")
wtimer.overrideredirect(True)
timer = Timer.Countdown(wtimer)
Timer.INIT_TIMER_HOLDER = wtimer   # This will pass the init the init timer and it will hold the timer window.
timer.init_Timer(wtimer)

# root.config(bg='black')
app = Dash.Dashboard.MainBody(root)
daily_tasks = daily()
# now here we need to put the function
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#

def on_exit():
    # print("On closing: ")

    daily_tasks.save_tasklist_database()    # saving the task list database before closing the application.
    for wid in root.winfo_children():
        # print("destroying widget: ",wid)
        wid.destroy()
    root.destroy()
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
# print("Root children: ", wid)
# root.protocol("WM_DELETE_WINDOW", lambda: on_exit(parent=root))
root.protocol("WM_DELETE_WINDOW", on_exit)
root.mainloop()
