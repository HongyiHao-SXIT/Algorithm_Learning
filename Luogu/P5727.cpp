#include <iostream>

void hail(int num) {
    int arr[1000];
    int length = 0;

    arr[length] = num;
    length++;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = num * 3 + 1;
        }
        arr[length] = num;
        length++;
    }

    for (int i = 0; i < length; i++) {
        std::cout << arr[i];
        if (i < length - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    int n;
    std::cin >> n;
    hail(n);
    return 0;
}
