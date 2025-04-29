#include "include/student_management_system.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>

void StudentManagementSystem::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }
    int num;
    std::string name, addr, tel, major;
    int classNum;
    while (file >> num >> name >> classNum >> addr >> tel >> major) {
        students.emplace_back(num, name, classNum, addr, tel, major);
    }
    file.close();
}

void StudentManagementSystem::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }
    for (const auto& student : students) {
        file << student.num << " " << student.name << " " << student.classNum
             << " " << student.addr << " " << student.tel << " " << student.major << std::endl;
    }
    file.close();
}

void StudentManagementSystem::addStudent(const Student& student) {
    students.push_back(student);
}

void StudentManagementSystem::displayAllStudents() const {
    std::cout << "Student ID\tName\tClass\tAddress\tTelephone\tMajor" << std::endl;
    for (const auto& student : students) {
        std::cout << student.num << "\t\t" << student.name << "\t" << student.classNum
                  << "\t" << student.addr << "\t" << student.tel << "\t" << student.major << std::endl;
    }
}

void StudentManagementSystem::searchStudentByNum(int num) const {
    for (const auto& student : students) {
        if (student.num == num) {
            std::cout << "Student ID\tName\tClass\tAddress\tTelephone\tMajor" << std::endl;
            std::cout << student.num << "\t\t" << student.name << "\t" << student.classNum
                      << "\t" << student.addr << "\t" << student.tel << "\t" << student.major << std::endl;
            return;
        }
    }
    std::cout << "Student ID does not exist, cannot search!" << std::endl;
}

void StudentManagementSystem::searchStudentByName(const std::string& name) const {
    for (const auto& student : students) {
        if (student.name == name) {
            std::cout << "Student ID\tName\tClass\tAddress\tTelephone\tMajor" << std::endl;
            std::cout << student.num << "\t\t" << student.name << "\t" << student.classNum
                      << "\t" << student.addr << "\t" << student.tel << "\t" << student.major << std::endl;
            return;
        }
    }
    std::cout << "Name does not exist, cannot search!" << std::endl;
}

void StudentManagementSystem::searchStudentByClass(int classNum) const {
    bool found = false;
    std::cout << "Student ID\tName\tClass\tAddress\tTelephone\tMajor" << std::endl;
    for (const auto& student : students) {
        if (student.classNum == classNum) {
            std::cout << student.num << "\t\t" << student.name << "\t" << student.classNum
                      << "\t" << student.addr << "\t" << student.tel << "\t" << student.major << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Class does not exist, cannot search!" << std::endl;
    }
}

void StudentManagementSystem::deleteStudentByNum(int num) {
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [num](const Student& student) { return student.num == num; }),
                   students.end());
    std::cout << "Delete successful!" << std::endl;
}

void StudentManagementSystem::deleteStudentByName(const std::string& name) {
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [name](const Student& student) { return student.name == name; }),
                   students.end());
    std::cout << "Delete successful!" << std::endl;
}

void StudentManagementSystem::modifyStudentByNum(int num) {
    for (auto& student : students) {
        if (student.num == num) {
            int newNum;
            std::string newName, newAddr, newTel, newMajor;
            int newClassNum;
            std::cout << "Please enter the new student ID, name, class, address, telephone, major:" << std::endl;
            std::cin >> newNum >> newName >> newClassNum >> newAddr >> newTel >> newMajor;
            student = Student(newNum, newName, newClassNum, newAddr, newTel, newMajor);
            std::cout << "Modify successful!" << std::endl;
            return;
        }
    }
    std::cout << "Student not found, cannot modify!" << std::endl;
}

void StudentManagementSystem::modifyStudentByName(const std::string& name) {
    for (auto& student : students) {
        if (student.name == name) {
            int newNum;
            std::string newName, newAddr, newTel, newMajor;
            int newClassNum;
            std::cout << "Please enter the new student ID, name, class, address, telephone, major:" << std::endl;
            std::cin >> newNum >> newName >> newClassNum >> newAddr >> newTel >> newMajor;
            student = Student(newNum, newName, newClassNum, newAddr, newTel, newMajor);
            std::cout << "Modify successful!" << std::endl;
            return;
        }
    }
    std::cout << "Student not found, cannot modify!" << std::endl;
}

void StudentManagementSystem::sortStudentsAscending() {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) { return a.num < b.num; });
    displayAllStudents();
}

void StudentManagementSystem::sortStudentsDescending() {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) { return a.num > b.num; });
    displayAllStudents();
}

void StudentManagementSystem::countStudentsByClass() const {
    std::unordered_map<int, int> classCount;
    for (const auto& student : students) {
        classCount[student.classNum]++;
    }
    for (const auto& pair : classCount) {
        std::cout << "Class " << pair.first << " has " << pair.second << " students." << std::endl;
    }
}

void StudentManagementSystem::countStudentsByProvince() const {
    std::vector<std::string> provinces = {"Hebei", "Shanxi", "Liaoning", "Jilin", "Heilongjiang", "Jiangsu", "Zhejiang",
                                          "Anhui", "Fujian", "Jiangxi", "Shandong", "Henan", "Hubei", "Hunan", "Guangdong",
                                          "Hainan", "Sichuan", "Guizhou", "Yunnan", "Shaanxi", "Gansu", "Qinghai", "Taiwan",
                                          "Inner Mongolia", "Guangxi", "Tibet", "Ningxia", "Xinjiang", "Beijing", "Tianjin",
                                          "Shanghai", "Chongqing", "Hong Kong", "Macau"};
    std::unordered_map<std::string, int> provinceCount;
    for (const auto& student : students) {
        for (const auto& province : provinces) {
            if (student.addr.find(province) != std::string::npos) {
                provinceCount[province]++;
                break;
            }
        }
    }
    for (const auto& pair : provinceCount) {
        std::cout << "There are " << pair.second << " students from " << pair.first << "." << std::endl;
    }
}