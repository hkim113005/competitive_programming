#include <iostream>

int main() {
    int k, n, cows[10][20], pairs[1000][2], cnt = 0;

    scanf("%d %d", &k, &n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cows[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs[cnt][0] = cows[0][i];
            pairs[cnt][1] = cows[0][j];
            cnt++;
        }
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                for (int m = 0; m < cnt; m++) {
                    if (cows[i][j] == pairs[m][1] && cows[i][l] == pairs[m][0]) {
                        pairs[m][0] = 0;
                        pairs[m][1] = 0;
                    }
                }
            }
        }
    }

    int count = 0;

    for (int i = 0; i < cnt; i++) {
        if (pairs[i][0] != 0) {
            count++;
        }
    }

    printf("%d", count);
}
