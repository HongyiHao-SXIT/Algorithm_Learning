#include <iostream>

int main() {
    int totalSeconds;
    std::cin >> totalSeconds;
    int hours = totalSeconds / 3600;
    int minutes = totalSeconds % 3600 / 60;
    int seconds = totalSeconds - hours * 3600 - minutes * 60;
    std::printf("%d:%d:%d", hours, minutes, seconds);
}
