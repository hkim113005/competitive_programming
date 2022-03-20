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
    int a[N];
    ll sum = 0;
    multiset<ll> p, q;
    p.clear();
    q.clear();
    for (int i = 0; i < n; i++) {
        a[i] = in();
        p.ins(a[i]);
        sum += a[i];
    }
    q.ins(sum);

    while (!q.empty()) {
        ll x = *--p.end(), y = *--q.end();
        if (x > y) break;
        q.erase(q.find(y));
        if (p.count(y) > 0) {
            p.erase(p.find(y));
        }
        else {
            q.ins(floor((double)y / 2));
            q.ins(ceil((double)y / 2));
        }
    }
    cout << (p.empty() ? "YES" : "NO") << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

