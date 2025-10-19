#include <iostream>

int main() {
    int a, b;

    std::cin >> a >> b;

    if (a > b) {
        std::cout << "kou" << std::endl;
    } else if (a < b) {
        std::cout << "yukari" << std::endl;// Please spell the word correctly.
    } else {
        std::cout << "draw" << std::endl;
    }

    return 0;
}