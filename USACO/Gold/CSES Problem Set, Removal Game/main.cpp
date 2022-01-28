#include <iostream>

#define int int64_t

using namespace std;

int n;
int x[5005];
int dp[5005][5005];
bool vis[5005][5005];
int a[5005];
int cnt = 0;


int solve(int i, int j) {
    cnt++;
    //if (cnt > 25000000) return 0;
    if (vis[i][j]) return dp[i][j];
    if (i > j || i >= n + 1 || j <= 0) return 0;
    if (i == j) return dp[i][j] = x[i];
    int res = max(a[j] - a[i] - solve(i + 1, j) + x[i], a[j - 1] - a[i - 1] - solve(i, j - 1) + x[j]);
    vis[i][j] = true;
    return dp[i][j] = res;
}

int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + x[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            vis[i][j] = false;
        }
    }

    cout << solve(1, n) << endl;

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
         for (int i = a; i <= b; i++) {
        res += x[i];
    }
     */

    return 0;
}

/*
 * dp[i][j] = sum(i + 1, j) - dp[i + 1][j] + x[i]
 * dp[i][j] = sum(i, j - 1) - dp[i][j - 1] + x[j]
 * 0 0 0 0 0
 * 0 4 5 6 7
 * 0 0 5 5 6
 * 0 0 0 1 3
 * 0 0 0 0 3
 * dp[i + 1][j] = sum(i + 1, j) + x[i] - dp[i][j]
 * dp[i][j - 1] = sum(i, j - 1) + x[i] - dp[i][j];
 */