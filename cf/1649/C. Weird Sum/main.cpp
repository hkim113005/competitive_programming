#include <iostream>
#include <vector>
#include <algorithm>

#define int int64_t

using namespace std;

int n, m;
vector<vector<int>> c;
vector<vector<int>> a;
vector<vector<int>> b;
int k[100005];

int sum(vector<int> f) {
    sort(f.begin(), f.end());
    int pre = 0, sum = 0;
    for (int i = 0; i < f.size(); i++) {
        pre += (f[i] * i - sum);
        sum += f[i];
    }
    return pre;
}

int32_t main() {
    cin >> n >> m;
    c.resize(n);
    a.emplace_back(vector<int>());
    b.emplace_back(vector<int>());
    for (int i = 0; i < n; i++) {
        c[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            int idx = k[c[i][j]];
            if (k[c[i][j]] == 0) {
                k[c[i][j]] = idx = a.size();
                a.emplace_back(vector<int>());
                b.emplace_back(vector<int>());
            }
            a[idx].emplace_back(i);
            b[idx].emplace_back(j);
        }
    }

    int ans = 0;
    for (int i = 1; i < a.size(); i++) {
        ans += sum(a[i]);
        ans += sum(b[i]);
    }
    cout << ans << endl;

    return 0;
}
