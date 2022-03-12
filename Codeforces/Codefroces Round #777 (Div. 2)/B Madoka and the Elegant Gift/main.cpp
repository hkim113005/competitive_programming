#include <iostream>
#include <vector>

#define x first
#define y second
#define pi pair<int, int>

using namespace std;

int t, n, m;
int a[105][105];
vector<pair<pi, pi>> rects;

bool black(pi p, pi q) {
    for (int i = p.x; i <= q.x; i++) {
        for (int j = p.y; j <= q.y; j++) {
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

bool nice(pi p, pi q) {
    bool res = true;
    vector<int> e;
    for (int i = 0; i < rects.size(); i++) {
        pi r = rects[i].first;
        pi s = rects[i].second;
        if (r.x <= p.x && p.x <= s.x && r.x <= q.x && q.x <= s.x && r.y <= p.y && p.y <= s.y && r.y <= q.y && q.y <= s.y) {
            res = false;
        }
        if (p.x <= r.x && r.x <= q.x && p.x <= s.x && s.x <= q.x && p.y <= r.y && r.y <= q.y && p.y <= s.y && s.y <= q.y) {
            e.push_back(i);
        }
    }
    for (int i = e.size() - 1; i >= 0; i--) {
        rects.erase(rects.begin() + e[i]);
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            a[i][j] = tmp[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    if (i == k && j == l) continue;
                    if (black({i, j}, {k, l}) && nice({i, j}, {k, l})) {
                        rects.push_back({{i, j}, {k, l}});
                    }
                }
            }
        }
    }

    cout << black({0, 0}, {2, 2});

    for (int i = 0; i < rects.size(); i++) {
        for (int j = i + 1; j < rects.size(); j++) {
        }
    }
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
