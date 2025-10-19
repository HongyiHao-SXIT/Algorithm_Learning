#include <iostream>
#include <algorithm>

int main() {
    int a, b, x;
    std::cin >> a >> b >> x;

    if (std::min(a, b) + x > std::max(a, b))
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}
