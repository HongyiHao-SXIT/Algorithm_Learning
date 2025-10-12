#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int totalLength, intervalCount;
    std::cin >> totalLength >> intervalCount;

    std::vector<std::pair<int, int>> intervals(intervalCount);
    for (auto &interval : intervals) {
        std::cin >> interval.first >> interval.second;
    }

    std::sort(intervals.begin(), intervals.end());

    int remainingLength = totalLength + 1;
    int lastCovered = -1;

    for (const auto &interval : intervals) {
        int start = interval.first;
        int end = interval.second;

        if (start > lastCovered) {
            remainingLength -= (end - start + 1);
            lastCovered = end;
        } else if (end > lastCovered) {
            remainingLength -= (end - lastCovered);
            lastCovered = end;
        }
    }

    std::cout << remainingLength << "\n";

    return 0;
}
