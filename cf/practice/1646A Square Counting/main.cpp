#include <iostream>

#define int int64_t

using namespace std;

int t, n, s;

void solve() {
    cin >> n >> s;
    cout << s / (n * n) << endl;
}

int32_t main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
