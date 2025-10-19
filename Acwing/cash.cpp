#include <iostream>
#include <cstdio>

int main() {
    int amount;
    std::cin >> amount;

    std::cout << amount << std::endl;

    int hundreds = amount / 100;
    amount %= 100;

    int fifties = amount / 50;
    amount %= 50;

    int twenties = amount / 20;
    amount %= 20;

    int tens = amount / 10;
    amount %= 10;

    int fives = amount / 5;
    amount %= 5;

    int twos = amount / 2;
    amount %= 2;

    int ones = amount;

    std::printf("%d nota(s) de R$ 100,00\n", hundreds);
    std::printf("%d nota(s) de R$ 50,00\n", fifties);
    std::printf("%d nota(s) de R$ 20,00\n", twenties);
    std::printf("%d nota(s) de R$ 10,00\n", tens);
    std::printf("%d nota(s) de R$ 5,00\n", fives);
    std::printf("%d nota(s) de R$ 2,00\n", twos);
    std::printf("%d nota(s) de R$ 1,00\n", ones);

    return 0;
}
