#include <iostream>
#include <vector>
#include <queue>

#define x first
#define y second
#define rock '#'
#define INF 1000000000

using namespace std;

typedef pair<int, int> ip;

int N, D;
char F[1005][1005];
int d[1005][1005];
int s[1005][1005];
vector<ip> c;
bool p[1005][1005];

int main() {
    queue<pair<ip, int>> dq;
    queue<pair<ip, int>> sq;
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> F[i][j];
            if (F[i][j] == 'S') {
                sq.push(make_pair(make_pair(i, j), 0));
                s[i][j] = 0;
            }
            else {
                s[i][j] = INF;
            }
            if (F[i][j] == rock) {
                dq.push(make_pair(make_pair(i, j), -1));
                d[i][j] = 0;
                s[i][j] = -1;
            }
            else {
                d[i][j] = INF;
            }
        }
    }

    while (!dq.empty()) {
        ip f = dq.front().first;
        int dep = dq.front().second;
        dq.pop();

        if (f.x + 1 < N && d[f.x + 1][f.y] == INF) {
            dq.push(make_pair(make_pair(f.x + 1, f.y), dep + 1));
            d[f.x + 1][f.y] = dep + 1;
        }
        if (f.x - 1 >= 0 && d[f.x - 1][f.y] == INF) {
            dq.push(make_pair(make_pair(f.x - 1, f.y), dep + 1));
            d[f.x - 1][f.y] = dep + 1;
        }
        if (f.y + 1 < N && d[f.x][f.y + 1] == INF) {
            dq.push(make_pair(make_pair(f.x, f.y + 1), dep + 1));
            d[f.x][f.y + 1] = dep + 1;
        }
        if (f.y - 1 >= 0 && d[f.x][f.y - 1] == INF) {
            dq.push(make_pair(make_pair(f.x, f.y - 1), dep + 1));
            d[f.x][f.y - 1] = dep + 1;
        }
    }

    while (!sq.empty()) {
        ip f = sq.front().first;
        int dep = sq.front().second;
        sq.pop();

        if (f.x + 1 < N && s[f.x + 1][f.y] == INF && s[f.x + 1][f.y] != -1) {
            sq.push(make_pair(make_pair(f.x + 1, f.y), dep + 1));
            s[f.x + 1][f.y] = dep + 1;
        }
        if (f.x - 1 >= 0 && s[f.x - 1][f.y] == INF && s[f.x - 1][f.y] != -1) {
            sq.push(make_pair(make_pair(f.x - 1, f.y), dep + 1));
            s[f.x - 1][f.y] = dep + 1;
        }
        if (f.y + 1 < N && s[f.x][f.y + 1] == INF && s[f.x][f.y + 1] != -1) {
            sq.push(make_pair(make_pair(f.x, f.y + 1), dep + 1));
            s[f.x][f.y + 1] = dep + 1;
        }
        if (f.y - 1 >= 0 && s[f.x][f.y - 1] == INF && s[f.x][f.y - 1] != -1) {
            sq.push(make_pair(make_pair(f.x, f.y - 1), dep + 1));
            s[f.x][f.y - 1] = dep + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s[i][j] /= D;
            if (s[i][j] <= d[i][j] && s[i][j] != -1) {
                c.emplace_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < c.size(); i++) {
        int x = c[i].x, y = c[i].y;
        if (s[x][y] == d[x][y]) {
            for (int j = x - d[x][y] + 1; j <= x + d[x][y] - 1; j++) {
                for (int k = abs(y - j - (x - d[x][y])) + 1; k <= (x + d[x][y]) - abs(y - j - (x - d[x][y])) - 1; k++) {
                    if (p[j][k]) continue;;
                    p[j][k] = true;
                }
            }
        }
        else {
            d[x][y]--;
            for (int j = x - (d[x][y]); j <= x + (d[x][y]); j++) {
                for (int k = abs(y - (j - (x - d[x][y]))); k <= (x + (d[x][y])) - abs(y - (j - (x - d[x][y]))); k++) {
                    if (p[j][k]) continue;;
                    p[j][k] = true;
                }
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cout << p[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < c.size(); i++) {
        cout << c[i].x << " " << c[i].y << endl;
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool b = true;
            for (int k = 0; k < c.size(); k++) {
                if (c[k].x == i && c[k].y == j) {
                    cout << "* ";
                    b = false;
                }
            }
            if (b) cout << p[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
 *   X
 *  XXX
 * XXXXX
 * if (t != 0 && t % D == 0) {
        if (field[c.x + nd][c.y] == rock) return;
        else if (field[c.x - nd][c.y] == rock) return;
        else if (field[c.x][c.y + nd] == rock) return;
        else if (field[c.x][c.y - nd] == rock) return;
        for (int i = 0; i <= nd; i++) {
            trv[c.x - nd + i][c.y + i] = true;
            trv[c.x - nd + i][c.y - i] = true;
            trv[c.x + i][c.y + nd - i] = true;
            trv[c.x + i][c.y - nd + i] = true;
        }
    }
    if (field[c.x + nd + 1][c.y] != rock) {
        for (int i = 0; i <= nd; i++) {
            trv[c.x + i + 1][c.y + nd - i - 1] = true;
            trv[c.x + i + 1][c.y - nd + i - 1] = true;
        }
        dfs(make_pair(c.x + 1, c.y), nt, nd);
    }
 */