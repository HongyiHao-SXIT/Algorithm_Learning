#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double feet_to_inches = 12.0;
    const double inches_to_meters = 0.0254;
    const double pounds_to_kg = 0.453592;
    double BMI, feet, inches, pounds, meters, kg;
    cout << "Please enter your height(feet): ";
    cin >> feet;
    cout << "Please enter your height(inches): ";
    cin >> inches;
    cout << "Please enter your weight(pounds): ";
    cin >> pounds;

    meters = (feet * feet_to_inches + inches) * inches_to_meters; 
    kg = pounds * pounds_to_kg;
    BMI = kg / pow(meters, 2);

    cout << "Your BMI is: " << BMI << endl;

    return 0;
}