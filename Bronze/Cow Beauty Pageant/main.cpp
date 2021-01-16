#include <iostream>
#include <math.h>

int n, m, cnt1 = 0, cnt2 = 0;
char hide[1000][1000];

typedef struct pos {
    int x, y;
} pos;

pos one[2500];
pos two[2500];

int main() {
    bool first = true;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &hide[i][j]);
            if (hide[i][j] == 10) {
                scanf("%c", &hide[i][j]);
            }
            if(first && hide[i][j] == 'X') {
                hide[i][j] = '1';
                first = false;
            }
        }
    }

    for (int h = 0; h < m; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (hide[i][j] == 'X') {
                    if (i - 1 >= 0) {
                        if (hide[i - 1][j] == '1') {
                            hide[i][j] = '1';
                        }
                    }
                    if (i + 1 < n) {
                        if (hide[i + 1][j] == '1') {
                            hide[i][j] = '1';
                        }
                    }
                    if (j - 1 >= 0) {
                        if (hide[i][j - 1] == '1') {
                            hide[i][j] = '1';
                        }
                    }
                    if (j + 1 < m) {
                        if (hide[i][j + 1] == '1') {
                            hide[i][j] = '1';
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (hide[i][j] == 'X') {
                hide[i][j] = '2';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (hide[i][j] == '1') {
                one[cnt1].x = i;
                one[cnt1].y = j;
                cnt1++;
            }
            if (hide[i][j] == '2') {
                two[cnt2].x = i;
                two[cnt2].y = j;
                cnt2++;
            }
        }
    }

    int min = 1000000;

    for (int i = 0; i < cnt1; i++) {
        for (int j = 0; j < cnt2; j++) {
            int tmp = abs(one[i].x - two[j].x) + abs(one[i].y - two[j].y);
            if (tmp < min) {
                min = tmp;
            }
        }
    }

    printf("%d", min - 1);
}
