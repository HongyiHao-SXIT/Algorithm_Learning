#include "StudentManager.h"
#include <cstdlib>

int main() {
    StudentManager manager;
    manager.loadFromFile("student.txt");

    while (true) {
        manager.showMenu();
        manager.handleInput();
        system("pause");
        system("cls");
    }

    return 0;
}