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
int x;

void solve() {
    cin >> n >> x;
    map<int, int> f;
    FOR(i, n) {
        cin >> a[i];
        f[a[i]]++;
    }
    auto be = f.begin(), en = f.end();
    for (auto i = be; i != en; i++) {
        if (f.count(i->first * x)) {
            if (f[i->first * x] > i->second) {
                f[i->first * x] -= i->second;
                i->second = 0;
            }
            else {
                i->second -= f[i->first * x];
                f[i->first * x] = 0;
            }
        }
    }
    int ans = 0;
    be = f.begin(), en = f.end();
    for (auto i = be; i != en; i++) {
        ans += i->second;
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

