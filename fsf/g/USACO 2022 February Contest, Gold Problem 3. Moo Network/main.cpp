#include <iostream>
#include <math.h>
#include <vector>

#define pi pair<int, int>
#define int int64_t
#define x first
#define y second
#define INF (int)1e18

using namespace std;

int N;
pi v[100005];
int key[100005];
bool in[100005];
int ans = 0;

int dist(int a, int b) {
    return pow(v[a].x - v[b].x, 2) + pow(v[a].y - v[b].y, 2);
}

int min_key() {
    int min = INF, min_i;
    for (int i = 0; i < N; i++) {
        if (!in[i] && key[i] < min) min = key[i], min_i = i;
    }
    ans += min;
    return min_i;
}

void solve() {
    for (int i = 0; i < N; i++) {
        key[i] = INF, in[i] = false;
    }
    key[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        int a = min_key();
        in[a] = true;

        for (int b = 0; b < N; b++) {
            if (!in[b] && dist(a, b) < key[b]) {
                key[b] = dist(a, b);
                if(i == N - 2) ans += dist(a, b);
            }
        }
    }
}

int32_t main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }

    solve();

    cout << ans << endl;

    return 0;
}
