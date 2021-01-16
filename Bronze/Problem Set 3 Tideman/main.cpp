#include <iostream>

bool circle(int a[10][2], int n, int N, int cnt) {
    if (N > cnt + 1) {
        return true;
    }
    for (int i = 0; i < cnt; i++) {
        if (a[i][0] == n) {
            if (circle(a, a[i][1], N + 1, cnt)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a[10][2];
    bool locked[10][10];
    int pair_count = 5, candidate_count = 4;
    for (int i = 0; i < 10; i++) {
        a[i][0] = -1;
        a[i][1] = -1;
        for (int j = 0; j < 10; j++) {
            locked[i][j] = false;
        }
    }
    for (int i = 0; i < pair_count; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    /*
    a[0][0] = 1;
    a[0][1] = 2;

    a[1][0] = 0;
    a[1][1] = 1;

    a[2][0] = 3;
    a[2][1] = 0;

    a[3][0] = 2;
    a[3][1] = 3;

    a[0][0] = 1;
    a[0][1] = 2;

    a[1][0] = 4;
    a[1][1] = 3;

    a[2][0] = 3;
    a[2][1] = 1;

    a[3][0] = 1;
    a[3][1] = 4;

    a[4][0] = 0;
    a[4][1] = 4;

    a[5][0] = 2;
    a[5][1] = 3;
    */

    bool c;
    for (int i = 0; i < pair_count; i++) {
        c = false;
        for (int j = 0; j < candidate_count; j++) {
            if (circle(a, j, 0, i + 1)) {
                c = true;
            }
        }
        if (c) {
            a[i][0] = -1;
            a[i][1] = -1;
        }
        else {
            locked[a[i][0]][a[i][1]] = true;
        }
    }
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            printf("%d ", locked[i][j]);
        }
        printf("\n");
    }
}
