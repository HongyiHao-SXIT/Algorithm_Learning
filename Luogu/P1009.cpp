#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 高精度乘法：大整数a乘以整数b
vector<int> multiply(const vector<int>& a, int b) {
    vector<int> result;
    int carry = 0;
    
    for (size_t i = 0; i < a.size() || carry; ++i) {
        if (i < a.size()) {
            carry += a[i] * b;
        }
        result.push_back(carry % 10);
        carry /= 10;
    }
    
    // 去除前导零（保留至少一位）
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    
    return result;
}

// 高精度加法：大整数a + 大整数b
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;
    
    for (size_t i = 0; i < a.size() || i < b.size() || carry; ++i) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        result.push_back(carry % 10);
        carry /= 10;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> sum(1, 0);        // 初始化为0
    vector<int> factorial(1, 1);  // 初始化为1
    
    for (int i = 1; i <= n; ++i) {
        factorial = multiply(factorial, i);  // 计算i!
        sum = add(sum, factorial);           // 累加到总和
    }
    
    // 反向输出结果
    for (auto it = sum.rbegin(); it != sum.rend(); ++it) {
        cout << *it;
    }
    cout << '\n';
    
    return 0;
}