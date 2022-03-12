#include <iostream>

using namespace std;

int N;
int a[1005], b[1005];
int dp[1005][1005];

int main() {
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }

    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + (abs(a[i] - b[j]) <= 4 ? 1 : 0), max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    cout << dp[N][N] << endl;

    return 0;
}

/*
 dp[N][N] => dp[remaining on left][remaining on right]

 for all possible connections where l <= i and r <= j
    dp[i][j] = max(dp[i - 1][j - 1] + |L[i] - R[j]| <= 4 ? 1 : 0, max(dp[i - 1][j], dp[i][j - 1]))
*/