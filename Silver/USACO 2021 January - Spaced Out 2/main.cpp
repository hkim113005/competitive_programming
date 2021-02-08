#include <iostream>

using namespace std;

int N, ans = 0;
int values[1005][1005];

void process(int x, int y, int picture[1005][1005]) {
    int cnt = 0;

    if (y + 1 >= N) {
        x++;
        y = 0;
    }
    if (x + 1 >= N) {
        int v = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (picture[i][j]) {
                    v += values[i][j];
                }
            }
        }

        ans = max(ans, v);

        return;
    }

    for (int i = x; i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
            if (picture[i][j] == 1) {
                cnt++;
            }
        }
    }

    if (cnt == 2) {
        process(x, y + 1, picture);
    }
    else {
        for (int i = x; i <= x + 1; i++) {
            for (int j = y; j <= y + 1; j++) {
                if (picture[i][j] == 0) {
                    picture[i][j] = 1;
                    process(x, y, picture);
                    picture[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int p[1005][1005];

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> values[i][j];

            p[i][j] = 0;
        }
    }

    process(0, 0, p);

    cout << ans;

    return 0;
}