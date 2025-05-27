#include <iostream>

int main() {
    double num = 0.0;
    double total = 0.0;
    
    while (true) {
        std::cout << "Please enter a number (0 to finish): ";
        std::cin >> num;
        
        if (num == 0) {
            break;
        }
        
        total += num;
    }
    
    std::cout << "\nThe sum of all entered numbers is: " << total << std::endl;
    
    return 0;
}