#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

bool isprime(int x) {
  if (x <= 1)
    return false;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n, a;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    std::cin >> a;
    if (isprime(a)) {
      std::cout << a << " ";
    }
  }

  return 0;
}
