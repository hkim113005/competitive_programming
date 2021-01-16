#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt, ans = 0, tot = 0;
vector<pair<int, int>> a;
vector<int> check;

void process1(int x) {
    tot++;

    if (tot > n * n) {
        ans = -1;
        return;
    }

    if (count(check.begin(), check.end(), x) == 0) {
        check.push_back(x);
        cnt++;
    }

    for (int i = 0; i < m; i++) {
        if (tot > n * n) {
            ans = -1;
            return;
        }

        if (a[i].first == x) {
            process1(a[i].second);
        }
    }
}

void process2(int x) {
    if (tot > n * n) {
        ans = -1;
        return;
    }

    if (count(check.begin(), check.end(), x) == 0) {
        check.push_back(x);
        cnt++;
    }

    for (int i = 0; i < m; i++) {
        if (tot > n * n) {
            ans = -1;
            return;
        }

        if (a[i].second == x) {
            process2(a[i].first);
        }
    }
}

int main() {
    cin >> n >> m;

    a.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < n; i++) {
        check.resize(0);
        cnt = 0;
        process1(i + 1);
        process2(i + 1);

        if (ans == -1) {
            cout << 0;
            return 0;
        }

        if (cnt == n) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
