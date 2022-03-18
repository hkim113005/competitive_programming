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

int t, n, m;

void solve() {
    ll a, s;
    stack<int> b;
    cin >> a >> s;
    while (a != 0 && s != 0) {
        int d = a % 10;
        if (s % 10 < d) {
            if ((s / 10) % 10 != 1) {
                cout << -1 << endl;
                return;
            }
            b.push(s % 10 + (s / 10) % 10 * 10 - d);
            s /= 100;
        }
        else {
            b.push(s % 10 - d);
            s /= 10;
        }
        a /= 10;
    }
    if (a != 0) {
        cout << -1 << endl;
        return;
    }
    if (s != 0) {
        while (s != 0) {
            b.push(s % 10);
            s /= 10;
        }
    }
    ll ans = 0;
    while (!b.empty()) {
        ans += b.top() * pow(10, b.size() - 1);
        b.pop();
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}
