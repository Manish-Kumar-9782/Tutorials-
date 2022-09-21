#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the inheritance mode, how they
work and how they are different to each other.

In C++ we have three kind of inheritance mode.

1. `Public Mode:` if we derive a subclass from a public base class. then
the public member of the base class will become public in the derived
 class and protected members of the base class will become protected in the derived class.


2. `Protected Mode:` If we derive a subclass from a Protected base class.
Then both public members and protected members of the base class will become
 protected in the derived class.

3. `Private Mode:` If we derive a subclass from a Private base class.
Then both public members and protected members of the base class will become
 Private in the derived class.

**`Note:`** The private members in the base class cannot be directly
accessed in the derived class, while protected members can be directly
accessed.

Now will make classes to demonstrate the things.
---------------------------------------------------------*/

// suppose that we have a class which has public, private, protected
// data members.

class A
{
private:
    int x;

protected:
    int y;

public:
    int z;
};
/*---------------------------------------------------------*/

// Now we will make a derived class with private inheriting mode.
class B : private A
{
    // private member of A will not be inherited.
    // all the protected and public member are inherited as
    // the private member of B.
public:
    int xyz;
};
/*---------------------------------------------------------*/

class C : protected A
{
    // private member of A will not be inherited.
    // all the protected and public member are inherited as
    // the protected member of C.
public:
    int xyz;
};

/*---------------------------------------------------------*/

class D : public A
{
    // private member of A will not be inherited.
    // all the protected members become protected members of D
    // all the public members become public members of D
public:
    int xyz;
};
/*---------------------------------------------------------*/

int main()
{
    system("cls");

    return 0;
}