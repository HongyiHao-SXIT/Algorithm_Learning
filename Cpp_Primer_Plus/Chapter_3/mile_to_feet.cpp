#include <iostream>

using namespace std;

int main(){
    const double element = 0.3048;
    float height;
    cout << "Enter your height(m): ";
    cin >> height;
    cout << "Your height is (feet): " << height * element;
    return 0;
}