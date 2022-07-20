// C program for the above approach
  
#include <stdio.h>
#include <windows.h>
  
// Driver Code
void main()
{
    // Input
    COORD c;
    c.X = 40;
    c.Y = 16;
  
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
  
    printf("hello");
    getch();
}
