#include <iostream>
#include <math.h>
#include <queue>

#define INF 1000000000

using namespace std;

int N;
int cows[1005][2];
int E[1005][1005];
bool visited[1005];

bool work(int x) {
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (!visited[i] && E[f][i] <= x) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
        visited[i] = false;
        for (int j = 0; j < N; j++) E[i][j] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            E[i][j] = (int)pow(abs(cows[i][0] - cows[j][0]), 2) + (int)pow(abs(cows[i][1] - cows[j][1]), 2);
        }
    }

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << E[i][j] << " ";
        }
        cout << endl;
    }
     */

    int l, r, m;

    l = 0, r = 1000000000, m = (l + r) / 2;

    while (l < r) {
        if (work(m)) {
            r = m;
        }
        else {
            l = m + 1;
        }

        m = (l + r) / 2;
    }

    cout << m << endl;

    return 0;
}
