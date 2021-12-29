#include <iostream>

using namespace std;

void solve() {
    int A, Y, X;

    cin >> A >> Y >> X;

    if (A < Y) {
        cout << A * X + 1 << endl;
    }

    cout << Y * X << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
