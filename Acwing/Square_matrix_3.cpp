#include <iostream>
#include <cmath>

int main() {
    int N;
    while (std::cin >> N) {
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int value = 1 << (i + j);
                if (j > 0) std::cout << " ";
                std::cout << value;
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}
