#include <iostream>
#include <vector>


struct Cube {
  int w, x, h;
  std::vector<std::vector<std::vector<int>>> data;

  Cube(int w, int x, int h)
      : w(w), x(x), h(h),
        data(w + 1, std::vector<std::vector<int>>(x + 1, std::vector<int>(h + 1, 1))) {}

  void remove_block(int x1, int y1, int z1, int x2, int y2, int z2) {
    for (int i = x1; i <= x2; ++i)
      for (int j = y1; j <= y2; ++j)
        for (int k = z1; k <= z2; ++k)
          data[i][j][k] = 0;
  }

  int count_remaining() const {
    int count = 0;
    for (const auto &plane : data)
      for (const auto &row : plane)
        for (int val : row)
          count += val;
    return count;
  }
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int w, x, h;
  std::cin >> w >> x >> h;

  Cube cube(w, x, h);

  int q;
  std::cin >> q;

  while (q--) {
    int x1, y1, z1, x2, y2, z2;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    cube.remove_block(x1, y1, z1, x2, y2, z2);
  }

  std::cout << cube.count_remaining() << '\n';

  return 0;
}
