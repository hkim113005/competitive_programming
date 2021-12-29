#include <iostream>
#include <math.h>

#define INF 1000000000
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll N, M, K;
ll s[200005], c[200005];
char e[200005];
ll mem[200005];
ll r[200005], rs[200005];
ll sums[200005];

ll dp(int x) {
    if (mem[x] != INF) return mem[x];
    if (x == 0) return mem[x] = 1;
    if (x < 0) return mem[x] = 0;

    ll sum = 0;
    for (int i = 0 ; i < N; i++) {
        if (s[i] <= x) sum = (sum + dp(x - s[i])) % MOD;
    }
    return mem[x] = sum;
}

ll power(int x, int y) {
    if (y == 0) return 1 % MOD;
    if (y == 1) return x % MOD;

    ll ret = power(x, y / 2);
    ret = (ret * ret) % MOD;
    if (y % 2 == 1) {
        ret = (ret * x) % MOD;
    }

    return ret;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    cin >> N >> M >> K;
    for (int i = 0; i <= K; i++) {
        mem[i] = INF;
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> c[i];
        r[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> e[i];
        rs[e[i]] = 0;
    }
    for (int i = 0; i < M; i++) {
        rs[e[i]]++;
    }

    for (int i = 0; i < N; i++) {
        r[c[i]] = (r[c[i]] + dp(K - s[i])) % MOD;
    }

    if (dp(K) == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 'A'; i <= 'Z'; i++) {
        ll sum = 0;
        for (int j = 1; j <= N; j++) {
            if (rs[i] != 0) sum = (sum + ((ll)power(r[j], rs[i]) % MOD)) % MOD;
        }
        sums[i - 'A'] = sum;
    }

    ll ans = 1;
    for (int i = 0; i < M; i++) {
        if (sums[i] != 0) ans = (ans * sums[i]) % MOD;
    }

    cout << ans << endl;

    /*
    cout << endl;
    for (int i = 1; i <= N; i++) {
        cout << r[i] << endl;
    }
    cout << endl;
    for (int i = 'A'; i <= 'Z'; i++) {
        cout << char(i) << ": " << rs[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < M; i++) {
        cout << sums[i] << endl;
    }
    */

    return 0;
}

/*
 * 10 = 7 = 6
 */