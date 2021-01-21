#include <iostream>

using namespace std;

int n;

bool check(int a[100]) {
    bool ok = false;

    for (int i = 2; i < n / 2 + 1; i++) {
        for (int j = 0; j < n - i; j++) {
            ok = false;
            for (int k = j; k < j + i; k++) {
                if (a[k] != a[k + i]) {
                    ok = true;
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
        if (check(a)) {
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
            dfs(cnt + 1, a);
        }
    }
}

int main() {
    cin >> n;

    int a[50];

    a[0] = 1;
    dfs(0, a);

    a[0] = 2;
    dfs(0, a);

    a[0] = 3;
    dfs(0, a);

    return 0;
}
