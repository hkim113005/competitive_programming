#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    static bool view[2001][2001];
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            view[i][j] = false;
        }
    }
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int i = x1 + 1000; i < x2 + 1000; i++) {
        for (int j = y1 + 1000; j < y2 + 1000; j++) {
            view[i][j] = true;
        }
    }

    int dx1 = x1, dy1 = y1, dx2 = x2, dy2 = y2;

    /*
    for (int i = dx1 + 1000; i < dx2 + 1000; i++) {
        for (int j = dy1 + 1000; j < dy2 + 1000; j++) {
            printf("%d ", view[i][j]);
        }
        printf("\n");
    }
    //*/

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int i = x1 + 1000; i < x2 + 1000; i++) {
        for (int j = y1 + 1000; j < y2 + 1000; j++) {
            if (view[i][j]) {
                view[i][j] = false;
            }
        }
    }

    /*
    printf("\n");
    for (int i = dx1 + 1000; i < dx2 + 1000; i++) {
        for (int j = dy1 + 1000; j < dy2 + 1000; j++) {
            printf("%d ", view[i][j]);
        }
        printf("\n");
    }
    //*/

    int cnt = 0, maxx = 0, maxy = 0;
    for (int i = dx1 + 1000; i < dx2 + 1000; i++) {
        for (int j = dy1 + 1000; j < dy2 + 1000; j++) {
            if (view[i][dy1 + 1000] && view[i][dy2 + 999]) {
                maxx = dy2 - dy1;
            }
            if (view[i][j]) {
                cnt++;
            } else {
                if (maxx < cnt) {
                    maxx = cnt;
                }
                cnt = 0;
            }
        }
        if (maxx < cnt) {
            maxx = cnt;
        }
        cnt = 0;
    }
    for (int i = dy1 + 1000; i < dy2 + 1000; i++) {
        for (int j = dx1 + 1000; j < dx2 + 1000; j++) {
            if (view[dx1 + 1000][i] && view[dx2 + 999][i]) {
                maxy = dx2 - dx1;
            }
            if (view[j][i]) {
                cnt++;
            } else {
                if (maxy < cnt) {
                    maxy = cnt;
                }
                cnt = 0;
            }
        }
        if (maxy < cnt) {
            maxy = cnt;
        }
        cnt = 0;
    }
    printf("%i\n", maxx * maxy);
}
