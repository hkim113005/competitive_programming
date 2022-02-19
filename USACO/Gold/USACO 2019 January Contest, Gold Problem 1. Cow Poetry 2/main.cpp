#include <iostream>
#include <math.h>

#define int int64_t
#define MOD 1000000007

using namespace std;

int N, M, K;
int s[5005], c[5005];
char e[100005];
int dp[5005];
int num[5005];
int ea[5005];

int power(int x, int y) {
    if (y == 0) return 1 % MOD;
    if (y == 1) return x % MOD;

    int ret = power(x, y / 2);
    ret = (ret * ret) % MOD;
    if (y % 2 == 1) {
        ret = (ret * x) % MOD;
    }

    return ret;
}

int32_t main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> c[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> e[i];
        ea[e[i] - 'A' + 1]++;
    }

    dp[0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (s[j] <= i) {
                dp[i] += dp[i - s[j]];
                dp[i] %= MOD;
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        num[c[i]] += dp[K - s[i]];
        num[c[i]] %= MOD;
    }
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        if (ea[i] == 0) continue;
        for (int j = 1; j <= N; j++) {
            sum += power(num[j], ea[i]);
            sum %= MOD;
        }
        ans *= sum;
        ans %= MOD;
    }

    cout << ans << endl;

    for (int i = 1; i <= N; i++) {
        //cout << power(8, i) << endl;
    }
}
