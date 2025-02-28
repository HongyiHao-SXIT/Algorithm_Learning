#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double distance, fuel_used;

    cout << "Please enter the driving distance (km): ";
    cin >> distance;

    cout << "Please enter the amount of gasoline used (L): ";
    cin >> fuel_used;

    double fuel_consumption_per_100km = (fuel_used / distance) * 100;

    cout << fixed << setprecision(2);
    cout << "The fuel consumption per 100 km is: " << fuel_consumption_per_100km << " L" << endl;

    return 0;
}