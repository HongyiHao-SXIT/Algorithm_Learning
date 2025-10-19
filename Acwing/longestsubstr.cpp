#include <iostream>
#include <string>

int main() {
    int testCount;
    std::cin >> testCount;

    while (testCount--) {
        std::string input;
        std::cin >> input;

        int startIndex = 0;
        int maxCount = 1;

        for (int i = 0; i < static_cast<int>(input.size()) - 1; ++i) {
            int count = 1;
            if (input[i] == input[i + 1]) {
                while (i + count < static_cast<int>(input.size()) && input[i + count] == input[i]) {
                    ++count;
                }
                if (count > maxCount) {
                    maxCount = count;
                    startIndex = i;
                }
            }
        }

        std::cout << input[startIndex] << " " << maxCount << '\n';
    }

    return 0;
}
