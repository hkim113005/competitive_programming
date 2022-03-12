#include <iostream>

#define int int64_t

using namespace std;

int M = (int)1e9 + 7;
int n, m;
int x[100005];
int dp[100005][105];

int32_t main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    if (x[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    }
    else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
                dp[i][j] %= M;
            }
        }
        else {
            int j = x[i];
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= M;
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += dp[n - 1][j];
        ans %= M;
    }
    cout << ans << endl;

    /*
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
     */

    return 0;
}

/*
 * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
 * dp[i][j] = 1;
 */