#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> charSet;
    int n = s.size();
    int left = 0, maxLength = 0;

    for (int right = 0; right < n; ++right) {
      while (charSet.count(s[right])) {
        charSet.erase(s[left]);
        ++left;
      }
      charSet.insert(s[right]);
      maxLength = std::max(maxLength, right - left + 1);
    }
    return maxLength;
  }
};
