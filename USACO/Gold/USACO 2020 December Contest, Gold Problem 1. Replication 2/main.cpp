#include <iostream>
#include <queue>
#include <vector>

#define int int64_t

using namespace std;

typedef pair<int, int> pi;

int N, D;
char G[1005][1005];
pi dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pi> Q;
queue<pi> S;
int rock_dist[1005][1005];
int star_dist[1005][1005];
vector<pi> center[5005];
bool ans[1005][1005];

int32_t main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
            if (G[i][j] == '#') Q.push({i, j}), rock_dist[i][j] = 0;
            else rock_dist[i][j] = -1;
            if (G[i][j] == 'S') S.push({i, j}), star_dist[i][j] = 0;
            else star_dist[i][j] = -1;
        }
    }

    while (!Q.empty()) {
        pi f = Q.front();
        Q.pop();
        for (pi d : dir) {
            int x = f.first + d.first, y = f.second + d.second;
            if (!(x >= 0 && x < N && y >= 0 && y < N)) continue;
            if (rock_dist[x][y] != -1) continue;
            rock_dist[x][y] = rock_dist[f.first][f.second] + 1;
            Q.push({x, y});
        }
    }

    Q = S;
    while (!Q.empty()) {
        pi f = Q.front();
        int x = f.first, y = f.second;
        Q.pop();
        center[rock_dist[x][y] - 1].emplace_back(f);
        ans[x][y] = true;
        if (star_dist[x][y] < D * rock_dist[x][y]) {
            for (pi d: dir) {
                int nx = x + d.first, ny = y + d.second;
                if (star_dist[nx][ny] != -1) continue;
                if (G[nx][ny] == '#') continue;
                if (!(nx >= 0 && nx < N && ny >= 0 && ny < N)) continue;
                if (star_dist[x][y] > D * rock_dist[nx][ny]) continue;
                Q.push({nx, ny});
                star_dist[nx][ny] = star_dist[x][y] + 1;
            }
        }
    }

    queue<pi> R;
    for (int i = N * 2; i >= 0; i--) {
        /*
        cout << i << ": " << endl;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cout << ans[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
         */
        swap(Q, R);
        while (!Q.empty()) {
            pi f = Q.front();
            Q.pop();
            int x = f.first, y = f.second;
            for (pi d: dir) {
                int nx = x + d.first, ny = y + d.second;
                if (!(nx >= 0 && nx < N && ny >= 0 && ny < N)) continue;
                if (ans[nx][ny]) continue;
                R.push({nx, ny});
                ans[nx][ny] = true;
            }
        }
        for (pi c : center[i]) {
            R.push(c);
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += ans[i][j];
        }
    }

    /*
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < center[i].size(); j++) {
            cout << center[i][j].first << " " << center[i][j].second << ", ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
     */

    cout << sum << endl;
}