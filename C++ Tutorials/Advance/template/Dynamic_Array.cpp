#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will make an Array Class which will be dynamic.
---------------------------------------------------------*/

template <typename type>
class Array
{
private:
    int size = 2;   // it contains the current size of the array.
    int length = 0; // it contains the value of number of element.
    type *items = new type[size];

public:
    Array()
    {
        for (int i = 0; i < size; i++)
        {
            this->items[i] = 0;
        }
    }

    void display()
    {
        cout << "array:[";

        for (int i = 0; i < size; i++)
        {

            if (i != size - 1)
            {
                cout << this->items[i] << ",";
            }
            else
            {
                cout << this->items[i];
            }
        }
        cout << "]"
             << "---->" << this->length << endl;
    }

    void add(type item)
    {
        if (this->size > this->length)
        {
            this->items[length++] = item;
        }
    }
};

int main()
{
    system("cls");

    Array<int> ar;

    ar.display();

    ar.add(10); // length 1
    ar.display();

    ar.add(12); // length 2
    ar.display();

    return 0;
}