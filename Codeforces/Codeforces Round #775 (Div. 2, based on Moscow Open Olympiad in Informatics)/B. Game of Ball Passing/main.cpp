#include <iostream>
#include <set>

#define int int64_t

using namespace std;

int t, n;
int a[100005];
multiset<int> s;

void solve() {
    s.clear();
    cin >> n;
    int m = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
        sum += a[i];
    }

    if (m * 2 <= sum) {
        cout << (bool)sum << endl;
        return;
    }
    cout << 2 * m - sum << endl;
    return;
}

int32_t main() {
    cin >> t;
    while (t) {
        solve();
        t--;
    }
    return 0;
}
