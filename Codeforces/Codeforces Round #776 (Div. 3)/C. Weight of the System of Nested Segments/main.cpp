#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n, m;
int x[200005], w[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;

void solve() {
    cin >> n >> m;
    int tw = 0;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> w[i];
        pq.push({w[i], i});
        tw += w[i];
    }
    int sw = 0;
    for (int i = 0; i < (m - 2 * n); i++) {
        sw += pq.top().first;
        pq.pop();
    }
    cout << tw - sw << endl;
    vector<pair<int, int>> p;
    while (!pq.empty()) {
        p.push_back({x[pq.top().second], pq.top().second});
        pq.pop();
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < p.size() - i - 1; i++) {
        cout << p[i].second << " " << p[p.size() - i - 1].second << endl;
    }
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
