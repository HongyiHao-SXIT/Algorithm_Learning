#include <iostream>
#include <vector>

bool is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int begin, end;
  std::cin >> begin >> end;

  std::vector<int> leap_years;
  leap_years.reserve((end - begin) / 4 + 1);

  for (int year = begin; year <= end; ++year) {
    if (is_leap_year(year)) {
      leap_years.push_back(year);
    }
  }

  std::cout << leap_years.size() << '\n';
  for (size_t i = 0; i < leap_years.size(); ++i) {
    std::cout << leap_years[i] << " \n"[i == leap_years.size() - 1];
  }

  return 0;
}
