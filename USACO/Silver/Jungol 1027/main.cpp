#include <iostream>

using namespace std;

int n;

bool check(int a[100], int s) {
    bool ok = false;

    for (int i = 2; i <= s / 2 + 1; i++) {
        for (int j = 0; j <= s - 2 * i; j++) {
            ok = false;
            for (int k = j; k < j + i; k++) {
                if (a[k] != a[k + i]) {
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int cnt, int a[100]) {
    if (cnt == n) {
        if (check(a, n)) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
            }

            cout << endl;
            exit(0);
        }

        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (i != a[cnt]) {
            a[cnt + 1] = i;
            if (check(a, cnt + 1)) {
                dfs(cnt + 1, a);
            }
        }
    }
}

int main() {
    cin >> n;

    int a[100];

    a[0] = 1;
    dfs(0, a);

    a[0] = 2;
    dfs(0, a);

    a[0] = 3;
    dfs(0, a);

    return 0;
}
