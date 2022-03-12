#include <iostream>
#include <stack>

using namespace std;

int N;
int green[505][505];
long long cnt = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> green[i][j];

            if (green[i][j] == 100) {
                cnt++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1 && j == 1) {
                continue;
            }

            for (int k = 0; k <= N - i; k++) {
                for (int l = 0; l <= N - j; l++) {
                    if (green[k][l] < 100) {
                        continue;
                    }

                    int min = -1;
                    for (int m = 0; m < i; m++) {
                        for (int n = 0; n < j; n++) {
                            if (min == -1 || green[m + k][n + l] < min) {
                                min = green[m + k][n + l];

                                if (min < 100) {
                                    break;
                                }
                            }
                        }

                        if (min < 100 && min != -1) {
                            break;
                        }
                    }

                    if (min == 100) {
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
