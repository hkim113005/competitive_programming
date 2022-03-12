#include <iostream>

int start_x, start_y, min = 100;
char farm[10][10];

void path(int x, int y, int cnt, int s) {
    if (x == -1 || y == -1 || x == 10 || y == 10 || cnt > 100) {
        return;
    }
    else if (farm[x][y] == 'L') {
        if (cnt < min) {
            min = cnt;
        }
        return;
    }
    else if (farm[x][y] == 'B') {
        return;
    }
    else if (farm[x][y] == 'R') {
        return;
    }
    if (s != -1) {
        path(x + 1, y, cnt + 1, 1);
    }
    if (s != -2) {
        path(x, y + 1, cnt + 1, 2);
    }
    if (s != 1) {
        path(x - 1, y, cnt + 1, -1);
    }
    if (s != 2) {
        path(x, y - 1, cnt + 1, -2);
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%c", &farm[i][j]);
            if (farm[i][j] == 10) {
                scanf("%c", &farm[i][j]);
            }
            if (farm[i][j] == 'B') {
                start_x = i;
                start_y = j;
            }
        }
    }

    path(start_x + 1, start_y, 0, 0);
    path(start_x, start_y + 1, 0, 0);

    printf("%d", min);
}
