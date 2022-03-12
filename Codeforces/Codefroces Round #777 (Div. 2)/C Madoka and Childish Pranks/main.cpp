#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, n, m;
int a[105][105];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            a[i][j] = tmp[j] - '0';
        }
    }
    bool exp[105][105];
    queue<pair<pair<int, int>, pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && a[i - 1][j] == 0 && a[i][j] == 1) {
                q.push({{i - 1, j}, {i, j}});
                exp[i][j] = true;
            }
            else if (j > 0 && a[i][j - 1] == 0 && a[i][j] == 1) {
                q.push({{i, j - 1}, {i, j}});
                exp[i][j] = true;
            }
            else exp[i][j] = false;
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> path;
    while (!q.empty()) {
        pair<int, int> e = q.front().first;
        pair<int, int> f = q.front().second;
        q.pop();

        a[f.first][f.second] = 0;
        exp[f.first][f.second] = true;
        path.push_back({e, f});

        if (f.first < n - 1 && a[f.first + 1][f.second] == 1 && !exp[f.first + 1][f.second]) {
            q.push({f, {f.first + 1, f.second}});
            exp[f.first + 1][f.second] = true;
        }
        if (f.second < m - 1 && a[f.first][f.second + 1] == 1 && !exp[f.first][f.second + 1]) {
            q.push({f, {f.first, f.second + 1}});
            exp[f.first][f.second + 1] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << path.size() << endl;
    for (int x = path.size() - 1; x >= 0; x--) {
        pair<pair<int, int>, pair<int, int>> i = path[x];
        cout << i.first.first + 1 << " " << i.first.second + 1 << " " << i.second.first + 1 << " " << i.second.second + 1 << endl;
    }
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
