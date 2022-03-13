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

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a) for (int i = 0; i < a; i++)
#define FORm(i, a, b) for (int i = a - 1; i >= b; i--)
#define FORm(i, a) for (int i = a - 1; i >= 0; i--)
#define FORi(i, a, b) for (int i = a; i <= b; i++)
#define FORi(i, a) for (int i = 1; i <= a; i++)
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
    cin >> n;
    FOR(i, n) {
        cin >> a[i];
    }
    FOR(i, n) {
        cin >> b[i];
    }

    int ans = INF;
    ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    
    int q[4] = { INF, INF, INF, INF };
    FOR(i, n) {
        q[0] = min(q[0], abs(a[0] - b[i]));
        q[1] = min(q[1], abs(a[n - 1] - b[i]));
        q[2] = min(q[2], abs(b[0] - a[i]));
        q[3] = min(q[3], abs(b[n - 1] - a[i]));
    }
    ans = min(ans, abs(a[0] - b[0]) + q[1] + q[3]);
    ans = min(ans, abs(a[n - 1] - b[0]) + q[0] + q[3]);
    ans = min(ans, abs(a[0] - b[n - 1]) + q[1] + q[2]);
    ans = min(ans, abs(a[n - 1] - b[n - 1]) + q[0] + q[2]);

    ans = min(ans, q[0] + q[1] + q[2] + q[3]);

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

