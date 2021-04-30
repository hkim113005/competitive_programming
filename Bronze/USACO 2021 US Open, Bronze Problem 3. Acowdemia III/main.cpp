#include <iostream>

using namespace std;

char f[10000][10000];
bool a[10000][10000][10000][10000];

int main() {
    int N, M, ans = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> f[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (f[i][j] == 'G') {
                if (i - 1 >= 0) {
                    if (f[i - 1][j] == 'C') {
                        if (i + 1 < N) {
                            if (f[i + 1][j] == 'C') {
                                cnt++;
                            }
                        }
                    }
                }

                if (i + 1 < N) {
                    if (f[i + 1][j] == 'C') {
                        cnt++;
                    }
                }

                if (j - 1 >= 0) {
                    if (f[i][j - 1] == 'C') {
                        cnt++;
                    }
                }

                if (j + 1 < M) {
                    if (f[i][j + 1] == 'C') {
                        cnt++;
                    }
                }

                if (cnt >= 2) {
                    cout << i + 1 << " " << j + 1 << endl;
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
