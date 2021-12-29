#include <iostream>

using namespace std;

void solve() {
    int N, K;

    cin >> N >> K;

    cout << N - K + K / 2 << endl;

    for (int i = K + 1; i <= N; i++) {
        cout << i << " ";
    }

    for (int i = 1; i <= K / 2; i++) {
        cout << K - i << " ";
    }

    cout << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
