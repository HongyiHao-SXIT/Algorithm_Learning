#include <iostream>

int main() {
    int* pointerC;
    int valueC;

    valueC = 5;
    std::cout << "Address of valueC (&valueC): " << &valueC << '\n';
    std::cout << "Value of valueC: " << valueC << "\n\n";

    pointerC = &valueC;
    std::cout << "Pointer pointerC holds address: " << pointerC << '\n';
    std::cout << "Value at address held by pointerC (*pointerC): " << *pointerC << "\n\n";

    valueC = 11;
    std::cout << "Pointer pointerC still holds address: " << pointerC << '\n';
    std::cout << "Updated value via pointer (*pointerC): " << *pointerC << "\n\n";

    *pointerC = 2;
    std::cout << "Address of valueC (&valueC): " << &valueC << '\n';
    std::cout << "Final value of valueC: " << valueC << '\n';

    return 0;
}
