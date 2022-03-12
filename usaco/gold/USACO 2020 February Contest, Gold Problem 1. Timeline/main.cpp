#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, C;
int S[100005];
vector<pair<int, int>> e[100005];
int p[100005];
int ans[100005];

int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        ans[i] = S[i];
    }
    for (int i = 1; i <= C; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        e[a].emplace_back(make_pair(b, x));
        p[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (p[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int f = q.front();
        for (auto i : e[f]) {
            ans[i.first] = max(ans[i.first], ans[f] + i.second);
            p[i.first]--;
            if (p[i.first] == 0) q.push(i.first);
        }
        q.pop();
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
