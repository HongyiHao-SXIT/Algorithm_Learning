#include <iostream>

struct Distance {
  int feet;
  float inch;
};

int main() {
  Distance *ptr, d;
  ptr = &d;

  std::cout << "Enter feet: ";
  std::cin >> ptr->feet;
  std::cout << "Enter inches: ";
  std::cin >> ptr->inch;

  std::cout << "\nDisplaying Information" << std::endl;
  std::cout << "Distance = " << ptr->feet << " feet " << ptr->inch << " inches";

  return 0;
}
