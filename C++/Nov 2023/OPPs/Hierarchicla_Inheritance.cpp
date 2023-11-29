#include <iostream>
#include <string>

using namespace std;

// ================================================================= //
class Automobile
{
protected:
    string name;
    int wheels;
    double weight;
    double length;
    double height;
    int speed;

public:
    // Constructor of Automobile class.
    Automobile(string name, int wheels, double weight,
               double length, double, int speed)
    {
        this->name = name;
        this->wheels = wheels;
        this->weight = weight;
        this->length = length;
        this->height = height;
        this->speed = speed;
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

// ================================================================= //

// Inheriting Automobile by Car
class Car : public Automobile
{
    // car has no data members
    // all other data members are inherited from Automobile.
public:
    Car(string name, int wheels, double weight, double length,
        double height, int speed)
        // calling Automobile (super class) constructor.
        : Automobile(name, wheels, weight, length, height, speed)
    {
        cout << "Car is created..." << endl;
    }
};

// ================================================================= //

// Inheriting Automobile by Truck
class Truck : public Automobile
{
public:
    // Truck constructor
    Truck(string name, int wheels, double weight, double length,
          double height, int speed)
        : Automobile(name, wheels, weight, length, height, speed)
    {
        this->name = name;
        cout << "Truck is created...." << endl;
    }

    // overriding the move
    void move()
    {
        string str = "";

        for (int i = 1; i < 60; i++)
        {

            if (i % 2 == 0)
            {
                str += "-";
            }
            else
            {
                str += "_";
            }
            cout << str << "|*|>"
                 << "\r";
            this->delay(10000);
        }
    }

    // over
};

int main()
{

    Automobile am("MyAuto", 5, 180.5, 10, 6, 60);

    am.start();
    am.move();

    cout << "================================================================" << endl;
    Car car("MyCar", 5, 180.5, 10, 6, 60);
    car.start();
    car.move();

    cout << "================================================================" << endl;
    Truck truck("menna di Gaddi", 5, 180.5, 10, 6, 60);
    truck.start();
    truck.move();
}