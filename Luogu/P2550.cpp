#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ticketCount;
    std::cin >> ticketCount;

    std::vector<int> winningNumbers(7);
    for (int &num : winningNumbers) {
        std::cin >> num;
    }
    std::sort(winningNumbers.begin(), winningNumbers.end());

    std::vector<int> awardCounts(7, 0);

    while (ticketCount--) {
        std::vector<int> ticketNumbers(7);
        for (int &num : ticketNumbers) {
            std::cin >> num;
        }
        std::sort(ticketNumbers.begin(), ticketNumbers.end());

        std::vector<int> matchedNumbers;
        std::set_intersection(
            winningNumbers.begin(), winningNumbers.end(),
            ticketNumbers.begin(), ticketNumbers.end(),
            std::back_inserter(matchedNumbers)
        );

        int matchCount = static_cast<int>(matchedNumbers.size());

        switch (matchCount) {
            case 7: awardCounts[0]++; break;
            case 6: awardCounts[1]++; break;
            case 5: awardCounts[2]++; break;
            case 4: awardCounts[3]++; break;
            case 3: awardCounts[4]++; break;
            case 2: awardCounts[5]++; break;
            case 1: awardCounts[6]++; break;
        }
    }

    for (int i = 0; i < 7; ++i) {
        std::cout << awardCounts[i];
        if (i < 6) {
            std::cout << " ";
        } else {
            std::cout << "\n";
        }
    }

    return 0;
}
