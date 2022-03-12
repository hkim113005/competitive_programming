#include <iostream>
#include <vector>
#include <queue>

#define INF 9223372036854775807

using namespace std;

typedef long long ll;

int N, M, T;
int c[10005];
vector<pair<int, int>> edges[10005];
ll dist[10005];
int parent[10005];
ll sum[10005];

int find_sum(int x) {
    int a = c[x];
    for (int i = 1; i <= N; i++) {
        if (parent[i] == x && i != x) {
            a += find_sum(i);
        }
    }
    return sum[x] = a;
}

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        dist[i] = INF;
        sum[i] = INF;
    }
    for (int i = 1; i <= M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[a].emplace_back(t, b);
        edges[b].emplace_back(t, a);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    parent[1] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator i;
        for (i = edges[u].begin(); i != edges[u].end(); i++) {
            int v = (*i).second;
            int t = (*i).first;
            if ((dist[v] > dist[u] + t) || (dist[v] == dist[u] + t && u < parent[v])) {
                dist[v] = dist[u] + t;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    find_sum(1);

    /*
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << endl;
    }
    cout << endl;
    for (int i = 1; i <= N; i++) {
        cout << parent[i] << endl;
    }
    cout << endl;
    for(int i = 1; i <= N; i++) {
        cout << sum[i] << endl;
    }
    cout << endl;
     */

    ll ans = 0;
    for (int i = 2; i <= N; i++) {
        if (ans < (dist[i] - T) * sum[i]) ans = (dist[i] - T) * sum[i];
    }
    cout << ans << endl;

    return 0;
}
