#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> winning_numbers(7);
    for (int i = 0; i < 7; ++i) {
        cin >> winning_numbers[i];
    }
    sort(winning_numbers.begin(), winning_numbers.end());

    vector<int> awards(7, 0);

    for (int i = 0; i < n; ++i) {
        vector<int> ticket_numbers(7);
        for (int j = 0; j < 7; ++j) {
            cin >> ticket_numbers[j];
        }
        sort(ticket_numbers.begin(), ticket_numbers.end());

        vector<int> intersection;
        set_intersection(winning_numbers.begin(), winning_numbers.end(),
                         ticket_numbers.begin(), ticket_numbers.end(),
                         back_inserter(intersection));

        int match_count = intersection.size();
        if (match_count == 7) {
            awards[0]++;
        } else if (match_count == 6) {
            awards[1]++;
        } else if (match_count == 5) {
            awards[2]++;
        } else if (match_count == 4) {
            awards[3]++;
        } else if (match_count == 3) {
            awards[4]++;
        } else if (match_count == 2) {
            awards[5]++;
        } else if (match_count == 1) {
            awards[6]++;
        }
    }

    for (int i = 0; i < 7; ++i) {
        cout << awards[i];
        if (i < 6) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}