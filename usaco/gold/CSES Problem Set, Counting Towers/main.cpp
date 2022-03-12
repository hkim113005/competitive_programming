#include <iostream>

#define int int64_t

using namespace std;

int t, n;
int dp[1000005][2];
int m = (int)1e9 + 7;

void solve() {

    for (int i = 1; i < n; i++) {
        if (dp[i][0] == 0) {
            dp[i][0] += (dp[i - 1][0] * 2) % m;
            dp[i][0] %= m;
            dp[i][0] += dp[i - 1][1] % m;
            dp[i][0] %= m;

            dp[i][1] += dp[i - 1][0] % m;
            dp[i][1] %= m;
            dp[i][1] += (dp[i - 1][1] * 4) % m;
            dp[i][1] %= m;
        }
    }

    cout << (dp[n - 1][0] + dp[n - 1][1]) % m << endl;
}

int32_t main() {
    cin >> t;

    dp[0][0] = dp[0][1] = 1;

    for (int i = 0; i < t; i++) {
        //cout << i;
        cin >> n;
        solve();
    }

    return 0;
}

/*
 * dp[i][0] = dp[i - 1][0] + 2;
 * dp[i][0] = dp[i - 1][1] + 1;
 * dp[i][1] = dp[i - 1][0] + 1;
 * dp[i][1] = dp[i - 1][1] + 4;
 */