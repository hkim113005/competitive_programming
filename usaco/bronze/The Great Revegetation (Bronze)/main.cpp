#include <iostream>
#include <fstream>

using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m, a[150], b[150], ans[100];

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];

        if (a[i] > b[i]) {
            int tmp = a[i];
            a[i] = b[i];
            b[i] = tmp;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
            }
            else if (a[j] == a[j + 1]) {
                if (b[j] > b[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;

                    tmp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        if (ans[a[i] - 1] == ans[b[i] - 1]) {
            bool subtract = true;
            if (ans[b[i] - 1] > 1) {
                for (int j = 0; j < i; j++) {
                    if (ans[a[j] - 1] == ans[b[i] - 1] - 1) {
                        subtract = false;
                    }
                }

                if (subtract) {
                    ans[b[i] - 1]--;
                }
                else {
                    ans[b[i] - 1]++;
                }
            }
            else {
                ans[b[i] - 1]++;
            }

        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }

    return 0;
}
