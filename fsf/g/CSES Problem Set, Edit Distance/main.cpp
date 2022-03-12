#include <iostream>
#include <string>

#define INF (int)1e9

using namespace std;

string s, t;
char a[5010], b[5010];
int n, m;
int dp[5010][5010];

int main() {
    //freopen("test.in", "r", stdin);

    cin >> s >> t;
    n = (int)s.size();
    m = (int)t.size();
    for (int i = n - 1; i >= 0; i--) {
        a[i + 1] = s[i];
    }
    for (int i = m - 1; i >= 0; i--) {
        b[i + 1] = t[i];
    }
    a[0] = b[0] = ' ';

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    cout << dp[n][m] << endl;

    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}