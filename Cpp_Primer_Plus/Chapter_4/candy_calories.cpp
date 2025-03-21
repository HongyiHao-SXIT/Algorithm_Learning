#include <iostream>
using namespace std;

struct CandyBar {
    string brand;
    double weight;
    int calories;
};

int main() {
    CandyBar snack;
    snack.brand = "Micha Munch";
    snack.weight = 2.3;
    snack.calories = 350;

    cout << "Food: " << snack.brand << ", Weight: " << snack.weight << " kg, Calories: " << snack.calories << endl;

    return 0;
}