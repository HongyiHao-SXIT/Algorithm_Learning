#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    Distance *ptr, d;

    ptr = &d;
    
    cout << "输入英尺: ";
    cin >> (*ptr).feet;
    cout << "输入英寸: ";
    cin >> (*ptr).inch;
 
    cout << "显示信息" << endl;
    cout << "距离 = " << (*ptr).feet << " 英尺 " << (*ptr).inch << " 英寸";

    return 0;
}