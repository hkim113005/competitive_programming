#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int t[10005];
int dp[100][100][10000];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    sort(t, t + n);

    dp[0][0][5000] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 5000; k++) {
                dp[i][j][k + 5000] += dp[i - 1][j][k + 5000];
                dp[i][j][k + 5000] += j * dp[i - 1][j][k + 5000];
                dp[i][j][k + 5000] += dp[i - 1][j - 1][k + t[i] + 5000];
                dp[i][j][k + 5000] += (j + 1) * dp[i - 1][j + 1][k - t[i] + 5000];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= x; i++) {
        ans += dp[n][0][i + 5000];
    }
    cout << ans;

    return 0;
}

/*
 * dp[i][j][k] += dp[i - 1][j][k]
 * dp[i][j][k] += j * dp[i - 1][j][k]
 * dp[i][j][k] += dp[i - 1][j - 1][k + t[i]]
 * dp[i][j][k] += (j + 1) * dp[i - 1][j + 1][k - t[i]]
 */