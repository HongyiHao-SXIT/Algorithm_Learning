#include <iostream>
#include <string>

int main() {
    std::string input, correct;
    std::cin >> input >> correct;

    if (input == correct)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}
