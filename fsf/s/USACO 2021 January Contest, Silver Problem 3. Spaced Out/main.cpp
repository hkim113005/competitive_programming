#include <iostream>

using namespace std;

int N;
int a[1005][1005];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int x, y;

    x = y = 0;

    for (int i = 0; i < N; i++) {
        int even1, odd1;
        int even2, odd2;

        even1 = odd1 = 0;
        even2 = odd2 = 0;

        for (int j = 0; j < N; j += 2) {
            even1 += a[i][j];
            even2 += a[j][i];
        }

        for (int j = 1; j < N; j += 2) {
            odd1 += a[i][j];
            odd2 += a[j][i];
        }

        if (odd1 > even1) {
            x += odd1;
        }
        else {
            x += even1;
        }

        if (odd2 > even2) {
            y += odd2;
        }
        else {
            y += even2;
        }
    }

    if (x > y) {
        cout << x;
    }
    else {
        cout << y;
    }

    return 0;
}
