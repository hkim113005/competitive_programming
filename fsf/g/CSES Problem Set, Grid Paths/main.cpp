#include <iostream>

using namespace std;

int n;
int m = 1e9 + 7;
char a[1005][1005];
int dp[1005][1005];
int inf = m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = inf;
        }
    }
    if (a[1][1] != '*') dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != '*') {
                if (j > 1 && a[i][j - 1] != '*') {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= m;
                }
                if (i > 1 && a[i - 1][j] != '*') {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= m;
                }
            }
        }
    }

    cout << (dp[n][n] == inf ? 0 : dp[n][n]);

    return 0;
}
