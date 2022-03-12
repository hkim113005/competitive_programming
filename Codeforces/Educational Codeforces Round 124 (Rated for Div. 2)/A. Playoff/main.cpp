#include <iostream>

using namespace std;

int t;
int n;

void solve() {
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
    }
    ans--;
    cout << ans << endl;
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
