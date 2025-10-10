#include <iostream>

const float PI = 3.141593;
const float FENCE_PRICE = 35;
const float CONCRETE_PRICE = 20;

class Circle {
 private:
  float radius;

 public:
  Circle(float r);
  float circumference();
  float area();
};

Circle::Circle(float r) { radius = r; }

float Circle ::circumference() { return 2 * PI * radius; }

float Circle::area() { return PI * radius * radius; }

int main() {
  float radius;
  std::cout << "Enter the radius of the pool: ";
  std::cin >> radius;

  Circle pool(radius);
  Circle poolRim(radius + 3);

  float fenceCost = poolRim.circumference() * FENCE_PRICE;
  std::cout << "Fenceing cost is $ " << fenceCost << std::endl;

  float concreateCost = (poolRim.area() - pool.area()) * CONCRETE_PRICE;
  std::cout << "Concrete Cost is $" << concreateCost << std::endl;

  return 0;
}
