#include <iostream>
#include <cmath>

int computeSmallestFactor(int number) {
    if (number % 2 == 0) {
        return number / 2;
    }

    for (int divisor = 3; divisor <= std::sqrt(number); divisor += 2) {
        if (number % divisor == 0) {
            return number / divisor;
        }
    }

    return 1;
  }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << "\n";
        return 0;
    }

    int result = computeSmallestFactor(n);
    std::cout << result << "\n";

    return 0;
}
