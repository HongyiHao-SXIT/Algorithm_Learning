#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int count[26] = {0};

    for (char c : str) {
        count[c - 'a']++;
    }
 
    for (char c : str) {
        if (count[c - 'a'] == 1) {
            std::cout << c << "\n";
            return 0;
        }
    }

    std::cout << "no\n";
    return 0;
}
