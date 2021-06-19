import tkinter as tk
import Apps
import Apps_func as apps
import json
import time
#================================== TEST COUNTDOWN TIMER========================================#

# Timer  = Apps.Timer.Countdown()
# root = tk.Tk()
# Timer.Ask_Countdown_Time(root)
#
# root.mainloop()


#================================== TEST ACTIVITY APP========================================#
# root = tk.Tk()
# root.title("Activities")
# activity = Apps.Activities_Apps(root)
# activity.Activity_list_bar()
# activity.pack()
# root.mainloop()

#=========================================== Testing Apps_Func Get Card details=========================#
# file = open('./data/temp')
# Database = json.load(file)
# tracks = apps.Tracks_Cards()
# time = apps.Time()
# card = tracks.Get_Card(Parent='Root.TM-TYT.Card1', Child='Physic', Database=Database)
# print(card)

#====================================== TESTING CheckFileStats =========================================#
# file = './data/Test1.txt'
# update = apps.CheckFileStats(file)
# update_count = 0
#
# while(1):
#     time.sleep(1)
#     result = update.checkupdate()
#     if result:
#         update_count += 1
#         print('file is updated: ',update_count)
#         update.file_modify_time = update.modifytime()

#====================================== TESTING Init Timer with Activities. =========================================#

root = tk.Tk()
root.geometry("500x150")
Timer = Apps.Timer.Countdown()
init_timer = Timer.init_Timer(root)


root.mainloop()