#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    if (str.size() == 2 && str[0] == str[1])
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}
