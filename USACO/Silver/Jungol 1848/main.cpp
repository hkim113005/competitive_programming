#include <iostream>

using namespace std;

int n, m;
int f[50];
int ans = 1;

void input() {
    cin >> n >> m;

    int p = 0;

    for (int i = 0; i < m; i++) {
        int t;

        cin >> t;

        f[i] = t - p - 1;

        p = t;
    }

    f[m] = n - p;
}

void dynamic() {
    int v[50];

    for (int i = 0; i < 50; i++) {
        v[i] = -1;
    }

    v[0] = 1;
    v[1] = 1;

    for (int i = 2; i <= n; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }

    for (int i = 0; i <= m; i++) {
        ans *= v[f[i]];
    }
}

void output() {
    cout << ans;
}

int main() {
    input();

    dynamic();

    output();

    return 0;
}
