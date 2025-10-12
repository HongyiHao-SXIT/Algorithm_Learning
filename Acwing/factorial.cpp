#include <iostream>

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  int num;
  std::cin >> num;
  std::cout << factorial(num) << std::endl;
  return 0;
}
