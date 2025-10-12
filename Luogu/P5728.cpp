#include <cmath>
#include <cstdio>
#include <iostream>

int n, arr[1010][3], sum[1010];
int cnt;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    sum[i] = arr[i][0] + arr[i][1] + arr[i][2];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(arr[i][0] - arr[j][0]) <= 5 && abs(arr[i][1] - arr[j][1]) <= 5 &&
          abs(arr[i][2] - arr[j][2]) <= 5 && abs(sum[i] - sum[j]) <= 10) {
        cnt++;
      }
    }
  }

  std::cout << cnt << std::endl;
  return 0;
}
