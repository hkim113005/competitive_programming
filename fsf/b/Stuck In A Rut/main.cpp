#include <iostream>

using namespace std;

typedef struct cow {
    int x, y;
    char d;
} cow;

cow cows[55];

int main() {
    int n, E[55][2], N[55][2], a = 0, b = 0, cnt[55];
    bool stop[55];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].d >> cows[i].x >> cows[i].y;

        if (cows[i].d == 'N') {
            N[b][0] = cows[i].x;
            N[b][1] = cows[i].y;
            b++;
        }
        else {
            E[a][0] = cows[i].x;
            E[a][1] = cows[i].y;
            a++;
        }

        stop[i] = false;
        cnt[i] = 0;
    }

    int t = 0;
    bool go = true;
    while (go) {
        go = false;

        for (int i = 0; i < n; i++) {
            int nx, ny;

            if (!stop[i]) {
                if (cows[i].d == 'N') {
                    nx = cows[i].x;
                    ny = cows[i].y + 1;

                    bool inf = true;
                    for (int j = 0; j < n; j++) {
                        if (cows[j].d == 'E') {
                            if (cows[j].y == ny && cows[j].x - cnt[j] <= nx && nx < cows[])
                        }
                    }

                    if (inf) {
                        stop[i] = true;
                        cnt[i] = -1;
                    }
                    else {
                        cows[i].x = nx;
                        cows[i].y = ny;
                        cnt[i]++;
                    }
                } else {
                    nx = cows[i].x + 1;
                    ny = cows[i].y;

                    bool inf = true;
                    for (int j = 0; j < b; j++) {
                        if (N[j][0] == nx && N[j][1] + t > ny) {
                            stop[i] = true;
                            break;
                        }
                        if (N[j][0] > nx) {
                            inf = false;
                        }
                    }

                    if (inf) {
                        stop[i] = true;
                        cnt[i] = -1;
                    }
                    else {
                        cows[i].x = nx;
                        cows[i].y = ny;
                        cnt[i]++;
                    }
                }

                go = true;
            }
        }

        t++;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] == -1) {
            cout << "Infinity" << endl;
        }
        else {
            cout << cnt[i] << endl;
        }
    }

    return 0;
}
