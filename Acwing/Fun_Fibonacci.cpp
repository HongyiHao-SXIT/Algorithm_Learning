#include <iostream>


int Fibonacci(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
  int num;
  std::cout << "Please enter the number you want to know: " << std::endl;
  std::cin >> num;

  std::cout << "The number is " << Fibonacci(num) << std::endl;
  return 0;
}
