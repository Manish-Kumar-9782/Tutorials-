#include <iostream>
#include <string>

using namespace std;

class Point
{
public:
    // #data members
    int x;
    int y;
    char ch;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->ch = '*';
    }

    // member function
    void move(int x, int y)
    {
        // row
        for (int i = 0; i <= y; i++)
        {
            // column
            for (int j = 0; j <= x; j++)
            {
                if (i == y && j == x)
                {
                    cout << " " << this->ch;
                }
                else
                {
                    cout << " -";
                }
            }
            cout << "\n";
        }
    }

    void display()
    {
        this->move(this->x, this->y);
    }
};

// operator overloading to print the Point
// ostream &operator<<(ostream &COUT, const Point &p)
// {
//     p.display();
// }

int main()
{
    Point p(0, 0);

    p.move(10, 5);
}