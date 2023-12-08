#include <iostream>
#include <string>

using namespace std;

class Automobile
{

public:
    string name;
    string fuelType;
    string engine;

    Automobile(string name, string fuelType, string engine)
    {
        this->name = name;
        this->fuelType = fuelType;
        this->engine = engine;
    }

    // member method to show that AutoMobile is starting.
    void start()
    {
        cout << this->name << " starting.. hrrr brrrr" << endl;
    }
    // member method to show that AutoMobile is moving.
    void move()
    {
        cout << this->name << " moving.... hrrr brrrr" << endl;
        string str = "-";
        for (int i = 0; i < 60; i++)
        {
            str += "-";
            cout << str << "*"
                 << "\r";
            delay(10000);
        }
    }

    void delay(int count)
    {
        for (int i = 1; i < count * 10000; i++)
        {
            continue;
        }
    }
};

class Car : public Automobile
{

public:
    Car(string name, string fueltype, string engine)
        : Automobile(name, fueltype, engine)
    {
    }

    void start()
    {
        string start_process[4] = {"|", "/", "--", "\\"};

        string start_string = "car starting: ";
        cout << endl;
        for (int i = 0, idx = 0; i <= 40; i++)
        {
            if ((i % 4) == 0)
            {
                idx = 0;
            }
            this->delay(10000);
            cout << start_string << " "
                 << " " << start_process[idx] << "\r";
            idx++;
        }
        this->move();
    }
};

int main()
{
    Car car("myCar", "diesel", "type1");
    cout << "--------------------------------" << endl;
    cout << "Automobile and Car start example" << endl;
    cout << "--------------------------------" << endl;
    Automobile myauto("MyAuto", "petrol", "type12");

    myauto.start();
    myauto.move();
    car.start();
    return 0;
}