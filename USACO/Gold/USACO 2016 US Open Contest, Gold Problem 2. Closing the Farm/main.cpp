#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> e[200005];
int par[200005];
int siz[200005];
int a[200005];
bool vis[200005];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    int p = find(x), q = find(y);

    if (p == q) return;

    if (siz[p] >= siz[q]) {
        par[q] = p;
        siz[p] += siz[q];
    }
    else {
        par[p] = q;
        siz[q] += siz[p];
    }
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int t, s;
        cin >> t >> s;
        e[t].emplace_back(s);
        e[s].emplace_back(t);
    }

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        par[i] = i;
        siz[i] = 1;
        vis[i] = false;
    }

    vector<string> ans;

    for (int i = N; i > 0; i--) {
        //cout << a[i] << endl;
        vis[a[i]] = true;
        for (int j = 0; j < e[a[i]].size(); j++) {
            if (vis[e[a[i]][j]]) {
                //cout << "\t" << a[i] << " " << e[a[i]][j] << endl;
                unite(a[i], e[a[i]][j]);
            }
        }

        //cout << siz[a[i]] << endl;

        if (siz[find(a[i])] == N - i + 1) {
            ans.emplace_back("YES");
        }
        else {
            ans.emplace_back("NO");
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }

    return 0;
}

/*
 * 0:
 * 1:1
 * 2:1
 * 3:1
 * 4:1
 */