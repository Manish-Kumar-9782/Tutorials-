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

    void start()
    {
        cout << this->name << " starting.. hrrr brrrr" << endl;
    }

    void move()
    {
        cout << this->name << " moving.... hrrr brrrr" << endl;
    }
};

// ================================================================= //

// Single level Inheritance
class Car : public Automobile
{
public:
    Car(string name, int wheels, double weight, double length,
        double height, int speed)
        : Automobile(name, wheels, weight, length, height, speed)
    {
        cout << "Car is created..." << endl;
    }
};

// ================================================================= //

int main()
{

    Automobile am("MyAuto", 5, 180.5, 10, 6, 60);

    am.start();
    am.move();

    Car car("MyCar", 5, 180.5, 10, 6, 60);
    car.start();
    car.move();
}