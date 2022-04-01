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
int a[N];
int neg[N];
int lx, rx;

int count(int l, int r, bool b) {
    int res = 0;
    int negs = neg[r] - neg[l - 1];
    
    if (l > r) {
        return 0;
    }

    if (l == r) {
        if (l > 0) {
            return l == 2;
        }
        else {
            return 0;
        }
    }

    if (negs % 2 == 0) {
        if (b) {
            lx = l;
            rx = r;
        }
        for (int i = l; i <= r; i++) {
            if (abs(a[i]) == 2) {
                res++;
            }
        }
        return res;
    }
    
    for (int i = l; i < r; i++) {
        if (a[i] < 0) {
            int tmp = count(i + 1, r, false);
            if (tmp > res) {
                res = tmp;
                lx = i + 1;
                rx = r;
            }
            break;
        }
    }
    for (int i = r; i > l; i--) {
        if (a[i] < 0) {
            int tmp = count(l, i - 1, false);
            if (tmp > res) {
                res = tmp;
                lx = l;
                rx = i - 1;
            }
            break;
        }
    }

    return res;
}

void solve() {
    n = in();
    neg[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        neg[i] = neg[i - 1] + (a[i] < 0 ? 1 : 0);
    }
    lx = 1, rx = n;

    int prev = 1;
    int cnt = 0;
    int l, r;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            int tmp = count(prev, i - 1, true);
            if (tmp > cnt) {
                l = lx;
                r = rx;
                cnt = tmp;
            }
            prev = i + 1;
        }
    }

    int tmp = count(prev, n, true);
    if (tmp > cnt) {
        l = lx;
        r = rx;
        cnt = tmp;
    }

    cout << l - 1 << " " << n - r << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> t;
    while (t--) solve();
    return 0;
}

