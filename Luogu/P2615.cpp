#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> magicSquare(n, std::vector<int>(n, 0));

    int currentRow = 0;
    int currentCol = n / 2;
    magicSquare[currentRow][currentCol] = 1;

    for (int num = 2; num <= n * n; ++num) {
        int nextRow, nextCol;

        if (currentRow == 0 && currentCol != n - 1) {
            nextRow = n - 1;
            nextCol = currentCol + 1;
        }
        else if (currentCol == n - 1 && currentRow != 0) {
            nextRow = currentRow - 1;
            nextCol = 0;
        }
        else if (currentRow == 0 && currentCol == n - 1) {
            nextRow = currentRow + 1;
            nextCol = currentCol;
        }
        else {
            nextRow = currentRow - 1;
            nextCol = currentCol + 1;

            if (!(nextRow >= 0 && nextCol < n && magicSquare[nextRow][nextCol] == 0)) {
                nextRow = currentRow + 1;
                nextCol = currentCol;
            }
        }

        currentRow = nextRow;
        currentCol = nextCol;
        magicSquare[currentRow][currentCol] = num;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << magicSquare[i][j];
            if (j < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
