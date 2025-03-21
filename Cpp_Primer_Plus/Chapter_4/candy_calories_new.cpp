#include <iostream>
using namespace std;

struct CandyBar {
    string brand;
    double weight;
    int calories;
};

int main() {
    CandyBar* snacks = new CandyBar[3];
    snacks[0] = {"Mocha Munch", 2.3, 350};
    snacks[1] = {"Choco Chip", 1.5, 250};
    snacks[2] = {"Caramel Crunch", 3.2, 450};

    for (int i = 0; i < 3; ++i) {
        cout << "Brand: " << snacks[i].brand << ", Weight: " << snacks[i].weight << ", Calories: " << snacks[i].calories << endl;
    }

    delete[] snacks;
    return 0;
}