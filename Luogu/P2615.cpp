#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 初始化一个 N x N 的二维向量来存储幻方，初始值都为 0
    vector<vector<int>> magic_square(N, vector<int>(N, 0));

    // 将 1 放在第一行的中间位置
    int row = 0, col = N / 2;
    magic_square[row][col] = 1;

    // 从 2 开始依次填充幻方
    for (int num = 2; num <= N * N; ++num) {
        int new_row, new_col;
        // 情况 1：若 (K - 1) 在第一行但不在最后一列
        if (row == 0 && col != N - 1) {
            new_row = N - 1;
            new_col = col + 1;
        }
        // 情况 2：若 (K - 1) 在最后一列但不在第一行
        else if (col == N - 1 && row != 0) {
            new_row = row - 1;
            new_col = 0;
        }
        // 情况 3：若 (K - 1) 在第一行最后一列
        else if (row == 0 && col == N - 1) {
            new_row = row + 1;
            new_col = col;
        }
        // 情况 4：若 (K - 1) 既不在第一行，也不在最后一列
        else {
            new_row = row - 1;
            new_col = col + 1;
            // 如果 (K - 1) 的右上方还未填数
            if (new_row >= 0 && new_col < N && magic_square[new_row][new_col] == 0) {
                // 保持新位置不变
            }
            // 否则将 K 填在 (K - 1) 的正下方
            else {
                new_row = row + 1;
                new_col = col;
            }
        }

        // 更新当前位置
        row = new_row;
        col = new_col;
        // 填充当前数字
        magic_square[row][col] = num;
    }

    // 输出幻方
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << magic_square[i][j];
            if (j < N - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}