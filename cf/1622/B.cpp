#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

template<class T> using p = pair<T, T>;
template<class T> using v = vector<T>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define trav(a, x) for (auto& a : x)
#define rdm(a, b) uniform_int_distribution<int>(a, b)(rng)

#define len(x) (int)(x).size()
#define mp make_pair
#define pb emplace_back
#define x first
#define y second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int const MOD = (int)1e9 + 7;
int const MX = (int)1e5 + 5;
int const INF = (int)1e9;
// ll const INF = (int)1e15;

int in() {
    int x;
    cin >> x;
    return x;
}

int t, n, m;

void solve() {
    n = in();
    int p[200005], q[200005];
    string s;
    for (int i = 0; i < n; i++) {
        p[i] = in();
    }
    cin >> s;

    v<pair<int, int>> lo, hi;
    for (int i = 0; i < len(s); i++) {
        if (s[i] == '0') lo.pb(mp(p[i], i));
        else hi.pb(mp(p[i], i));
    }

    sort(all(lo));
    sort(all(hi));

    for (int i = 0; i < len(lo); i++) {
        q[lo[i].y] = i + 1;
    }
    for (int i = 0; i < len(hi); i++) {
        q[hi[i].y] = len(lo) + i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

