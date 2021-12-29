#include <iostream>

using namespace std;

int n, m, ans = 0;
char field[1002][1002];

int laser(int x, int y, char d, int cnt) {
    if (field[x][y] == '#' || cnt > n * m) {
        return cnt;
    }

    if (d == 'S') {
        if (field[x][y] == '/') {
            return laser(x, y - 1, 'W', cnt + 1);
        }
        if (field[x][y] == '|') {
            return laser(x, y + 1, 'E', cnt + 1);
        }
    }

    if (d == 'N') {
        if (field[x][y] == '/') {
            return laser(x, y + 1, 'E', cnt + 1);
        }
        if (field[x][y] == '|') {
            return laser(x, y - 1, 'W', cnt + 1);
        }
    }

    if (d == 'W') {
        if (field[x][y] == '/') {
            return laser(x + 1, y, 'S', cnt + 1);
        }
        if (field[x][y] == '|') {
            return laser(x - 1, y, 'N', cnt + 1);
        }
    }

    if (d == 'E') {
        if (field[x][y] == '/') {
            return laser(x - 1, y, 'N', cnt + 1);
        }
        if (field[x][y] == '|') {
            return laser(x + 1, y, 'S', cnt + 1);
        }
    }
}

int main() {
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            field[i][j] = '#';
        }
    }

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char tmp;

            cin >> tmp;

            if (tmp == '/') {
                field[i][j] = '/';
            }
            else {
                field[i][j] = '|';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int tmp;

        tmp = laser(i, 1, 'E', 0);
        if (ans < tmp) {
            ans = tmp;
        }

        tmp = laser(i, m, 'W', 0);
        if (ans < tmp) {
            ans = tmp;
        }
    }

    for (int j = 1; j <= m; j++) {
        int tmp;

        tmp = laser(1, j, 'S', 0);
        if (ans < tmp) {
            ans = tmp;
        }

        tmp = laser(n, j, 'N', 0);
        if (ans < tmp) {
            ans = tmp;
        }
    }

    if (ans > n * m) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
