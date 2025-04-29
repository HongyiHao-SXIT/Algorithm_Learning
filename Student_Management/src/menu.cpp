#include <iostream>
#include "include/menu.h"

void displayMenu() {
    std::cout << "****************【Student Contact Management System】**************" << std::endl;
    std::cout << "*\t\t1. Enter student contact information               *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t2. Browse student information                       *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t3. Search function                                  *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t4. Delete student information                       *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t5. Modify student information                       *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t6. Sort student information                         *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t7. Statistics of student information                *" << std::endl;
    std::cout << "*--------------------------------------------------*" << std::endl;
    std::cout << "*\t\t0. Exit the system                                  *" << std::endl;
    std::cout << "****************************************************" << std::endl;
}