#include <iostream>
#include <vector>

void backtrack(std::vector<int> &nums, std::vector<bool> &used, std::vector<int> &path,
               std::vector<std::vector<int>> &result) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    std::vector<bool> used(n, false);
    std::vector<int> path;
    std::vector<std::vector<int>> result;

    backtrack(nums, used, path, result);

    for (const auto &perm : result) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
