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

void solve() {
    n = in();
    int minL = INF, costL = INF;
    int maxR = 0, costR = INF;
    int maxLen = 0, costLen = INF;
    for (int i = 0; i < n; i++) {
        int l = in(), r = in(), c = in();
        if (l < minL) {
            minL = l;
            costL = INF;
        }
        if (l == minL) {
            costL = min(costL, c);
        }

        if (r > maxR) {
            maxR = r;
            costR = INF;
        }
        if (r == maxR) {
            costR = min(costR, c);
        }
        
        if (maxLen < r - l + 1) {
            maxLen = r - l + 1;
            costLen = INF;
        }
        if (maxLen == r - l + 1) {
            costLen = min(costLen, c);
        }

        int ans = costL + costR;
        if (maxLen == maxR - minL + 1) {
            ans = min(ans, costLen);
        }
        cout << ans << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

