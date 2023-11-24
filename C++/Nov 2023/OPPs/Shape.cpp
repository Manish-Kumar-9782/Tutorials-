#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Point
{
    COORD point;
    char point_char = '*';

public:
    Point(int x, int y)
    {
        point.X = x;
        point.Y = y;
    }

    void draw()
    {
        // set the curser position
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
        cout << point_char << endl;
    }
};

class Rectangle_
{

    double width, height;

public:
    Rectangle_(double width, double height)
    {
        this->width = width;
        this->height = height;
    }

    double perimeter()
    {
        return width + height;
    }

    double area()
    {
        return width * height;
    }
};

int main()
{
    // Rectangle_ rect1(10, 20);
    // cout << "Rectangle Perimeter: " << rect1.perimeter() << endl;
    // cout << "Rectangle Area: " << rect1.area() << endl;
    system("cls");
    Point p(10, 10);
    p.draw();
    return 0;
}