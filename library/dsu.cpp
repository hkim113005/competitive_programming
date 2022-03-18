struct DSU {
    vector<ll> p;

    DSU(int n) {
        p = vector<ll>(n, -1);
    }

    ll find(int x) {
        return p[x] < 0 ? x : p[x] = get(p[x]);
    }

    bool joint(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -p[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }
}

