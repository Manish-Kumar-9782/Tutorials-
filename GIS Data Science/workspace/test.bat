@echo off
rem Open a new cmd window
start cmd /k

rem Wait for a moment to ensure the new cmd window is fully loaded
timeout /t 2 >nul

rem Send a command to the new cmd window
echo dir

rem You can add more commands here as needed
echo echo Hello from the new cmd window!

rem Pause to keep the cmd window open (optional)
pause
