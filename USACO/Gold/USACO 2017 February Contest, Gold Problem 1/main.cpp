#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define INF 1000000000

int N, T;
int c[1005][10005];
int mem[1005][1005][3];
int op[2] = {-1, 1};

bool possible(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    /*
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];

            for (int k = 0; k < 3; k++) {
                mem[i][j][k] = INF;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    mem[0][0][0] = 0;

    while (true) {
        if (q.empty()) break;

        tuple<int, int, int> f = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int d = (get<2>(f) + 1) % 3;

            int x = get<0>(f) + op[i];
            int y = get<1>(f);
            int v = (mem[get<0>(f)][get<1>(f)][get<2>(f)] + T) + (d == 0 ? c[x][y] : 0);
            if (possible(x, y) && v < mem[x][y][d]) {
                q.push(make_tuple(x, y, d));
                mem[x][y][d] = v;
            }

            x = get<0>(f);
            y = get<1>(f) + op[i];
            v = (mem[get<0>(f)][get<1>(f)][get<2>(f)] + T) + (d == 0 ? c[x][y] : 0);
            if (possible(x, y) && v < mem[x][y][d]) {
                q.push(make_tuple(x, y, d));
                mem[x][y][d] = v;
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 3; i++) {
        ans = min(ans, mem[N - 1][N - 1][i]);
    }

    cout << ans;
     */
}