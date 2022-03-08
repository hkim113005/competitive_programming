#include <iostream>
#include <algorithm>

#define int int64_t
#define INF (int)1e9 + 7

using namespace std;

int t, n;
int a[200005];

void solve() {
    cin >> n;
    int mx = 0, mn[2] = { INF, INF };
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int red = 0, blue = a[0];
    for (int i = n - 1; i >= 0; i--) {
        red += a[i];
        blue += a[n - i];
        //cout << red << " " << blue << endl;
        if (red > blue) {
            cout << "YES" << endl;
            return;
        }

    }

    cout << "NO" << endl;
    return;
}

int32_t main() {
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
