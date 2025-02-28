#include <iostream>

using namespace std;

const double degrees_minute = 60.0;
const double min_second = 60.0;

int main(){
    int degrees, minute, second;
    double degree;

    cout << "Enter a latitude in degrees, minutes, and seconds: " <<endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout <<"Next, enter the seconds of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;

    degree = degrees + minute / degrees_minute + second / (degrees_minute * min_second);

    cout << degrees << " degrees," << minute << " minutes," << second << " seconds = " << degree << " degrees" << endl;

    return 0;
}