#include <iostream>

int main() {
    int n, m, cnt = 0, pos[2500][2];
    char cw[52][52];

    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            cw[i][j] = '#';
        }
    }

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        char tmp[52];

        scanf("%s", tmp);

        for (int j = 0; j < m; j++) {
            cw[i + 1][j + 1] = tmp[j];
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (cw[i][j] == '.') {
                if (cw[i][j - 1] == '#' && cw[i][j + 1] == '.' && cw[i][j + 2] == '.' ) {
                    pos[cnt][0] = i;
                    pos[cnt][1] = j;
                    cnt++;
                }
                else if (cw[i - 1][j] == '#' && cw[i + 1][j] == '.' && cw[i + 2][j] == '.') {
                    pos[cnt][0] = i;
                    pos[cnt][1] = j;
                    cnt++;
                }
            }
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", pos[i][0], pos[i][1]);
    }
}
