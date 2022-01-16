#include <iostream>

#define MOD (int)1e9 + 7

using namespace std;

int N;
int dp[10000005];

int main() {
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    for (int i = 7; i <= N; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
        dp[i] += dp[i - 2];
        dp[i] %= MOD;
        dp[i] += dp[i - 3];
        dp[i] %= MOD;
        dp[i] += dp[i - 4];
        dp[i] %= MOD;
        dp[i] += dp[i - 5];
        dp[i] %= MOD;
        dp[i] += dp[i - 6];
        dp[i] %= MOD;
    }

    cout << dp[N] << endl;

    return 0;
}
