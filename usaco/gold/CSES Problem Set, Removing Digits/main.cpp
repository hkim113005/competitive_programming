#include <iostream>

#define INF (int)1e9

using namespace std;

int n;
int dp[1000005];

int main() {
    cin >> n;

    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j /= 10) {
            dp[i] = min(dp[i - j % 10] + 1, dp[i]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}

/*
 * 170
 * 163
 * 157
 * 150 -> 151, 152, 153, 154, 155, 156, 157, 158, 159
 * 151 -> 152, 156
 * 152 -> 153, 157
 * 153 -> 154, 158
 * 154 -> 155, 160
 * 155 -> 156, 161
 * 156 -> 157, 162
 * 157 -> 158, 163
 * 158 -> 159, 164
 * 159 -> 160, 165
 */
