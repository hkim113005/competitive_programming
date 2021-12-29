#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1000000000

using namespace std;

int N, M;
vector<tuple<int, int, int>> e[1005];
priority_queue<int, vector<int>, greater<>> fr;

int dijkstra(int fl) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N + 5, INF);

    pq.push(make_pair(0, 1));
    dist[1] = 0;

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        for (int i = 0; i < e[v].size(); i++) {
            int u = get<0>(e[v][i]);
            int w = get<1>(e[v][i]);
            int f = get<2>(e[v][i]);

            if (f < fl) continue;

            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push(make_pair(dist[u], u));
            }
        }
    }

    return dist[N];
}

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        e[a].emplace_back(make_tuple(b, c, f));
        e[b].emplace_back(make_tuple(a, c, f));
        fr.push(f);
    }

    int ans = 0;
    while (!fr.empty()) {
        int fl = fr.top();
        ans = max(ans, (int)((double)fl / (double)dijkstra(fl) * 1000000));
        fr.pop();
    }
    cout << ans << endl;

    return 0;
}
