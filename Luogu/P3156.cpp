#include <bits/stdc++.h>

const int MAX_SIZE = 2000001;
long long a[MAX_SIZE];

int main() {
  long long n, m, x;

  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= m; ++i) {
    std::cin >> x;
    std::cout << a[x] << std::endl;
  }

  return 0;
}
