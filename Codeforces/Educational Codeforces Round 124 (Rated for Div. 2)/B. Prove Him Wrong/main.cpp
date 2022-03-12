#include <iostream>
#include <math.h>

#define int int64_t

using namespace std;

int t, n;

void solve() {
    cin >> n;
    if (n > 19) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << (int)pow(3, i) << " ";
    }
    cout << endl;
}

int32_t main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
