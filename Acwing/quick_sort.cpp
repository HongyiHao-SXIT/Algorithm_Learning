#include <algorithm>
#include <iostream>

const int MAX_SIZE = 1'000'010;
int numbers[MAX_SIZE];

void quickSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int i = left - 1, j = right + 1;
    int pivot = arr[(left + right) / 2];

    while (i < j) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, j + 1, right);
}

int main() {
    int n;
    std::scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        std::scanf("%d", &numbers[i]);
    }

    quickSort(numbers, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::printf("%d ", numbers[i]);
    }
    std::putchar('\n');

    return 0;
}
