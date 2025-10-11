#include <iostream>

int main() {
  int H1, M1, H2, M2;
  std::cin >> H1 >> M1;
  std::cin >> H2 >> M2;

  int total_H = H2 - H1;
  int total_M;

  if (M2 < M1) {
    total_M = M2 + 60 - M1;
    total_H -= 1;
  } else {
    total_M = M2 - M1;
  }

  int time = total_H * 60 + total_M;
  std::cout << time << std::endl;

  return 0;
}
