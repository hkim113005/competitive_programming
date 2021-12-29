#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll N, M;
ll F[100005], S[100005];
vector<pair<ll, ll>> s;

int par[100005];
ll taste[100005];

ll find(ll x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void union_f(ll x, ll y) {
    int a = find(x);
    int b = find(y);

    par[b] = a;
    taste[a] += taste[b];
}

ll find_t(ll x) {
    return taste[find(x)];
}

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    cin >> N >> M;
    s.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i];
        s[i].first = S[i];
        s[i].second = i;
        par[i] = i;
        taste[i] = F[i];
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < N; i++) {
        if (s[i].second > 0 && S[s[i].second - 1] <= s[i].first) {
            union_f(s[i].second, s[i].second - 1);
        }
        if (s[i].second < N - 1 && S[s[i].second + 1] <= s[i].first) {
            union_f(s[i].second, s[i].second + 1);
        }
        if (find_t(s[i].second) >= M) {
            cout << s[i].first << endl;
            return 0;
        }
    }
}

/*
 * Working solution #1.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ll N, M;
ll F[100005], S[100005];
vector<pair<ll, ll>> s;

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    cin >> N >> M;

    s.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i];
        s[i].first = S[i];
        s[i].second = i;
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < N; i++) {
        ll sum = F[s[i].second];
        for (int j = s[i].second + 1; j < N; j++) {
            if (S[j] > s[i].first) break;
            sum += F[j];
            if (sum >= M) {
                cout << s[i].first << endl;
                return 0;
            }
        }
        for (int j = s[i].second - 1; j >= 0; j--) {
            if (S[j] > s[i].first) break;
            sum += F[j];
            if (sum >= M) {
                cout << s[i].first << endl;
                return 0;
            }
        }
    }

    return 0;
}
*/