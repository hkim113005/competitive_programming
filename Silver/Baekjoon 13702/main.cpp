#include <iostream>

using namespace std;

int N, K;
long long pots[10005];

long long minMl = 0, maxMl = 0;
long long cur;

void solve () {
    cur = (maxMl - minMl) / 2 + minMl;

    if (minMl == maxMl || minMl == cur) {
        return;
    }

    long long t = 0;

    for (int i = 0; i < N; i++) {
        t += pots[i] / cur;
    }

    if (t >= K) {
        minMl = cur;

        solve();
    }

    if (t < K) {
        maxMl = cur;

        solve();
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> pots[i];

        if (pots[i] > maxMl) {
            maxMl = pots[i];
        }
    }

    solve();

    cout << cur;

    return 0;
}

