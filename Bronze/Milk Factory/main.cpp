#include <iostream>
#include <fstream>

using namespace std;

typedef struct node {
    int cnt = 0;
    int parent[105];
} node;

node stations[105];
int n;
bool explored[105];

bool all_explored() {
    for (int i = 1; i <= n; i++) {
        if (!explored[i]) {
            return false;
        }
    }

    return true;
}

bool bfs(int x) {
    if (all_explored()) {
        return true;
    }

    for (int i = 0; i < stations[x].cnt; i++) {
        if (!explored[stations[x].parent[i]]) {
            explored[stations[x].parent[i]] = true;
            bfs(stations[x].parent[i]);
        }
    }

    if (all_explored()) {
        return true;
    }

    return false;
}

int main() {
    //freopen("factory.in", "r", stdin);
    //freopen("factory.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        stations[b].parent[stations[b].cnt] = a;
        stations[b].cnt++;
    }

    bool solution = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            explored[j] = false;
        }

        explored[i] = true;

        if (bfs(i)) {
            cout << i << endl;

            solution = true;
        }
    }

    if (!solution) {
        cout << -1;
    }

    return 0;
}
