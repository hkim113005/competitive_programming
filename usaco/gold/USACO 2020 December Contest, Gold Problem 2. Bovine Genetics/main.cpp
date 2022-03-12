#include <iostream>
#include <string>

using namespace std;

string S;
int s[100005];
int N;
int dp[100005][5];
int dp1[1005][1005][5];

int main() {
    cin >> S;
    N = S.size();
    int tmp[100005];
    tmp['A'] = 0, tmp['G'] = 1, tmp['C'] = 2, tmp['T'] = 3, tmp['?'] = 4;
    for (int i = 0; i < N; i++) {
        s[i] = tmp[S[i]];
    }
    for (int i = 0; i < N; i++) {
        if (s[i] == 4) {
            dp1[i][i][0] = 1;
            dp1[i][i][1] = 1;
            dp1[i][i][2] = 1;
            dp1[i][i][3] = 1;
        }
        else {
            dp1[i][i][s[i]] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == 4) {
                dp1[i][j][0] = dp1[i][j + 1][1] + dp1[i][j + 1][2] + dp1[i][j + 1][3];
                dp1[i][j][1] = dp1[i][j + 1][0] + dp1[i][j + 1][2] + dp1[i][j + 1][3];
                dp1[i][j][2] = dp1[i][j + 1][0] + dp1[i][j + 1][1] + dp1[i][j + 1][3];
                dp1[i][j][3] = dp1[i][j + 1][0] + dp1[i][j + 1][1] + dp1[i][j + 1][2];
            }
            else {
                dp1[i][j][s[j]] = dp1[i][j + 1][0] + dp1[i][j + 1][1] + dp1[i][j + 1][2] + dp1[i][j + 1][3] - dp1[i][j + 1][s[j]];
            }
        }
    }
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k < 4; k++) {
                if (s[j] ==  k || s[j] == 4) {
                    if (s[i] == 4) {
                        dp[i][k] += dp[j - 1][0] * dp1[i - 1][j - 1][k];
                        dp[i][k] += dp[j - 1][1] * dp1[i - 1][j - 1][k];
                        dp[i][k] += dp[j - 1][2] * dp1[i - 1][j - 1][k];
                        dp[i][k] += dp[j - 1][3] * dp1[i - 1][j - 1][k];
                    }
                    else {
                        dp[i][k] += dp[j - 1][s[i]] * dp1[i - 1][j - 1][k];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += dp[N][i];
    }

    cout << ans << endl;

    cout << dp1[0][0][0] << endl << dp1[0][0][1];

    return 0;
}
