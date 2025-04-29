#include "student.h"

Student::Student(int num, const std::string& name, int classNum, const std::string& addr,
                 const std::string& tel, const std::string& major)
    : num(num), name(name), classNum(classNum), addr(addr), tel(tel), major(major) {}