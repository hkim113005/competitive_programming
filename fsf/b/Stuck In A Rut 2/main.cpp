#include <iostream>

using namespace std;

typedef struct cow {
    int x, y;
    char d;
} cow;

cow cows[55];

int main() {
    int n, cnt[55], E[55][3], N[55][3], a = 0, b = 0, min[55];
    bool stop[55], infinity[55];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].d >> cows[i].x >> cows[i].y;
        cnt[i] = 0;
        stop[i] = false;
        infinity[i] = false;

        if (cows[i].d == 'E') {
            E[a][0] = cows[i].x;
            E[a][1] = cows[i].y;
            E[a][2] = i;
            a++;
        }
        else {
            N[b][0] = cows[i].x;
            N[b][1] = cows[i].y;
            N[b][2] = i;
            b++;
        }

        min[i] = -1;
    }

    bool go = true;
    int s = 0;
    while (go) {
        /*
        int m = 15;
        char board[30][30];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = '*';
            }
        }
        for (int i = 0; i < n; i++) {
            if (cows[i].d == 'N') {
                board[cows[i].x][cows[i].y] = 'N';
            }
            else {
                board[cows[i].x][cows[i].y] = 'E';
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << board[j][i];
            }
            cout << endl;
        }

        cout << endl << endl;
        */
        go = false;

        for (int i = 0; i < n; i++) {
            if (!stop[i]) {
                if (cows[i].d == 'N') {
                    cows[i].y++;
                    cnt[i]++;

                    if (cows[i].y > 1000000000) {
                        stop[i] = true;
                        infinity[i] = true;
                    }
                } else {
                    cows[i].x++;
                    cnt[i]++;

                    if (cows[i].x > 1000000000) {
                        stop[i] = true;
                        infinity[i] = true;
                    }
                }

                go = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!stop[i]) {
                if (cows[i].d == 'N') {
                    bool inf = true;

                    for (int j = 0; j < n; j++) {
                        if (cows[j].d == 'E') {
                            if ((cows[j].y == cows[i].y && cows[j].x - cnt[j] < cows[i].x && cows[i].x < cows[j].x) || (cows[j].y == cows[i].y && infinity[j] && cows[j].x - cnt[j] < cows[i].x)) {
                                stop[i] = true;
                            }
                            if (cows[j].y >= cows[i].y) {
                                inf = false;
                            }
                        }
                    }

                    if (inf) {
                        stop[i] = true;
                        infinity[i] = true;
                    }
                } else {
                    bool inf = true;

                    for (int j = 0; j < n; j++) {
                        if (cows[j].d == 'N') {
                            if (cows[j].x == cows[i].x && cows[j].y - cnt[j] < cows[i].y && cows[i].y < cows[j].y || (cows[j].x == cows[i].x && infinity[j] && cows[j].y - cnt[j] < cows[i].y)) {
                                stop[i] = true;
                            }
                            if (cows[j].x >= cows[i].x) {
                                inf = false;
                            }
                        }
                    }

                    if (inf) {
                        stop[i] = true;
                        infinity[i] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (infinity[i]) {
            cout << "Infinity" << endl;
        }
        else {
            cout << cnt[i] << endl;
        }
    }

    return 0;
}
/*
10
N 12 4
N 7 7
N 4 1
N 6 8
N 9 10
N 10 2
N 5 3
N 8 5
N 11 6
N 1 9
 */