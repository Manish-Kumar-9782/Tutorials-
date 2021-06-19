import tkinter as tk
import os, json
import Widgets
wid = Widgets.Widgets()

#======================================== TESTING WIDGETS TRACKS CARDS PROGRESS BAR UPDATE============================
# root = tk.Tk()
# tracks_card = wid.Track_Card(root)
# card = tracks_card.Card_Progress_Bar(cardName='Card1', cardParent='Root.TM-TYT')
# print(json.dumps(card,indent=2))
# root.mainloop()
#======================================================================================================================#

#======================================== TESTING WIDGETS PROGRESS BAR UPDATE==========================================#

# root = tk.Tk()
# tracks_card = wid.Track_Card(root)
# card = tracks_card.Card_Progress_Bar(cardName='Card1', cardParent='Root.TM-TYT')
# print(json.dumps(card,indent=2))
# root.mainloop()

#======================================== TESTING WIDGETS Activity class ==========================================#
root = tk.Tk()
root.geometry("400x400")
act = wid.Activities(root)
act.add_activity_to_watchlist(root)
act.pack()

root.mainloop()