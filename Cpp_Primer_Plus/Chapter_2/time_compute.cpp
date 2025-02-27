#include <iostream>

using namespace std;

void format(int hour, int minute){
    cout << "Time: " << hour << ":" << minute <<endl; 
}

int main(){
    int hour, minute;
    cout << "Enter  the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minute;
    format(hour, minute);
}