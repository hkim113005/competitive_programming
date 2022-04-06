#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;

template<class T> using p = pair<T, T>;
template<class T> using v = vector<T>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define trav(a, x) for (auto& a : x)
#define rdm(a, b) uniform_int_distribution<int>(a, b)(rng)

#define len(x) (int)(x).size()
#define mp make_pair
#define pb emplace_back
#define ft first
#define sd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int const MOD = (int)1e9 + 7;
int const MX = (int)1e5 + 5;
int const N = (int)5e5 + 5;
int const INF = (int)1e9;
// ll const INF = (int)1e15;

int in() {
    int x;
    cin >> x;
    return x;
}

int t, n;
int k;
int b[N], c[N];
int cost[N];
int X = 1005;
int sum = 0;

void solve() {
    n = in();
    k = in();
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += cost[b[i]];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int K = min(k, sum);

    int dp[N];
    for (int i = 0; i <= K; i++) {
        dp[i] = -INF;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = K - cost[b[i]]; j >= 0; j--) {
            if (dp[j] != -INF) dp[j + cost[b[i]]] = max(dp[j + cost[b[i]]], dp[j] + c[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= K; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    for (int i = 1; i < X; i++) {
        cost[i] = INF;
    }
    cost[1] = 0;
    for (int i = 1; i < X; i++) {
        for (int j = 1; j <= i; j++) {
            cost[i + i / j] = min(cost[i + i / j], cost[i] + 1);
        }
    }

    cin >> t;
    while (t--) solve();
    return 0;
}

