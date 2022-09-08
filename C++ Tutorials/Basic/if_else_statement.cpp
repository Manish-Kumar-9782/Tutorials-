//  if else statement in c++
#include <iostream>
#include <string>

// std namespace

using namespace std;

int main()
{

    string cmd = "active";
    int pin = 123;

    if (cmd == "active" && pin == 123) 
    {
        cout << "command: your account has be activated" << endl;
    }
    else if (cmd == "deactive")
    {
        cout << "command: your account has be deactivated" << endl;
    }
    else
    {
        cout << "command: invalid command:" << endl;
    }

    return 0;
}
