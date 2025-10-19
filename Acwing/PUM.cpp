#include <iostream>

int main() {
    int rows, columns;
    std::cin >> rows >> columns;

    for (int i = 1; i <= rows * columns; ++i) {
        if (i % columns == 0) {
            std::cout << "PUM\n";
        } else {
            std::cout << i << " ";
        }
    }

    return 0;
}
