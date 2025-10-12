#include <iostream>
#include <string>

class FurryCharacter {
private:
    std::string name_;
    double favorability_;

public:
    FurryCharacter() : name_(""), favorability_(0.0) {}
    std::string getName() const { return name_; }
    void setName(const std::string& name) { name_ = name; }

    double getFavorability() const { return favorability_; }
    void adjustFavorability(double delta) { favorability_ += delta; }
};

void displayMenu() {
    std::cout << "1. Solve academic/life/entrepreneurial problems for Huhu\n";
    std::cout << "2. Accompany Huhu\n";
    std::cout << "3. Soothe the inner trauma of the fox\n";
    std::cout << "4. Exit\n";
}

int main() {
    FurryCharacter fox;
    FurryCharacter wolf;

    fox.setName("Lanyi_adict");
    wolf.setName("Wolf_MoMo");

    std::cout << "Please enter " << fox.getName()
              << "'s initial favorability value towards the wolf "
                 "(positive means favorability, negative means malice): ";

    double initialFavor;
    if (!(std::cin >> initialFavor)) {
        std::cout << fox.getName() << " sneaks away and goes back to sleep.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return 0;
    }

    fox.adjustFavorability(initialFavor);

    if (fox.getFavorability() < 0) {
        std::cout << "Bad " << fox.getName() << " (negative favorability)\n";
    } else if (fox.getFavorability() > 0) {
        std::cout << "Good " << fox.getName() << " (positive favorability)\n";
    } else {
        std::cout << fox.getName() << " sneaks away and goes back to sleep.\n";
    }

    int wolfAction = 0;
    do {
        displayMenu();
        std::cout << "Please choose the wolf's action: ";
        std::cin >> wolfAction;

        switch (wolfAction) {
        case 1:
            fox.adjustFavorability(1.0);
            std::cout << fox.getName() << "'s favorability increased by 1.0, "
                      << "current favorability: " << fox.getFavorability() << '\n';
            break;
        case 2:
            fox.adjustFavorability(2.0);
            std::cout << fox.getName() << "'s favorability increased by 2.0, "
                      << "current favorability: " << fox.getFavorability() << '\n';
            break;
        case 3:
            fox.adjustFavorability(5.0);
            std::cout << fox.getName() << "'s favorability increased by 5.0, "
                      << "current favorability: " << fox.getFavorability() << '\n';
            break;
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid selection, please try again.\n";
        }
    } while (wolfAction != 4);

    if (fox.getFavorability() >= 100.0) {
        std::cout << "Let's be together ❤️\n";
    } else {
        std::cout << "Still need to work harder 🐺\n";
    }

    return 0;
}
