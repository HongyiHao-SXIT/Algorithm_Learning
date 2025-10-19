#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int N;
    while (std::cin >> N) {
        if (N == 0) break;

        std::vector<std::vector<int>> a(N, std::vector<int>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int layer = std::min(std::min(i, j), std::min(N - 1 - i, N - 1 - j));
                a[i][j] = layer + 1;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j) std::cout << " ";
                std::cout << a[i][j];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
