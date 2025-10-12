#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string inputLine;
    std::string targetWord;
    std::string replacementWord;

    std::getline(std::cin, inputLine);
    std::cin >> targetWord >> replacementWord;

    std::vector<std::string> wordList;
    std::string currentWord;
    std::stringstream stringStream(inputLine);

    while (stringStream >> currentWord) {
        wordList.push_back(currentWord);
    }

    for (auto &word : wordList) {
        if (word == targetWord) {
            word = replacementWord;
        }
    }

    for (size_t i = 0; i < wordList.size(); ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << wordList[i];
    }
    std::cout << std::endl;

    return 0;
}
