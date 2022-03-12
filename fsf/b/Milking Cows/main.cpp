/*
ID: hyungja1
LANG: C++
TASK: milk2
 */
#include <iostream>

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int n, time[5000][2];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &time[i][0], &time[i][1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (time[j][0] > time[j + 1][0]) {
                int tmp;

                tmp = time[j][0];
                time[j][0] = time[j + 1][0];
                time[j + 1][0] = tmp;

                tmp = time[j][1];
                time[j][1] = time[j + 1][1];
                time[j + 1][1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (time[i][0] < time[j][0] && time[i][1] > time[j][1]) {
                time[j][0] = -1;
                time[j][1] = -1;
            }
            else if (time[i][0] > time[j][0] && time[i][1] < time[j][1]) {
                time[i][0] = -1;
                time[i][1] = -1;
            }
        }
    }

    int cnt = 0, ntime[5000][2];

    for (int i = 0; i < n; i++) {
        if (time[i][0] != -1) {
            ntime[cnt][0] = time[i][0];
            ntime[cnt][1] = time[i][1];
            cnt++;
        }
    }

    int milk = 0, t;

    t = ntime[0][1] - ntime[0][0];

    for (int i = 0; i < cnt - 1; i++) {
        if (ntime[i + 1][0] <= ntime[i][1]) {
            if (ntime[i + 1][1] > ntime[i][1]) {
                t += ntime[i + 1][1] - ntime[i][1];
            }
        }
        else {
            if (t > milk) {
                milk = t;
            }
            t = ntime[i + 1][1] - ntime[i + 1][0];
        }
    }
    if (t > milk) {
        milk = t;
    }

    int idle = 0;

    for (int i = 0; i < cnt - 1; i++) {
        int dif = ntime[i + 1][0] - ntime[i][1];

        if (dif > idle) {
            idle = dif;
        }
    }

    if (n == 1) {
        milk = time[0][1] - time[0][0];
        idle = 0;
    }

    if (cnt == 0) {
        idle = 0;
    }

    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", ntime[i][0], ntime[i][1]);
    }

    printf("%d %d\n", milk, idle);
}
