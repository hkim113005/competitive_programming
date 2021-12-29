#include <iostream>

using namespace std;

int main() {
    int N;
    int A[100005];
    int x = -1, y;
    int ans = 1000000000;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];

        if (A[i] < 0) {
            x++;
        }
    }
    y = x + 1;

    if (x == -1) {
        ans = A[0] + A[1];
    }

    if (y == N) {
        ans = A[N - 2] + A[N - 1];
    }

    while (x >= 0 && y < N) {
        if (abs(A[x] + A[y]) < abs(ans)) {
            ans = A[x] + A[y];
        }

        if (-A[x] < A[y]) {
            x--;
        } else {
            y++;
        }
    }

    cout << ans;

    return 0;
}
