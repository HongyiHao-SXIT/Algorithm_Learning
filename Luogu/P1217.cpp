#include <iostream>
#include <vector>
#include <cmath>

// 判断一个数是否为质数
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// 判断一个数是否为回文数
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// 找出指定范围内的回文质数
std::vector<int> findPalindromicPrimes(int a, int b) {
    std::vector<int> result;
    for (int num = a; num <= b; ++num) {
        if (isPalindrome(num) && isPrime(num)) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::vector<int> palindromicPrimes = findPalindromicPrimes(a, b);
    for (int prime : palindromicPrimes) {
        std::cout << prime << std::endl;
    }
    return 0;
}