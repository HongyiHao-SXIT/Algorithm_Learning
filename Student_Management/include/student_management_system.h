#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H

#include <vector>
#include <string>
#include "student.h"

class StudentManagementSystem {
private:
    std::vector<Student> students;

public:
    void readFromFile(const std::string& filename);

    void writeToFile(const std::string& filename) const;

    void addStudent(const Student& student);

    void displayAllStudents() const;

    void searchStudentByNum(int num) const;

    void searchStudentByName(const std::string& name) const;

    void searchStudentByClass(int classNum) const;

    void deleteStudentByNum(int num);

    void deleteStudentByName(const std::string& name);

    void modifyStudentByNum(int num);

    void modifyStudentByName(const std::string& name);

    void sortStudentsAscending();

    void sortStudentsDescending();

    void countStudentsByClass() const;

    void countStudentsByProvince() const;
};

#endif