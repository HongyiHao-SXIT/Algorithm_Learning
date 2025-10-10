#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int n = s.size();
    int left = 0, maxLength = 0;

    for (int right = 0; right < n; ++right) {
      while (charSet.count(s[right])) {
        charSet.erase(s[left]);
        ++left;
      }
      charSet.insert(s[right]);
      maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
  }
};
