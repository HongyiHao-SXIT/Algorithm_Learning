#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    int num;
    std::string name;
    int classNum;
    std::string addr;
    std::string tel;
    std::string major;

    Student(int num, const std::string& name, int classNum, const std::string& addr,
            const std::string& tel, const std::string& major);
};

#endif