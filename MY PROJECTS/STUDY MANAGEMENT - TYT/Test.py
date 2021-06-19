import tkinter as tk
import ExWid
from tkinter import ttk
import Widgets
import Frame_Section
import Apps
import DailyRoutine as dr

# root = tk.Tk()
# root.geometry("400x400")
# root.title('Keep Card')
#
# s = ttk.Style()
# s.theme_use('winnative')
# tab = Frame_Section.Frames(root)
# tab = tab.Tracks_Frame(root, height = 400, width = 400)
# tab.pack(fill= tk.BOTH , expand=1)

# apps = Apps.Tracks()
# apps.Add_Record(root)

# frame = Widgets.Widgets.Date_Frame(root)
# frame.Date_Frame(root)

# keeps = Widgets.Widgets.Keeps_Card.KeepCardBar(root,height = 200, width =50, relief = 'groove', bd=5)
# keeps.pack(pady=20)

## Testing the TTH_ProgressBar
# tth = Widgets.Widgets.TTH_ProgressBar(root, time=((1, 3), (4, 7), (7, 8)))
# tth.config(height=100, width=200, bg='red') # 120, 80,80
# tth.t1_var.set(80)
# tth.t2_var.set(0)
# tth.t3_var.set(0)
# tth.tth_theme_configure(bar1='red')
# root.update_idletasks()
#
# tth.pack(pady=20)
# root.update()
# # def button_event(event):
# #     print("button event is done")
# #
# #     print(root.focus_get())
# #     if root.focus_get() != keeps.Entry:
# #
# #         del keeps.Content
# # button = tk.Button(root, text='Strike', command = keeps.Check_Completed)
# # button.pack()
# #root.bind("<Button>",button_event)
# root.mainloop()

#=======================================DAILY ROUTINE =================================================================#
root = tk.Tk()
root.resizable(False, False)
root.title("Set Task Notification")
routine = dr.DailyRoutine(root)
tasklist = dr.DailyRoutine.SetNotify(root)
tasklist.pack()


routine.pack(pady=20)
root.mainloop()
#====================================================================================================================#

#==========================================TIME FRAME FROM WIDGETS===================================================#
# root = tk.Tk()
# wid = Widgets.Widgets()
# tf = wid.Time_Frame(root)
# tf.pack()
# root.mainloop()

#=====================================================================================================================#

#===========================================TESTING THE EXWID==============================================================#
# root = tk.Tk()
# time = ExWid.SetTime(root)
# time.pack()
#
# day = ExWid.DayChoice(root)
# day.pack()
#
# root.mainloop()

#=====================================================================================================================#