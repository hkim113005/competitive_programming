#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int N, L;
    int a[100005];
    int ans = 1;
    bool all_zero = true;

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> a[i];

        if (a[i] != 0) {
            all_zero = false;
        }
    }

    if (L == 0 && all_zero) {
        ans = 0;

        cout << ans << endl;

        return;
    }

    sort(a, a + N);

    for (int i = N - 1; i >= 0; i--) {
        int c = N - 1 - i + 1;

        if (c >= a[i]) {
            ans = max(a[i], ans);
        }

        if (c >= a[i] + 1 && L != 0) {
            if (a[i] + 1 > ans) {
                int l = L;

                for (int j = i + 1; j < N; j++) {
                    if (a[j] < a[i] + 1) {
                        l -= a[i] + 1 - a[j];
                    }
                }

                if (l <= 0) {
                    break;
                }

                L = l;

                ans = a[i] + 1;
            }
        }
    }

    if (ans == 1 && !(a[0] == 1 || a[0] == 0)) {
        for (int i = a[0]; i >= 1; i--) {
            if (i <= N) {
                ans = i;

                break;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}
