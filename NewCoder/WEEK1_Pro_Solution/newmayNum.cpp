#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n > 50 && n % 2 == 0)
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;

    return 0;
}
