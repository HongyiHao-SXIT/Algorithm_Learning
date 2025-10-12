#include <iostream>
#include <algorithm>

const int MAX_SIZE = 2000000;

int main() {
    int numbers[MAX_SIZE];
    int totalNumbers, unusedN;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> totalNumbers >> unusedN;
    for (int i = 0; i < unusedN; ++i) {
        std::cin >> numbers[i];
    }

    std::sort(numbers, numbers + unusedN);

    for (int i = 0; i < unusedN; ++i) {
        std::cout << numbers[i];
        if (i != unusedN - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
