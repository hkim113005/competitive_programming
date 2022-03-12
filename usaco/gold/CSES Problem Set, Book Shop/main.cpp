#include <iostream>
#include <algorithm>

#define INF -(int)1e9

using namespace std;

int n, x;
int h[1000000], s[1000000];

int dp[1000000];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i <= x; i++) {
        dp[i] = -1;
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x - h[i]; j >= 0; j--) {
            if (dp[j] != -1) dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
        }
    }

    sort(dp, dp + x + 1);

    cout << dp[x] << endl;

    for (int i = 0; i <= x; i++) {
        //cout << dp[i] << endl;
    }

    return 0;
}


