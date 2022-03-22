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
ll const INF = (int)1e15;

int in() {
    int x;
    cin >> x;
    return x;
}

int t;
ll mem[N];
ll ans = INF;
ll n;

ll fact(ll x) {
    if (mem[x] != 0) return mem[x];
    if (x == 0 || x == 1) return mem[x] = 1;
    return mem[x] = x * fact(x - 1);
}

void a(ll sum, ll x, ll cnt) {
    if (sum > n) {
        return;
    }
    if (x > 15) {
        return;
    }

    ll res = 0;
    ll y = n - sum;
    while (y > 0) {
        if (y & 1) res++;
        y = y >> 1;
    }

    ans = min(ans, cnt + res);

    a(sum + fact(x), x + 1, cnt + 1);
    a(sum, x + 1, cnt);
}

void solve() {
    cin >> n;
    
    ans = INF;

    a(0, 3, 0);

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

/*
 * 0000000000000001
 * 0000000000000001
 * 0000000000000010
 * 0000000000000110
 * 0000000000011000
 * 0000000001111000
 * 0000001011010000
 * 0001001110110000
 * 1001110110000000
 *
 * 1111111111111111
 * 1001110110000000
 * 
 * 0110001001111111
 * 0000000001111000
 * 
 * 0110001000000111
 * 0000000000000110
 * 
 * 0110001000000001
 * 
 */
