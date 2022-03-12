#include <iostream>

#define int int64_t

using namespace std;

int MOD = 1000000007;
int n;
int dp[10000000];

int power (int b, int e) {
    b %= MOD;
    int res = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            res = res * b % MOD;
        }
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}

int inverse(int b) {
    return power(b, MOD - 2) % MOD;
}

int32_t main() {
    cin >> n;

    int sum = (n + 1) * n / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }

    //cout << sum << endl;
    //cout << dp[sum] << endl;
    cout << dp[sum] % MOD * inverse(2) % MOD << endl;
    for (int j = 0; j <= sum; j++) {
        //cout << dp[j] << " ";
    }
    //cout << endl;

    return 0;
}
