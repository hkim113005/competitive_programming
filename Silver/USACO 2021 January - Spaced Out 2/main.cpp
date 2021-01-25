#include <iostream>

using namespace std;

int N, ans = 0;
int values[1005][1005], p[1005][1005];

void print(int picture[1005][1005]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << picture[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void process(int x, int y, int picture[1005][1005]) {
    int cnt = 0;

    if (y + 1 >= N) {
        x++;
        y = 0;
    }
    if (x + 1 >= N) {
        print(picture);

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

    print(picture);

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
                for (int k = x; k <= x + 1; k++) {
                    for (int l = y; l <= x + 1; l++) {
                        if (picture[i][j] == -1 && picture[k][l] == -1) {
                            int ni, nj, nk, nl;

                            if (i == x) {
                                ni = x + 1;
                            }
                            else {
                                ni = x;
                            }

                            if (j == y) {
                                ni = y + 1;
                            }
                            else {
                                ni = y;
                            }

                            if (k == x) {
                                nk = x + 1;
                            }
                            else {
                                nk = x;
                            }

                            if (l == y) {
                                nl = y + 1;
                            }
                            else {
                                nl = y;
                            }

                            picture[ni][nj] = 0;

                            picture[nk][nl] = 0;

                            picture[i][j] = 1;
                            picture[k][l] = 1;
                            process(x, y, picture);
                            picture[k][l] = 1;
                            picture[i][j] = -1;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> values[i][j];

            p[i][j] = -1;
        }
    }

    process(0, 0, p);

    cout << ans << endl;

    return 0;
}
