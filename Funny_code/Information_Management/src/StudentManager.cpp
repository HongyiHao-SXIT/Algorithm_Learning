#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

StudentManager::StudentManager() : head(new Node({0, "", 0, "", "", ""})) {
    head->next = nullptr;
}

StudentManager::~StudentManager() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void StudentManager::showMenu() const {
    std::cout << "*************** [Student Contact Management System] ***************\n";
    std::cout << "*  1. Add Student Information                                     *\n";
    std::cout << "*  2. View All Student Information                                *\n";
    std::cout << "*  3. Search Student Information                                  *\n";
    std::cout << "*  4. Delete Student Information                                  *\n";
    std::cout << "*  5. Update Student Information                                  *\n";
    std::cout << "*  6. Sort Student Information                                    *\n";
    std::cout << "*  7. Statistics                                                  *\n";
    std::cout << "*  0. Exit                                                        *\n";
    std::cout << "*******************************************************************\n";
    std::cout << "Please select an option: ";
}

void StudentManager::handleInput() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 0: {
            std::cout << "Exiting system...\n";
            saveToFile("student.txt");
            exit(0);
        }
        case 1: {
            Student data;
            std::cout << "Enter Student ID, Name, Class, Address, Phone, Major:\n";
            std::cin >> data.id >> data.name >> data.classNum >> data.address >> data.phone >> data.major;
            addStudent(data);
            std::cout << "Student added successfully.\n";
            break;
        }
        case 2:
            displayStudents();
            break;
        case 3:
            handleSearch();
            break;
        case 4:
            handleDelete();
            break;
        case 5:
            handleUpdate();
            break;
        case 6:
            handleSort();
            break;
        case 7:
            handleStatistics();
            break;
        default:
            std::cout << "Invalid selection. Please try again.\n";
            break;
    }
    saveToFile("student.txt");
}

void StudentManager::addStudent(const Student& data) {
    Node* newNode = new Node(data);
    newNode->next = head->next;
    head->next = newNode;
}

void StudentManager::displayStudents() const {
    Node* current = head->next;
    std::cout << "ID\tName\tClass\tAddress\tPhone\t\tMajor\n";
    while (current) {
        std::cout << current->data.id << "\t" << current->data.name << "\t" 
                  << static_cast<int>(current->data.classNum) << "\t" 
                  << current->data.address << "\t" << current->data.phone << "\t" 
                  << current->data.major << "\n";
        current = current->next;
    }
}

void StudentManager::searchStudents(SearchType type, const void* key) {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "Student list is empty.\n";
        return;
    }

    Node* current = head->next;
    bool found = false;
    
    std::cout << "ID\tName\tClass\tAddress\tPhone\t\tMajor\n";
    
    while (current != nullptr) {
        bool match = false;
        
        switch (type) {
            case SearchType::BY_ID:
                if (current->data.id == *static_cast<const int*>(key)) {
                    match = true;
                }
                break;
                
            case SearchType::BY_NAME:
                if (current->data.name == *static_cast<const std::string*>(key)) {
                    match = true;
                }
                break;
                
            case SearchType::BY_CLASS:
                if (current->data.classNum == *static_cast<const int*>(key)) {
                    match = true;
                }
                break;
        }
        
        if (match) {
            std::cout << current->data.id << "\t" << current->data.name << "\t" 
                      << static_cast<int>(current->data.classNum) << "\t" 
                      << current->data.address << "\t" << current->data.phone << "\t" 
                      << current->data.major << "\n";
            found = true;
            
            if (type == SearchType::BY_ID) {
                return;
            }
        }
        
        current = current->next;
    }
    
    if (!found) {
        switch (type) {
            case SearchType::BY_ID:
                std::cout << "Student with ID " << *static_cast<const int*>(key) << " not found.\n";
                break;
                
            case SearchType::BY_NAME:
                std::cout << "Student with name \"" << *static_cast<const std::string*>(key) << "\" not found.\n";
                break;
                
            case SearchType::BY_CLASS:
                std::cout << "No students found in class " << *static_cast<const int*>(key) << ".\n";
                break;
        }
    }
}

void StudentManager::handleSearch() {
    int choice, id, classNum;
    std::string name;

    std::cout << "Search by:\n1. ID\n2. Name\n3. Class\nChoice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter Student ID: ";
            std::cin >> id;
            searchById(id);
            break;
        case 2:
            std::cout << "Enter Student Name: ";
            std::cin >> name;
            searchByName(name);
            break;
        case 3:
            std::cout << "Enter Class Number: ";
            std::cin >> classNum;
            searchByClass(classNum);
            break;
        default:
            std::cout << "Invalid selection.\n";
    }
}

void StudentManager::searchById(int id) {
    searchStudents(SearchType::BY_ID, &id);
}

void StudentManager::searchByName(const std::string& name) {
    searchStudents(SearchType::BY_NAME, &name);
}

void StudentManager::searchByClass(int classNum) {
    searchStudents(SearchType::BY_CLASS, &classNum);
}

void StudentManager::handleDelete() {
    int choice, id;
    std::string name;

    std::cout << "Delete by:\n1. ID\n2. Name\nChoice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter Student ID to delete: ";
            std::cin >> id;
            deleteById(id);
            break;
        case 2:
            std::cout << "Enter Student Name to delete: ";
            std::cin >> name;
            deleteByName(name);
            break;
        default:
            std::cout << "Invalid selection.\n";
    }
}

