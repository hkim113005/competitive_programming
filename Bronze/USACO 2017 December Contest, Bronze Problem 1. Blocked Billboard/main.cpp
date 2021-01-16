#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

bool view[2005][2005] = { false };

void process(int x1, int y1, int x2, int y2, int n) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            if (!view[i + 1000][j + 1000]) {
                if (n != 2) {
                    view[i + 1000][j + 1000] = true;
                }
            }
            else {
                if (n == 2) {
                    view[i + 1000][j + 1000] = false;
                }
            }
        }
    }
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2, cnt = 0, minx, miny, maxx, maxy;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        process(x1, y1, x2, y2, i);
    }
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (view[i][j]) {
                cnt++;
            }
        }
    }

    printf("%d", cnt);
}
