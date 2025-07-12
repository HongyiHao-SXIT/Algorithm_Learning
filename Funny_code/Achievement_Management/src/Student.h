#ifdef STUDENT_H
#define STUDENT_H

#include<string>

class Student {
public:
    std::string className;
    int id;
    std::string name;
    map<string, float> scores;
    float average;

    Student() = default;
};