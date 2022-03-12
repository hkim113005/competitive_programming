#include <iostream>
#include <math.h>
#include <vector>

#define INF (int)1e9 + 7
#define int int64_t

using namespace std;

int t, n;
int a[200005], b[200005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int mn1 = INF, mn2 = INF;
    vector<pair<int, int>> p1, p2;
    for (int i = 1; i <= n; i++) {
        if (mn1 == abs(a[1] - b[i])) {
            p1.push_back({1, i});
        }
        if (mn1 > abs(a[1] - b[i])) {
            mn1 = abs(a[1] - b[i]);
            p1.clear();
            p1.push_back({1, i});
        }
        if (mn2 == abs(a[n] - b[i])){
            p2.push_back({n, i});
        }
        if (mn2 > abs(a[n] - b[i])) {
            mn2 = abs(a[n] - b[i]);
            p2.clear();
            p2.push_back({n, i});
        }
    }
    int mn3 = INF, mn4 = INF;
    vector<pair<int, int>> p3, p4;
    for (int i = 1; i <= n; i++) {
        if (mn3 == abs(b[1] - a[i])) {
            p3.push_back({i, 1});
        }
        if (mn3 > abs(b[1] - a[i])) {
            mn3 = abs(b[1] - a[i]);
            p3.clear();
            p3.push_back({i, 1});
        }
        if (mn4 == abs(b[n] - a[i])) {
            p4.push_back({i, n});
        }
        if (mn4 > abs(b[n] - a[i])) {
            mn4 = abs(b[n] - a[i]);
            p4.clear();
            p4.push_back({i, n});
        }
    }

    for (auto x : p1) {
        for (auto y : p3) {
            if (x == y) {
                mn3 = 0;
            }
        }
    }
    for (auto x : p1) {
        for (auto y : p4) {
            if (x == y) {
                mn4 = 0;
            }
        }
    }
    for (auto x : p2) {
        for (auto y : p3) {
            if (x == y) {
                mn3 = 0;
            }
        }
    }
    for (auto x : p2) {
        for (auto y : p4) {
            if (x == y) {
                mn4 = 0;
            }
        }
    }

    int mn = min(mn1 + mn2 + mn3 + mn4, abs(a[1] - b[1]) + abs(a[n] - b[n]));
    mn = min(mn, abs(a[1] - b[n]) + abs(a[n] - b[1]));

    cout << mn << endl;
}

int32_t main() {
    cin >> t;
    while (t--) solve();
    return 0;
}

/*
7
6 10 0 0 0 1 3
2 5 0 0 0 0 2
 */
