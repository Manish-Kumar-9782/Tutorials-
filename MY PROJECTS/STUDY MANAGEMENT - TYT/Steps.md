
# Apps Section
### start_timer_button
1. Now after pressing the button we need a top level borderless
    size window with a fixed size.
   
2. This window should contain the (start,pause,stop) button.
   
   * Start: This button will start the paused countdown.
   
   * Pause: This button will pause the running countdown timer. when we press this button then we should run the idle timer (stopwatch) to count the idle time
   
   * Stop: This will stop the running countdown timer.
    

## display start timer:
    This section will be used to display a small top level border less window
    which can be put any where in the application but, at the starting time this 
    will be shown on the desktop level at top of the all application, and will show
    start timer label and a start button.

* Start Button: when we press this start button then it should ask countdown time.
                Subjects, topics, subtopics etc.
  

## Steps to set the top level window.

1. first we need to set the default geometry of the top level window.
2. after setting this we need to use the master.updateidle_task() metod to update the gemometry.
3. Now we will get the dpi value used by tkinter by using root.fpixle('li')
4. After getting the dpi we need to get the screen size by using the root.winfo_screenwidth() and root.winfo_screenheight()
5. NOw to get the real screen_height and screen_width we need to multiply them with dpi
6. After multiplying (screen_height, screen_width) with dpi we will get our screen_resolution.
7. Now we can get the center line in x and y direction by using this screen_resolution.

#### Center position
    Before making the center posion we should notice the in window gemometry
    "WxH+x+y", x and y are the screen cordinate at which the top left conrner of the 
    window is placed.

    So in order to make the center point we need to subtract the center point of the 
    screen from the center point of the window.
    like center_height = cneter_of_screen_height -  center_of_window_height  
         cneter_width  = center_of_screen_width  -  center_of_window_width 


## Initiate the Countdown
    This window will be appear after pressing the start button on the start timer
    window.
    * After pressing the start button we need to ask for the time of countdown.
    * for that we need to make another top level window.

### SaveTime Class in Apps_func
In this class we will have all the function which will be used to store the time stamps.

* first of all we need to save the starting time of the countdown
   we need to set this in Ask_Countdown_time.
* second, save the Countdown_time, if we complete the countdown time then we also
    need to save the additional time.
  
* additional time will be stored in different column.
* if we stop the time then also need save elapsed, and..
* if we restart the time then also we need to save the time in separate column with name restart_i
    where i is the integer, and the number of attempt of restart.
  
* when time will be saved.
    1. When time is stopped.
    2. When time is restarted.
    3. When the application is stopped.