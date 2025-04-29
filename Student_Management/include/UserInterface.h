#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "student_management_system.h"

class UserInterface {
private:
    StudentManagementSystem sms;

    int getValidInput();

public:
    UserInterface();
    void run();
};

#endif