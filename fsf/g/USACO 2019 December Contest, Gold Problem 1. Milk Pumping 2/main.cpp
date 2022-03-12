#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define int int64_t
#define INF (int)1e10

using namespace std;

int N, M;
int c[1005], f[1005];
int f_o[1005];
vector<pair<int, int>> e[1005];

int solve(int min_f) {
    queue<int> q;
    q.push(1);
    int val[1005];

    for (int i = 0; i <= N; i++) {
        val[i] = INF;
    }
    val[1] = 0;

    while (!q.empty()){
        int i = q.front();

        for (auto j : e[i]) {
            if (f[j.second] >= min_f && val[i] + c[j.second] < val[j.first]) {
                val[j.first] = val[i] + c[j.second];
                q.push(j.first);
            }
        }

        q.pop();
    }

    return val[N];
}

int32_t main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b >> c[i] >> f[i];
        e[a].emplace_back(b, i);
        e[b].emplace_back(a, i);
        f_o[i] = f[i];
    }

    sort(f_o + 1, f_o + M + 1, greater<>());

    double ans = -INF;
    for (int i = 1; i <= M; i++) {
        //cout << f_o[i] << endl;
        int cost = solve(f_o[i]);
        //cout << cost << endl;
        if (cost == INF) continue;
        ans = max(ans, (double)f_o[i] / (double)cost);
    }

    cout << (int)(ans * 1000000) << endl;

    return 0;
}
