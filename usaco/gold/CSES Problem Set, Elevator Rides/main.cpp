#include <iostream>
#include <math.h>
#include <vector>

#define INF (int)1e9
#define int unsigned int

using namespace std;

int n, x;
int w[50];
vector<pair<int, int>> dp;
//2097152

int32_t main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    dp.resize(pow(2, n));
    for (int i = 0; i < pow(2, n); i++) {
        dp[i] = make_pair(n + 1, x + 1);
    }
    dp[0] = make_pair(1, 0);

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                pair<int, int> pre = dp[mask ^ (1 << i)];
                int num = pre.first;
                int wei = pre.second;
                if (wei + w[i] <= x) {
                    wei += w[i];
                }
                else {
                    num++;
                    wei = w[i];
                }
                dp[mask] = min(dp[mask], make_pair(num, wei));
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}