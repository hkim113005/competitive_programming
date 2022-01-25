#include <iostream>
#include <string>

using namespace std;

string s, t;
int n, m;
int dp[5005][5005];

int main() {
    cin >> s >> t;
    n = s.size();
    m = t.size();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << s[i - 1] << " ";
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << endl;

    cout << n << " " << m << endl;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    cout << max(n, m) - dp[n][m] << endl;

    return 0;
}

/*
 * SQTCKWAMFJEBV
 * IUWGGNJOMQFP
 */