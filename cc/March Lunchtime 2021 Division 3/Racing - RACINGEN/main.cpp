#include <iostream>

using namespace std;

void solve() {
    long double X, R, M;

    cin >> X >> R >> M;

    if (R > M) {
        cout << "NO" << endl;
        return;
    }

    long double r, m;

    r = R * 60;
    m = M * 60;

    //cout << a << endl;

    if (2 * r - X <= m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
