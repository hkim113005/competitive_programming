#include <iostream>

using namespace std;

void solve() {
    int N, K;
    char S[100005];
    int count[26];

    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> S[i];

        count[S[i] - 'a']++;
    }

    if (N % K != 0) {
        cout << -1;

        return;
    }

    for (int i = N - 1; i >= 0; i++) {
        for (int )
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
