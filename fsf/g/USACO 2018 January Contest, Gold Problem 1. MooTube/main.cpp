#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> node;

int N, Q;
priority_queue<node, vector<node>> E;
int par[100005];
int siz[100005];
priority_queue<node, vector<node>> A;

int find(int x) {
    return par[x] = (par[x] == x ? x : find(par[x]));
}

void update(int x, int y) {
    x = find(x), y = find(y);
    if (siz[x] > siz[y]) {
        par[y] = par[x];
        siz[x] += siz[y];
    }
    else {
        par[x] = par[y];
        siz[y] += siz[x];
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> N >> Q;
    for (int i = 1; i < N; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        E.push(make_pair(r, make_pair(p, q)));
        par[i] = i;
        siz[i] = 1;
    }
    par[N] = N;
    siz[N] = 1;
    for (int i = 1; i <= Q; i++) {
        int k, v;
        cin >> k >> v;
        A.push(make_pair(k, make_pair(v, i)));
    }

    int ans[100005];
    while (!A.empty()) {
        node f = A.top();
        A.pop();

        while (!E.empty() && E.top().first >= f.first) {
            node g = E.top();
            E.pop();
            update(g.second.first, g.second.second);
        }

        /*
        for (int i = 1; i <= N; i++) {
            cout << par[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= N; i++) {
            cout << siz[i] << ' ';
        }
        cout << endl << endl;
         */

        ans[f.second.second] = siz[find(f.second.first)] - 1;
    }

    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
