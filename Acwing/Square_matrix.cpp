#include <iostream>
#include <algorithm>

void printPattern(int size) {
    if (size == 0) {
        return;
    }

    for (int row = 1; row <= size; ++row) {
        for (int col = 1; col <= size; ++col) {
            int value = std::min(std::min(row, size - row + 1), std::min(col, size - col + 1));
            std::cout << value;
            if (col < size) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        printPattern(n);
    }
    return 0;
}
