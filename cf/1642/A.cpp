#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double
#define pi pair<int, int>
#define pd pair<double, double>
#define vi vector<int>
#define vd vector<double>
#define vpi vector<pi>

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FORS(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a) for (int i = 0; i < a; i++)
#define FORSM(i, a, b) for (int i = a - 1; i >= b; i--)
#define FORM(i, a) for (int i = a - 1; i >= 0; i--)
#define FORSI(i, a, b) for (int i = a; i <= b; i++)
#define FORI(i, a) for (int i = 1; i <= a; i++)
#define TRAV(a, x) for (auto& a : x)
#define UID(a, b) uniform_int_distribution<int>(a, b)(rng)

#define len(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define MOD (int)1e9 + 7
#define MX (int)1e5 + 1
#define INF (int)1e15

int t, n, m;
int a[500005], b[500005];

void solve() {
    int x[3], y[3];
    FOR(i, 3) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    if (y[0] == y[1] && y[0] != 0 && y[0] > y[2]) {
        ans += abs(x[0] - x[1]);
    }
    if (y[1] == y[2] && y[1] != 0 && y[1] > y[0]) {
        ans += abs(x[1] - x[2]);
    }
    if (y[2] == y[0] && y[2] != 0 && y[2] > y[1]) {
        ans += abs(x[2] - x[0]);
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

