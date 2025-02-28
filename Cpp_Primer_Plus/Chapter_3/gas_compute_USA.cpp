#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double distance_km, fuel_used_l;
    const double KM_TO_MILES = 1.0 / 1.60934;
    const double L_TO_GALLONS = 1.0 / 3.78541;

    cout << "Please enter the driving distance (km): ";
    cin >> distance_km;

    cout << "Please enter the amount of gasoline used (L): ";
    cin >> fuel_used_l;

    double distance_miles = distance_km * KM_TO_MILES;
    double fuel_used_gallons = fuel_used_l * L_TO_GALLONS;

    double fuel_consumption_mpg = distance_miles / fuel_used_gallons;

    cout << fixed << setprecision(2);
    cout << "The fuel consumption is: " << fuel_consumption_mpg << " mpg" << endl;

    return 0;
}