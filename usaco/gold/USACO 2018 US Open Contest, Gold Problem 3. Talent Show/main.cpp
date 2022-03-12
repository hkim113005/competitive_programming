#include <iostream>

#define INF 1000000000
#define int int64_t

using namespace std;

int N, W;
int w[300], t[300];

bool possible(int rt) {
    int dp[10000];
    for (int i = 0; i <= W; i++) {
        dp[i] = -INF;
    }
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        int v = 1000 * t[i] - rt * w[i];
        for (int j = W; j >= 0; j--) {
            int k = min(W, j + w[i]);
            if (dp[j] != -INF) {
                dp[k] = max(dp[k], dp[j] + v);
            }
        }
    }

    return dp[W] >= 0;
}

int32_t main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> t[i];
    }

    int m, l = 1, r = INF;
    while (l < r) {
        m = (l + r) / 2 + 1;
        if (possible(m)) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }

    cout << l << endl;

    return 0;
}
