#include <iostream>
#include <string>

using namespace std;

class ICEngine
{
    string engine;
    int cc = 800;

public:
    ICEngine(string engine, int cc)
    {
        this->engine = engine;
        this->cc = cc;
    }

    string engine_start()
    {
        cout << "ICEngine Start ... starting..." << endl;
    }
};

class ElectricMotor
{
    string motor;
    int hp = 2000;

public:
    ElectricMotor(string motor, int hp)
    {
        this->motor = motor;
        this->hp = hp;
    }

    string motor_start()
    {
        cout << "Electric Start ... starting..." << endl;
    }
};

// hybrid car will inherit the both ICEngine and ElectricMotor car.
class HybridCar : public ICEngine, public ElectricMotor
{
    int wheels;

public:
    HybridCar()
        : ICEngine("type1", 800),
          ElectricMotor("type2", 2000)
    {
        this->wheels = 4;
    }

    void start(int type)
    {
        switch (type)
        {
        case 1:
            this->engine_start();
            break;
        case 2:
            this->motor_start();
            break;
        }
    }
};

int main()
{

    HybridCar car;

    car.start(1);

    cout << " car stopped " << endl;

    car.start(2);

    cout << " car stopped " << endl;

    return 0;
}
