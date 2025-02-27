#include <iostream>
using namespace std;

int main() {
    int world_population, USA_population;
    cout << "Enter the world's population: ";
    cin >> world_population;
    cout << "Enter the population of USA: ";
    cin >> USA_population;

    double percentage = static_cast<double>(USA_population) / world_population * 100;

    cout << "The population of the US is " << percentage << "% of the world population." << endl;

    return 0;
}