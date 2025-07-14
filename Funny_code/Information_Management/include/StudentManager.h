#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Node.h"
#include "SearchType.h"

class StudentManager {
private:
    Node* head;
    static const int MAX_CLASSES = 6;

    Node* createNode(const Student& data);
    void searchStudents(SearchType type, const void* key);

public:
    StudentManager();
    ~StudentManager();

    void showMenu() const;
    void handleInput();
    void addStudent(const Student& data);
    void displayStudents() const;
    void handleSearch();
    void handleDelete();
    void handleUpdate();
    void handleSort();
    void handleStatistics();
    void searchById(int id);
    void searchByName(const std::string& name);
    void searchByClass(int classNum);
    void deleteById(int id);
    void deleteByIds(int begin, int end);
    void deleteByName(const std::string& name);
    void updateById(int id);
    void updateByName(const std::string& name);
    void sortAscending();
    void sortDescending();
    void countByClass();
    void countByProvince();
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
};

#endif