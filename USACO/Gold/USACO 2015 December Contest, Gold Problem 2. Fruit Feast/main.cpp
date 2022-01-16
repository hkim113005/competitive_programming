#include <iostream>

using namespace std;

int T, A, B;
bool dp[5000005];

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    cin >> T >> A >> B;

    dp[0] = true;
    for (int i = 0; i <= T; i++) {
        if (i - A >= 0) dp[i] = dp[i - A] || dp[i];
        if (i - B >= 0) dp[i] = dp[i - B] || dp[i];
    }

    for (int i = 0; i <= T; i++) {
        if (i * 2 + 1 <= T) dp[i] = dp[i * 2] || dp[i * 2 + 1] || dp[i];
    }

    for (int i = 0; i <= T; i++) {
        if (i - A >= 0) dp[i] = dp[i - A] || dp[i];
        if (i - B >= 0) dp[i] = dp[i - B] || dp[i];
    }

    for (int i = T; i >= 0; i--) {
        if (dp[i]) {
            cout << i << endl;
            break;
        }
    }

    for (int i = 0; i <= T; i++) {
        //cout << dp[i] << " ";
    }
    //cout << endl;

    return 0;
}
