#include <iostream>

class Clock {
 public:
  void setTime(int newH, int newM, int newS) {
    hour = newH;
    minute = newM;
    second = newS;
  }

  void showTime() {
    std::cout << "Current time is: " << hour << ":" << minute << ":" << second
              << std::endl;
  }

 private:
  int hour, minute, second;
};

int main() {
  Clock myClock;

  myClock.setTime(10, 30, 45);
  myClock.showTime();

  return 0;
}
