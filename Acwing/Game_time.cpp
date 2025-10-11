#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b;
  if (b > a) {
    c = b - a;
  } else {
    c = (b + 24) - a;
  }
  printf("O JOGO DUROU %d HORA(S)", c);
  return 0;
}