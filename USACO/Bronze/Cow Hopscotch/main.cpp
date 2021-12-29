#include <iostream>

int n, m, board[20][20], cnt = 0;

void hopscotch(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        cnt++;
    }
    for (int i = x + 1; i < n; i++) {
        for (int j = y + 1; j < m; j++) {
            if (board[x][y] != board[i][j]) {
                hopscotch(i, j);
            }
        }
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);

    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &tmp);
            if (tmp == 10) {
                scanf("%c", &tmp);
            }
            if (tmp == 'R') {
                board[i][j] = 1;
            }
            else {
                board[i][j] = 0;
            }
        }
    }

    hopscotch(0, 0);

    printf("%d", cnt);
}
