#include <iostream>

using namespace std;

int n, m, tx, ty, mint = -1;

void process(int x, int y, int cnt, bool traveled[105][105]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == x && j == y) {
                cout << 'X';
            }
            else if (i == tx && j == ty) {
                cout << 'O';
            }
            else {
                cout << traveled[i][j];
            }
        }
        cout << endl;
    }

    cout << endl;

    if (x == tx && y == ty) {
        if (cnt < mint || mint == -1) {
            mint = cnt;
        }
        return;
    }

    if (cnt > mint && mint != -1) {
        return;
    }

    if (x + 2 < n && y + 1 < m) {
        if (!traveled[x + 2][y + 1]) {
            traveled[x + 2][y + 1] = true;
            process(x + 2, y + 1, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (x + 2 < n && y - 1 >= 0) {
        if (!traveled[x + 2][y - 1]) {
            traveled[x + 2][y - 1] = true;
            process(x + 2, y - 1, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (x - 2 >= 0 && y + 1 < m) {
        if (!traveled[x - 2][y + 1]) {
            traveled[x - 2][y + 1] = true;
            process(x - 2, y + 1, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (x - 2 >= 0 && y - 1 >= 0) {
        if (!traveled[x - 2][y - 1]) {
            traveled[x - 2][y - 1] = true;
            process(x - 2, y - 1, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (y + 2 < m && x + 1 < n) {
        if (!traveled[x + 1][y + 2]) {
            traveled[x + 1][y + 2] = true;
            process(x + 1, y + 2, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (y + 2 < m && x - 1 >= 0) {
        if (!traveled[x - 1][y + 2]) {
            traveled[x - 1][y + 2] = true;
            process(x - 1, y + 2, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (y - 2 >= 0 && x + 1 < n) {
        if (!traveled[x + 1][y - 2]) {
            traveled[x + 1][y - 2] = true;
            process(x + 1, y - 2, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
    if (y - 2 >= 0 && x - 1 >= 0) {
        if (!traveled[x - 1][y - 2]) {
            traveled[x - 1][y - 2] = true;
            process(x - 1, y - 2, cnt + 1, traveled);
            if (cnt > mint) {
                return;
            }
        }
    }
}

int main() {
    int sx, sy;
    bool traveled[105][105];

    cin >> n >> m >> sx >> sy >> tx >> ty;

    sx--;
    sy--;
    tx--;
    ty--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            traveled[i][j] = false;
        }
    }

    traveled[sx][sy] = true;

    process(sx, sy, 0, traveled);

    cout << mint;

    return 0;
}
