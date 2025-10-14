#include <cmath>
#include <iomanip>
#include <iostream>

constexpr double calculateDistance(double x1, double y1, double x2,
                                   double y2) noexcept {
  const double dx = x1 - x2;
  const double dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  struct Point {
    double x, y;
  };
  Point p1, p2, p3;

  std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  const double perimeter = calculateDistance(p1.x, p1.y, p2.x, p2.y) +
                           calculateDistance(p2.x, p2.y, p3.x, p3.y) +
                           calculateDistance(p3.x, p3.y, p1.x, p1.y);

  std::cout << std::fixed << std::setprecision(2) << perimeter << '\n';

  return 0;
}
