#include <iostream>

using namespace std;

int N, M;
int a[10000][2];
bool explored[10000];
bool t;
int tmp;

void solve(int x) {
    if (t) {
        for (int i = 0; i < M; i++) {
            if (!explored[a[i][0]] && a[i][1] == x) {
                explored[a[i][0]] = true;
                tmp++;
                solve(a[i][0]);
            }
        }
    }

    t = false;

    for (int i = 0; i < M; i++) {
        if (!explored[a[i][1]] && a[i][0] == x) {
            explored[a[i][1]] = true;
            tmp++;
            solve(a[i][1]);
        }
    }
}

int main() {
    int ans = 0;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            explored[j] = false;
        }
        t = true;
        tmp = 1;

        solve(i);

        if (tmp == N) {
            ans++;
        }
    }

    cout << ans;
}