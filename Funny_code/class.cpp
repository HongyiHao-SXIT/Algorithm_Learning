#include <iostream>
using namespace std;

class Test {
private:
    int data1;
    float data2;

public:
    void insertIntegerData(int d) {
        data1 = d;
        cout << "数字: " << data1;
    }

    float insertFloatData() {
        cout << "\n输入数据: ";
        cin >> data2;
        return data2;
    }
};

int main() {
    Test o1, o2;
    float secondDataOfObject2;

    o1.insertIntegerData(12);
    secondDataOfObject2 = o2.insertFloatData();

    cout << "您输入了 " << secondDataOfObject2;
    return 0;
}