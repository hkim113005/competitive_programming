#include <iostream>

using namespace std;

void solve() {
    int N, X;

    cin >> N >> X;

    int mR = 0;

    for (int i = 0; i < N; i++) {
        int S, R;

        cin >> S >> R;

        if (S <= X && R > mR) {
            mR = R;
        }
    }

    cout << mR << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
