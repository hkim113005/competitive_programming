#include <iostream>
#include <algorithm>
#include <math.h>

#define int int64_t

using namespace std;

int m = (int)1e9 + 7;
int n, x;
int t[105];
int dp[105][55][10005];

int32_t main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    dp[0][0][5000] = 1;

    sort(t, t + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 10001; k++) {
                dp[i][j][k] %= m;
                if (!dp[i][j][k]) continue;
                dp[i + 1][j][k] += dp[i][j][k] * (j + 1);
                if (j < 50) dp[i + 1][j + 1][k - t[i]] += dp[i][j][k];
                if (j > 0) dp[i + 1][j - 1][k + t[i]] += dp[i][j][k] * j;
            }
        }
    }

    int ans = 0;
    for (int k = 5000; k <= 5000 + x; k++) {
        ans += dp[n][0][k];
        ans %= m;
    }
    cout << ans << endl;

    return 0;
}