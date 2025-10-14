#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> multiply(const std::vector<int> &a, int b) {
  std::vector<int> result;
  int carry = 0;

  for (size_t i = 0; i < a.size() || carry; ++i) {
    if (i < a.size()) {
      carry += a[i] * b;
    }
    result.push_back(carry % 10);
    carry /= 10;
  }

  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }

  return result;
}

std::vector<int> add(const std::vector<int> &a, const std::vector<int> &b) {
  std::vector<int> result;
  int carry = 0;

  for (size_t i = 0; i < a.size() || i < b.size() || carry; ++i) {
    if (i < a.size())
      carry += a[i];
    if (i < b.size())
      carry += b[i];
    result.push_back(carry % 10);
    carry /= 10;
  }

  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> sum(1, 0);
  std::vector<int> factorial(1, 1);

  for (int i = 1; i <= n; ++i) {
    factorial = multiply(factorial, i);
    sum = add(sum, factorial);
  }

  for (auto it = sum.rbegin(); it != sum.rend(); ++it) {
    std::cout << *it;
  }
  std::cout << '\n';

  return 0;
}
