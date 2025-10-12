#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Candidate {
    int candidateId;
    std::string votes;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int candidateCount;
    std::cin >> candidateCount;

    std::vector<Candidate> candidates(candidateCount);

    for (int i = 0; i < candidateCount; ++i) {
        candidates[i].candidateId = i + 1;
        std::cin >> candidates[i].votes;
    }

    auto compareVotes = [](const Candidate &a, const Candidate &b) {
        if (a.votes.length() != b.votes.length()) {
            return a.votes.length() > b.votes.length();
        }
        return a.votes > b.votes;
    };

    std::sort(candidates.begin(), candidates.end(), compareVotes);

    std::cout << candidates[0].candidateId << '\n';
    std::cout << candidates[0].votes << std::endl;

    return 0;
}
