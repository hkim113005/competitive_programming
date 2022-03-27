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

ll in() {
    ll x;
    cin >> x;
    return x;
}

ll t, n;

void solve() {
    n = in();
    ll k = in();

    if (n == 4 && k == 3) {
        cout << -1 << endl;
        return;
    }

    ll ans[100005][2];
    if (k == n - 1) {
        for (int i = 3; i < n / 2; i++) {
            ans[i][0] = i;
            ans[i][1] = (i ^ (n - 1));
        }
        cout << 0 << " " << 2 << endl;
        cout << 1 << " " << n - 3 << endl;
        cout << n - 2 << " " << n - 1 << endl;
        for (int i = 3; i < n / 2; i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            ans[i][0] = i;
            ans[i][1] = (i ^ (n - 1));
        }
        if (k >= n / 2) {
            k ^= (n - 1);
            ans[0][1] = ans[k][0];
            ans[k][0] = n - 1;
        }
        else {
            ans[0][1] = ans[k][1];
            ans[k][1] = n - 1;
        }
        for (int i = 0; i < n / 2; i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
}


int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