void StudentManager::deleteById(int id) {
    Node* prev = head;
    Node* current = head->next;

    while (current && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        std::cout << "Student with ID " << id << " not found.\n";
        return;
    }

    prev->next = current->next;
    delete current;
    std::cout << "Student deleted successfully.\n";
}

void StudentManager::deleteByIds(int begin, int end) {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }

    if (begin > end) {
        std::cout << "Invalid range: begin ID > end ID.\n";
        return;
    }

    Node* prev = head;
    Node* current = head->next;
    int count = 0;

    while (current != nullptr) {
        if (current->data.id >= begin && current->data.id <= end) {
            Node* toDelete = current;
            prev->next = current->next;
            current = current->next;
            delete toDelete;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }

    std::cout << "Deleted " << count << " students with IDs between " << begin << " and " << end << ".\n";
}

void StudentManager::deleteByName(const std::string& name) {
    Node* prev = head;
    Node* current = head->next;

    while (current && current->data.name != name) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        std::cout << "Student with name " << name << " not found.\n";
        return;
    }

    prev->next = current->next;
    delete current;
    std::cout << "Student deleted successfully.\n";
}

void StudentManager::handleUpdate() {
    int choice, id;
    std::string name;

    std::cout << "Update by:\n1. ID\n2. Name\nChoice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter Student ID to update: ";
            std::cin >> id;
            updateById(id);
            break;
        case 2:
            std::cout << "Enter Student Name to update: ";
            std::cin >> name;
            updateByName(name);
            break;
        default:
            std::cout << "Invalid selection.\n";
    }
}

void StudentManager::updateById(int id) {
    Node* current = head->next;

    while (current && current->data.id != id) {
        current = current->next;
    }

    if (!current) {
        std::cout << "Student with ID " << id << " not found.\n";
        return;
    }

    std::cout << "Enter new ID, Name, Class, Address, Phone, Major:\n";
    std::cin >> current->data.id >> current->data.name >> current->data.classNum
              >> current->data.address >> current->data.phone >> current->data.major;
    std::cout << "Student information updated successfully.\n";
}

void StudentManager::updateByName(const std::string& name) {
    Node* current = head->next;

    while (current && current->data.name != name) {
        current = current->next;
    }

    if (!current) {
        std::cout << "Student with name " << name << " not found.\n";
        return;
    }

    std::cout << "Enter new ID, Name, Class, Address, Phone, Major:\n";
    std::cin >> current->data.id >> current->data.name >> current->data.classNum
              >> current->data.address >> current->data.phone >> current->data.major;
    std::cout << "Student information updated successfully.\n";
}

void StudentManager::handleSort() {
    int choice;

    std::cout << "Sort by:\n1. ID Ascending\n2. ID Descending\nChoice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            sortAscending();
            break;
        case 2:
            sortDescending();
            break;
        default:
            std::cout << "Invalid selection.\n";
    }
}

void StudentManager::sortAscending() {
    Node *i, *j;
    Student temp;

    for (i = head->next; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.id > j->data.id) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    std::cout << "Sorted in ascending order.\n";
    displayStudents();
}

void StudentManager::sortDescending() {
    Node *i, *j;
    Student temp;

    for (i = head->next; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.id < j->data.id) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    std::cout << "Sorted in descending order.\n";
    displayStudents();
}

void StudentManager::handleStatistics() {
    int choice;

    std::cout << "Statistics:\n1. Class Count\n2. Province Count\nChoice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            countByClass();
            break;
        case 2:
            countByProvince();
            break;
        default:
            std::cout << "Invalid selection.\n";
    }
}

void StudentManager::countByClass() {
    int count[MAX_CLASSES + 1] = {0};
    Node* current = head->next;

    while (current) {
        if (current->data.classNum >= 1 && current->data.classNum <= MAX_CLASSES) {
            count[current->data.classNum]++;
        }
        current = current->next;
    }

    for (int i = 1; i <= MAX_CLASSES; i++) {
        std::cout << "Class " << i << ": " << count[i] << " students\n";
    }
}

void StudentManager::countByProvince() {
    std::vector<std::string> provinces = {
        "Hebei", "Shanxi", "Liaoning", "Jilin", "Heilongjiang", "Jiangsu", "Zhejiang",
        "Anhui", "Fujian", "Jiangxi", "Shandong", "Henan", "Hubei", "Hunan", "Guangdong",
        "Hainan", "Sichuan", "Guizhou", "Yunnan", "Shaanxi", "Gansu", "Qinghai", "Taiwan",
        "Inner Mongolia", "Guangxi", "Tibet", "Ningxia", "Xinjiang", "Beijing", "Tianjin",
        "Shanghai", "Chongqing", "Hong Kong", "Macau"
    };

    int count[34] = {0};
    Node* current = head->next;

    while (current) {
        for (int i = 0; i < 34; i++) {
            if (current->data.address == provinces[i]) {
                count[i]++;
                break;
            }
        }
        current = current->next;
    }

    for (int i = 0; i < 34; i++) {
        if (count[i] > 0) {
            std::cout << provinces[i] << ": " << count[i] << " students\n";
        }
    }
}

void StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    Student data;
    while (file >> data.id >> data.name >> data.classNum >> data.address >> data.phone >> data.major) {
        addStudent(data);
    }

    file.close();
}

void StudentManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file for writing.\n";
        return;
    }

    Node* current = head->next;
    while (current) {
        file << current->data.id << "\t" << current->data.name << "\t"
             << static_cast<int>(current->data.classNum) << "\t"
             << current->data.address << "\t" << current->data.phone << "\t"
             << current->data.major << "\n";
        current = current->next;
    }

    file.close();
}