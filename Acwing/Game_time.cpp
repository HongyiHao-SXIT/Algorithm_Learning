#include <iostream>

int main() {
    int startHour, endHour, duration;

    std::cin >> startHour >> endHour;

    if (endHour > startHour) {
        duration = endHour - startHour;
    } else {
        duration = (endHour + 24) - startHour;
    }

    std::cout << "O JOGO DUROU " << duration << " HORA(S)" << std::endl;

    return 0;
}
