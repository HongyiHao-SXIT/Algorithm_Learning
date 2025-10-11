#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d;
  if (a > c) {
    if (b > d) {
      e = (c + 24) - a - 1;
      f = (d + 60) - b;
    } else if (b < d) {
      e = (c + 24) - a;
      f = d - b;
    } else if (b == d) {
      e = (c + 24) - a;
      f = 0;
    }
  } else if (a < c) {
    if (b > d) {
      e = c - a - 1;
      f = (d + 60) - b;
    } else if (b < d) {
      e = c - a;
      f = d - b;
    } else if (b == d) {
      e = c - a;
      f = 0;
    }
  } else if (a == c) {
    if (b > d) {
      e = (c + 24) - a - 1;
      f = (d + 60) - b;
    } else if (b < d) {
      e = 0;
      f = d - b;
    } else if (b == d) {
      e = 24;
      f = 0;
    }
  }

  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", e, f);
  return 0;
}