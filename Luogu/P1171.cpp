#include <algorithm>
#include <iostream>

constexpr int MAX_SIZE = 1'000'010;
int numbers[MAX_SIZE];

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int i = left - 1;
    int j = right + 1;
    int pivotValue = arr[left + (right - left) / 2];

    while (i < j) {
        do {
            ++i;
        } while (arr[i] < pivotValue);

        do {
            --j;
        } while (arr[j] > pivotValue);

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, j + 1, right);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    quickSort(numbers, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i];
        if (i < n - 1)
            std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}
