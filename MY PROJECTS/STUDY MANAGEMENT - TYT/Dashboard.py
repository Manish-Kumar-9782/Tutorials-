
# This Section of the project will be used to display all the application on a dashboard window.
from tkinter import Frame,Label, Button
from tkinter import TOP, BOTTOM,LEFT,RIGHT,BOTH,X,Y
from Widgets import widgets

class Dashboard:
    
    def __init__(self):
        pass
    
    class Keeps(Frame):
        """
        This class will be used to manage the keeps notes on the Application.
        """
        def __init__(self, master = None):
            # 
            super().__init__(master)
            pass
            
            
    class Calender(Frame):
        """
        This class will be used to handle all the operation related to datetime and calendar object. like, date, time, week, day, month, year.
        """
        def __init__(self, master = None):
            # 
            super().__init__(master)
            pass

    class StudyRecord(Frame):
        """
        This class will be used to set and retrieve all the subject and their related recordes.
        """
        def __init__(self, master = None):
            # 
            super().__init__(master)
            pass
        

##---------------------------------------------------------------------------------------------------------------------##
##---------------------------------------------------------------------------------------------------------------------##
    class MainBody(Frame):
        """
        This class will be used to handle the all the operation related to dashboard display section and menus.
        This class will take four main section.
        
        Menu section: In this we will define all the menu functions. it will be at the top of the application.
        
        About section: This will be at the bottom of the application and it will show some useful information about the current section. 
        
        App Menu section: This section will holds some app button and by pressing them we can switch b/w application.`
        
        App Content section: This section will display the current application related content.
        """
        def __init__(self, master = None):
            # 
            super().__init__(master)
            
            self.master = master
            self.master.title("TM-TYT") # title: Time Management Track Your Time.
            self.master.geometry("900x700")
            self.master.update_idletasks()
            self.widgets = widgets()

            self.Applications() # In this function we puts all of our section.
        
        def MenuSection(self, master=None):
            """
            This section will be used to put all the menu button and functions. this will packed at the top of the 
            :param master: master at which we will put this menu section.
            :return: this will not return anything.
            """
            menu_section = Frame(master, bg = 'red', height = 50 )
            menu_section.pack(fill = X, expand = True, side = TOP, anchor = 'n')
            menu_section.pack_propagate(False)

            # Now we will put a label for each section.
            label = Label(menu_section, text = "Menu Section")
            label.pack()
        
        
        def AppMenuSeciton(self , master=None):
            """
            This section will be used to display the some useful information about the current section. this will be placed at
               the bottom of the application.
            :param master: master at which we will put this about section.
            :return: this will not return anything.
            """
            app_menu_section = Frame(master, bg = 'blue', width = 200, height = 600)
            app_menu_section.pack(side = LEFT, fill = Y)
            app_menu_section.pack_propagate(False)

            label = Label(app_menu_section, text="App Menu Section")
            label.pack()

            # Keeps button will be used to initiate the Keeps application on the AppContentSection
            self.Keeps_Button = Button(app_menu_section, text='Keeps')
            self.Keeps_Button.pack(pady = 20)

            # Tracks button will be used to initiate the Tracks of subject, project , activity,
            self.Track_Button = Button(app_menu_section, text = 'Tracks')
            self.Track_Button.pack(pady = 20)



        def AppContentSection(self ,master=None):
            
            app_content_section = Frame(master , bg = 'yellow', width = 600, height = 600)
            app_content_section.pack(side = LEFT, fill = BOTH, expand=True )
            app_content_section.pack_propagate(False)

            self.Track_Button.config(command=lambda: self.widgets.Tracks_Section(master=app_content_section))

            label = Label(app_content_section, text="App Content Section")
            label.pack()
        
        def AboutSection(self, master=None):
            """
            This section will be used to display the some useful information about the current section. this will be placed at
                the bottom of the application.
            :param master: master at which we will put this about section.
            :return: this will not return anything.
            """
            about_section = Frame(master, bg= 'green' , height=50)
            about_section.pack(side=BOTTOM, fill = X, expand = True, anchor ='s')
            about_section.pack_propagate(False)

            label = Label(about_section, text="About Section")
            label.pack()
            
        def Applications(self):
            """
            This function will be used to put all the sections all together.
            :return: 
            """
            root = self.master # here we will define the self.master window as the root window, from now we will use the root for the self.master
            
            self.MenuSection(root)

            # her now we need to make another frame on which AppMenuSection and AppContentSection can be put.
            AppMidSection = Frame(root, width = 900, height = 700)
            AppMidSection.pack(fill = BOTH, expand = True, side = TOP)
            AppMidSection.pack_propagate(False)

            self.AppMenuSeciton(AppMidSection)
            self.AppContentSection(AppMidSection)
            self.AboutSection(root)
            
            