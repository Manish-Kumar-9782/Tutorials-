
# Keeps application.
    * This application will be used to make keeps note which will be to do list
    of the project/topics/ subject/ activity.
    * This application will hold some tags for per keep note.
    

# Tracks application.
    * Tracks application will contain subject to track and their records.
    * Tracks also will contain data of day, weeks, month, year, data.
    * Tracks also will show all the records with the help of some graphs.
    * It alos should contain the daily work/study/effort hour and this will be trakced by the countdown.


## Track_Record_Data Frame
    This frame can contain muliple things like:
    * Date: The data at which the Project/Subject/Activity is registered.
    * Time: The time at which the Project/Subject/Activity is registered.
    * Name: Name of the Project/Subject/Activity.
    * Topic: Name of the topic/cheapter of Project/Subject/Activity.
    * SubTopic: In this section we can have subtopic and this can be add with a button.
    * Completed: In this we will display a progressbar to show the completion record.
    * Completed Hour: In this we will show that how much hr we have spend on that project.
    * Target Hour: This is the total time or we can say that it is the target time of the Project/Subject/Activity.
    * Expand time: This will be used to expand the time (targe time) with a button. 

#### Subtopic Adding technique
    * To add and display subtopic we can make a subtopic frame and we can put this
    Frmae int the Track_Record_Data Frame Columns.
    * This Frame will be managed by the grid layout system so we can show all thing 
    more structured way
    * This section will contain a button also which will be used to add new subtopic
    * Every sub topic should contain its own time record.
    * To manage the subtopics we can save these things in a separate data file.
    this will make easier to retrive and put the data.

## Add Record from apps
    This function will be used to make a singel card for every record.
    This will contain:
    * A Type Name and Name of the card.
    * This will contain topic and subtopic section.
    * This will also contain the total target hour and completion progress.
    * SubTopic frame will be designed in Widgets section.

#### link buttons with the address of the Cards and SubCards
    Now we need to link every subcard with the button it and we need to store 
    them in a dictionary data structure.

    Ways to do this:
    * The first way is that we can store a full path of the current card in its
    details dictionary and we can retrieve by pressing the button.

    * The second way is that we can make a dictionary of a button with its values
    and the values will be its corresponding Card, in which this button is placed.



## Steps to create a card Record (TM-TYT)

    In this application different functionallity classes are definied in different
    classes:
    Widgets: this class holds all the custom Frames/widgets 
    App_func: This module contains the logical data manipulating method which will be
            used to handle the generated or stored data,
    Apps: This module contain all the small application which are used in this 
            application, this contain different classes for different application.

    Frame_section: This module is used to put all the above module in one place
            and make a them usable from one application.

    Dash_board: This module is the filnal stage of this application, in this  
            defines all of our Sections in which we will put our applications


#### Steps to make a card
    1. Now first of all we will use some methods form Apps_func module and put \
        them in Apps to handle some data and information.
    2. With the above process we will use some small widgets from Widgets 
        module.
    3. By using above both steps we will make a toplevel window or a Frame 
        in which will be used to define our Root card or Subcard information.
        In this step we will use Add_Record or Add_SubRecord method to Generate
        Card information.
    
    4. After Defining our Cards we will put that card information  in Track_Card class
        which is placed inside the widgets Module. This class will be used to create
        New Root_card or a Subcard Frame.

    5. With the 3 and 4 steps we will save our Nested data information on our local 
        storage in json format.
