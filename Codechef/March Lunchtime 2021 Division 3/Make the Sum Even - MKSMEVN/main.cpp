#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void solve() {
    int N;
    int A[100005];
    int sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if (sum % 2 == 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == 2) {
            cout << 1 << endl;
            return;
        }
        /*
        int p = max(0, (int)ceil((double)A[i] / 2) - 1);

        int a = A[i] % 2;
        int b = (int)pow(A[i], p) % 2;

        if (a != b) {
            cout << 1 << endl;
            return;
        }
         */
    }

    cout << -1 << endl;
    return;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
