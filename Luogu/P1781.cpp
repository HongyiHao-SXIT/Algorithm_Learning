#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string max_votes = "";
    int winner = 0;

    for (int i = 1; i <= n; ++i) {
        string votes;
        cin >> votes;
        if (votes.length() > max_votes.length() || (votes.length() == max_votes.length() && votes > max_votes)) {
            max_votes = votes;
            winner = i;
        }
    }

    cout << winner << endl;
    cout << max_votes << endl;

    return 0;
}