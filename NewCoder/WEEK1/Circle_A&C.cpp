#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  const double PI = 3.14159;
  double a;
  std::cin >> a;

  double circumference = 2 * PI * a;
  double area = PI * pow(a, 2);

  std::cout << std::fixed << std::setprecision(6);
  std::cout << circumference << std::endl;
  std::cout << area << std::endl;

  return 0;
}
