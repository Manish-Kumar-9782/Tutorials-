#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{

    time_t *t = NULL;

    time_t t2 = time(nullptr);
    tm *ct = localtime(&t2);

    char str_time[30];

    cout << "Your Time: " << t << endl;

    cout << asctime(ct)
         << t2 << " seconds since the Epoch\n";

    strftime(str_time, 30, "%m %b %Y", localtime(&t2));
    cout
        << "Your Year: " << str_time << endl;

    return 0;
}
