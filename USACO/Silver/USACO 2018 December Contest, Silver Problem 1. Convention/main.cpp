#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, C;
int c[100005];

bool check(int x) {
    int cur = 0;
    int b = 1;

    for (int i = 1; i < N; i++) {
        if (i - cur + 1 > C || c[i] - c[cur] > x) {
            cur = i;
            b++;
        }
    }

    return b <= M;
};

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> N >> M >> C;

    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    sort(c, c + N);

    int l = 0, h = 1000000000;

    while (l < h) {
        int m = (l + h) / 2;

        if (check(m)) {
            h = m;
        } else {
            l = m + 1;
        }
    }

    cout << l;

    return 0;
}