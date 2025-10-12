#include <iostream>
#include <cstring>

int main() {
    const int MAX_LENGTH = 200;
    char inputStr[MAX_LENGTH];
    int shift, length;
    int shifted[MAX_LENGTH];

    std::cin >> shift >> inputStr;
    length = static_cast<int>(std::strlen(inputStr));

    for (int i = 0; i < length; i++) {
        shifted[i] = static_cast<int>(inputStr[i]) + shift;

        if (shifted[i] > 'z') {
            shifted[i] = (shifted[i] - 'a') % 26 + 'a';
        }
    }

    for (int i = 0; i < length; i++) {
        inputStr[i] = static_cast<char>(shifted[i]);
        std::cout << inputStr[i];
    }
    std::cout << std::endl;

    return 0;
}
