#include <iostream>

using namespace std;

int N, ans = 0;
int value[1005][1005];
bool check[1005][1005];
bool go[1005][1005];

int tl(int x, int y) {
    if (x - 1 < 0) {
        return 2;
    }

    if (y - 1 < 0) {
        return 2;
    }

    int cnt = 0;

    if (check[x - 1][y]) {
        cnt++;
    }

    if (check[x][y - 1]) {
        cnt++;
    }

    if (check[x - 1][y - 1]) {
        cnt++;
    }

    return cnt < 2;
}
int tr(int x, int y) {
    if (x - 1 < 0) {
        return 2;
    }

    if (y + 1 >= N) {
        return 2;
    }

    int cnt = 0;

    if (check[x - 1][y]) {
        cnt++;
    }

    if (check[x][y + 1]) {
        cnt++;
    }

    if (check[x - 1][y + 1]) {
        cnt++;
    }

    return cnt < 2;
}

int bl(int x, int y) {
    if (x + 1 >= N) {
        return 2;
    }

    if (y - 1 < 0) {
        return 2;
    }

    int cnt = 0;

    if (check[x + 1][y]) {
        cnt++;
    }

    if (check[x][y - 1]) {
        cnt++;
    }

    if (check[x + 1][y - 1]) {
        cnt++;
    }

    return cnt < 2;
}

int br(int x, int y) {
    if (x + 1 >= N) {
        return 2;
    }

    if (y + 1 >= N) {
        return 2;
    }

    int cnt = 0;

    if (check[x + 1][y]) {
        cnt++;
    }

    if (check[x][y + 1]) {
        cnt++;
    }

    if (check[x + 1][y + 1]) {
        cnt++;
    }

    return cnt < 2;
}

bool possible(int x, int y) {
    return tl(x, y) && tr(x, y) && bl(x, y) && br(x, y);
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << check[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void dfs(int x, int y) {
    //print();

    go[x][y] = true;

    if (y >= N) {
        x++;
        y = 0;
    }

    if (x >= N) {
        print();
        int v = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check[i][j]) {
                    v += value[i][j];
                }
            }
        }

        ans = max(ans, v);

        go[x][y] = false;

        return;
    }

    if (!possible(x, y)) {
        dfs(x, y + 1);
        go[x][y] = false;
        return;
    }
    else {
        if (!go[x + 1][y]) {
            check[x][y] = true;
            dfs(x + 1, y);
            check[x][y] = false;
        }
        if (!go[x][y + 1]) {
            check[x][y] = true;
            dfs(x, y + 1);
            check[x][y] = false;
        }
        if (!go[x + 1][y + 1]) {
            check[x][y] = true;
            dfs(x + 1, y + 1);
            check[x][y] = false;
        }
        if (y - 1 >= 0) {
            if (!go[x + 1][y - 1]) {
                check[x][y] = true;
                dfs(x + 1, y - 1);
                check[x][y] = false;
            }
        }
    }

    go[x][y] = false;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> value[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}
