#include <iostream>
using namespace std;

const int MAX_W = 200;
const int MAX_X = 200;
const int MAX_H = 200;


int cube[MAX_W + 1][MAX_X + 1][MAX_H + 1];

int main() {
    int w, x, h;
    cin >> w >> x >> h;


    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                cube[i][j][k] = 1;
            }
        }
    }

    int q;
    cin >> q;


    for (int t = 0; t < q; t++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;


        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                for (int k = z1; k <= z2; k++) {
                    cube[i][j][k] = 0;
                }
            }
        }
    }


    int remaining = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                if (cube[i][j][k] == 1) {
                    remaining++;
                }
            }
        }
    }

    cout << remaining << endl;

    return 0;
}