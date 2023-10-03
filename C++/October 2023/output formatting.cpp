#include <iostream>
#include <iomanip>

// %fw.p[flag]
int main()
{
    system("cls");

    std::cout << "hello world" << std::endl;

    // simple output with tabs.

    std::cout << "name\tage\theight" << std::endl;
    std::cout << "Ashutosh kumar\t21\t5.7" << std::endl;

    std::cout << "================================================================" << std::endl;
    std::cout << "setting field width for table format\n"
              << std::endl;

    // creating a table format by using the setw function.
    std::cout << std::setw(30) << "name"
              << std::setw(10) << "age"
              << std::setw(10) << "height" << std::endl;

    std::cout << std::setw(30) << "Ashutosh Kumar"
              << std::setw(10) << "21"
              << std::setw(10) << "5.7" << std::endl;

    std::cout << "================================================================" << std::endl;
    std::cout << "Changing the alignment of text\n"
              << std::endl;

    // changing the direction of the fill character.
    std::cout << std::left << std::setw(30) << "name"
              << std::setw(10) << "age"
              << std::setw(10) << "height" << std::endl;

    std::cout << std::setw(30) << "Ashutosh Kumar"
              << std::setw(10) << "21"
              << std::setw(10) << "5.7" << std::endl;

    return 0;
}