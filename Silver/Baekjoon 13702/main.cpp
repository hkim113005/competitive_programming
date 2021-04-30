#include <iostream>

using namespace std;

int N, K;
int pots[10005];

int minMl = 0, maxMl = 0;
int cur;

void solve () {
    cur = (maxMl - minMl) / 2 + minMl;

    if (minMl == maxMl || minMl == cur) {
        return;
    }

    int t = 0;

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
