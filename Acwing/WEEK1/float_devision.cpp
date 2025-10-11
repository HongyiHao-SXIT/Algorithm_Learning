#include <iomanip>
#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  double result = static_cast<double>(a) / b;

  std::cout << std::fixed << std::setprecision(3) << result << std::endl;

  return 0;
}
