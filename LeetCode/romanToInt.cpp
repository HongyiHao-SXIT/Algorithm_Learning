#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    map<char, int> romanMap = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}};

    int total = 0;
    for (int i = 0; i < s.size(); i++) {
      int currentVal = romanMap[s[i]];
      int nextVal = (i + 1 < s.size()) ? romanMap[s[i + 1]] : 0;

      if (currentVal < nextVal) {
        total += nextVal - currentVal;
        i++;
      } else {
        total += currentVal;
      }
    }
    return total;
  }
};
