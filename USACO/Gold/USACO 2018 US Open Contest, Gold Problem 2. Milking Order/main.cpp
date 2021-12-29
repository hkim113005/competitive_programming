#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> m[50005];
vector<int> ans;

bool top(int x) {
    vector<int> pans;
    vector<vector<int>> e(N + 5);
    vector<int> deg(N + 5, 0);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < m[i].size() - 1; j++) {
            e[m[i][j]].emplace_back(m[i][j + 1]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            deg[e[i][j]]++;
        }
    }

    int cnt = 0;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int v = q.top();
        q.pop();
        pans.emplace_back(v);
        for (int u = 0; u < e[v].size(); u++) {
            deg[e[v][u]]--;
            if (deg[e[v][u]] == 0) q.push(e[v][u]);
        }
        cnt++;
    }

    if (cnt != N) return false;
    ans = pans;
    return true;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        m[i].resize(tmp);
        for (int j = 0; j < tmp; j++) {
            cin >> m[i][j];
            m[i][j]--;
        }
    }

    int l = 0, r = M, x;
    while (l < r) {
        x = (l + r) / 2 + 1;
        if (top(x)) {
            l = x;
        }
        else {
            r = x - 1;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1;
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}