#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, m;
    cin >> l >> m;

    vector<bool> removed(l + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; ++j) {
            removed[j] = true;
        }
    }

    int remaining = 0;
    for (int i = 0; i <= l; ++i) {
        if (!removed[i]) {
            ++remaining;
        }
    }

    cout << remaining << endl;

    return 0;
}