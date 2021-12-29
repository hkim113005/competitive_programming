#include <iostream>

using namespace std;

int n, ans;
int board[15][15];
bool check[30];

void bishop(int lvl, int cnt) {
    if (lvl >= 2 * n) {
        ans = max(ans, cnt);
        return;
    }

    int x = lvl, y = 0, flag = 0;

    if (lvl >= n) {
        x = n - 1;
        y = lvl - n + 1;
    }

    for (x, y; x >= 0 && y < n; x--, y++) {
        if (!check[n + x - y] && board[x][y] == 1) {
            check[n + x - y] = true;
            bishop(lvl + 1, cnt + 1);
            check[n + x - y] = false;

            flag = 1;
        }
    }

    if (flag == 0) {
        bishop(lvl + 1, cnt);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    bishop(0, 0);

    cout << ans;

    return 0;
}
