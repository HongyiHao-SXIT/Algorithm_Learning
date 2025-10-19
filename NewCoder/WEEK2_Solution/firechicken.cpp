#include <iostream>

int main() {
    int a[6];
    int sum = 0;

    for (int i = 0; i < 6; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (a[0] < sum / 30.0)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}
