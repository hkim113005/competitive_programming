#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<pair<int, int>> e;
bool on[200005];

int par[200005];
int siz[200005];

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
    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        char act;
        cin >> act;
        int a, b;
        if (act == 'A') {
            cin >> a >> b;
            e.emplace_back(a, b);
        }
        else {
            cin >> a;
        }

        if (act == 'A') {
            unite(a, b);
        }
        if (act == 'D') {
            unite(e[a - 1].first, e[a - 1].first);
            unite(e[a - 1].second, e[a - 1].second);
        }
    }

    return 0;
}
