#include <iomanip>
#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  double avg = (a + b + c) / 3.0;
  std::cout << std::fixed << std::setprecision(6) << avg << std::endl;

  return 0;
}
