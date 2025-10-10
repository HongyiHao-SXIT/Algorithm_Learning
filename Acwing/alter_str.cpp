#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string inputLine;
  string targetWord;
  string replacementWord;

  getline(cin, inputLine);
  cin >> targetWord >> replacementWord;

  vector<string> wordList;
  string currentWord;
  stringstream stringStream(inputLine);

  while (stringStream >> currentWord) {
    wordList.push_back(currentWord);
  }

  for (auto& word : wordList) {
    if (word == targetWord) {
      word = replacementWord;
    }
  }

  for (size_t i = 0; i < wordList.size(); ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << wordList[i];
  }
  cout << endl;

  return 0;
}
