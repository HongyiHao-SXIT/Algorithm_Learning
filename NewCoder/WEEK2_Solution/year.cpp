#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
        std::cout << "yes";
    else
        std::cout << "no";

    return 0;
}
