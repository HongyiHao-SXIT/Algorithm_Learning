#include <iostream>

int main() {
    int k;
    std::cin >> k;

    if (k == 1 || k == 2) {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long a = 1, b = 1, c;
    for (int i = 3; i <= k; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    std::cout << b << std::endl;
    return 0;
}
