#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
struct S {
  double a;
  double b;
};
int main() {
  S a = {1.1, 2.2};
  S b = {2.1, 4.2};
  S c = {3.1, 5.2};

  unordered_set<S*> us;
  us.insert(&a);
  us.insert(&b);
  us.insert(&c);
  for_each(us.begin(), us.end(), [](S* i) { cout << (*i).a << ", "; });
  cout << "\nNext\n";

  cin.get();
}
