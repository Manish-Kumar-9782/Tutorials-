#include <iostream>
#include <string>

using namespace std;

class Mobile
{

public:
    // creating a virtual method for abstraction.
    // abstracted method call.
    virtual void call() = 0;
};

class Samsung : public Mobile
{
public:
    void call()
    {
        cout << "Calling Samsung" << endl;
    }
};

class Motorola : public Mobile
{

public:
    void call()
    {
        cout << "Calling Motorola" << endl;
    }
};

class User
{
public:
    void call_from_mobile(Mobile &mobile)
    {
        mobile.call();
    }
};
int main()
{
    // Mobile mobile;
    // cannot create an object of a class which contains virtual methods.

    Samsung samsung;
    Motorola motorola;
    // mobile.call();
    // samsung.call();

    User user;
    user.call_from_mobile(motorola);
    return 0;
}