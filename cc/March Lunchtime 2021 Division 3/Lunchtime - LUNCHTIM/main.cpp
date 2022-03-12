#include <iostream>

using namespace std;

void solve() {
    int N;
    int A[100005] = {0, };
    int C[100005] = {0, };

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];

        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > A[i]) {
                break;
            }

            if (A[j] == A[i]) {
                C[i]++;
                C[j]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << C[i] << " ";
    }

    cout << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}