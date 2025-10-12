#include <iostream>

int main() {
    int startHour, startMinute, endHour, endMinute;
    int durationHour, durationMinute;

    std::cin >> startHour >> startMinute >> endHour >> endMinute;

    if (startHour > endHour) {
        if (startMinute > endMinute) {
            durationHour = (endHour + 24) - startHour - 1;
            durationMinute = (endMinute + 60) - startMinute;
        } else if (startMinute < endMinute) {
            durationHour = (endHour + 24) - startHour;
            durationMinute = endMinute - startMinute;
        } else {
            durationHour = (endHour + 24) - startHour;
            durationMinute = 0;
        }
    } else if (startHour < endHour) {
        if (startMinute > endMinute) {
            durationHour = endHour - startHour - 1;
            durationMinute = (endMinute + 60) - startMinute;
        } else if (startMinute < endMinute) {
            durationHour = endHour - startHour;
            durationMinute = endMinute - startMinute;
        } else {
            durationHour = endHour - startHour;
            durationMinute = 0;
        }
    } else {
        if (startMinute > endMinute) {
            durationHour = (endHour + 24) - startHour - 1;
            durationMinute = (endMinute + 60) - startMinute;
        } else if (startMinute < endMinute) {
            durationHour = 0;
            durationMinute = endMinute - startMinute;
        } else {
            durationHour = 24;
            durationMinute = 0;
        }
    }

    std::cout << "O JOGO DUROU " << durationHour 
         << " HORA(S) E " << durationMinute 
         << " MINUTO(S)" << std::endl;

    return 0;
}
