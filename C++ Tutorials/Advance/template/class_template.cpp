#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will try to understand the class template,
we will learn how to make class template and use it.

syntax:

    template <typename type, typename type2, ....., typename typen>
    class class_name{
        // class body.
    }
---------------------------------------------------------*/
template <typename type1, int size>
class Array
{
private:
    int arSize = size;
    type1 *arr = new type1[size];

public:
    Array()
    {
        for (int i = 0; i < arSize; i++)
        {
            this->arr[i] = 0;
        }
    }
    void display()
    {
        cout << "array:[";

        for (int i = 0; i < arSize; i++)
        {

            if (i != arSize - 1)
            {
                cout << this->arr[i] << ",";
            }
            else
            {
                cout << this->arr[i];
            }
        }
        cout << "]" << endl;
    }
};

int main()
{
    system("cls");

    Array<int, 5> ar;

    Array<char, 3> charr;

    ar.display();
    charr.display();

    return 0;
}