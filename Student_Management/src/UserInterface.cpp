#include <iostream>
#include <limits>
#include "include/UserInterface.h"
#include "include/menu.h"
#include "include/student.h"

UserInterface::UserInterface() {
    sms.readFromFile("student.txt");
}

int UserInterface::getValidInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please enter an integer: ";
    }
    return input;
}

void UserInterface::run() {
    while (true) {
        displayMenu();
        std::cout << "Please enter your choice: ";
        int choice = getValidInput();
        switch (choice) {
            case 0:
                sms.writeToFile("student.txt");
                std::cout << "Exit normally." << std::endl;
                return;
            case 1: {
                int num;
                std::string name, addr, tel, major;
                int classNum;
                std::cout << "Please enter the student ID, name, class, address, telephone, major:" << std::endl;
                std::cin >> num >> name >> classNum >> addr >> tel >> major;
                sms.addStudent(Student(num, name, classNum, addr, tel, major));
                std::cout << "Entry successful!" << std::endl;
                break;
            }
            case 2:
                std::cout << "----------------【Browse Student Contact Information】----------------" << std::endl;
                sms.displayAllStudents();
                break;
            case 3: {
                std::cout << "----------------【Search Function】----------------" << std::endl;
                std::cout << "\t\t1. Search by student ID\n";
                std::cout << "\t\t2. Search by name\n";
                std::cout << "\t\t3. Search by class\n";
                std::cout << "Please enter your sub-choice: ";
                int subChoice = getValidInput();
                switch (subChoice) {
                    case 1: {
                        int num;
                        std::cout << "Please enter the student ID: ";
                        std::cin >> num;
                        sms.searchStudentByNum(num);
                        break;
                    }
                    case 2: {
                        std::string name;
                        std::cout << "Please enter the name: ";
                        std::cin >> name;
                        sms.searchStudentByName(name);
                        break;
                    }
                    case 3: {
                        int classNum;
                        std::cout << "Please enter the class: ";
                        std::cin >> classNum;
                        sms.searchStudentByClass(classNum);
                        break;
                    }
                    default:
                        std::cout << "Invalid choice, please enter again......" << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "----------------【Delete Student Contact Information】----------------" << std::endl;
                std::cout << "\t\t1. Delete by student ID\n";
                std::cout << "\t\t2. Delete by name\n";
                std::cout << "Please enter your sub-choice: ";
                int subChoice = getValidInput();
                switch (subChoice) {
                    case 1: {
                        int num;
                        std::cout << "Please enter the student ID to delete: ";
                        std::cin >> num;
                        sms.deleteStudentByNum(num);
                        break;
                    }
                    case 2: {
                        std::string name;
                        std::cout << "Please enter the name to delete: ";
                        std::cin >> name;
                        sms.deleteStudentByName(name);
                        break;
                    }
                    default:
                        std::cout << "Invalid choice, please enter again......" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "----------------【Modify Student Contact Information】----------------" << std::endl;
                std::cout << "\t\t1. Find and modify by student ID\n";
                std::cout << "\t\t2. Find and modify by name\n";
                std::cout << "Please enter your sub-choice: ";
                int subChoice = getValidInput();
                switch (subChoice) {
                    case 1: {
                        int num;
                        std::cout << "Please enter the student ID to modify: ";
                        std::cin >> num;
                        sms.modifyStudentByNum(num);
                        break;
                    }
                    case 2: {
                        std::string name;
                        std::cout << "Please enter the name to modify: ";
                        std::cin >> name;
                        sms.modifyStudentByName(name);
                        break;
                    }
                    default:
                        std::cout << "Invalid choice, please enter again......" << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << "----------------【Sort Student Contact Information】----------------" << std::endl;
                std::cout << "\t\t1. Sort in ascending order by student ID\n";
                std::cout << "\t\t2. Sort in descending order by student ID\n";
                std::cout << "Please enter your sub-choice: ";
                int subChoice = getValidInput();
                switch (subChoice) {
                    case 1:
                        sms.sortStudentsAscending();
                        break;
                    case 2:
                        sms.sortStudentsDescending();
                        break;
                    default:
                        std::cout << "Invalid choice, please enter again......" << std::endl;
                }
                break;
            }
            case 7: {
                std::cout << "----------------【Statistics of Student Contact Information】----------------" << std::endl;
                std::cout << "\t\t1. Count the number of students in each class\n";
                std::cout << "\t\t2. Count the number of students from each province\n";
                std::cout << "Please enter your sub-choice: ";
                int subChoice = getValidInput();
                switch (subChoice) {
                    case 1:
                        sms.countStudentsByClass();
                        break;
                    case 2:
                        sms.countStudentsByProvince();
                        break;
                    default:
                        std::cout << "Invalid choice, please enter again......" << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice, please enter again......" << std::endl;
        }
        std::cout << std::endl;
    }
}