#include <iostream>

using namespace std;

int main() {
    int N;
    int a[55];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                continue;
            }

            ans += i - j;

            int tmp = a[i];

            for (int k = i; k > j; k--) {
                a[k] = a[k - 1];
            }

            a[j] = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
