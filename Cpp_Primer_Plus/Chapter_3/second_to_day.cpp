#include <iostream>

using namespace std;

const int day_hour = 24;
const int hour_min = 60;
const int min_second = 60;

int main(){
    long int seconds;
    int days = 0, hour = 0, minute = 0, second = 0;
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    days = seconds / (day_hour * hour_min * min_second);

    hour = (seconds % (day_hour * hour_min * min_second)) / (hour_min * min_second);

    minute = (seconds % (hour_min * min_second)) / min_second;

    second = seconds % min_second;

    cout << seconds << " seconds = " << days << " days, " << hour << " hours, " << minute << " minutes, " << second << " seconds" << endl;

    return 0;

}