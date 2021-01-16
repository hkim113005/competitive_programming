#include <iostream>

using namespace std;

int board[105][105];
int n, m, sx, sy, tx, ty;

void process(int x, int y, int cnt) {
    if (x == tx && y == ty) {
        if (board[x][y] > cnt || board[x][y] == -1) {
            board[x][y] = cnt;
        }
        return;
    }
    if (x + 2 < n && y + 1 < m) {
        if (board[x + 2][y + 1] > cnt || board[x + 2][y + 1] == -1) {
            board[x + 2][y + 1] = cnt;
            process(x + 2, y + 1, cnt + 1);
        }
    }
    if (x + 2 < n && y - 1 >= 0) {
        if (board[x + 2][y - 1] > cnt || board[x + 2][y - 1] == -1) {
            board[x + 2][y - 1] = cnt;
            process(x + 2, y - 1, cnt + 1);
        }
    }
    if (x - 2 >= 0 && y + 1 < m) {
        if (board[x - 2][y + 1] > cnt || board[x - 2][y + 1] == -1) {
            board[x - 2][y + 1] = cnt;
            process(x - 2, y + 1, cnt + 1);
        }
    }
    if (x - 2 >= 0 && y - 1 >= 0) {
        if (board[x - 2][y - 1] > cnt || board[x - 2][y - 1] == -1) {
            board[x - 2][y - 1] = cnt;
            process(x - 2, y - 1, cnt + 1);
        }
    }
    if (y + 2 < m && x + 1 < n) {
        if (board[x + 1][y + 2] > cnt || board[x + 1][y + 2] == -1) {
            board[x + 1][y + 2] = cnt;
            process(x + 1, y + 2, cnt + 1);
        }
    }
    if (y + 2 < m && x - 1 >= 0) {
        if (board[x - 1][y + 2] > cnt || board[x - 1][y + 2] == -1) {
            board[x - 1][y + 2] = cnt;
            process(x - 1, y + 2, cnt + 1);
        }
    }
    if (y - 2 >= 0 && x + 1 < n) {
        if (board[x + 1][y - 2] > cnt || board[x + 1][y - 2] == -1) {
            board[x + 1][y - 2] = cnt;
            process(x + 1, y - 2, cnt + 1);
        }
    }
    if (y - 2 >= 0 && x - 1 >= 0) {
        if (board[x - 1][y - 2] > cnt || board[x - 1][y - 2] == -1) {
            board[x - 1][y - 2] = cnt;
            process(x - 1, y - 2, cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m >> sx >> sy >> tx >> ty;

    sx--;
    sy--;
    tx--;
    ty--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = -1;
        }
    }

    board[sx][sy] = 0;

    process(sx, sy, 1);

    cout << board[tx][ty];

    return 0;
}
