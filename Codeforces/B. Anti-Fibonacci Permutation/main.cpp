#include <iostream>
#include <vector>

using namespace std;

int t, n;
int cnt = 0;

void dfs(int x, bool mem[], vector<int> path) {
    if (cnt == n) return;
    if (x == n + 1) {
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
        cnt++;

        return;
    }

    if (x < 3) {
        for (int i = 1; i <= n; i++) {
            if (mem[i]) {
                mem[i] = false;
                path.emplace_back(i);
                dfs(x + 1, mem, path);
                path.erase(path.end() - 1);
                mem[i] = true;
            }
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (mem[i] && i != path[x - 3] + path[x - 2]) {
                mem[i] = false;
                path.emplace_back(i);
                dfs(x + 1, mem, path);
                path.erase(path.end() - 1);
                mem[i] = true;
            }
        }
    }

    return;
}

void solve() {
    cin >> n;
    bool start[55];
    cnt = 0;
    for (int i = 0; i <= n; i++) {
        start[i] = true;
    }
    dfs(1, start, vector<int>());
}

int main() {
    cin >> t;
    while (t--) solve();

    return 0;
}
