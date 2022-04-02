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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 0;

    int p = 0, p_max = 0;
    int last_zero = 0;
    int l = 1, r = 0;
    int negs = 0, first = 0, last = 0, first_count = 0, last_count = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (abs(a[i]) == 2) {
            p++;
            last_count++;
        }
        if (first == 0 && abs(a[i]) == 2) {
            first_count++;
        }
        if (a[i] < 0) {
            if (first == 0) {
                first = i;
                last = i;
                last_count = 0;
            }
            else {
                last = i;
                last_count = 0;
            }
            
            if (abs(a[i]) == 2) {
                last_count++;
            }
            negs++;
        }
        else if (a[i] == 0) {
            if (negs % 2 == 0) {
                if (p > p_max) {
                    p_max = p;
                    l = last_zero + 1;
                    r = i - 1;
                }
            }
            else {
                if (first_count > last_count && p - last_count > p_max) {
                    p_max = p - last_count;
                    l = last_zero + 1;
                    r = last - 1;
                }
                else if (first_count <= last_count && p - first_count > p_max) {
                    p_max = p - first_count;
                    l = first + 1;
                    r = i - 1;
                }
            }
            last_zero = i;
            p = negs = first = last = first_count = last_count = 0;
        }
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

