#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string sentence, target, replacement;
    std::getline(std::cin, sentence);
    std::cin >> target >> replacement;

    std::stringstream ss(sentence);
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) {
        if (word == target) word = replacement;
        words.push_back(word);
    }

    for (size_t i = 0; i < words.size(); ++i) {
        if (i) std::cout << " ";
        std::cout << words[i];
    }
    std::cout << std::endl;
}
