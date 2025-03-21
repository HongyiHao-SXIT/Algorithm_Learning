#include <iostream>
using namespace std;

struct CandyBar {
    string brand;
    double weight;
    int calories;
};

int main() {
    CandyBar snacks[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Choco Chip", 1.5, 250},
        {"Caramel Crunch", 3.2, 450}
    };

    for (int i = 0; i < 3; ++i) {
        cout << "Brand: " << snacks[i].brand << ", Weight: " << snacks[i].weight << ", Calories: " << snacks[i].calories << endl;
    }

    return 0;
}