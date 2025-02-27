#include <iostream>

using namespace std;

void light_year(){
    double light_year;
    cout << "Enter the number of a Celsius value: ";
    cin >> light_year;
    cout << light_year << " light years = " << light_year * 63240 << "astronomical units" << endl;
}
int main(){
    light_year();
}