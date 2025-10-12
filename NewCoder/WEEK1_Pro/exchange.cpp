#include <iostream>

int main() {
    int X, Y;
    std::cin >> X >> Y;

    if (X < Y) {
        int temp = X;
        X = Y;
        Y = temp;
    }

    std::cout << X << std::endl;
    std::cout << Y << std::endl;

    return 0;
}
