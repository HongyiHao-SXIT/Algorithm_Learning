#include <iostream>

int main() {
    int num1, num2;
    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    int lower = std::min(num1, num2);
    int upper = std::max(num1, num2);

    int total = 0;
    for (int i = lower + 1; i < upper; ++i) {
        total += i;
    }

    std::cout << "The sum of numbers between " << num1 << " and " << num2 << " is: " << total << std::endl;
    return 0;
}
